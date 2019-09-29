//
//  main.cpp
//  findDecimal
//
//  Created by Kim Seong Jin on 2019. 9. 20..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> subVec(vector<int>src, vector<int> exist){
    vector<int>::iterator fi;
    for(int n : exist){
        fi = find(src.begin() , src.end(), n);
        if(fi!=src.end())src.erase(fi);
    }
    return src;
}

void test(vector<int>tNum){
    vector<int> iStack;
    
    for(int t : tNum)  iStack.push_back(t);
    
    cout<<endl;
   
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> test{0, 1, 2, 3, 4};
    vector<int> exist{1, 2};
    vector<int>sub = subVec(test, exist);
    
    for(int i : sub) cout<< i << " ";
    return 0;
}
