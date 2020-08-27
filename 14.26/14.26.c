/*
  14.26.c
  <TBC>
  Created by Chan Ho Park on <20200730>.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void update_string(char* str, int(*pf)(int));
void ToUpper(char* str);
void ToLower(char* str);
void Transpose(char* c_ptr, char* str, int n);
char Menu(void);

int main()
{
    char options[] = { 'u', 'l' };
    int n = sizeof(options) / sizeof(char);

    typedef void (*FUNC_TYPE)(char*);
    FUNC_TYPE operations[] = { ToUpper, ToLower };

    printf("Enter a string\n>> ");

    char input[100];

    while (scanf("%[^\n]%*c", input) != 1)
        printf("Please try again.\n>> ");

    char flag = Menu();

    Transpose(options, &flag, n);
    update_string(input, operations[flag]);

    printf("%s", input);

    return 0;
}

void update_string(char* str, int(*pf)(int))
{
    pf(str);
}

void ToUpper(char* str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

void ToLower(char* str)
{
    while (*str)
    {
        *str = tolower(*str);
        str++;
    }
}

void Transpose(char* c_ptr, char* str, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (*str == c_ptr[i])
        {
            *str = i;
            return;
        }
    }
    printf("You made a wrong input.\n");
    exit(1);
}

char Menu(void)
{
    char ptr;

    printf("upper for u, lower for l");

    if (scanf("%c", &ptr) != 1)
        printf("Please try again.\n>> ");

    return ptr;
}
