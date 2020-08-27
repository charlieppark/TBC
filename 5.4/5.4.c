/*
  5.4.c
  <TBC>
  Created by Chan Ho Park on <20200705>.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
    double seed, target, interest;
    int year = 0;

    printf("Input seed money : ");
    scanf("%lf", &seed);
    printf("Input target money : ");
    scanf("%lf", &target);
    printf("Input annual interest (%%) : ");
    scanf("%lf", &interest);

    while (seed < target)
    {
        seed *= (1.00f + interest * 0.01);
        printf("\n%f", seed);
        year++;
    }

    printf("\n\nIt takes %d years\n\n", year);

    return 0;
}