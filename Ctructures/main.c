//
//  main.c
//  Ctructures
//
//  Created by Özgür Kamalı on 4.01.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#define QNODE0TYPE char*
#define QNODE0NAME name
#define LNODE3TYPE char*
#define LNODE3NAME text
#define SNODE3TYPE int
#define SNODE3NAME number

#include "queue.h"
#include "stack.h"
#include "linkedlist.h"


int main(void){

    Queue *its_first_queue = queueinit();
    Stack *its_first_stack = stackinit();
    List *its_first_list = listinit();
    
    enqueue(its_first_queue, "hello im added");
    printf("queues first nodes index is %d and element of node is \" %s\"\n" , its_first_queue->head->index, its_first_queue->head->name);
    
    push(its_first_stack, 10);
    printf("stacks first nodes index is %d and element of node is \"%d\" \n" , its_first_stack->top->index,its_first_stack->top->number);
    
    append(its_first_list, "im lists first element");
    printf("List first nodes index is %d and element of node  first node is \" %s\" \n " , its_first_list->root->index,its_first_list->root->text);
    
    insert(its_first_list, 0, "im going to be first node");
    printf("List first nodes index is %d and element of node  first node is \" %s \" \n " , its_first_list->root->index,its_first_list->root->nextPtr->text);

    

}
