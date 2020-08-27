/*
  15.3.c
  <TBC>
  Created by Chan Ho Park on <20200731>.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned char to_decimal(const char bi[]);
void print_binary(const unsigned char num);

int main()
{
    unsigned char i = to_decimal("01000110");
    unsigned char mask = to_decimal("00000101");

    print_binary(i);
    print_binary(mask);
    print_binary(i & mask);

    return 0;
}

unsigned char to_decimal(const char bi[])
{
    int sum = 0;

    for (int i = 0; i < 8; i++)
        sum += (int)pow(2, 7 - i) * ((int)bi[i] - 48);
    return sum;
}

void print_binary(unsigned char num)
{

    for (int i = 0; i < 8; i++)
        printf("%d", ((int)pow(2, 7-i)&num)==pow(2, 7 - i));

    printf("\n");

    return;
}

