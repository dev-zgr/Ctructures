
Cstructures Documentation:

1. Quick Start Quide



1.  Quick Start Guide: 

Before including headers you should define qnodes ,snodes and lnodes members with macro functions because every function and node created respect to your settings.

Quick definition Guide:

for defining a string called name in Queue nodes you can use following syntax before including header.
maximum of 5 arbitrary members can be included to these nodes. most node setters named with QNODE[ node_number ]TYPE or  QNODE[ node_number ]NAME


#define QNODE0TYPE char*
#define QNODE0NAME name
Sets  member for Queue nodes.


#define SNODE3TYPE int
#define SNODE3NAME number
Sets  member for Stacks nodes.



#define LNODE3TYPE char*
#define LNODE3NAME text
Sets  member for List nodes.


Now you are ready for including headers: 

#include "queue.h"
#include "stack.h"
#include "linkedlist.h"



after setting structures node member you can simply initalize a Queue, Stack or List object. 
Warn that queueinit() function returns pointer to Queue :

Queue *its_first_queue = queueinit();
Stack *its_first_stack = stackinit();
List *its_first_list = listinit();



after initialize your you can add  new nodes to these objects:



    enqueue(its_first_queue, "hello im added");
    printf("queues first nodes index is %d and element of node is \" %s\"\n" , its_first_queue->head->index, its_first_queue->head->name);

Enqueue functions adds new to to queue respect to queue datastructure's rules. also you can access queues elements by [QUEUENAME]->head->[YOUR VARIABLE NAME]
Also each qnode elements contains nextPtr so you can traverse around each individual node with [QUEUENAME]->head->nextPtr->[YOUR VARIABLE NAME]
Each nodes contains index number also using them may be useful for your code.

    
    push(its_first_stack, 10);
    printf("stacks first nodes index is %d and element of node is \"%d\" \n" , its_first_stack->top->index,its_first_stack->top->number);
    

push functions adds new to to stack respect to stack datastructure's rules. also you can access queues elements by [STACKNAME]->top->[YOUR VARIABLE NAME]
Also each snode elements contains nextPtr so you can traverse around each individual node with [STACKNAME]->top->nextPtr->[YOUR VARIABLE NAME]
Each nodes contains index number also using them may be useful for your code.


    append(its_first_list, "im lists first element");
    printf("List first nodes index is %d and element of node  first node is \" %s\" \n " , its_first_list->root->index,its_first_list->root->text);
    
    insert(its_first_list, 0, "im going to be first node");
    printf("List first nodes index is %d and element of node  first node is \" %s \" \n " , its_first_list->root->index,its_first_list->root->text);


There is two options for adding elements to list append functions adds node to end of function.  insert functions adds index to specified position. also you can access List elements by [LISTNAME]->root->[YOUR VARIABLE NAME]
Also each lnode elements contains nextPtr so you can traverse around each individual node with [LISTNAME]->root->nextPtr->[YOUR VARIABLE NAME]
Each nodes contains index number also using them may be useful for your code.

Also these element adding functions return True if element added to structure successfully else it return "False".


Also there is node removing function for every data strucuture:


    qnode dequeued = dequeue(its_first_queue);
    printf("element with index %d removed and it was consisting \" %s \" \n" , dequeued.index , dequeued.name);
    printf("Queue count is now \"%d\" \n\n" , its_first_queue->count);


dequeue function takes and input as pointer to Queue object and removes qnode object and returns this removed object. Removing performed respect to queue (LIFO) rules. also its deallocates node from memory so you don't have to worry about memory issues.


    snode popped = pop(its_first_stack);
    printf("element with index %d removed and it was consisting \" %d \" \n" , popped.index , popped.number);
    printf("Stack count is now \"%d\" \n\n" , its_first_stack->count);


pop function function removes and returns a node from Stack object. removing performed respect to Stack rules (FIFO). pop function returns a copy of removed node as snode object and deallocates actual object from memory.


    lnode removed = listremove(its_first_list, 1);
    printf("element with index %d removed and it was contaning \"%s\"\n" , removed.index, removed.text);
    printf("list count is now \"%d\" \n\n",its_first_list->count);


listremove function removes a node from linked list. you should pass pointer to list that you would like to manipulate. Also listremove function has extra ability that allows you to remove any list node specified with index. listremove function returns a copy of removed lnode object and deallocates actual node from memory.
    

Reverse functions are built for every data List's Stacks and Queues: 

   
	Queue *queue_to_reverse = queueinit();
    enqueue(queue_to_reverse, "im first element");
    enqueue(queue_to_reverse, "im second element");
    printf("queue_to_revers's first element is: \"%s\" second element:\" %s\"\n" , queue_to_reverse->head->name , queue_to_reverse->head->nextPtr->name);
    queuervrs(queue_to_reverse);
   printf("queue_to_revers's first element is now : \"%s\" second element is now:\" %s\"\n" , queue_to_reverse->head->name , queue_to_reverse->head->nextPtr->name);

queuervrs(Queue*) function takes parameter as pointer to queue to reverse and doesnt return anything after reversing queue.

	
	Stack *stack_to_reverse = stackinit();
    push(stack_to_reverse, 1);
    push(stack_to_reverse, 2);
    printf("stack_to_reverse's top element is: \"%d\" bottom element:\" %d\"\n" , stack_to_reverse->top->number , stack_to_reverse->top->nextPtr->number);
    stackrvrs(stack_to_reverse);
    printf("stack_to_reverse's top element is now: \"%d\" bottom element is now :\" %d\"\n\n" , stack_to_reverse->top->number , stack_to_reverse->top->nextPtr->number);


stackrvrs(Stack*) function takes parameter as pointer to Stack to reverse and doesnt return anything after reversing stack. 




as we mentioned before  all functions and nodes formed respect to your setting so enqueue functions parameters list formed with our settings #define QNODE0TYPE char* #define QNODE0NAME name. 
and warn that their position are formed with node setters number


Queue object serves  you many attributes few of them is:

its_first_queue--->count : 				Returns node count of queue
its_first_queue--->isEmpty : 			returns True if queue is not empty, False if its empty
its_first_queue--->head : 				Returns head of of queue
its_first_queue--->head--->nextPtr		May be used to traverse arround queues Nodes.
