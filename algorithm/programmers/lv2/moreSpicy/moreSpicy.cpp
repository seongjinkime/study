//
//  main.cpp
//  moreSpicy
//
//  Created by Kim Seong Jin on 2019. 9. 17..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;


/*
void popValues(vector<int>* elems, long long* first, long long* second){
    *first = (*elems).back();
    (*elems).pop_back();
    
    *second = (*elems).back();
    (*elems).pop_back();
}

void pushHeap(vector<int>* elems, long long value){
    (*elems).push_back(value);
    push_heap((*elems).begin(), (*elems).end());
}

int solution(vector<int> scoville, int K) {
    long long first, second, mix;
    int cnt;
    
    first = second = 0;
    cnt = 0;
    
    make_heap(scoville.begin(), scoville.end());
    
    while(scoville.size() > 1){
        popValues(&scoville, &first, &second);
        if(first>=K)
            return cnt;
        mix = first + (second*2);
        pushHeap(&scoville, mix);
        cnt++;
    }
    return -1;
    
}
*/


void popValues(priority_queue<int, vector<int>, greater<int>>* pq, int* first, int* second){
    *first = (*pq).top();
    (*pq).pop();
    *second = (*pq).top();
    (*pq).pop();
}

int solution(vector<int> scoville, int K) {
    int cnt;
    int first, second;
    int mix;
    
    cnt = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int idx = 0 ; idx<scoville.size() ; idx++){
        pq.push(scoville[idx]);
    }
    
    while(pq.size() > 1){
        popValues(&pq, &first, &second);
        if(first >= K){
            return cnt;
        }
        mix = first + (second*2);
        pq.push(mix);
        cnt++;
    }
    
    
    return -1;
}

int main(int argc, const char * argv[]) {
    vector<int> scoville {7, 7, 7, 9 , 10, 12};
    cout << solution(scoville, 7) << endl;
    
    return 0;
}
