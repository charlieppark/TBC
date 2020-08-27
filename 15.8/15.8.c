/*
  15.8.c
  <TBC>
  Created by Chan Ho Park on <20200731>.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define BYTE_MASK 0xff

int main()
{
    unsigned int rgba_color = 0x66CDAAFF;
    //4 byte, medium aqua marine (102, 205, 170, 255)

    unsigned char red, green, blue, alpha;

    alpha = rgba_color & 0xff;
    blue = (rgba_color >> 8) & 0xff;
    green = (rgba_color >> 16) & 0xff;
    red = (rgba_color >> 24) & 0xff;

    printf("medium aqua marine (%hhu, %hhu, %hhu, %hhu)", red, green, blue, alpha);

    return 0;
}