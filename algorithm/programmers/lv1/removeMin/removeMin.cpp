//
//  main.cpp
//  removeMin
//
//  Created by Kim Seong Jin on 2019. 9. 13..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> solution(vector<int> arr);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> test{10, 11};
    vector<int> ans = solution(test);
    
    for(vector<int>::iterator it = ans.begin() ; it != ans.end(); it++){
        cout << *it ;
    }
    
    return 0;
}



vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min = 0;
    
    for(int idx = 1 ; idx < arr.size() ; idx++){
        if (arr[idx] < arr[min])
            min = idx;
    }
    
    arr.erase(arr.begin() + min);
    return arr.size() > 0 ? arr : vector<int> {-1};

}
