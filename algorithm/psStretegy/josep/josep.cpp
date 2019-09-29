//
//  main.cpp
//  josep
//
//  Created by Kim Seong Jin on 2019. 9. 24..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

void solutionByQueue(int pNum, int k){
    queue<int> peoples;
    for(int i = 1 ; i <= pNum ; i++)peoples.push(i);
    while(pNum>2){
        peoples.pop();
        pNum--;
        for(int j = 0 ; j < k-1 ; j++){
            peoples.push(peoples.front());
            peoples.pop();
        }
    }
    
    cout<<peoples.front() << ", " << peoples.back();
}

void answer(int pNum, int k){
    //리스트를 준비한다
    list<int> survivors;
    for(int i = 1 ; i <= pNum ; i++) survivors.push_back(i);
    //죽을 사람을 나타내는 포인터
    list<int>::iterator kill = survivors.begin();
    
    while(pNum > 2){
        kill = survivors.erase(kill); // 첫번째 사람이 자살한다. erase()는 지운 다음의 원소 반환
        if(kill==survivors.end()) kill = survivors.begin();
        pNum--; //사람의 수 감소
        for(int i = 0 ; i < k-1 ; i++){ //직전에 죽었던 사람의 다음 순서를 가리키고 있으므로 k-1번 만큼만 이동
            kill++; //죽음의 포인터 이동
            if(kill == survivors.end()) kill = survivors.begin(); //만약 끝에 도달 했다면 처음 으로 이동
        }
    }
    for(int i : survivors) cout<<i<<" ";
    
}

void solution(int pNum, int k){
    list<int> peoples;
    for(int i = 1 ; i <= pNum ; i++){
        peoples.push_back(i);
    }
    list<int>::iterator it = peoples.begin();
    while(peoples.size()>2){
        peoples.erase(it);
        for(int i = 0 ; i < k ; i++){
            it++;
            if(it == peoples.end())
                it = peoples.begin();
        }
    }
    for(int i : peoples) cout<<i<<" ";
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n = 40;
    int k = 3;
    //solution(n, k);
    answer(n, k);
    solutionByQueue(n, k);
    cout<<endl;
    return 0;
}
