/*
  8.5.c
  <TBC>
  Created by Chan Ho Park on <20200712>.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void display(char cr, int lines, int width);

int main()
{
    char c;
    int rows, cols;

    printf("Input a character and two numbers : \n");

    while ((c = getchar()) != '\n')
    {
        scanf("%d %d", &rows, &cols);
        while (getchar() != '\n') continue;
        //scanf가 필요한 값을 받아들인 후 남은 data를 buffer에 남기기 때문에 buffer 정리 필요
        display(c, rows, cols);

        printf("Input another character and two numbers (enter to quit) : \n");
    }

    return 0;
}

void display(char cr, int lines, int width)
{
    for (int i = 0; i < lines; i++)
    {
        for (int k = 0; k < width; k++)
            printf("%c", cr);

        printf("\n");
    }
}