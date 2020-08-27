/*
  4.3.c
  <TBC>
  Created by Chan Ho Park on <20200704>.
*/

#include <stdio.h>

int main()
{
    int a = 1;
    int int_arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    printf("%i %i %i\n", int_arr[0], int_arr[1], int_arr[9]);

    //printf("%i\n", int_arr[10000]);
    // 지정된 사이즈를 넘어가면 error 발생

    char c = 'a';
    char str1[10] = "Hello";
    char str2[10] = { 'H', 'i' };

    printf("%c\n", c);
    printf("%s\n", str1);
    printf("%s\n", str2);
    /*
    결과값에서 string의 10bytes 가 전부 다 출력되지 않음.
    string 끝의 \0(null character)가 string의 끝을 알리기 때문.
    */

    printf("%hhi %hhi %hhi %hhi %hhi\n", str2[0], str2[1], str2[2], str2[3], str2[4]);

    //char str3[10] = "Hello, World";
    //배열의 크기가 입력되는 문자열에 비해 충분하지 않다.
    char str3[20] = "Hello, \0World";
    printf("%s\n", str3);

    return 0;
}