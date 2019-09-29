//
//  main.cpp
//  findKim
//
//  Created by Kim Seong Jin on 2019. 9. 9..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string mySolution(vector<string> seoul);
string bestSolution(vector<string> seoul);

int main(int argc, const char * argv[]) {
    
    vector<string> example;
    example.push_back("Jane");
    example.push_back("Kim");
    
    cout << mySolution(example) << endl;
    cout << bestSolution(example) << endl;
    
    return 0;
}

string mySolution(vector<string> seoul) {
    int loc = distance(seoul.begin(), find(seoul.begin(), seoul.end(), "Kim"));
    return "김서방은 " + to_string(loc) + "에 있다";
    
}

string bestSolution(vector<string> seoul) {
    int loc = find(seoul.begin(), seoul.end(), "Kim") - seoul.begin();
    return "김서방은 " + to_string(loc) + "에 있다";
    
}
