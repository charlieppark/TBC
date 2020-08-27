/*
  14.14.c
  <TBC>
  Created by Chan Ho Park on <20200730>.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define SLEN 101

struct book
{
    char name[SLEN];
    char author[SLEN];
};

void print_books(const struct book* books, int n);
void write_books(const char* filename, const struct book* books, int n_ptr);
struct book* read_books(const char* filename, int* n);
void read_books2(const char* filename, struct book** books_dptr, int* n_ptr);

int main()
{
    int temp;
    int n = 3;

    struct book* my_books = (struct book*)malloc(sizeof(struct book) * n);

    if (!my_books)
    {
        printf("Malloc failed");
        exit(1);
    }

    my_books[0] = (struct book){ "The Great Gatsby", "F. Scott Fitzgerald" };
    my_books[1] = (struct book){ "Hamlet", "William Shakespeare" };
    my_books[2] = (struct book){ "The Odyssey", "Homer" };

    print_books(my_books, n);
    printf("\nWriting to a file.\n");
    write_books("books.txt", my_books, n);
    free(my_books);
    n = 0;
    printf("Done.\n");
    
    printf("\nPress any key to read data from a file.\n\n");
    temp = _getch();

    my_books = read_books("books.txt", &n);
    //read_books2("books.txt", &my_books, &n);
    print_books(my_books, n);
    free(my_books);
    n = 0;

    return 0;
}

void print_books(const struct book* books, int n)
{
    for (int i = 0; i < n; i++)
        printf("Book %d : \"%s\" written by \"%s\"\n", i, books[i].name, books[i].author);

}

void write_books(const char* filename, const struct book* books, int n)
{
    char* ch = NULL;
    FILE* fw;


    if ((fw = fopen(filename, "w")) == NULL)
    {
        printf("Can't open %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fprintf(fw, "%d\n", n);

    for (int i = 0; i < n; i++)
    {
        fprintf(fw, "%s\n", books[i].name);
        fprintf(fw, "%s\n", books[i].author);
    }

    fclose(fw);
}

struct book* read_books(const char* filename, int* n_ptr)
{

    FILE* fr;


    if ((fr = fopen(filename, "r")) == NULL)
    {
        printf("Can't open %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fscanf(fr, "%d", n_ptr);
    int num = *n_ptr;
    
    struct book* tmpb = (struct book*)malloc(sizeof(struct book) * num);

    if (!tmpb)
    {
        printf("Malloc failed");
        exit(1);
    }

    for (int i = -1; i < num; i++)
    {
        if (i == -1)
        {
            fgetc(fr);
        }
        else
        {
            fgets(tmpb[i].name, SLEN, fr);
            fgets(tmpb[i].author, SLEN, fr);
            
        }
    }

    for (int i = 0; i < num; i++)
    {
        if (tmpb[i].name[strlen(tmpb[i].name) - 1] == '\n')
            tmpb[i].name[strlen(tmpb[i].name) - 1] = '\0';
        if (tmpb[i].author[strlen(tmpb[i].author) - 1] == '\n')
            tmpb[i].author[strlen(tmpb[i].author) - 1] = '\0';
    }

    fclose(fr);

    return tmpb;
}

void read_books2(const char* filename, struct book** books_dptr, int* n_ptr)
{
    //TBC 예제코드를 그대로 복사
    FILE* file = fopen(filename, "r");

    if (file == NULL)
    {
        fputs("Can't open the file.", stderr);
        exit(1);
    }

    int flag;
    flag = fscanf(file, "%d%*c", n_ptr);
    if (flag != 1)
    {
        printf("File read failed");
        exit(1);
    }

    struct book* books = (struct book*)calloc(sizeof(struct book), *n_ptr);

    if (!books)
    {
        printf("Calloc() failed");
        exit(1);
    }

    for (int i = 0; i < *n_ptr; ++i)
    {
        flag = fscanf(file, "%[^\n]%*c%[^\n]%*c", books[i].name, books[i].author);

        if (flag != 2)
        {
            printf("File read failed");
            exit(1);
        }
    }

    fclose(file);

    *books_dptr = books;
}
