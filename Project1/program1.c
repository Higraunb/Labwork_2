#define _CRT_SECURE_NO_WARNINGS
#define __GOT_SECURE_LIB__
#define CLOCK_PER_SEC
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "laba2.h"
int main()
{

	FILE* file_of_numbers = 0;
	int count_of_numbers = 0, number_input_selection = 0, user_selection_sort = 0,
		user_selection = 0, size_of_file = 0, user_selection_reset = 0;
	char Filename[10];
	double min_ch = 0, max_ch = 0, random_number = 0, entered_number = 1, s = 0,
		* array_of_number = 0, time_spend = 0.0;
back:
	printf("if you want to enter random numbers, enter 1\nif you want to "
		"enter numbers from the keyboard, enter 2\nif you want to enter numbers from a file, enter 3\n");
	scanf("%d", &number_input_selection);
	if (number_input_selection == 1)
	{
		printf("Enter the minimum number to generate: ");
		scanf("%lf", &min_ch);
		printf("Enter the maximum number to generate: ");
		scanf("%lf", &max_ch);
		printf("Enter the count of generated numbers: ");
		scanf("%d", &count_of_numbers);
		array_of_number = (double*)malloc(count_of_numbers * sizeof(double));
		if (array_of_number != NULL)
		{
			for (int counter = 0; counter < count_of_numbers; counter++)
			{
				array_of_number[counter] = make_random_number(min_ch, max_ch, counter);
			}
		}
	}
	else if (number_input_selection == 2)
	{
		count_of_numbers = 0;
		array_of_number = (double*)malloc(100000 * sizeof(double));
		printf("Enter numbers, To finish entering, press 0\n");
		while (entered_number != 0)
		{
			scanf("%lg", &entered_number);
			if (entered_number == 0)
			{
				break;
			}
			if (entered_number != 0)
			{
				array_of_number[count_of_numbers] = entered_number;
				count_of_numbers++;
			}
			else
			{
				printf("Eror\n");
				return 1;
			}
		}
	}
	else if (number_input_selection == 3)
	{
		printf("Enter file name\n");
		scanf("%s", &Filename);
		file_of_numbers = fopen(Filename, "r");
		fseek(file_of_numbers, 0, SEEK_END);
		size_of_file = ftell(file_of_numbers);
		array_of_number = (double*)malloc(size_of_file * sizeof(double));
		for (counter = 0; counter < size_of_file; counter++)
		{
			fscanf(file_of_numbers, "%lg", array_of_number[counter]);
		}
		count_of_numbers = size_of_file;
		fclose(file_of_numbers);
	}
	else
	{
		printf("Eror\n");
		return 2;
	}
while (user_selection_reset == 0)
{
printf("if you want to print an array press 1\n"
	"if you want to sort the array press 2\n"
	"if you want to go back to the beginning press 3\n"
	"if you want to exit the program press 4\n");
	scanf("%d", &user_selection);
	if (user_selection == 1)
	{
		for (counter = 0; counter < count_of_numbers; counter++)
		{
			printf("%lg\n", array_of_number[counter]);
		}
	}
	else if (user_selection == 2)
	{
		printf("choose which sort to perform - \n Bubble_Sort - 1\n Choice_Sort - 2\n, "
			"Insertion_Sort - 3\n Merge_Sort - 4\n Quick_Sort - 5\n Shell_Sort - 6\n подсчетом - 7\n");
		user_selection = 0;
		scanf("%d", &user_selection_sort);

		if (user_selection_sort == 1)
		{
			time_spend = 0.0;
			begin = clock();
			Bubble_Sort(array_of_number, count_of_numbers);
			end = clock();
			time_spend += (double)(end - begin) / CLOCKS_PER_SEC;
			printf("%lg\n", time_spend);
		}
		else if (user_selection_sort == 2)
		{
			time_spend = 0.0;
			begin = clock();
			Choice_Sort(array_of_number, count_of_numbers);
			end = clock();
			time_spend += (double)(end - begin) / CLOCKS_PER_SEC;
			printf("%lg\n", time_spend);
		}
		else if (user_selection_sort == 3)
		{
			time_spend = 0.0;
			begin = clock();
			Insertion_Sort(array_of_number, count_of_numbers);
			end = clock();
			time_spend += (double)(end - begin) / CLOCKS_PER_SEC;
			printf("%lg\n", time_spend);
		}
		else if (user_selection_sort == 4)
		{
			time_spend = 0.0;
			begin = clock();
			Merge_Sort(array_of_number, count_of_numbers);
			end = clock();
			time_spend += (double)(end - begin) / CLOCKS_PER_SEC;
			printf("%lg\n", time_spend);
		}
		else if (user_selection_sort == 5)
		{
			time_spend = 0.0;
			begin = clock();
			Quick_Sort(array_of_number, array_of_number[1], array_of_number[count_of_numbers]);
			end = clock();
			time_spend += (double)(end - begin) / CLOCKS_PER_SEC;
			printf("%lg\n", time_spend);
		}
		else if (user_selection_sort == 6)
		{
			time_spend = 0.0;
			begin = clock();
			Shell_Sort(array_of_number, count_of_numbers);
			end = clock();
			time_spend += (double)(end - begin) / CLOCKS_PER_SEC;
			printf("%lg\n", time_spend);
		}
		else
			printf("Eror\n");
	}
	else if (user_selection == 3)
	{
		goto back;
	}
	else if (user_selection == 4)
	{
		break;
	}
}
	free(array_of_number);
	return 0;
}
