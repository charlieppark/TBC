#include "postFixEvaluate.h"
#include "stack.h"

bool postFixEval(char* exp, Data* result)
{
	Stack* stack = createStack(); // 수식을 담을 스택 생성
	
	char* c = exp; // 수식의 현재 위치를 저장할 포인터

	while (*c != '\0') // 문자열의 끝이 아닐때까지
	{
		if (isOperand(c)) // 피연산자라면
		{
			pushStack(stack, (*c) - ('0')); // 스택에 값을 저장
		}
		else // 연산자라면
		{
			Data oper1, oper2;

			if (!popStack(stack, &oper2)) // 피연산자1 pop
				return 0;
			if (!popStack(stack, &oper1)) // 피연산자2 pop
				return 0;

			Data value = calculate(oper1, *c, oper2); // 연산 결과를 value에 저장

			pushStack(stack, value); // value를 스택에 push
		}

		c++; // 포인터 연산을 통해 수식의 다음 문자로 이동
	}

	popStack(stack, result); // 최종 결과를 pop

	if (emptyStack(stack)) // 스택이 비어있다면 (정상)
	{
		free(stack);
		return 1; // 정상
	}
	else // 스택이 비어있지 않다면 (계산 불가)
	{
		destoryStack(&stack); // 스택 제거
		return 0; // 계산 불가
	}
}

Data calculate(Data o1, char operator, Data o2) // 각 연산자에 맞게 연산 후 결과 반환
{
	switch (operator)
	{
	case '+':
		return o1 + o2;

	case '-':
		return o1 - o2;

	case '*':
		return o1 * o2;

	default:
		break;
	}

	return 0;
}

bool isOperand(char* c)
{
	if ((*c == '+') || (*c == '-') || (*c == '*'))
		return 0;
	else
		return 1;
}