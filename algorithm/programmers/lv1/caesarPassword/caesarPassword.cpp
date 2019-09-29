//
//  main.cpp
//  caesarPassword
//
//  Created by Kim Seong Jin on 2019. 9. 11..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s, int n);
int indexOf(string s, char pattern);
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << solution("a B z", 4) << endl;
    //string test = "ABC";
    //cout <<indexOf(test, test[2]) << endl;
    return 0;
}



string solution(string s, int n) {
    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lower = "abcdefghijklmnopqrstuvwxyz";
    int nextIdx;
    
    for(int idx = 0 ; idx < s.size() ; idx++){
        if(s[idx] == ' ')
            continue;
        
        if(s[idx] >= 'a' && s[idx] <= 'z'){
            nextIdx = (indexOf(lower, s[idx]) + n) % lower.size();
            s[idx] = lower[nextIdx];
        }
        
        if(s[idx] >= 'A' && s[idx] <= 'Z'){
            nextIdx = (indexOf(upper, s[idx]) + n) % upper.size();
            s[idx] = upper[nextIdx];
        }
        
    }
    
    
    return s;
}

int indexOf(string s, char pattern){
    string::size_type idx = s.find(pattern, 0);
    if(idx != string::npos){
        return idx;
    }else{
        return -1;
    }
    
}
