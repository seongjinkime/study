/*This program implement insert an data on array
  array is moved after inserting data
Written by : seongjin.kim
Date : 2019.09.08
*/

#include <iostream>
#include <stdlib.h>

#define SIZE 5
using namespace std;

void printArr(char* data);

int main(void){
    char data[SIZE] = {'a', 'b', 'd', 'e'};
    char c = 'c';
    char temp, next;
    
    printArr(data);
    printf("\n");
    int idx = 0;
    for( ; idx < SIZE ; idx++){
        if(data[idx] > c){
            temp = data[idx];
            data[idx] = c;
            break;
        }
    }
    
    
    idx += 1;
    
    for( ; idx < 5 ; idx++){
        next = data[idx]; //save to next roop
        data[idx] = temp; //assign saved data
        temp = next; //assign save to next roop
    }
    printArr(data);
    
}

void printArr(char* data){
    for (int i = 0 ; i < SIZE ; i++){
        printf("%C ", data[i]);
    }
}
