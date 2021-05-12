/*
  main.c
  <TBC>
  Created by Chan Ho Park on <20200830>.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "interface.h"

int main()
{

	struct movie* head = NULL;

	head = file_read(head);

	print_menu(head);

	return 0;
}