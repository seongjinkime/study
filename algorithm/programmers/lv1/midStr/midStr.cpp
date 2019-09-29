//
//  main.cpp
//  midStr
//
//  Created by Kim Seong Jin on 2019. 9. 9..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string mySolution(string s);
string bestSolution(string s);

int main(int argc, const char * argv[]) {
    
    cout << mySolution("abced") << endl;
    cout << mySolution("qwer") << endl;
    
    cout << bestSolution("abced") << endl;
    cout << bestSolution("qwer") << endl;
    
    return 0;
}

string mySolution(string s) {
    int mid = s.size() / 2;
    
    if (s.size() % 2 == 0){
        return s.substr(mid-1, 2);
    }else{
        return s.substr(mid, 1);
    }
    
}

string bestSolution(string s){
    return s.size() & 1 ? s.substr(s.size()*0.5, 1) : s.substr(s.size()*0.5-1, 2);
}
