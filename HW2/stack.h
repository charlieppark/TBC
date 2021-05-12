#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Data.h"

typedef struct _node // Node 타입
{
	Data data;
	struct _node* link; // 다음 노드로의 연결
}Node;

typedef struct _head // Stack 타입
{
	int count; // Stack의 element 수
	Node* top; // Stack의 top 을 가리키는 포인터
} Stack;

Stack* createStack(void); // 스택 생성 함수
bool emptyStack(Stack*); // 스택이 비어있는지 확인하는 함수

void pushStack(Stack*, Data); // push 함수
bool popStack(Stack*, Data*); // pop 함수
bool stackTop(Stack*, Data*); // top 함수
int stackCount(Stack*); // 스택의 원소 개수를 반환하는 함수
void destoryStack(Stack**); // 스택을 없애는 함수 - stack의 해제까지 처리하기 위해 이중 포인터 사용

#endif