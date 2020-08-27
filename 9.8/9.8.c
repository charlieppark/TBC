/*
  9.8.c
  <TBC>
  Created by Chan Ho Park on <20200713>.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int recursion_factorial(int num);
int loop_factorial(int num);

int main()
{
    int num;

    printf("Input number you want to calculate factorial :\n");

    scanf("%d", &num);

    printf("Recursion factorial of %d is %d.\n", num, recursion_factorial(num));
    printf("Loop factorial of %d is %d.\n", num, loop_factorial(num));
    
    return 0;
}

int recursion_factorial(int num)
{
    if (num > 1)
    {
        return num * recursion_factorial(num - 1); //tail recursion (end recursion)
    }

    return num;
}

int loop_factorial(int num)
{
    int result = 1;

    for (int i = 2; i <= num; i++)
        result *= i;

    return result;
}
