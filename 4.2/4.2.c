/*
  4.2.c
  <TBC>
  Created by Chan Ho Park on <20200704>.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // malloc()

struct MyStruct
{
    int i;
    float f;
};

int main()
{
    /* 1. sizeof basic types */

    int a = 0;
    unsigned int int_size1 = sizeof a;
    unsigned int int_size2 = sizeof(int);
    unsigned int int_size3 = sizeof(a);

    /*
    시스템에 따라 sizeof 연산자가 반환하는 type이 다를 수 있음.
    이에 이식성을 높이기 위해 size_t를 사용하기도 함.
    Portable type.
    */
    size_t int_size4 = sizeof(a);
    size_t float_size = sizeof(float);
    
    printf("Size of int type is %u bytes.\n", int_size1);
    printf("Size of int type is %zu bytes.\n", int_size4); //%zu는 size_t에 대응
    printf("Size of int type is %zu bytes.\n\n\n", float_size);



    /* 2. sizeof arrays */
    int  int_arr[30]; // compile time 에 120byte로 결정
    int* int_ptr = NULL;
    int_ptr = (int*)malloc(sizeof(int) * 30); // Run time 에 120byte로 결정

    printf("Size of array = %zu bytes\n", sizeof(int_arr));
    printf("Size of pointer = %zu bytes\n\n\n", sizeof(int_ptr));



    /* 3. sizeof character array */

    char c = 'a';
    char string[10]; // maximally 9 character + '\0' (null character)

    size_t char_size = sizeof(char);
    size_t str_size = sizeof(string);

    printf("Size of char type is %zu types.\n", char_size);
    printf("Size of string type is %zu types.\n", str_size);


    /* 4. sizeof structure */

    printf("%zu\n", sizeof(struct MyStruct));
    // 최상단 definition에 따라 MyStruct의 size는 8 (int 4, float 4)

    return 0;
}