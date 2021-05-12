#ifndef __POSTEVAL_H__
#define __POSTEVAL_H__

#include <stdio.h>
#include <stdbool.h>
#include "Data.h"

bool postFixEval(char*, Data*); // 전체 수식 계산을 담당하는 함수
Data calculate(Data, char, Data); // 두 피연산자와 연산자를 통한 계산을 담당하는 함수
bool isOperand(char*); // 피연산자인지 판단하는 함수

#endif