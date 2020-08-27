/*
  3.7.c
  <TBC>
  Created by Chan Ho Park on <20200703>.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{


    char c = 65;
    short s = 200;
    unsigned int ui = 3000000000U;
    /* 3'000'000'000U ----- '를 이용해서 자릿수 표현이 가능.
    '의 자릿수 표현은 C의 경우 Visual Studio에서만 사용이 가능하고, C++에서는 표준. */

    long l = 65537L;
    long long ll = 12345678908642LL; // 12'345'678'908'642LL

    printf("char = %hhd, %d, %c\n\n", c, c, c);
    printf("short = %hhd, %hd, %d\n\n", s, s, s);
    printf("unsigned int = %u, %d\n\n", ui, ui);
    printf("long = %ld, %hd\n\n", l, l);
    printf("long long = %lld, %ld\n\n", ll, ll);

    return 0;
}