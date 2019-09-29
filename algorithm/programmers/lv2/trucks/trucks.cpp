//
//  main.cpp
//  trucks
//
//  Created by Kim Seong Jin on 2019. 9. 19..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <queue>
#include <list>

using namespace std;

typedef struct _TRUCK{
    int weight;
    int process;
}TRUCK;

bool isOver(list<TRUCK>bridge, queue<TRUCK> wtg, int weight){
    int sum=wtg.front().weight;
    list<TRUCK>::iterator truck;
    for(truck = bridge.begin() ; truck != bridge.end() ; truck++){
        sum+=(*truck).weight;
    }
    
    return sum>weight;
}

void process(list<TRUCK>& bridge){
    list<TRUCK>::iterator truck;
    for(truck = bridge.begin() ; truck != bridge.end() ; truck++){
        (*truck).process+=1;
    }
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<TRUCK>wtg, fin;
    list<TRUCK>bridge;
    int cnt = 1;
    
    for(int w : truck_weights)
        wtg.push(TRUCK{w, 0});
    
    while(fin.size()!=truck_weights.size()){
        
        if(wtg.size()>0 && !isOver(bridge, wtg, weight)){
            bridge.push_back(wtg.front());
            wtg.pop();
        }
        
        process(bridge);
        
        if(bridge.front().process==bridge_length){
            fin.push(bridge.front());
            bridge.pop_front();
        }
        cnt++;
    }
    
    return cnt;
}

int main(int argc, const char * argv[]) {
    vector<int> trucks {10,10,10,10,10,10,10,10,10,10};
    int len = 100;
    int w = 100;
    
    cout<<solution(len, w, trucks)<<endl;
    
    return 0;
}
