/*
  9.10.c
  <TBC>
  Created by Chan Ho Park on <20200713>.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
    int count;

    scanf("%d", &count);
    
    printf("%d", Fibonacci(count));

    return 0;
}

int Fibonacci(int num)
{  

    if (num > 2)
    {
        return Fibonacci(num - 1) + Fibonacci(num - 2);
    }

    return 1;
}