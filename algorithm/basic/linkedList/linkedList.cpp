/*This program implement linked list
 Written by : seongjin.kim
 Date : 2019.09.08
 */

#include<iostream>
#include <stdlib.h>
#include <stdbool.h>


using namespace std;

typedef struct node{
    char data;
    struct node* next;
}NODE;

//Function Declaraions
void appendNode(NODE* head, NODE* tail, int data);
void insertNode(NODE* head, NODE* tail, int data);
void printNodes(NODE* head, NODE* tail);
void deleteNode(NODE* head, NODE* tail, int target);

int main(void){
    NODE* head = (NODE*)malloc(sizeof(NODE));
    NODE* tail = (NODE*)malloc(sizeof(NODE));
    head->next = tail;
    tail->next = NULL;
    
    insertNode(head, tail, 3);
    insertNode(head, tail, 5);
    insertNode(head, tail, 4);
    insertNode(head, tail, 2);
    
    deleteNode(head, tail,5);
    
    printNodes(head, tail);
    printf("\n");
    
    return 0;
}


void insertNode(NODE* head, NODE* tail, int data){
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    
    if(!newNode){
        printf("Out of memory!, exit with error 101");
        exit(101);
    }
    newNode->data = data;
    
    NODE* walker = head;
    
    while(walker->next != tail){
        if(walker->next->data > data ){
            break;
        }
        walker = walker->next;
    }
    
    newNode->next = walker->next;
    walker->next = newNode;
    
    return;
}



void deleteNode(NODE* head, NODE* tail, int target){
    NODE* walker = head->next;
    NODE* toDel = NULL;
    
    while(walker -> next !=tail){
        if(walker->next->data == target){
            toDel = walker->next;
            break;
        }
        walker = walker->next;
    }//to remain walker insatance
    
    if (!toDel){
        printf("NOT found node error\n");
        return;
    }
    
    walker->next = toDel->next;
    free(toDel);
    return;
}


void printNodes(NODE* head, NODE* tail){
    NODE* walker = head->next;
    
    printf("Linked List: ");
    while(walker != tail){
        printf("%d ", walker->data);
        walker = walker->next;
    }
    
    return;
}
