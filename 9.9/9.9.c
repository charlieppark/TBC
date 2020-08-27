/*
  9.9.c
  <TBC>
  Created by Chan Ho Park on <20200713>.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void binary_print(int num);

int main()
{
    int num;

    printf("Input number you want to calculate into binary :\n");

    scanf("%d", &num);
    
    binary_print(num);

    return 0;
}

void binary_print(int num)
{
    if (num > 1)
    {
        binary_print(num/2);
    }

    printf("%d", num % 2);

    return;
}

