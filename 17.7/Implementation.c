#include <stdio.h>

#define MAX_LEN 40

void buf_clr()
{
	while (getchar() != '\n') continue;
	return;
}

int input_index(void)
{
	int index;

	printf("Input an index of item to do the function.\n>> ");

	while (scanf("%d", &index) != 1)
		printf("\nYou made a wrong input\n");

	buf_clr();

	return index;
}

struct movie* file_read(struct movie* head)
{
	FILE* fr;

	char* file_name = (char*)malloc(MAX_LEN);

	int count = 0;

	struct movie* new_node;

	struct movie* temp = NULL;

	printf("Please input filename to read and press [Enter].\n>> ");

	scanf("%s", file_name);

	if ((fr = fopen(file_name, "r")) == NULL)
	{
		printf("ERROR : Cannot Open File.");
		exit(1);
	}

	count = fgetc(fr) - 48; // ex. ASCII char '6' -> int 6



	for (int i = -1; i < count; i++)
	{
		if (i == -1)
		{
			fgetc(fr);
		}

		else
		{
			new_node = (struct movie*)malloc(sizeof(struct movie));

			if (head == NULL)
				head = new_node;
			else
				temp->next = new_node;


			fscanf(fr, "%[^\n]%*c", new_node->title);
			fscanf(fr, "%lf%*c", &(new_node->rating));

			temp = new_node;
			new_node->next = NULL;
		}
	}



	fclose(fr);

	printf("%d items read completed.\n\n\n", count);

	return head;
}

void file_write(struct movie* head)
{
	FILE* fw;

	char* file_name = (char*)malloc(MAX_LEN);

	printf("Please input filename to write and press [Enter].\n>> ");

	scanf("%s", file_name);

	if ((fw = fopen(file_name, "w")) == NULL)
	{
		printf("ERROR : Cannot Open File.");
		exit(1);
	}

	struct movie* search = head;

	int count = 0;

	while (search != NULL)
	{
		count++;
		search = search->next;
	}

	char ch = count + 48;

	for (int i = -1; i < count; i++) //fprintf ·Î ±¸ÇöÇÏ¸é ÈÎ¾À ½¬¿ï °Í
	{
		if (i == -1)
		{
			fputc(ch, fw);
			fputc('\n', fw);
		}

		else
		{
			fprintf(fw, "%s\n%.1lf\n", head->title, head->rating);
			head = head->next;
		}
	}

	printf("%d items write completed.\n\n\n", count);

	fclose(fw);

	return;
}

void print_movies(const struct movie* head)
{
	struct movie* search = head;

	int count = 0;

	while (search != NULL)
	{
		printf("%d : ", count);
		count++;

		print_a_movie(search);

		search = search->next;
	}

	printf("\n\n");

	return;
}

void print_a_movie(const struct movie* search)
{
	printf("\"%s\", %.1f\n", search->title, search->rating);
}

void search_movie(const struct movie* head)
{
	int check = -1;
	char movie_title[MAX_LEN];

	struct movie* search = head;

	printf("Input title to search and press enter.\n>> ");

	scanf("%[^\n]%*c", movie_title);

	while (search != NULL)
	{

		if (strcmp(movie_title, search->title) != 0)
		{
			check++;
			search = search->next;
		}
		else
		{
			check++;
			break;
		}
	}


	if (check != -1)
		print_a_movie(search);
	else
		printf("No movie found.\n");
}



void edit_item(const struct movie* movie)
{
	printf("\nInput a new title and press enter.\n>> ");

	while (scanf("%[^\n]%*c", movie->title) != 1)
		printf("\naYou made a wrong input\n");

	printf("\nInput a new rating and press enter.\n>> ");

	while (scanf("%lf", &(movie->rating)) != 1)
		printf("\nbYou made a wrong input\n");

	buf_clr();
}

void add_item(struct movie** head_ptr)
{
	struct movie* new_node = (struct movie*)malloc(sizeof(struct movie));

	struct movie* temp = *head_ptr;


	edit_item(new_node);

	new_node->next = NULL;

	if (*head_ptr != NULL)
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = new_node;
	}

	else
		*head_ptr = new_node;
}

void insert_item(struct movie* head, int index)
{
	struct movie* temp = search_index(head, index);

	struct movie* insert = search_index(head, index - 1);

	insert->next = NULL;

	add_item(head);

	(insert->next)->next = temp;

	return;
}

void delete_item(struct movie** head_ptr, int index)
{
	struct movie* temp;

	if (index != 0)
	{
		temp = search_index(*head_ptr, index);

		struct movie* before_deleted = search_index(*head_ptr, index - 1);

		before_deleted->next = temp->next;

		free(temp);
	}

	else
	{
		temp = *head_ptr;
		*head_ptr = (*head_ptr)->next;
		free(temp);
	}

	return;
}

void delete_all_items(struct movie** head_ptr)
{
	struct movie* node_free = *head_ptr;

	while ((*head_ptr) != NULL)
	{
		node_free = *head_ptr;
		*head_ptr = (*head_ptr)->next;
		free(node_free);
	}

	return;
}

struct movie* search_index(const struct movie* head, const int num)
{
	struct movie* temp = head;

	for (int i = 0; i < num; i++)
	{
		if (i == 0)
			temp = head->next;
		else
			temp = temp->next;

		if (temp == NULL)
		{
			printf("Error! You inputted a wrong index");
			return NULL;
		}
	}

	return temp;
}
