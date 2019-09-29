/*This program implements undirect graph using adjacency matrix
Written by : seongjin.kim
Date : 2019.09.18
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct _GRAPH{
    int vertex;
    int edge;
    int** matrix;
}GRAPH;

int* visited;

void printTable(GRAPH* graph){
    for(int cnt = 0 ; cnt < graph->vertex * graph->vertex ; cnt++){
        if(cnt%graph->vertex == 0)printf("\n");
        printf("%2d ", graph->matrix[cnt/graph->vertex][cnt%graph->vertex]);
    }
}

void insertEdge(GRAPH* graph, int u, int v){
    graph->matrix[u][v] = 1;
    graph->matrix[v][u] = 1;
}

GRAPH* createGraph(){
    GRAPH* graph = (GRAPH*)malloc(sizeof(GRAPH));
    if(!graph) exit(-101);
    
    graph->vertex = 4;
    graph->edge = 4;
    
    //memory allocation
    graph->matrix = (int**)malloc(sizeof(int*) * graph->vertex);
    for(int row = 0 ; row < graph->vertex ; row++){
        graph->matrix[row] = (int*)malloc(sizeof(int) * graph->vertex);
    }
    
    //assign false value for all
    for(int cnt = 0 ; cnt < graph->vertex * graph->vertex ; cnt++)
        graph->matrix[cnt/graph->vertex][cnt%graph->vertex] = 0;
    
    insertEdge(graph, 0, 1);
    insertEdge(graph, 0, 2);
    insertEdge(graph, 2, 1);
    insertEdge(graph, 2, 3);
    
    return graph;
}

void DFS(GRAPH* graph, int u){
    visited[u] = 1;
    printf("%3d ",  u);
    
    for(int v = 0 ; v<graph->vertex ; v++){
        if(graph->matrix[u][v] == 1 && !visited[v]){
            DFS(graph, v);
        }
    }
}

void DFSTraverse(GRAPH* graph){
    visited = (int*)malloc(sizeof(int)* graph->vertex);
    for(int i = 0 ; i<graph->vertex ; i++){
        visited[i] = 0;
    }
    DFS(graph, 2);
}

int main(void){
    GRAPH* graph = createGraph();
    DFSTraverse(graph);
    cout<<endl;
}

