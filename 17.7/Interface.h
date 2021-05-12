#pragma once

#define MAX_LEN 40

struct movie
{
	char title[MAX_LEN];
	double rating;
};

typedef struct movie Item;

typedef struct node
{
	Item item;
	struct movie* next;
} node;

typedef struct list
{
	node* head;
	int size;
} List;

void search_movie(const struct movie*);

struct movie* file_read(struct movie*);

void file_write(struct movie*);

void print_movies(const struct movie*);

void print_a_movie(const struct movie*);

void print_menu(const struct movie*);

void edit_member(const struct movie*);

void edit_item(const struct movie*);

void insert_item(const struct movie*, int);

void delete_item(struct movie**, int);

void delete_all_items(const struct movie**);

void buf_clr();

int input_index(void);

struct movie* search_index(struct movie*, int);

void add_item(struct movie**);