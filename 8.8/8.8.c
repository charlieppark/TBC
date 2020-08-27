/*
  <8.8>.c
  <TBC>
  Created by Chan Ho Park on <20200712>.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
    char input;
    int num, out = 1;

    while (out)
    {
        printf("Enter the letter of your choice.\n");
        printf("a. avengers\tb. beep\nc. count\tq. quit\n");

        scanf("%c", &input);
        while (getchar() != '\n') continue;
        switch (input)
        {
        case 'a':
            printf("Avengers Assemble!\n\n");
            break;
        case 'b':
            printf("\a\n");
            break;
        case 'c':
            printf("Enter an integer :\n");
            scanf("%d", &num);
            while (getchar() != '\n') continue;
            for (int i = 1; i <= num; i++)
                printf("%d\n", i);
            printf("\n");
            break;
        case 'q':
            out = 0;
            break;
        case '\n':
            printf("No input was made. Press enter.\n\n");
            break;
        default:
            printf("Wrong Input.\n\n");
            break;
        }
    }
    return 0;
}