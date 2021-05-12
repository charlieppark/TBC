#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* read_maze(FILE*, int, int);
void print_maze(char*, int, int);
char* find_way(char*, int, int, int, int, char*);
char* find_another_way(char*, int, int, int, int, char*);


int main()
{
	FILE* fp = (FILE*)malloc(sizeof(FILE));
	
	fp = fopen("input.txt", "r");

	int N;

	while(fscanf(fp, "%d", &N) != 1) continue;
	
	for (int i = 0; i < N; i++)
	{
		printf("\n\ncase : %d\n", i);

		int row, col;

		while (fscanf(fp, "%d %d", &row, &col) != 2) continue;

		char* maze = (char*)malloc(sizeof(char) * row * col);

		maze = read_maze(fp, row, col);
		
		char* way = (char*)calloc(row * col, sizeof(char));

		char* copy_maze = (char*)calloc(row * col, sizeof(char));

		memcpy(copy_maze, maze, row * col);

		way = find_way(copy_maze, row, col, row, col, way);

		print_maze(way, row, col);

		free(copy_maze);
		free(maze);
		free(way);
	}

	fclose(fp);

	return 0;
}

char* read_maze(FILE* fp, int row, int col)
{
	char* maze = (char*)malloc(sizeof(char) * row * col);

	if (maze == NULL)
	{
		printf("malloc error");
		exit(1);
	}

	for (int j = 0; j < row; j++)
	{
		int temp_int;

		for (int k = 0; k < col; k++)
		{
			while (fscanf(fp, "%d", &temp_int) != 1) continue;

			*(maze + j * col + k) = temp_int;
		}
	}

	return maze;
}

void print_maze(char* maze, int row, int col)
{
	if (maze == NULL)
	{
		printf("NOWAY\n");
		return;
	}
	else
	{
		for (int j = 0; j < row; j++)
		{
			for (int k = 0; k < col; k++)
			{
				printf("%d", *(maze + j * col + k));
			}
			printf("\n");
		}
	}
}

char* find_way(char* maze, int cur_row, int cur_col, int row, int col, char* way)
{
	if (cur_row * cur_col == 1)
	{
		*maze = 2;
		return maze;
	}
	else
	{
		char* c_temp;

		while (1)
		{
			if ( (*(maze + 1) == 1) && (cur_col > 1) )
			{
				if ((c_temp = find_way(maze + 1, cur_row, cur_col - 1, row, col, way)) != NULL)
				{
					*maze = 2;
					return maze;
				}
				else
				{
					*(maze + 1)= 0;
				}

			}
			if (*(maze + col) == 1)
			{
				if ((c_temp = find_way(maze + col, cur_row - 1, cur_col, row, col, way)) != NULL)
				{
					*maze = 2;
					return maze;
				}
				else
				{
					*(maze + col) = 0;
				}
			}
			if ((*(maze - col) == 1) && (*(maze - col + 1) == 1) && (cur_col > 1))
			{
				if ((c_temp = find_way(maze - col, cur_row + 1, cur_col, row, col, way)) != NULL)
				{
					*maze = 2;
					return maze;
				}
				else
				{
					*(maze - col) = 0;
				}
			}

			return NULL;
		}
	}
}
char* find_another_way(char* maze, int cur_row, int cur_col, int row, int col, char* way)
{
	;
}