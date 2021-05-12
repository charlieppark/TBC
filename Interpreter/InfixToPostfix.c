#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBaseStack.h"

//중위 표기법에서의 연산자 우선순위
int Precedence(char op)
{
	switch (op)
	{
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':
		return 1;
	}

	return -1;  //등록되지 않은 연산자
}

// 연산자 우선순위를 비교
int PrecChecker(char op1, char op2)
{
	int op1Prec = Precedence(op1);
	int op2Prec = Precedence(op2);

	if (op1Prec > op2Prec)
		return 1;
	else if (op1Prec < op2Prec)
		return -1;
	else
		return 0;
}

//중위 표기법을 후위 표기법으로 변환
void ToRPN(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	char* convExp = (char*)malloc(expLen + 1);

	int i, idx = 0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char) * expLen + 1);
	Init(&stack);

	for (i = 0; i < expLen; i++)
	{
		tok = exp[i];
		
		// 현재 문자가 숫자인지 연산자인지 확인
		if (isdigit(tok))
		{
			for (int k = i; k < expLen; k++)
			{
				i = k;

				//여러 자리의 숫자를 확인
				if (isdigit(exp[k]) == 0)
				{
					break;
				}
				convExp[idx++] = exp[k];
			}

			// 후위 표기법에서의 여러자리 숫자 연산을 위해 한 숫자가 끝나면 . 으로 표기
			convExp[idx++] = '.';
			
		}
		else
		{
			switch (tok)
			{
			case '(':
				pushStack(&stack, tok);
				break;

			case ')':
				while (1)
				{
					popOp = popStack(&stack);
					if (popOp == '(')
						break;
					convExp[idx++] = popOp;
				}
				break;

			//연산자일 경우
			case '+':
			case '-':
			case '*':
			case '/':
				while (!emptyStack(&stack) &&
					PrecChecker(stackTop(&stack), tok) >= 0)
					convExp[idx++] = popStack(&stack);

				pushStack(&stack, tok);
				break;
			}
		}
	}

	while (!emptyStack(&stack))
	{
		convExp[idx++] = popStack(&stack);
	}

	memcpy(exp, convExp, expLen + 1);
	free(convExp);
}