//
//  main.cpp
//  nerd2
//
//  Created by Kim Seong Jin on 2019. 9. 27..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int findLowScore(vector<int> totals, int total){
    for(int idx = 0 ; idx < totals.size() ; idx++){
        if(totals[idx] < total) return idx;
    }
    return -1;
}

int solution(vector<vector<int>> scores){
    vector<int> totals;
    int cnt = 0;
    for(int idx = 0 ; idx < scores.size() ; idx++){
        int total = scores[idx][0] + scores[idx][1];
        int pLow = findLowScore(totals, total);
        if(pLow!=-1) totals.erase(totals.begin()+pLow);
        totals.push_back(total);
        cnt+=totals.size();
    }
    return cnt;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> scores;
    scores.push_back({1, 5});
    scores.push_back({2, 4});
    scores.push_back({3, 3});
    scores.push_back({4, 2});
    scores.push_back({5, 1});
    cout<<solution(scores)<<endl;
    return 0;
}
