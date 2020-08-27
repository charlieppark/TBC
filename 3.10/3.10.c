/*
  3.10.c
  <TBC>
  Created by Chan Ho Park on <20200703>.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
    char c = 'A';
    char d = 65; // 65 = 'a'

    printf("%c %hhd\n", c, c);
    printf("%c %hhd\n", d, d);

    printf("%c\n", c+1);

    char a = '\a';
    printf("%c", a);
    // \a = 7

    printf("\07"); //oct 7
    printf("\x7"); //hex 7

    float salary;
    printf("$______\b\b\b\b\b\b");
    scanf("%f", &salary);

    printf("\n\n\n");

    printf("AB\tCDEF\n");
    printf("ABC\tDEF\n");

    printf("\\ \' \" \? \n");

    return 0;
}