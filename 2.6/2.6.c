/*
  2.6.c
  <TBC> 
  Created by Chan Ho Park on <20200630>.
*/

#include <stdio.h>

int main()
{
    printf("\"The truth is ... \nI am Iron man.\"\n");
    // print formatted
    // \n -> Escape Sequence

    printf("\n\n\n\nCALCULATE\n\n");

    int x = 1, y = 4;
    int sum;

    sum = x + y;

    printf("%i + %i = %i\n\n\n", x, y, sum);
    // printf와 같은 output에서 %d, %i간 차이는 없다. scanf에서는 차이가 있다
    
    printf("\a");

    return 0;
}