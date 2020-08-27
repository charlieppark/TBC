/*
  7.8.c
  <TBC>
  Created by Chan Ho Park on <20200711>.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int words = 0, lines = 1, characters = 0;

    char ch;
    
    while ((ch = getchar()) != '.')
    {
        if (ch == ' ' || ch == '\n')
        {
            if (ch == '\n')
                lines++;
            words++;
        }
        else
            characters++;
    }
    words++;

    printf("words = %d, lines = %d, characters = %d", words, lines, characters);

    return 0;
}