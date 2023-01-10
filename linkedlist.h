//
//  linkedlist.h
//  Ctructures
//
//  Created by Özgür Kamalı on 10.01.2023.
//

//This header contains Linked List object called List ,  linked list node object called lnode and their setters. Also Linked list manipulation function provided

/*
 
 !!!!WARNING!!!!!    YOU MUST  DECIDE AND DECLARE QNODE MEMBERS  WITH MACRO DEFINITIONS BEFORE INCLUDING HEADER         !!!!WARNING!!!!!
 !!!!WARNING!!!!!    #define LNODE[X]TYPE [YOUR_TYPE_HERE]         DEFINES  STRUCTURES Xth' ELEMENT TYPE                !!!!WARNING!!!!!
 !!!!WARNING!!!!!    #define LNODE[X]NAME [YOUR_NAME_HERE]      DEFINES  STRUCTURES Xth' ELEMENT NAME                   !!!!WARNING!!!!!
 
 
 */


#ifndef linkedlist_h
#define linkedlist_h



#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



struct l_node{
    
    // Defines queue node respect to LNODE[X]TYPE LNODE[X]NAME options. node index and links (pointers) also included

    int index;
    #if defined LNODE0TYPE && defined LNODE0NAME
    #define LNODE_PARAM0(x) ,LNODE0TYPE first
    LNODE0TYPE LNODE0NAME;
    #else
    #define LNODE_PARAM0(x)
    #endif
    
    #if defined LNODE1TYPE && defined LNODE1NAME
    #define LNODE_PARAM1(x) ,LNODE1TYPE second
    LNODE1TYPE LNODE1NAME;
    #else
    #define LNODE_PARAM1(x)
    #endif
    
    #if defined LNODE2TYPE && defined LNODE2NAME
    #define LNODE_PARAM2(x) ,LNODE2TYPE third
    LNODE2TYPE LNODE2NAME;
    #else
    #define LNODE_PARAM2(x)
    #endif
    
    #if defined LNODE3TYPE && defined LNODE3NAME
    #define LNODE_PARAM3(x) ,LNODE3TYPE fourth
    LNODE3TYPE LNODE3NAME;
    #else
    #define LNODE_PARAM3(x)
    #endif
    
    #if defined LNODE4TYPE && defined LNODE4NAME
    #define LNODE_PARAM4(x) ,LNODE4TYPE fifth
    LNODE4TYPE LNODE4NAME;
    #else
    #define LNODE_PARAM4(x)
    #endif
    
    struct l_node *nextPtr;
};
typedef struct l_node lnode;




struct List{
    
    // List object definition
    
    int count;
    int isEmpty;
    lnode *root;
};
typedef struct List List;



List* listinit(void){
    
    // This functions initializes and return new Queue object
    
    List *hold = (List*)malloc(sizeof(List));
    if (hold != NULL){
        hold->isEmpty = 1;
        hold->root = NULL;
        hold->count = 0;
        return hold;
        
    }else{
        return NULL;
    }
}



int append(List* list LNODE_PARAM0(void) LNODE_PARAM1(void) LNODE_PARAM2(void) LNODE_PARAM3(void) LNODE_PARAM4(void)){
    
    //This functions add new nodes to end of List Also declaring  parameters and node members up to you. You can define your list node anyway
    
    lnode *tempNode = malloc(sizeof(lnode));
    if (tempNode != NULL){
    
    #if defined LNODE0TYPE && defined LNODE0NAME
        tempNode->LNODE0NAME = first;
    #endif

    #if defined LNODE1TYPE && defined LNODE1NAME
        tempNode->LNODE1NAME = second;
    #endif
        
    #if defined LNODE2TYPE && defined LNODE2NAME
        tempNode->LNODE2NAME = third;
    #endif
    
    #if defined LNODE3TYPE && defined LNODE3NAME
        tempNode->LNODE3NAME = fourth;
    #endif
        
    #if defined LNODE4TYPE && defined LNODE4NAME
        tempNode->LNODE4NAME = fifth;
    #endif
        
        if(list->isEmpty == 1){
            tempNode->index = 0;
            tempNode->nextPtr = NULL;
            list->isEmpty = 0;
            list->count++;
            list->root = tempNode;
        }else{
            tempNode->index = list->count;
            tempNode->nextPtr = NULL;
            lnode *placefinder = NULL;
            lnode *nextfinder = list->root;
            while (nextfinder != NULL) {
                placefinder =  nextfinder;
                nextfinder = nextfinder->nextPtr;
            }
            placefinder->nextPtr = tempNode;
            list->count++;
        }
        return 1;
    }else{
        return 0;
    }
}



int insert(List *list , int index LNODE_PARAM0(void) LNODE_PARAM1(void) LNODE_PARAM2(void) LNODE_PARAM3(void) LNODE_PARAM4(void)){
    
    //This functions add new nodes to the specified position specified by index
    // Also declaring  parameters and node members up to you. You can define your list node anyway
    //Assertion raised if you attempt to add node index less than zero or position that greater than List count
    
    assert(index>= 0 && index <= list->count);
    
    lnode *tempNode = malloc(sizeof(lnode));
    if (tempNode != NULL){
        
    #if defined LNODE0TYPE && defined LNODE0NAME
        tempNode->LNODE0NAME = first;
    #endif
        
    #if defined LNODE1TYPE && defined LNODE1NAME
        tempNode->LNODE1NAME = second;
    #endif
    
    #if defined LNODE2TYPE && defined LNODE2NAME
        tempNode->LNODE2NAME = third;
    #endif

    #if defined LNODE3TYPE && defined LNODE3NAME
        tempNode->LNODE3NAME = fourth;
    #endif
    
    #if defined LNODE4TYPE && defined LNODE4NAME
        tempNode->LNODE4NAME = fifth;
    #endif
        
        tempNode->index = index;
        tempNode->nextPtr = NULL;
        
        if(list->count == 0){
            
            list->root = tempNode;
            list->isEmpty = 0;
            
        }else if(list->count == index){
            
            lnode *holdback = NULL;
            lnode *holdnext = list->root;
            
            while (holdnext != NULL) {
                holdback = holdnext;
                holdnext = holdnext->nextPtr;
            }
            holdback->nextPtr = tempNode;
            
        }else if(index == 0){
            lnode *next = list->root;
            list->root = tempNode;
            tempNode->nextPtr = next;
            lnode *holdnext = tempNode->nextPtr;
            int index_holder = 1;
            
            while(holdnext != NULL){
                holdnext->index = index_holder;
                index_holder++;
                holdnext = holdnext->nextPtr;
            }
            
        }else{
            lnode *holdback = NULL;
            lnode *holdnext = list->root;
            
            while(holdnext->index != index){
                holdback = holdnext;
                holdnext = holdnext->nextPtr;
            }
            
            tempNode->nextPtr = holdnext;
            holdback->nextPtr = tempNode;
            
            while(holdnext != NULL){
                holdnext->index++;
                holdnext = holdnext->nextPtr;
            }
        }
        list->count++;
        return 1;
    }else{
        return 0;
    }
}



lnode *listpeek(List *list, void *seeking){
    
    //This function return a object reference (pointer) to any type of value.
    // you should pass the address of the element you are looking for  and void pointer will be converted to correct type  while searhing for element.
    
    lnode *nextHolder = list->root;
    while (nextHolder != NULL) {
    
#if defined LNODE0TYPE && defined LNODE0NAME
        LNODE0TYPE new_seeking0 =  *((LNODE0TYPE*) seeking);
        if (nextHolder->LNODE0NAME == new_seeking0){
            return nextHolder;
        }
    #endif
    
    #if defined LNODE1TYPE && defined LNODE1NAME
        LNODE1TYPE new_seeking1 =  *((LNODE1TYPE*) seeking);
        if (nextHolder->LNODE1NAME == new_seeking1){
        return nextHolder;
        }
    #endif
        
        
    #if defined LNODE2TYPE && defined LNODE2NAME
        LNODE2TYPE new_seeking2 =  *((SLNODE2TYPE*) seeking);
        if (nextHolder->LNODE2NAME == new_seeking2){
            return nextHolder;
    }
    #endif

    #if defined LNODE3TYPE && defined LNODE3NAME
        LNODE3TYPE new_seeking3 =  *((LNODE3TYPE*) seeking);
        if (nextHolder->LNODE3NAME == new_seeking3){
            return nextHolder;
        }
    #endif
        
    #if defined LNODE4TYPE && defined LNODE4NAME
        LNODE4TYPE new_seeking4 =  *((LNODE4TYPE*) seeking);
        if (nextHolder->LNODE4NAME == new_seeking4){
            return nextHolder;
        }
    #endif

        
        nextHolder = nextHolder->nextPtr;
    }
    return NULL;
}



lnode *listget(List *list , int index){
    
    //This functions lets you get a object reference (pointer) to Linked List in specified index
    //assertion raised if you attempt you index out of linked list's bound

    assert(index < list->count);
    lnode *peeking = list->root;
    while (peeking->index != index) {
        peeking = peeking->nextPtr;
    }
    return peeking;
}




lnode listremove(List *list , int index){
    
    //Removes the specified  indexed node from from Linked list
    //assertion raised if you attempt you index out of linked list's bound
    
    assert(index>= 0 && index < list->count);
    lnode removed;
 
    lnode *indexCorrector;
    if(index == 0 ){
        lnode *temp = (*list).root;
        list->root = temp->nextPtr;
        removed = *(temp);
        free(temp);
        indexCorrector = list->root;
        
    }else if(index + 1 == list->count){
        lnode *backholder = NULL;
        lnode *currentholder = list->root;
        
        while (currentholder->index != index) {
            backholder = currentholder;
            currentholder = currentholder->nextPtr;
        }
        
        backholder->nextPtr = NULL;
        lnode *temp = currentholder;
        removed = *(temp);
        free(temp);
        indexCorrector = NULL;
    }
    else{
        lnode *backindex = list->root;
        lnode *current = list->root;
        
        while(current->index != index){
            backindex = current;
            current = current->nextPtr;
        }
        
        lnode *temp = current;
        removed = *(temp);
        free(temp);
        backindex->nextPtr = removed.nextPtr;
        indexCorrector = removed.nextPtr;
        }
    
    while (indexCorrector != NULL) {
        indexCorrector->index--;
        indexCorrector = indexCorrector->nextPtr;
    }
    
    list->count--;
    if (list->count == 0){
        list->isEmpty = 1;
    }
    return removed;
}


void listrvrs(List *list){
    
    //This function reverses Linked List's nodes from start to end
    //assertion raised if list is empty
    
    assert(!list->isEmpty);
    if(list->count == 1){
        return;
    }else{
        lnode *newRoot = NULL;
        lnode *backHolder = list->root;
        lnode *nextHolder = list->root->nextPtr;
        list->root->nextPtr = NULL;
        
        while (nextHolder != NULL) {
            lnode *newNext = nextHolder->nextPtr;
            nextHolder->nextPtr = backHolder;
            backHolder = nextHolder;
            nextHolder= newNext;
            newRoot = backHolder;
        }
        list->root = newRoot;
    }
    lnode *indexHolder = list->root;
    int index = 0;
    
    while (indexHolder != NULL){
        indexHolder->index = index;
        index++;
        indexHolder = indexHolder->nextPtr;
    }
}



void listextend(List *base , List *extender){
    
    // extends base class with extender list
    
    lnode *placetoextend = base->root;
    lnode *next = base->root;
    while (next != NULL) {
        placetoextend = next;
        next = next->nextPtr;
    }
    placetoextend->nextPtr = extender->root;
    base->count = base->count + extender->count;
}


#endif /* linkedlist_h */
