/*
  14.4.c
  <TBC>
  Created by Chan Ho Park on <20200727>.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_TITLE 40
#define MAX_AUTHOR 40
#define MAX_BOOKS 3



char* s_gets(char* st, int n)
{
    char* ret_val;
    char* find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n') continue;
    }
    
    return ret_val;
}

struct book
{
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    float price;
};

int main()
{
    struct book library[MAX_BOOKS] = { {"Empty", "Empty", 0.0f}, };

    int count = 0;

    while (1)
    {
        printf("Input a book title or press [Enter] to stop.\n>>>");
        if (s_gets(library[count].title, MAX_TITLE) == NULL) break;
        if (library[count].title[0] == '\0') break;

        printf("Input the author.\n>>>");
        s_gets(library[count].author, MAX_AUTHOR);

        printf("Input the price.\n>>>");
        scanf("%f", &library[count].price);

        while (getchar() != '\n') continue;

        count++;

        if (count == MAX_BOOKS)
        {
            printf("NO MORE BOOKS\n\n");
            break;
        }
    }

    if (count > 0)
    {
        printf("The list of books : \n");
        for (int i = 0; i < count; i++)
        {
            printf("\"%s\" written by %s : $%.1f\n", library[i].title, library[i].author, library[i].price);
        }

    }
    else
    {
        printf("No books inputted");
    }

    
    return 0;
}