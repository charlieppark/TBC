/*
  6.12.c
  <TBC>
  Created by Chan Ho Park on <20200708>.
*/

#include <stdio.h>  
#include <math.h>

int main()
{
    double speed, e_time;
    
    speed = e_time = 1.0;
    
    for (int i = 1; i <= 100; i++, e_time = 2*(1.0-pow(0.5, i))) // 등비급수
        printf("Elapsed time = %.10fs, Archilleus = %.10fm, Turtle = %.10fm\n",\
            e_time, e_time * speed, 0.1+ e_time * speed);

    return 0;
}