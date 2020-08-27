/*
  4.4.c
  <TBC>
  Created by Chan Ho Park on <20200704>.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100] = "Hello";
    char str2[] = "Hello";
    char str3[100] = "\0";
    char str4[100] = "\n";

    printf("%zu %zu\n", sizeof(str1), strlen(str1));
    printf("%zu %zu\n", sizeof(str2), strlen(str2));
    printf("%zu %zu\n", sizeof(str3), strlen(str3));
    printf("%zu %zu\n", sizeof(str4), strlen(str4));

    // 결과값에서 확인할 수 있듯이, strlen()은 \0을 세지 않음.

    /* Extra */
    char* str5 = (char*)malloc(sizeof(char) * 100);
    str5[0] = 'H';
    str5[1] = 'e';
    str5[2] = 'l';
    str5[3] = 'l';
    str5[4] = 'o';
    str5[5] = '\0';
    printf("%zu %zu\n", sizeof(str5), strlen(str5));

    return 0;
}