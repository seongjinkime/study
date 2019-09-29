//
//  main.cpp
//  removeSameNum
//
//  Created by Kim Seong Jin on 2019. 9. 10..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> mySolution(vector<int> arr);

int main(void) {
    // insert code here...
    int test[] = {1,1,3,3,0,1,1};
    
    vector<int> arr;
    
    vector<int> ans;
    arr.insert(arr.begin(), begin(test), end(test));
    ans = mySolution(arr);
    
    for(vector<int>:: iterator it = ans.begin() ; it != ans.end() ; it++){
        cout<< *it << " ";
    }
    cout << endl;
    
    
    return 0;
}

vector<int> mySolution(vector<int> arr)
{
    vector<int> answer;
    answer.push_back(arr[0]);
    
    for (int idx = 1 ; idx < arr.size() ; idx++){
        if(arr[idx] != answer.back()){
            answer.push_back(arr[idx]);
        }
    }
    
    return answer;
}

