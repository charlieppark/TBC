/*
  4.10.c
  <TBC>
  Created by Chan Ho Park on <20200705>.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <inttypes.h> // intmax_t


int main()
{
    /* multiple inputs with blank seperators */
    int i;
    float f;
    char str[30];
    scanf("%d %f %s", &i, &f, str);
    printf("\n%d %f %s\n\n", i, f, str);

    /* character */
    char c;
    scanf("%c", &c);    // try blank
    printf("%i\n\n", c);// blank is 32

    /* Unsigned as signed */
    unsigned k;
    scanf("%i", &k); // try negative number
    printf("%i\n\n", k);

    /* floating point numbers */
    double d = 0.0;
    scanf("%f", &d);    // lf, try E notation
    printf("%f\n\n", d);// f

    /* integer with characters */
    int n;
    scanf("%i", &n);    // try 123a456
    printf("%i\n\n", n);

    /* j modifier */
    intmax_t i;
    scanf("%ji", &i);
    printf("%ji", i);

    /* Regular characers (정규식) */
    int a, b;
    scanf("%d %d", &a, &b);
    scanf("%d ,%d", &a, &b);
    scanf("%d, %d", &a, &b);
    scanf("%d,%d", &a, &b);
    scanf("%d-%d", &a, &b);
    scanf("%dA%d", &a, &b);
    printf("%d %d\n\n", a, b);

    /* *modifier for printf() */
    int o = 123;
    int width;
    printf("Input width : ");
    scanf("%d", &width);
    printf("%*d\n\n", width, o);

    /* *modifier for scanf() */
    int ti;
    scanf("%*d%*d%d", &t);
    printf("Your third input = %d", t);

    return 0;
}