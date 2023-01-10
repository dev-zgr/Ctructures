# Ctructures
This git abstract you from general data structures like Queue , Stacks , Linked list.


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




as we mentioned before  all functions and nodes formed respect to your setting so enqueue functions parameters list formed with our settings #define QNODE0TYPE char* #define QNODE0NAME name. 
and warn that their position are formed with node setters number


Queue object serves  you many attributes few of them is:

its_first_queue--->count : 				Returns node count of queue
its_first_queue--->isEmpty : 			returns True if queue is not empty, False if its empty
its_first_queue--->head : 				Returns head of of queue
its_first_queue--->head--->nextPtr		May be used to traverse arround queues Nodes.







