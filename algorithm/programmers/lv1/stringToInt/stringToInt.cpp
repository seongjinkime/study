//
//  main.cpp
//  stringToInt
//
//  Created by Kim Seong Jin on 2019. 9. 11..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s);
int pow(int num, int n);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    cout << solution("-1234") << endl;
    return 0;
}


int solution(string s) {
    int answer = 0;
    int sign = 1;
    int powNum = 1;
    
    switch(s[0]){
        case '+':
            s = s.substr(1, s.size());
            break;
        case '-':
            sign = -1;
            s = s.substr(1, s.size());
            break;
    }
    
    for(int idx = s.size()-1 ; idx >= 0 ; idx--){
        answer += (s[idx] - '0') * powNum;
        powNum *= 10;
    }
    
    return sign * answer;
}

