#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

int RPNExp(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	char tok;
	int op1, op2;

	Init(&stack);

	for (int i = 0; i < expLen; i++)
	{
		tok = exp[i];

		if (isdigit(tok))
		{
			int temp = 0;

			//문자로 표현된 여러 자리 숫자를 .이 나타날 때까지 숫자 값으로 변환
			while (1)
			{

				temp += exp[i++] - '0';

				if (exp[i] == '.')
				{
					break;
				}
				
				temp *= 10;
			}

			pushStack(&stack, temp);
		}
		else
		{
			op2 = popStack(&stack);
			op1 = popStack(&stack);

			switch (tok)
			{
			case '+':
				pushStack(&stack, op1 + op2);
				break;
			case '-':
				pushStack(&stack, op1 - op2);
				break;
			case '*':
				pushStack(&stack, op1 * op2);
				break;
			case '/':
				pushStack(&stack, op1 / op2);
				break;
			}
		}
	}
	return popStack(&stack);
}