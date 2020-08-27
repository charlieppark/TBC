/*
  6.1.c
  <TBC>
  Created by Chan Ho Park on <20200707>.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
    int num, sum = 0;
    int status;

    printf("Enter an integer (q to quit) : ");

    //status = scanf("%d", &num);

    //while (status == 1)
    while (scanf("%d", &num) == 1)
    {
        sum = sum + num;

        printf("Enter next integer (q to quit) : ");
        //status = scanf("%d", &num);
    }

    printf("Sum is %d", sum);

    return 0;
}