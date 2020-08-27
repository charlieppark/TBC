/*
  14.19.c
  <TBC>
  Created by Chan Ho Park on <20200730>.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

enum spectrum { red, orange, yellow, green, blue };
const char* colors[] = { "red", "orange","yellow", "green", "blue" };
const char* things[] = { "roses", "shoes","umbrella", "grass", "ocean" };

#define LEN 30

int main()
{
    char choice[LEN];
    enum spectrum color;
    bool color_is_found = false;



    while (1)
    {
        printf("Input a color name (empty line to quit).\n>> ");
        if(scanf("%[^\n]%*c", choice) != 1)
        {
            printf("GOODBYE!\n");
            break;
        }

        for (color = red; color <= blue; color++)
        {
            if (strcmp(choice, colors[color]) == 0)
                printf("%s %s\n", colors[color], things[color]);
        }

    
    }

    return 0;
}