/*This program implements hash table 
Written by : seongjin.kim
Date : 2019.09.17
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX 100
#define OVERFLOW 3

typedef struct _NODE{
    int key[3];
    int count;
}NODE;

int buf[MAX];
NODE hash[MAX/2];

void init(void){
    for(int i = 0 ; i < MAX ; i++)
        buf[i] = -1;
    
    for(int i = 0 ; i < MAX/2 ; i++){
        hash[i].key[0] = hash[i].key[1] = hash[i].key[2] = -1;
        hash[i].count = 0;
    }
    return;
}

bool isNumExist(int num, NODE node){
    for(int i = 0 ; i < OVERFLOW ; i++)
        if(num == node.key[i]) return true;
    
    return false;
}

void makeRand(void){
    srand(time(NULL));
    int cnt, num;
    NODE node;
    
    cnt = 0;
    while(cnt < 50){
        num = rand()%MAX;
        node = hash[num%50];
        printf("%p ", &hash[num%50]);
        if (isNumExist(num, hash[num%50])) continue;
        if(hash[num%50].count > 2) continue;
        
        hash[num%50].key[node.count] = num;
        hash[num%50].count+=1;
        //printf("%2d %2d %p ", node.key[node.count-1], node.count, &node);
        buf[num] = num;
        cnt++;
        
    }
}

void printBuffer(void){
    for(int i = 0 ; i<MAX ; i++){
        if(i%10 == 0) printf("\n");
        printf("%2d ", buf[i]);
    }
    printf("\n");
}

void printHash(void){
    NODE node;
    for(int i = 0 ; i<MAX/2 ; i++){
        node = hash[i];
        if(i%5 == 0) printf("\n");
        switch (node.count) {
            case 0:
                printf("-1 ");
                break;
            case 1:
                printf("%2d ", node.key[0]);
                break;
            case 2:
                printf("%2d/%2d ", node.key[0], node.key[1]);
                break;
            case 3:
                printf("%2d/%2d/%2d ", node.key[0], node.key[1], node.key[2]);
                break;
            default:
                break;
        }
    }
    printf("\n");
}

int main(void){
    init();
    makeRand();
    printf("=======Buffer=======\n");
    printBuffer();
    printf("=======Hash=======\n");
    printHash();
}
