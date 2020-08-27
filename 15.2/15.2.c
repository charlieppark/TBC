/*
  15.2.c
  <TBC>
  Created by Chan Ho Park on <20200731>.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

unsigned char to_decimal(const char bi[]);

int main()
{
    printf("Binary (string) to Decimal conversion\n");

    printf("%d\n", to_decimal("00000110"));
    printf("%d\n", to_decimal("00010110"));

    printf("%d\n", to_decimal("10010100"));

    return 0;
}

unsigned char to_decimal(const char bi[])
{
    int sum = 0;

    for (int i = 0; i < 8; i++)
        sum += (int)pow(2, 7 - i) * ((int)bi[i] - 48);
    return sum;
}
