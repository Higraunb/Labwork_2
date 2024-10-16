#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "laba2.h"
int main()
{
	FILE* file_of_numbers = 0;
	int count_of_numbers = 0, number_input_selection = 0;
	char Filename[10];
	double min_ch = 0, max_ch = 0, random_number = 0, entered_number = 1,s = 0 , *array_of_random_number = (double*)malloc(count_of_numbers * sizeof(double));
	printf("if you want to enter random numbers, enter 1, if you want to enter numbers from the keyboard, enter 2, if you want to enter numbers from a file, enter 3\n");
	scanf("%d", &number_input_selection);
	if (number_input_selection == 1)
	{
		printf("Enter the minimum number to generate: ");
		scanf("%lf", &min_ch);
		printf("Enter the maximum number to generate: ");
		scanf("%lf", &max_ch);
		printf("Enter the count of generated numbers: ");
		scanf("%d", &count_of_numbers);
		array_of_random_number = (double*)malloc(count_of_numbers * sizeof(double));
		if (array_of_random_number != NULL)
		{
			for (int counter = 0; counter < count_of_numbers; counter++)
			{
				array_of_random_number[counter] = make_random_number(min_ch, max_ch, counter);
			}
		}
		Bubble_Sort(array_of_random_number, count_of_numbers);
		for (int counter = 0; counter < count_of_numbers; counter++)
		{
			printf("%lg\n" , array_of_random_number[counter]);
		}
		printf("\n");
		Insertion_Sort(array_of_random_number, count_of_numbers);
		for (int counter = 0; counter < count_of_numbers; counter++)
		{
			printf("%lg\n", array_of_random_number[counter]);
		}
		printf("\n");
		Quick_Sort(array_of_random_number,0 , count_of_numbers - 1);
		for (int counter = 0; counter < count_of_numbers; counter++)
		{
			printf("%lg\n", array_of_random_number[counter]);
		}
	}
	else if (number_input_selection == 2)
	{
		printf("To finish entering, press 0\n");
		while (entered_number != 0)
		{
			scanf("%lg", &entered_number);
			if (entered_number == 0)
			{
				break;
			}
			if (entered_number != 0)
			{
				array_of_random_number = malloc(1000 * sizeof(double));
				*array_of_random_number = entered_number;
			}
			else
			{
				printf("Eror");
				return 1;
			}
		}
	}
	else if (number_input_selection == 3)
	{
		scanf("%s", &Filename);
		int fg = 0;
		file_of_numbers = fopen(Filename, "r");
		for (int i = 0; i < 4; i++)
		{
			fscanf(file_of_numbers, "%d", &fg);
			printf("%d", fg);
		}
	}
	else
	{
		printf("Eror");
		return 2;
	}
	free(array_of_random_number);
	return 0;
}
