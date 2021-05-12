#include "stack.h"

Stack* createStack(void) // 스택 생성
{
	Stack* head = (Stack*)malloc(sizeof(Stack)); // head에 스택 할당
	head->count = 0; // 원소 개수 0개로 초기화
	head->top = NULL; // top 초기화
	return head; // 스택 반환
}

bool emptyStack(Stack* stack) // 스택이 비어있는지 확인
{
	if (stack->count == 0)
		return 1;
	else
		return 0;
}

void pushStack(Stack* stack, Data data)
{
	Node* NewNode = (Node*)malloc(sizeof(Node)); // 새 노드 생성
	NewNode->data = data; // 노드에 데이터 저장
	NewNode->link = stack->top; // 노드의 아래 원소로 기존의 top 저장
	stack->top = NewNode; // 스택의 top으로 새 노드 저장
	stack->count++; // 원소 개수 +1

	return;
}

bool popStack(Stack* stack, Data* dataOut)
{
	bool success;

	if (emptyStack(stack)) // 스택이 비어있다면
		success = 0; // pop 실패
	else
	{
		Node* temp = stack->top; // 현재의 top을 temp에 저장
		
		*dataOut = stack->top->data; // 스택 top의 데이터를 dataOut으로

		stack->top = stack->top->link; // 스택의 top을 하나 밑으로 이동

		free(temp); // 기존의 top을 해제

		stack->count--; // 원소 개수 -1

		success = 1; // pop 성공
	}

	return success;
}

bool stackTop(Stack* stack, Data* dataOut)
{
	bool success;

	if (emptyStack) // 스택이 비어있다면
		success = 0; // top 실패
	else // 비어있지 않다면
	{
		*dataOut = stack->top->data; // top의 데이터를 dataOut으로
		success = 1;
	}

	return success;
}

int stackCount(Stack* stack)
{
	return stack->count;
}

void destoryStack(Stack** stack)
{
	if (!emptyStack) // 스택이 비어있지 않다면
	{
		Node* temp;

		while (!emptyStack) // 스택이 빌때 까지
		{
			temp = (*stack)->top; // top의 노드를 temp에 저장하고
			(*stack)->top = (*stack)->top->link; // top을 한 칸 아래로 이동
			free(temp); // 노드를 해제
		}
	}

	free(*stack); // 스택에 할당된 공간 해제

	return;
}