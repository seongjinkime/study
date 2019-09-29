//
//  main.cpp
//  stringBasic
//
//  Created by Kim Seong Jin on 2019. 9. 9..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>

using namespace std;

bool mySolution(string s);
bool bestSolution(string s);

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << mySolution("a234") << endl;
    cout << mySolution("1234") << endl;
    
    cout << bestSolution("a234") << endl;
    cout << bestSolution("1234") << endl;
    
    return 0;
}

bool mySolution(string s) {
    
    if (s.size() != 4 && s.size() != 6){
        return false;
    }
    
    for(int idx = 0 ; idx < s.size() ; idx++){
        if(s[idx] - '0' > 9){
            return false;
        }
    }
    
    return true;
}

bool bestSolution(string s){
    for (int idx = 0 ; idx < s.size() ; idx++){
        if(! isdigit(s[idx])){
            return false;
        }
    }
    
    return s.size() == 4 || s.size() == 6;
}
