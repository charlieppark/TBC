/*
  8.9.c
  <TBC>
  Created by Chan Ho Park on <20200712>.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c;
    FILE* file = NULL;
    char file_name[] = "my_file.txt";

    file = fopen(file_name, "r"); //read or write
    if (file == NULL)
    {
        printf("Failed to open file.\n");
        exit(1);
    }

    while ((c = getc(file)) != EOF)
        putchar(c);
    fclose(file);

    return 0;
}