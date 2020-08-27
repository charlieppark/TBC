/*
  3.12.c
  <TBC>
  Created by Chan Ho Park on <20200704>.
*/

#include <stdio.h>
#include <float.h>
#include <math.h>

int main()
{
    
    float a, b;
    a = 1000.0f + 1.0f;
    b = a - 1000.0f;
    printf("No Round-Off Errors : %f\n\n\n", b);

    
    //round-off errors (ex1)
    float a1, b1;
    a1 = 1.0e20f + 1.0f;
    b1 = a1 - 1.0e20f;
    printf("Round-Off Errors (1) : %f\n\n\n", b1);


    //round-off errors (ex2)
    float a2 = 0.0f;

    //100회 더하기
    for (int count = 0; count < 100; count++)
    {
        a2 = a2 + 0.01f; // 0.01을 정확히 표현할 수 없음 (0.009999999776F). 오차누적
    }
    printf("Round-Off Errors (2) : %f\n\n\n",a2);


    //overflow
    float max = FLT_MAX;
    printf("Maximum of float is %f\n", max);
    max = max * 100.0f;
    printf("overflow : %f\n\n\n", max);

    //underflow
    float min = FLT_TRUE_MIN;
    printf("Minimum of float is %e\n", min);
    min = min / 2.0f; // subnormal
    printf("underflow : %e\n\n\n", min);


    float f = 104.0f;
    printf("f = %f\n", f);
    f = f / 0.0f;
    printf("f / 0.0f = %f\n\n\n", f);
    
    float arcsin = asinf(1.0f);
    printf("arcsin(1.0f) = %f\n", arcsin);

    arcsin = asinf(2.0f);
    printf("arcsin(2.0f) = %f\n\n\n", arcsin);
    // 수학적으로 존재하지 않는 값을 계산 - 결과값 nan(not a number)

    return 0;
}