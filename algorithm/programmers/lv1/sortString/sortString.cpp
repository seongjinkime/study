//
//  main.cpp
//  sortString
//
//  Created by Kim Seong Jin on 2019. 9. 11..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int idx;
vector<string> mySolution(vector<string> strings, int n);
vector<string> bestSolution(vector<string> strings, int n);
bool comp (string s1, string s2);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string> test {"sun", "bed", "car"};
    vector<string> ans;
    int n = 1;
    
    ans = mySolution(test, n);
    ans = bestSolution(test, n);
    cout << ans[0] << ans[1] << ans[2] << endl;
    return 0;
}


bool comp (string s1, string s2){
    if (s1[idx] != s2[idx]){
        return s1[idx] < s2[idx];
    }else{
        return s1 < s2;
    }
}

vector<string> mySolution(vector<string> strings, int n) {
    vector<string> answer;
    idx = n;
    sort(strings.begin(), strings.end(), comp);
    return strings;
}

bool compare(string s1, string s2){
    return s1[idx] == s2[idx] ? s1 < s2 : s1[idx] < s2[idx];
}


vector<string> bestSolution(vector<string> strings, int n) {
    idx = n;
    sort(strings.begin(), strings.end(), comp);
    return strings;
}
