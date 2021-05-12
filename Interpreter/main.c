#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "InfixCalculator.h""

//변수를 담기 위한 구조체
typedef struct 
{
	char name[50];
	int value;
} var;

var variable;

void interpreter(char*, int);

int main()
{
	printf("This program is Statement Interpreter.\n\n");
	printf("All the operators, operands, and variable should be separated by blank space.\n\n");
	printf("You can use only one variable and name of it should be shorter than 50.\n\n"); 
	printf("Operators like '=', '+', '*', '(', ')' are supported.\n\n");
	printf("You an print result using 'print' before statement or variable.\n\n");
	printf("To quit this program, please input 'Q'. (Cannot use 'Q' for variable name)\n\n");

	char* input = (char*)malloc(sizeof(char) * 100);

	//제대로 할당되지 않았을 경우 메모리 오류 (이하 주석 생략)
	if (input == NULL)
	{
		printf("Memory Error Occurred");
		exit(1);
	}

	char quit = 'Q';

	while (1)
	{
		// input 으로 명령문을 받음
		fgets(input, 100, stdin);

		for (int i = 0; i < 100; i++)
		{
			if (*(input + i) == '\n')
				*(input + i) = '\0';
		}

		if (*input == quit)
		{
			break;
		}
		
		interpreter(input, strlen(input));
	}

	printf("Thank You For Using This Program");

	free(input);

	return 0;
}

void interpreter(char* expression, int length)
{
	for (int i = 0; i < length; i++)
	{
		//치환문 검증 - 명령문의 현재 문자가 =일 경우
		if (*(expression + i) == '=')
		{
			//변수 이름을 받아줄 포인터
			char* var_name = (char*)malloc(sizeof(char) * i);

			if (var_name == NULL)
			{
				printf("Memory Error Occurred");
				exit(1);
			}

			int index = 0;

			//명령문의 처음부터 =가 있는 위치까지
			for (int k = 0; k < i; k++)
			{
				//알파벳일 경우 변수에 담는다
				if (isalpha(*(expression + k)))
				{
					*(var_name + index) = *(expression + k);
					index++;
				}
			}

			//문자열로 인식되기 위해 끝에 '\0'로 처리 (이하 주석 생략)
			*(var_name + index) = '\0';


			//변수에 이름 저장
			memcpy(variable.name, var_name, strlen(var_name));

			int exp_exist = 0;

			for (int j = i + 1; j < length; j++)
			{
				switch (*(expression + j))
				{
				case '(':
				case ')':
				case '+':
				case '-':
				case '*':
				case '/':
					exp_exist = 1;
					break;
				}
			}

			if (exp_exist)
			{
				// = 뒤의 수식을 계산
				variable.value = InfixExp(expression + i + 1);
			}
			else
			{
				variable.value = atoi(expression + i + 1);
			}

			//사용을 마친 포인터 반환 (이하 주석 생략)
			free(var_name);

			break;
		}

		//print 문 검증
		else if (*(expression + i) == 'p')
		{
			char* temp = (char*)malloc(sizeof(char) * 10);

			//비교를 위해 print 문자열 생성
			char str[6] = "print";

			//명령문 현재 위치에서 print 문자열 크기만큼 복사
			memcpy(temp, expression + i, 5);

			*(temp + 5) = '\0';

			// 입력된 문자열이 print가 맞다면
			if (strcmp(temp, str) == 0) 
			{
				// print 뒤에 수식만 있을 경우를 확인하기 위한 변수
				int var_existence = 0;

				// print 이후부터 읽어들임
				i += 5;

				int name_length = strlen(variable.name);

				// 출력 값을 담기 위한 변수
				int temp_value;

				for (int j = i; j < length; j++)
				{
					// print 뒤에 알파벳이 입력되었고 입력된 내용이 변수의 이름과 같다면 
					if (isalpha(*(expression + j)) && (strncmp(expression + j, variable.name, name_length)) == 0) 
					{
						// print 뒤에 변수가 있음
						var_existence = 1;

						//변수 뒤에 수식이 없을 경우
						if (strlen(expression + j + name_length + 1) == 0)
						{
							//변수를 출력 값으로 지정
							temp_value = variable.value;
						}
						//변수 뒤에 수식이 있을 경우
						else
						{
							//변수명을 값으로 치환해 수식을 담을 포인터
							char* new_exp = (char*)malloc(sizeof(char) * 100);

							//변수명을 값으로 치환
							_itoa(variable.value, new_exp, 10);

							int len = strlen(new_exp);

							*(new_exp + len) = ' ';
							*(new_exp + len + 1) = '\0';

							len = strlen(new_exp);

							//치환한 후의 수식을 새로 저장
							memcpy(new_exp + len, expression + j + name_length + 1, length - j - name_length - 1);

							*(new_exp + len + length - j - name_length - 1) = '\0';
							

							//수식을 계산하여 출력값으로 지정
							temp_value = InfixExp(new_exp);

							free(new_exp);
						}
						break;
					}
				}

				// print 뒤에 변수가 없을 경우
				if (var_existence == 0)
				{
					// print 뒤의 수식을 계산하여 출력값으로 지정
					temp_value = InfixExp(expression + i);
				}

				free(temp);

				printf("%d\n\n", temp_value);
			}
		}
	}

}