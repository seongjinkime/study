//
//  main.cpp
//  124Numbers
//
//  Created by Kim Seong Jin on 2019. 9. 23..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>


using namespace std;

vector<string>numbers{"0","1","2","4"};


string solution(int n) {
    int index = 4;
    string newNumber;
    while(index <= n){
        if(index % 3 == 0){
            newNumber = to_string(stoll(numbers[index-1]) + 2);
        }else{
            newNumber = numbers[index/3] + numbers[index%3];
        }
        numbers.push_back(newNumber);
        index++;
    }
    
    return numbers[n];
}


int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<solution(23)<<endl;
    
    return 0;
}
