#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

typedef struct _TASK{
    int priority;
    int id;
}TASK;

vector<TASK*> queue;

void enqueue(int id, int priority){
    TASK* task = (TASK*)malloc(sizeof(TASK));
    task->priority = priority;
    task->id = id;
    queue.push_back(task);
}

bool isMaxPriority(TASK* task){
    vector<TASK*>::iterator it;
    for( it = queue.begin() ; it != queue.end() ; it++){
        if((*it)->priority > task->priority)
            return false;
    }
    return true;
}

TASK* dequeue(){
    TASK* task = queue.front();
    queue.erase(queue.begin());
    
    while(!isMaxPriority(task)){
        queue.push_back(task);
        task = queue.front();
        queue.erase(queue.begin());
    }
    return task;
}

int solution(vector<int> priorities, int location) {
    int cnt;
    
    for(int idx = 0 ; idx < priorities.size() ; idx++)
        enqueue(idx, priorities[idx]);
    
    for(cnt = 1 ; dequeue()->id != location ; cnt++);
    
    
    return cnt;
}

int main(void){
    vector<int>test {1, 1, 9, 1, 1, 1};
    cout << solution(test, 0);

    
}
