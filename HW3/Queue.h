#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "BST.h"

typedef struct _queue_node
{
	NODE* dataPtr;
	struct _queue_node* next;
}QUEUENODE;

typedef struct _queue
{
	QUEUENODE* front;
	QUEUENODE* rear;
	int count;
} QUEUE;

QUEUE* createQueue();
bool enqueue(QUEUE* queue, NODE* node);
bool dequeue(QUEUE* queue, NODE** nodePtr);
void destoryQueue(QUEUE* queue);
bool isQEmpty(QUEUE* queue);


#endif