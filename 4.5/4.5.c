/*
  4.5.c
  <TBC>
  Created by Chan Ho Park on <20200705>.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define PI 3.141592f
#define AI_NAME "Jarvis"
//define 에서 상수나 매크로등을 선언할때는 대문자로 하는게 관습

int main()
{
    float radius, area, circum;

    printf("I'm %s.\n\n", AI_NAME);

    printf("Input radius : ");
    scanf("%f", &radius);

    area = PI * radius * radius;
    circum = 2.0 * PI * radius;



    printf("\n\nArea is %f\n", area);
    printf("Circumference is %f\n\n", circum);



    return 0;
}