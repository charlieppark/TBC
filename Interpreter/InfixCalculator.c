#include <string.h>
#include <stdlib.h>
#include "InfixToPostfix.h"
#include "PostCalculator.h"

// 중위 표기법으로 된 식을 계산
int InfixExp(char exp[])
{
	int len = strlen(exp);
	int ret;
	char* expcpy = (char*)malloc(len + 1);
	memcpy(expcpy, exp, len + 1);

	//중위 표기법을 후위 표기법으로 변환
	ToRPN(expcpy);
	
	//후위 표기법으로 계산한 수식을 받음
	ret = RPNExp(expcpy);

	free(expcpy);
	return ret;
}