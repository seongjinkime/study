//
//  main.cpp
//  developFunction
//
//  Created by Kim Seong Jin on 2019. 9. 20..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int publish(vector<int>& progresses, vector<int>& speeds){
    int cnt = 0;
    while(progresses.size() > 0 && progresses.front() >= 100){
        cnt++;
        progresses.erase(progresses.begin());
        speeds.erase(speeds.begin());
    }
    return cnt;
    
}

void work(vector<int>& progresses, vector<int>speeds){
    for(int idx = 0 ; idx < progresses.size() ; idx++){
        progresses[idx] += speeds[idx];
    }
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int pub;
    while(progresses.size()>0){
        work(progresses, speeds);
        pub = publish(progresses, speeds);
        if(pub>0) answer.push_back(pub);
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    //vector<int>progresses{93,30,55};
    vector<int>progresses{93,30,55};
    vector<int>speeds{1,30,5};
    
    vector<int> ans = solution(progresses, speeds);
    for(int i : ans){
        cout<<i << " ";
    }
    cout<<endl;
    
    return 0;
}
