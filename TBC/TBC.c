
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



int main()

{
	char input1[10];
	char input2[10];

	scanf("%[^\n]%*c", input1);
	scanf("%[^\n]%*c", input2);

	printf("%s checked", input1);
	printf("%s checked", input2);

}