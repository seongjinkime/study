//
//  main.cpp
//  decisionSquareRoot
//
//  Created by Kim Seong Jin on 2019. 9. 12..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(long long n);

int main(int argc, const char * argv[]) {
    // insert code here...
    int test = 121;
    cout << solution(test) << endl;
    
    return 0;
}



long long solution(long long n) {
    long long root = -1;
    for (long long i = 0 ; i < n ; i++){
        if(i*i ==  n){
            root = i;
            break;
        }
    }
    
    if(root > 0){
        root++;
        return root * root;
    }else{
        return -1;
    }
    
}
