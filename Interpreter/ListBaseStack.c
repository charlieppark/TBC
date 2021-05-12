#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

//스택 초기화
void Init(Stack* pstack)
{
	pstack->head = NULL;
}

//스택이 비어있는지 확인
int emptyStack(Stack* pstack)
{
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

//스택 Push
void pushStack(Stack* pstack, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = pstack->head;

	pstack->head = newNode;
}

//스택 Pop
Data popStack(Stack* pstack)
{
	Data rdata;
	Node* rnode;

	if (emptyStack(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	rdata = pstack->head->data;
	rnode = pstack->head;

	pstack->head = pstack->head->next;
	free(rnode);

	return rdata;
}

//스택 Peek
Data stackTop(Stack* pstack)
{
	if (emptyStack(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->head->data;
}