//
//  main.cpp
//  contactList
//
//  Created by Kim Seong Jin on 2019. 9. 17..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>
#include<map>


using namespace std;

bool solution(vector<string> phone_book) {
    vector<string>::iterator walker;
    string prefix, other;
    for (int idx = 0 ; idx < phone_book.size() ; idx++){
        prefix = phone_book[idx];
        for(walker = phone_book.begin() ; walker != phone_book.end() ; walker++){
            other = (*walker);
            if(other == phone_book[idx]) continue;
            
            if(other.compare(0, prefix.size(), prefix) == 0) return false;
        }
    }
    
    return true;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string> test {"123","456","789"};
    string pre = "12";
    string post = "12345";
    cout << post.compare(0, post.size(), pre) << endl;
    
    
    cout <<solution(test)<<endl;
    return 0;
}
