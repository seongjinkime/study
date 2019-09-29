//
//  main.cpp
//  laser
//
//  Created by Kim Seong Jin on 2019. 9. 20..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>

using namespace std;

vector<int>popLasers(string& arrangement){
    vector<int>lasers;
    for(int idx = 0 ; idx < arrangement.size() ; idx++){
        if (arrangement[idx] == '(' && arrangement[idx+1] == ')'){
            arrangement[idx] = ' ';
            arrangement[idx+1] = ' ';
            lasers.push_back(idx);
        }
    }
    return lasers;
}

int nextEnd (string& arrangement, int start){
    char end = ')';
    int search = start+1;
    for( ; start < arrangement.size() ; search++){
        if(arrangement[search] == end)return search;
    }
    return -1;
}

vector<vector<int>> popPipes(string& arrangement){
    char start = '(';
    int next;
    vector<vector<int>> pipes;
    
    
    for(int idx = arrangement.size()-1 ; idx >= 0 ; idx--){
        if(arrangement[idx] == start ){
            next = nextEnd(arrangement, idx);
            if(next == -1) break;
            arrangement[idx] = arrangement[next] = ' ';
            pipes.push_back(vector<int>{idx, next});
        }
    }
    return pipes;
}

int solution(string arrangement) {
    int answer = 0;
    vector<int>lasers = popLasers(arrangement);
    vector<vector<int>> pipes = popPipes(arrangement);
    int laserCnt;
    for(int idx = 0 ; idx<pipes.size();idx++){
        laserCnt = 0;
        for(int laser : lasers){
            if(laser > pipes[idx][0] && laser < pipes[idx][1]){
                laserCnt+=1;
            }
        }
        answer+= (laserCnt+1);
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string arrangement = "(((()())(())()))(())";
    cout << solution(arrangement) << endl;
    return 0;
}
