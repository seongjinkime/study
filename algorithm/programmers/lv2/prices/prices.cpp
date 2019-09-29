//
//  main.cpp
//  prices
//
//  Created by Kim Seong Jin on 2019. 9. 23..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    vector<int>::iterator min;
    int distance = 0;
    while(prices.size()>0){
        min = min_element(prices.begin(), prices.end());
        
        if(prices.front() == (*min)){
            distance = (int)prices.size()-1;
        }else{
            distance = (prices.end() - min)-1;
            cout<<distance;
        }
        answer.push_back(distance);
        prices.erase(prices.begin());
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> test {1, 2, 3, 2, 3};
    solution(test);
    return 0;
}
