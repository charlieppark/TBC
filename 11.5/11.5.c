/*
  11.5.c
  <TBC>
  Created by Chan Ho Park on <20200720>.
*/

#include <stdio.h>

void custom_put(const char* str);
int custom_put2(const char* str);

int main()
{
    char* text = "The truth is ... I am Iron man.";
   
    custom_put(text);

    printf("count is %d", custom_put2(text));

    return 0;
}

void custom_put(const char* str)
{
    while (*str != '\0')
        putchar(*str++);
}

int custom_put2(const char* str)
{
    int count = 0;

    while (*str != '\0')
    {
        count++;
        putchar(*str++);
    }
    putchar('\n');

    return count;
}
