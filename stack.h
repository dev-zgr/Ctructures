//
//  stack.h
//  Ctructures
//
//  Created by Özgür Kamalı on 10.01.2023.
//

//This header contains Stack object qnode object and their setters. Also Stack manipulation function provided

/*
 
 !!!!WARNING!!!!!    YOU MUST  DECIDE AND DECLARE QNODE MEMBERS  WITH MACRO DEFINITIONS BEFORE INCLUDING HEADER           !!!!WARNING!!!!!
 !!!!WARNING!!!!!    #define SNODE[X]TYPE [YOUR_TYPE_HERE]         DEFINES  STRUCTURES Xth' ELEMENT TYPE                !!!!WARNING!!!!!
 !!!!WARNING!!!!!    #define SNODE[X]NAME [YOUR_NAME_HERE]      DEFINES  STRUCTURES Xth' ELEMENT NAME                   !!!!WARNING!!!!!
 
 
 */



#ifndef stack_h
#define stack_h


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



struct s_node{
    
    // Defines stack node respect to SNODE[X]TYPE SNODE[X]NAME options. node index and links (pointers) also included

    int index;
    #if defined SNODE0TYPE && defined SNODE0NAME
    #define SNODE_PARAM0(x) ,SNODE0TYPE first
    SNODE0TYPE SNODE0NAME;
    #else
    #define SNODE_PARAM0(x)
    #endif
    
    #if defined SNODE1TYPE && defined SNODE1NAME
    #define SNODE_PARAM1(x) ,SNODE1TYPE second
    SNODE1TYPE SNODE1NAME;
    #else
    #define SNODE_PARAM1(x)
    #endif
    
    #if defined SNODE2TYPE && defined SNODE2NAME
    #define SNODE_PARAM2(x) ,SNODE2TYPE third
    SNODE2TYPE SNODE2NAME;
    #else
    #define SNODE_PARAM2(x)
    #endif
    
    #if defined SNODE3TYPE && defined SNODE3NAME
    #define SNODE_PARAM3(x) ,SNODE3TYPE fourth
    SNODE3TYPE SNODE3NAME;
    #else
    #define SNODE_PARAM3(x)
    #endif
    
    #if defined SNODE4TYPE && defined SNODE4NAME
    #define SNODE_PARAM4(x) ,SNODE4TYPE fifth
    SNODE4TYPE SNODE4NAME;
    #else
    #define SNODE_PARAM4(x)
    #endif
    
    struct s_node *nextPtr;
};
typedef struct s_node snode;



struct stack{
    
    // Stack object definition
    
    int isEmpty;
    int count;
    snode *top;
};
typedef struct stack Stack;



Stack* stackinit(void){
    
    // This functions initializes and return new Queue object
    
    Stack *hold = (Stack*)malloc(sizeof(Stack));
    if (hold != NULL){
        hold->isEmpty = 1;
        hold->top = NULL;
        hold->count = 0;
        return hold;
        
    }else{
        return NULL;
    }
}



int push(Stack* stack SNODE_PARAM0(void) SNODE_PARAM1(void) SNODE_PARAM2(void) SNODE_PARAM3(void) SNODE_PARAM4(void)){
    
    //This functions add new nodes to top of Stack. Also declaring  parameters and node members up to you. You can define your Stack node any way
    
    snode *tempNode = malloc(sizeof(snode));
    if (tempNode != NULL){
    
    #if defined SNODE0TYPE && defined SNODE0NAME
        tempNode->SNODE0NAME = first;
    #endif

    #if defined SNODE1TYPE && defined SNODE1NAME
        tempNode->SNODE1NAME = second;
    #endif
        
    #if defined SNODE2TYPE && defined SNODE2NAME
        tempNode->SNODE2NAME = third;
    #endif
    
    #if defined SNODE3TYPE && defined SNODE3NAME
        tempNode->SNODE3NAME = fourth;
    #endif
        
    #if defined SNODE4TYPE && defined SNODE4NAME
        tempNode->SNODE4NAME = fifth;
    #endif
        
        if(stack->isEmpty == 1){
            tempNode->index = 0;
            tempNode->nextPtr = NULL;
            stack->isEmpty = 0;
            stack->count++;
            stack->top = tempNode;
        }else{
            tempNode->index = 0;
            tempNode->nextPtr = stack->top;
            stack->top = tempNode;
            stack->count++;
            snode *holdNext = stack->top->nextPtr;
            while (holdNext != NULL) {
                holdNext->index++;
                holdNext = holdNext->nextPtr;
            }
        }
        return 1;
    }else{
        return 0;
    }
}



snode pop(Stack* stack){
    
    // This function pops node from the top of Stacks. returns Copy of node and removes (deallocates from memory) it from Stack
    
    assert(!stack->isEmpty);
    
    snode top = *(stack->top);
    free(stack->top);
    
    stack->count--;
    if(stack->count == 0){
        stack->isEmpty = 1;
    }
    
    stack->top = top.nextPtr;
    snode *indexPtr = top.nextPtr;
    int indexCount = 0;
    
    while (indexPtr != NULL) {
        indexPtr->index = indexCount;
        indexCount++;
        indexPtr = indexPtr->nextPtr;
    }
    return top;
}



void stackrvrs(Stack *stack){
    
    //This function reverses Queue's nodes from top to bottom
    
    assert(!stack->isEmpty);
    if(stack->count == 1){
        return;
    }else{
        snode *newTop = NULL;
        snode *nextHolder = stack->top->nextPtr;
        snode *backHolder = stack->top;
        stack->top->nextPtr = NULL;
        while (nextHolder != NULL) {
            snode *newNext = nextHolder->nextPtr;
            nextHolder->nextPtr = backHolder;
            backHolder = nextHolder;
            nextHolder= newNext;
            newTop = backHolder;
        }
        stack->top = newTop;
    }
    
    snode *indexHolder = stack->top;
    int index = 0;
    while (indexHolder != NULL){
        indexHolder->index = index;
        index++;
        indexHolder = indexHolder->nextPtr;
    }
}



snode *stackget(Stack *stack , int index){
    
    //This functions lets you get a object reference (pointer) to node in specified index;
    
    assert(index < stack->count);
    snode *peeking = stack->top;
    while (peeking->index != index) {
        peeking = peeking->nextPtr;
    }
    return peeking;
}



snode *stackpeek(Stack *stack, void *seeking){
    
    /*This function return a object reference (pointer) to any type of value. you should pass the address of the element you are looking for  and void pointer will be converted to correct type  while searhing for element */
    
    snode *nextHolder = stack->top;
    while (nextHolder != NULL) {
    

    #if defined SNODE0TYPE && defined SNODE0NAME
        SNODE0TYPE new_seeking0 =  *((SNODE0TYPE*) seeking);
        if (nextHolder->SNODE0NAME == new_seeking0){
            return nextHolder;
        }
    #endif

    #if defined SNODE1TYPE && defined SNODE1NAME
        SNODE1TYPE new_seeking1 =  *((SNODE1TYPE*) seeking);
        if (nextHolder->SNODE1NAME == new_seeking1){
        return nextHolder;
        }
    #endif
        
        #if defined SNODE2TYPE && defined SNODE2NAME
        SNODE2TYPE new_seeking2 =  *((SNODE2TYPE*) seeking);
        if (nextHolder->SNODE2NAME == new_seeking2){
            return nextHolder;
    }
    #endif

    #if defined SNODE3TYPE && defined SNODE3NAME
        SNODE3TYPE new_seeking3 =  *((SNODE3TYPE*) seeking);
        if (nextHolder->SNODE3NAME == new_seeking3){
            return nextHolder;
        }
    #endif
        
    #if defined SNODE4TYPE && defined SNODE4NAME
        SNODE4TYPE new_seeking4 =  *((SNODE4TYPE*) seeking);
        if (nextHolder->SNODE4NAME == new_seeking4){
            return nextHolder;
        }
    #endif

        
        nextHolder = nextHolder->nextPtr;
    }
    return NULL;
}



#endif /* stack_h */
