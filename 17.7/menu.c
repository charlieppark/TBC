typedef enum {
	OPTION_SELECT,
	PRINT_ALL,
	PRINT_ONE,
	EDIT,
	ADD,
	INSERT,
	DELETE,
	DELETE_ALL,
	SAVE,
	SEARCH,
	QUIT
};

char* msg[] = {
	"Please select an option and press[Enter].",
	"Print all items\t",
	"Print an item",
	"Edit an item\t\t",
	"Add an item",
	"Insert an item\t"
	"Delete an item",
	"Delete all items\t"
	"Save file",
	"Search by name\t",
	"Quit"
}




void print_menu(const struct movie* head)
{
	int check = 1;

	struct movie* temp;

	while (check)
	{
		int choice = -1;

		int option = 0;

		printf("\n%s\n", msg[OPTION_SELECT]);
		printf("1. %s2. %s\n", msg[PRINT_ALL], msg[PRINT_ONE]);
		printf("3. %s4. %s\n", msg[EDIT], msg[ADD]);
		printf("5. %s6. %s\n", msg[INSERT], msg[DELETE]);
		printf("7. %s8. %s\n", msg[DELETE_ALL], msg[SAVE]);
		printf("9. %s10. %s\n\n>> ", msg[SEARCH], msg[QUIT]);

		while (scanf("%d", &option) != 1)
			printf("\nYou made a wrong input\n");

		buf_clr();

		printf("\n");

		switch (option)
		{
		case 1:
			print_movies(head);
			break;

		case 2:
			choice = input_index();
			temp = search_index(head, choice);

			if (temp != NULL)
				print_a_movie(temp);

			printf("\n\n");
			break;

		case 3:
			edit_member(head);
			printf("\n\n");
			break;

		case 4:
			add_item(&head);
			break;

		case 5:
			choice = input_index();
			insert_item(head, choice);
			break;

		case 6:
			choice = input_index();
			delete_item(&head, choice);
			break;

		case 7:
			delete_all_items(&head);
			break;

		case 8:
			file_write(head);
			break;

		case 9:
			search_movie(head);
			break;

		case 10:
			printf("\n\nG O O D B Y E\n\n");
			delete_all_items(&head); // to free all nodes
			free(head);
			exit(1);
			break;

		default:
			printf("You chose a wrong number.\n\n");
			break;
		}

	}
}

void edit_member(const struct movie* head)
{
	struct movie* temp;

	int index;

	index = input_index();

	temp = search_index(head, index);

	print_a_movie(temp);

	edit_item(temp);

	return;
}