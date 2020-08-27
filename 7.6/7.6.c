/*
  7.6.c
  <TBC>
  Created by Chan Ho Park on <20200710>.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main()
{
    unsigned num = 2;
    bool isPrime = 1;

    while (num < 100)
    {
        for (unsigned i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                isPrime = 0;
                break;
            }
        }

        if (isPrime)
            printf("%u is a prime number.\n", num);
        else
            //printf("%u is not a prime number. Can be divided by %u\n", num, i)
            ;

        num++;
        isPrime = 1;
    }
    return 0;
}