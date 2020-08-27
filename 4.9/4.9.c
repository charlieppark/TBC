/*
  4.9.c
  <Name of project>
  Created by Chan Ho Park on <Date>.
*/

#include <stdio.h>

int main()
{
    float   n1 = 3.14;  // 4 bytes
    double  n2 = 1.234; // 8 bytes
    int     n3 = 1024;  // 4 bytes

    // Note the warnings in output window
    printf("%d %d %d\n\n", n1, n2, n3); // 4, 4, 4 (N, N, N)
    printf("%lld %lld %d\n\n", n1, n2, n3); // 8, 8, 4 (N, N, Y)
    printf("%f %d %d\n\n", n1, n2, n3); // 8, 4, 4 (Y, N, N)
    printf("%f %lld %d\n\n", n1, n2, n3); // 8, 8, 4 (Y, N, Y)

    return 0;
}