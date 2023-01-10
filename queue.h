//
//  queue.h
//  Ctructures
//
//  Created by Özgür Kamalı on 10.01.2023.
//



/*This header contains Queue object qnode object and their setters. Also Queue manipulation function provided*/

/*
 
 !!!!WARNING!!!!!  YOU MUST  DECIDE AND DECLARE QNODE MEMBERS  WITH MACRO DEFINITIONS BEFORE INCLUDING HEADER
 !!!!WARNING!!!!!    #define QNODE[X]TYPE [YOUR_TYPE_HERE]         DEFINES  STRUCTURES Xth' ELEMENT TYPE
 !!!!WARNING!!!!!    #define QNODE[X]NAME [YOUR_NAME_HERE]      DEFINES  STRUCTURES Xth' ELEMENT NAME
 
 
 */



#ifndef queue_h
#define queue_h



#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



struct q_node{
    
    // Defines queue node respect to QNODE[X]TYPE QNODE[X]NAME options. node index and links (pointers) also included
    
    int index;
    #if defined QNODE0TYPE && defined QNODE0NAME
    #define QNODE_PARAM0(x) ,QNODE0TYPE first
    QNODE0TYPE QNODE0NAME;
    #else
    #define QNODE_PARAM0(x)
    #endif
    
    #if defined QNODE1TYPE && defined QNODE1NAME
    #define QNODE_PARAM1(x) ,QNODE1TYPE second
    QNODE1TYPE QNODE1NAME;
    #else
    #define QNODE_PARAM1(x)
    #endif
    
#if defined QNODE2TYPE && defined QNODE2NAME
    #define QNODE_PARAM2(x) ,QNODE2TYPE third
    QNODE2TYPE QNODE2NAME;
    #else
    #define QNODE_PARAM2(x)
    #endif
    
#if defined QNODE3TYPE && defined QNODE3NAME
    #define QNODE_PARAM3(x) ,QNODE3TYPE fourth
    QNODE3TYPE QNODE3NAME;
    #else
    #define QNODE_PARAM3(x)
    #endif
    
#if defined QNODE4TYPE && defined QNODE4NAME
    #define QNODE_PARAM4(x) ,QNODE4TYPE fifth
    QNODE4TYPE QNODE4NAME;
    #else
    #define QNODE_PARAM4(x)
    #endif
    
    struct q_node *nextPtr;
};
typedef struct q_node qnode;



struct Queue{
   
    // Queue object definition
    
    int isEmpty;
    int count;
    qnode *head;
    qnode *tail;
};
typedef struct Queue Queue;





Queue* queueinit(void){
    
    // This functions initializes and return new Queue object
    
    Queue *hold = (Queue*)malloc(sizeof(Queue));
    
    if (hold != NULL){
        hold->isEmpty = 1;
        hold->tail = NULL;
        hold->head = NULL;
        hold->count = 0;
        return hold;
        
    }else{
        return NULL;
    }
    
}




int enqueue(Queue* queue QNODE_PARAM0(void) QNODE_PARAM1(void) QNODE_PARAM2(void) QNODE_PARAM3(void) QNODE_PARAM4(void)){
    
    //This functions add new nodes to tail of queue Also declaring  parameters and node members up to you. You can define your queue node any way
    
    qnode *tempNode = malloc(sizeof(qnode));
    if (tempNode != NULL){
    
    #if defined QNODE0TYPE && defined QNODE0NAME
        tempNode->QNODE0NAME = first;
    #endif

    #if defined QNODE1TYPE && defined QNODE1NAME
        tempNode->QNODE1NAME = second;
    #endif
        
    #if defined QNODE2TYPE && defined QNODE2NAME
        tempNode->QNODE2NAME = third;
    #endif
    
    #if defined QNODE3TYPE && defined QNODE3NAME
        tempNode->QNODE3NAME = fourth;
    #endif
        
    #if defined QNODE4TYPE && defined QNODE4NAME
        tempNode->QNODE4NAME = fifth;
    #endif
        
        if(queue->isEmpty == 1){
            tempNode->index = 0;
            tempNode->nextPtr = NULL;
            queue->isEmpty = 0;
            queue->count++;
            queue->head = tempNode;
            queue->tail = tempNode;
        }else{
            tempNode->index = queue->tail->index + 1;
            tempNode->nextPtr = NULL;
            queue->tail->nextPtr = tempNode;
            queue->tail = tempNode;
            queue->count++;
        
        }return 1;
    }else{
        return 0;
    }
}



qnode dequeue(Queue* queue){
    
    // This function dequeues node from the head of Queue. returns Copy of node and removes (deallocates from memory) it from queue
    
    assert(!queue->isEmpty);
    
    qnode head = *(queue->head);
    free(queue->head);
    
    queue->count--;
    if(queue->count == 0){
        queue->isEmpty = 1;
    }
    
    queue->head = head.nextPtr;
    qnode *indexPtr = head.nextPtr;
    int indexCount = 0;
    
    while (indexPtr != NULL) {
        indexPtr->index = indexCount;
        indexCount++;
        indexPtr = indexPtr->nextPtr;
    }
    return head;
}



void queuervrs(Queue *queue){
    
    //This function reverses Queue's nodes from head to tail
    
    assert(!queue->isEmpty);
   
    if(queue->count == 1){
        
        return;
        
    }else{
        
        qnode *newTail = queue->head;
        qnode *newHead = queue->tail;
        qnode *nextHolder = queue->head->nextPtr;
        qnode *backHolder = queue->head;
        queue->head->nextPtr = NULL;
        
        while (nextHolder != NULL) {
            qnode *newNext = nextHolder->nextPtr;
            nextHolder->nextPtr = backHolder;
            backHolder = nextHolder;
            nextHolder= newNext;
            
        }
        queue->head = newHead;
        queue->tail = newTail;
    }
    
    qnode *indexHolder = queue->head;
    int index = 0;
    
    while (indexHolder != NULL){
        indexHolder->index = index;
        index++;
        indexHolder = indexHolder->nextPtr;
    }
}



qnode *queueget(Queue *queue , int index){
    
    //This functions lets you get a object reference (pointer) to node in specified index;
    
    assert(index < queue->count);
    qnode *peeking = queue->head;
    while (peeking->index != index) {
        peeking = peeking->nextPtr;
    }
    
    return peeking;
}


qnode *queuepeek(Queue *queue, void *seeking){
    
    //This function return a object reference (pointer) to any type of value.
    // you should pass the address of the element you are looking for  and void pointer will be converted to correct type  while searhing for element.
    
    qnode *nextHolder = queue->head;
    while (nextHolder != NULL) {
    
#if defined QNODE0TYPE && defined QNODE0NAME
        QNODE0TYPE new_seeking0 =  *((QNODE0TYPE*) seeking);
        if (nextHolder->QNODE0NAME == new_seeking0){
            return nextHolder;
        }
    #endif


    #if defined QNODE1TYPE && defined QNODE1NAME
        QNODE1TYPE new_seeking1 =  *((QNODE1TYPE*) seeking);
        if (nextHolder->QNODE1NAME == new_seeking1){
        return nextHolder;
        }
    #endif
        
        
    #if defined QNODE2TYPE && defined QNODE2NAME
        QNODE2TYPE new_seeking2 =  *((QNODE2TYPE*) seeking);
        if (nextHolder->QNODE2NAME == new_seeking2){
            return nextHolder;
    }
    #endif

    #if defined QNODE3TYPE && defined QNODE3NAME
        QNODE3TYPE new_seeking3 =  *((QNODE3TYPE*) seeking);
        if (nextHolder->QNODE3NAME == new_seeking3){
            return nextHolder;
        }
    #endif
        
    #if defined QNODE4TYPE && defined QNODE4NAME
        QNODE4TYPE new_seeking4 =  *((QNODE4TYPE*) seeking);
        if (nextHolder->QNODE4NAME == new_seeking4){
            return nextHolder;
        }
    #endif

        
        nextHolder = nextHolder->nextPtr;
    }
    return NULL;
}





#endif /* queue_h */
