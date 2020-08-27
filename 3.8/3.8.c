/*
  3.8.c
  <TBC>
  Created by Chan Ho Park on <20200703>.
*/

#include <stdio.h>

int main()
{
    unsigned int decimal = 4294967295;
    unsigned int binary = 0b11111111111111111111111111111111;
    unsigned int oct = 037777777777; // 8진수 선언할때 리터럴 맨 앞에 0붙임
    unsigned int hex = 0xffffffff;

    printf("%u\n", decimal);
    printf("%u\n", binary);
    printf("%u\n", oct);
    printf("%u\n", hex);

    printf("%o %x %#o %#x %#X", decimal, decimal, decimal, decimal, decimal);
    // #을 붙이면 0이나 0x를 붙여 8진수 또는 16진수임을 알려줌
    
    return 0;
}