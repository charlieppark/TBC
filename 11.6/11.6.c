/*
  11.6.c
  <TBC>
  Created by Chan Ho Park on <20200720>.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void fit_str(char*, unsigned int);
void copy_strcat(char*, char*);

int main()
{
    //char msg[] = "Just,"" do it!";
    char str1[100] = "Let's go Party";
    char str2[] = " Yeah! Let's go!";

    /*printf("length = %d", strlen(msg));
    fit_str(msg, 4);
    puts(msg);
    printf("length = %d", strlen(msg));*/

    copy_strcat(str1, str2);
    puts(str1);
    printf("%d", strlen(str1));

    return 0;
}

void fit_str(char* str, unsigned int n)
{
    if (strlen(str) >= n)
        *(str + n) = '\0';
}

void copy_strcat(char* str1, char* str2)
{
    int temp = strlen(str1);
    for (int i = 0; i < strlen(str2); i++)
        *(str1 + temp + i) = str2[i];

}
