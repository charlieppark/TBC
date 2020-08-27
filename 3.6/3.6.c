/*
  3.6.c
  <TBC>
  Created by Chan Ho Park on <20200702>.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void overunderflow(unsigned int num);

int main()
{
    printf("Size of unsigned integer is %u bytes.\n\n", sizeof(unsigned int));
    // 결과값은 4(byte). 즉 32bit.


    // 0b는 binary number 임을 알려줌 (C에서 표준은 아니나 대부분 사용할 수 있게 해둠)
    // unsigned int 는 32bit이므로 0b11111111111111111111111111111111은 unsigned int의 최댓값임
    unsigned int bin = 0b11111111111111111111111111111111;
    unsigned int U_MAX = UINT_MAX;
    signed int I_MAX = INT_MAX;
    signed int I_MIN = INT_MIN;

    printf("Maximum limit of unsigned integer is %u.\n\n", bin);
    printf("Maximum limit of unsigned integer is %u.\n\n", U_MAX);
    printf("Maximum limit of signed integer is %d.\n\n", I_MAX);
    printf("Minimum limit of signed integer is %d.\n\n", I_MIN);

    overunderflow(U_MAX);
    overunderflow(I_MAX);
    overunderflow(I_MIN);

    return 0;
}

void overunderflow(unsigned int num)
{
    char buffer[33];
    _itoa(num, buffer, 2);
    // 입력된 숫자 num의 값을 이진수로 buffer 문자열에 저장

    if (num == UINT_MAX)
    {
        printf("\n\n\n\nInput num is maximum limit of unsigned integer.\n");
        printf("Decimal : %u\n", num);
        printf("Binary  : %u\n", num);

        num++;
        printf("1 added to the number");
        printf("Decimal : %u\n", num);
        printf("Binary  : %u\n", num);

        printf("\n\nOVERFLOW!\n\n");
    }

    else if (num == INT_MAX)
    {
        printf("\n\n\n\nInput num is maximum limit of signed integer.\n");
        printf("Decimal : %d\n", num);
        printf("Binary  : %d\n", num);

        num++;
        printf("Add 1 to the number");
        printf("Decimal : %d\n", num);
        printf("Binary  : %d\n", num);

        printf("\n\nOVERFLOW!\n\n");
    }

    else if (num == INT_MIN)
    {
        printf("\n\n\n\nInput num is minimum limit of signed integer.\n");
        printf("Decimal : %d\n", num);
        printf("Binary  : %d\n", num);

        num--;
        printf("1 subtracted from the number");
        printf("Decimal : %d\n", num);
        printf("Binary  : %d\n", num);

        printf("\n\nUNDERFLOW!\n\n");
    }

    else
    {
        return;
    }

    return;
}