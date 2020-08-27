/*
  12.7.c
  <TBC>
  Created by Chan Ho Park on <20200722>.
*/

#include <stdio.h>

void count(void);

int main()
{
    printf("The truth is ... I am Iron man.");

    count();
    count();
    count();
    count();
    count();

    return 0;
}

void count(void)
{
    static int ct = 0;
    static int pt;
    pt = 0;
    ct++;
    pt++;

    printf("ct = %d, pt = %d.\n", ct, pt);
}