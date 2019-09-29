//
//  main.cpp
//  KMP
//
//  Created by Kim Seong Jin on 2019. 9. 25..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printArr(vector<int> table){
    for(int i : table) cout<<i<<", ";
    cout<<endl;
}

vector<int> getPartialMatchNaive(const string& pattern){
    int pSize = pattern.size();
    vector<int>pi(pSize, 0);
    
    for(int begin = 1 ; begin < pSize ; ++begin){
        for(int i = 0 ; i < pSize ; ++i){
            //printArr(pi);
            //cout<<begin+i<<endl;
            if(pattern[begin+i] != pattern[i])break;
            pi[begin+i] = max(pi[begin+i], i+1);
            
        }
        
    }
    printArr(pi);
    cout<<pi[3]<<endl;
    
    return pi;
}

vector<int>makeTable(string pattern){
    vector<int>table (pattern.size(), 0);
    int j = 0;
    
    for(int i = 1 ; i < pattern.size() ; i++){
        while(j>0 && pattern[j] != pattern[i]){
            j = table[j-1];
        }
        if(pattern[i] == pattern[j]){
            table[i] = ++j;
        }
    }
    
    return table;
}

vector<int> kmpSearch(const string&src, const string& pattern){
    int pSize= pattern.size();
    int sSize = src.size();
    vector<int>ret;
    vector<int> pi = makeTable(pattern);
    int begin = 0, matched = 0;
    while(begin <= sSize - pSize){
        if(matched< pSize && src[begin+matched] == pattern[matched]){
            ++matched;
            if(matched==pSize)ret.push_back(begin+1);
        }else{
            if(matched==0)
                begin++;
            else{
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    for(int i : ret) printf("found at %d\n",i);
    
    
    return ret;
}

void KMP(string src, string pattern){
    vector<int>table = makeTable(pattern);
    int j = 0;
    
    for(int  i = 0  ; i < src.size() ; i++){
        while(j>0 && src[i] != pattern[j])
            j = table[j-1];
        
        if(pattern[j] == src[i]){
            if(j == pattern.size()-1){
                printf("found at %d\n", i-j+1);
                j = table[j];
            }else{
                j++;
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    string src = "ababacabacaabacaaba";
    //string pattern = "ababbaba";
    //string pattern = " aabaa";
    string pattern = "abcaabc";
    //cout<<pattern[5]<<endl;
    KMP("abc", "abc");
    //kmpSearch(src, pattern);
    //getPartialMatchNaive(pattern);
    //cout<<endl;
    
    cout<<endl;

    vector<int> pi = {0, 0, 1, 2, 0, 1, 2, 3};
    int k = pi.size();
    while(k>0){
        //cout<<k<<", ";
        k = pi[k-1];
    }
    
    return 0;
}
