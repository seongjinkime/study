//
//  main.cpp
//  descendString
//
//  Created by Kim Seong Jin on 2019. 9. 10..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>

using namespace std;


string solution(string s);
bool comp(char c1, char c2);

int main(int argc, const char * argv[]) {
    // insert code here...
    string test = "Zbcdefg";
    cout << test[0] << endl;
    //solution(test);
    return 0;
}


bool comp(char c1, char c2){
    return c1 > c2;
}

string solution(string s) {
    string answer = "";
    sort(s.begin(), s.end(), comp);
    cout << s << endl;
    return answer;
}
