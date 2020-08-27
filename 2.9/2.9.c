/*
  <2.9>.c
  <TBC>
  Created by Chan Ho Park on <20200630>.
*/

#include <stdio.h>

void say_hello(void); // prototyping, function declaration

int main()
{
    say_hello();
    say_hello();
    say_hello();
    say_hello();
    say_hello();

    return 0;
}

void say_hello(void) // function definition
{
    printf("Hello World!\n");

    return;
}