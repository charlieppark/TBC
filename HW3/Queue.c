#include "BST.h"
#include "Queue.h"

QUEUE* createQueue()
{
	QUEUE* head = (QUEUE*)malloc(sizeof(QUEUE));

	if (head == NULL)
	{
		printf("MALLOC FAILED ERROR. QUIT PROGRAM.\n");
		exit(1);
	}

	head->front = NULL;
	head->rear = NULL;
	head->count = 0;
	return head;
}

bool isQEmpty(QUEUE* queue)
{
	if (queue->count == 0)
		return true;
	else
		return false;
}

bool enqueue(QUEUE* queue, NODE* node)
{
	QUEUENODE* newQNode = (QUEUENODE*)malloc(sizeof(QUEUENODE));
	
	if (newQNode == NULL)
	{
		printf("MALLOC FAILED ERROR. QUIT PROGRAM.\n");
		exit(1);
	}

	newQNode->dataPtr = node;
	newQNode->next == NULL;

	if (isQEmpty(queue))
	{
		queue->front = newQNode;
	}
	else
	{
		queue->rear->next = newQNode;
	}

	queue->rear = newQNode;
	queue->count++;

	return true;
}

bool dequeue(QUEUE* queue, NODE** nodePtr)
{
	if (isQEmpty(queue))
	{
		return false;
	}

	*nodePtr = queue->front;

	if (queue->front == queue->rear)
	{
		queue->rear == NULL;
	}

	queue->front = queue->front->next;
	queue->count--;
}

void destoryQueue(QUEUE* queue)
{
	if (!isQEmpty(queue))
	{
		while (!isQEmpty(queue))
		{
			QUEUENODE* temp = queue->front;
			queue->front = temp->next;
			free(temp);
			queue->count--;
		}
	}

	free(queue);
}