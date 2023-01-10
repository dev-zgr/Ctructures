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
    printf("queues first nodes index is %d and element of node is \" %s\"\n\n" , its_first_queue->head->index, its_first_queue->head->name);
    
    push(its_first_stack, 10);
    printf("stacks first nodes index is %d and element of node is \"%d\" \n\n" , its_first_stack->top->index,its_first_stack->top->number);
    
    append(its_first_list, "im lists first element");
    printf("List first nodes index is %d and element of node  first node is \" %s\" \n " , its_first_list->root->index,its_first_list->root->text);
    
    insert(its_first_list, 0, "im going to be first node");
    printf("List first nodes index is %d and element of node  first node is \" %s \" \n \n" , its_first_list->root->index,its_first_list->root->nextPtr->text);

    
    qnode dequeued = dequeue(its_first_queue);
    printf("element with index %d removed and it was consisting \" %s \" \n" , dequeued.index , dequeued.name);
    printf("Queue count is now \"%d\" \n\n" , its_first_queue->count);
    
    snode popped = pop(its_first_stack);
    printf("element with index %d removed and it was consisting \" %d \" \n" , popped.index , popped.number);
    printf("Stack count is now \"%d\" \n\n" , its_first_stack->count);
    
    lnode removed = listremove(its_first_list, 1);
    printf("element with index %d removed and it was contaning \"%s\"\n\n" , removed.index, removed.text);
    printf("list count is now \"%d\" \n\n",its_first_list->count);
    
    
    Queue *queue_to_reverse = queueinit();
    enqueue(queue_to_reverse, "im first element");
    enqueue(queue_to_reverse, "im second element");
    printf("queue_to_revers's first element is: \"%s\" second element:\" %s\"\n" , queue_to_reverse->head->name , queue_to_reverse->head->nextPtr->name);
    queuervrs(queue_to_reverse);
    printf("queue_to_revers's first element is now : \"%s\" second element is now:\" %s\"\n" , queue_to_reverse->head->name , queue_to_reverse->head->nextPtr->name);
    
    
    Stack *stack_to_reverse = stackinit();
    List *list_to_reverse = listinit();


}
