//
//  main.c
//  Ctructures
//
//  Created by Özgür Kamalı on 4.01.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>




#ifdef QNODE0TYPE
#undef QNODE0TYPE
#define QNODE0TYPE float
#else
#define QNODE0TYPE float
#endif

#ifdef QNODE0NAME
#undef QNODE0NAME
#define QNODE0NAME sort
#else
#define QNODE0NAME sort
#endif

#ifdef QNODE1TYPE
#undef QNODE1TYPE
#define QNODE1TYPE char*
#else
#define QNODE1TYPE char*
#endif

#ifdef QNODE1NAME
#undef QNODE1NAME
#define QNODE1NAME name
#else
#define QNODE1NAME name
#endif

#ifdef QNODE2NAME
#undef QNODE2NAME
#define QNODE2NAME sayi
#else
#define QNODE2NAME sayi
#endif

#ifdef QNODE2TYPE
#undef QNODE2TYPE
#define QNODE2TYPE int
#else
#define QNODE2TYPE int
#endif




#define SNODE0TYPE int
#define SNODE0NAME sayi
#define SNODE1TYPE char*
#define SNODE1NAME adi


#define LNODE0TYPE char*
#define LNODE0NAME ismi
#define LNODE1TYPE int
#define LNODE1NAME asal


















struct q_node{
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
    int isEmpty;
    int count;
    qnode *head;
    qnode *tail;
};
typedef struct Queue Queue;


Queue* queueinit(void){
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
        
        }
        return 1;
    }else{
        return 0;
    }
}

qnode dequeue(Queue* queue){
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
    assert(index < queue->count);
    qnode *peeking = queue->head;
    while (peeking->index != index) {
        peeking = peeking->nextPtr;
    }
    return peeking;
}

qnode *queuepeek(Queue *queue, void *seeking){
    
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





















struct s_node{
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
    int isEmpty;
    int count;
    snode *top;
};
typedef struct stack Stack;


Stack* stackinit(void){
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
    assert(index < stack->count);
    snode *peeking = stack->top;
    while (peeking->index != index) {
        peeking = peeking->nextPtr;
    }
    return peeking;
}



snode *stackpeek(Stack *stack, void *seeking){
    
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










struct l_node{
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
    #define QNODE_PARAM3(x) ,LNODE3TYPE fourth
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
    int count;
    int isEmpty;
    lnode *root;
};
typedef struct List List;

List* listinit(void){
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
    assert(index < list->count);
    lnode *peeking = list->root;
    while (peeking->index != index) {
        peeking = peeking->nextPtr;
    }
    return peeking;
}

lnode listremove(List *list , int index){
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
    lnode *placetoextend = base->root;
    lnode *next = base->root;
    while (next != NULL) {
        placetoextend = next;
        next = next->nextPtr;
    }
    placetoextend->nextPtr = extender->root;
    base->count = base->count + extender->count;
}

int main(void){

    Queue *number1 = queueinit();
    enqueue(number1,100 , "fist" , 10);
    enqueue(number1 , 50,"second" , 20);
    enqueue(number1 ,60,"third", 30);
    enqueue(number1, 30, "ozgur xx ya", 40);
    enqueue(number1, 31.31, "trying if functions works", 50);
    dequeue(number1);
    queuervrs(number1);
    queueget(number1, 2);
    char *str = "ozgur xx ya";
    qnode *looking = queuepeek(number1, &str);
    printf("%s\n" , number1->head->nextPtr->name);
    printf("%d\n", looking->index);
    
    
    
    
    
    
    
    Stack *first_stack = stackinit();
    push(first_stack, 31, "added");
    push(first_stack, 62, "this will be top");
    push(first_stack, 93, "new top");
    push(first_stack, 123, "cant belive that done this");
    stackrvrs(first_stack);
    printf("%s" , first_stack->top->adi);
    

    List *firstlist = listinit();
    append(firstlist, "adı" , 1000);
    append(firstlist, "iki", 231);
    append(firstlist, "üç", 4435);
    append(firstlist, "dört", 5345);
    printf("%d\n" ,firstlist->root->index);
    
    
    List *secondList = listinit();
    append(secondList, "2nd list", 2);
    append(secondList, "2nd 2nd", 3);
    listextend(firstlist, secondList);
    
    printf("%d\n" , firstlist->count);
    printf("%s" , firstlist->root->nextPtr->nextPtr->nextPtr->nextPtr->nextPtr->ismi);
}
