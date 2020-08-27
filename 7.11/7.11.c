/*
  7.11.c
  <TBC>
  Created by Chan Ho Park on <20200712>.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>

int main()
{
    int input = 0, max = -INT_MAX, min = INT_MAX, sum = 0, count = 0;

    while (scanf("%d", &input) == 1)
    {
        max = (input > max) ? input : max;
        
        min = (input < min) ? input : min;
        
        sum += input;
        count++;
    }
    if (count > 0)
        printf("min = %d, max = %d, ave = %f", min, max, ((float)sum / count));
    else
        printf("No Input");
    return 0;
}