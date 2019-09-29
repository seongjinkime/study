//
//  main.cpp
//  targetNumber
//
//  Created by Kim Seong Jin on 2019. 9. 18..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdbool.h>
#include <vector>

using namespace std;

typedef struct _GRAPH{
    int vertex;
    int edge;
    int** matrix;
}GRAPH;

typedef struct _NODE{
    bool visited;
    int number;
    
}NODE;

vector<NODE> nodes;
int cnt;

GRAPH* createTable(vector<int> nums){
    GRAPH* graph = (GRAPH*)malloc(sizeof(GRAPH));
    graph->vertex = (int)nums.size();
    graph->edge = 0;
    graph->matrix = (int**)malloc(sizeof(int*) * graph->vertex);
    
    for(int row = 0 ; row < graph->vertex ; row++){
        graph->matrix[row] = (int*)malloc(sizeof(int) * graph->vertex);
        for(int col = 0 ; col < graph->vertex ; col++){
            if(row==col){
                graph->matrix[row][col] = 0;
            }else{
                graph->matrix[row][col] = 1;
                graph->edge += 1;
            }
        }
    }
    
    return graph;
}

int DFS(GRAPH* graph, int u){
    nodes[u].visited = true;
    for(int v = 0; v < graph->vertex ; v++){
        if(graph->matrix[u][v] == 1 && nodes[v].visited == false)
            return nodes[u].number + DFS(graph, v);
    }
    return nodes[u].number;
}

void dfs(vector<int>numbers, int sum, int depth, int target){
    if(depth >= numbers.size()){
        if(sum == target) cnt++;
        return;
    }
    dfs(numbers, sum-numbers[depth], depth+1, target);
    dfs(numbers, sum+numbers[depth], depth+1, target);
}

int solution(vector<int> numbers, int target) {
    cnt = 0;
    dfs(numbers, numbers[0] * -1, 1, target);
    dfs(numbers, numbers[0] *  1, 1, target);
    return cnt;
}

/*
int solution(vector<int> numbers, int target) {
    int answer = 0;
    int sum = 0;
    GRAPH* graph = createTable(numbers);
    
    for(int idx = 0 ; idx < numbers.size() ; idx++)
        nodes.push_back(NODE{false, numbers[idx]});
    
    for(int idx = 0 ; idx < numbers.size() ; idx++){
        for(int n = 0 ; n < nodes.size() ; n++)
            nodes[n].visited = false;
        
        nodes[idx].number *= -1;
        sum = DFS(graph, idx);
        if (sum == target) answer+=1;
        nodes[idx].number *= -1;
    }
    
    return answer;
}*/

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> test {1, 1, 1, 1, 1};
    int target = 3;
    
    cout<<solution(test, target)<<endl;
    return 0;
}
