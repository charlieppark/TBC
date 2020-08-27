/*
  4.1.c
  <TBC>
  Created by Chan Ho Park on <20200704>.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
    char fruit_name[40];

    printf("What is your favorite fruit?\n");
    scanf("%s", fruit_name);
    printf("You like %s!\n\n", fruit_name);

    return 0;
}