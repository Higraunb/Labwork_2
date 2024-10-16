#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


double make_random_number(double min_ch, double max_ch, int sid_variable)
{
	double random_number = 0;
	srand(clock() + sid_variable * 3452);
	random_number = (double)rand() * (max_ch - min_ch) / RAND_MAX + min_ch;
	return random_number;
}
void Bubble_Sort(double *array,int len_of_array)
{
	double auxiliary_variable;
	for (int counter = 0; counter < len_of_array - 1; counter++)
	{
		for (int counter_2 = len_of_array - 2; counter_2 >= counter; counter_2--)
		{
			if (array[counter_2] > array[counter_2 + 1])
			{
				auxiliary_variable = array[counter_2];
				array[counter_2] = array[counter_2 + 1];
				array[counter_2 + 1] = auxiliary_variable;
			}
		}
	}
}
void Insertion_Sort(double *array, int len_of_array)
{
    double newElement;
	int location;
    for (int counter = 1; counter < len_of_array; counter++)
    {
        newElement = array[counter];
        location = counter - 1;
        while (location >= 0 && array[location] > newElement)
        {
            array[location + 1] = array[location];
            location = location - 1;
        }
        array[location + 1] = newElement;
    }
}
void Quick_Sort(double *array, int left, int right)
{
    double pivot; // разрешающий элемент
    int index; // индекс разрешающего элемента
    double l_hold = left; //левая граница
    double r_hold = right; // правая граница
    pivot = array[left];
    while (left < right) // пока границы не сомкнутся
    {
        while ((array[right] > pivot) && (left < right))
            right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
        if (left != right) // если границы не сомкнулись
        {
            array[left] = array[right]; // перемещаем элемент [right] на место разрешающего
            left++; // сдвигаем левую границу вправо
        }
        while ((array[left] < pivot) && (left < right))
            left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
        if (left != right) // если границы не сомкнулись
        {
            array[right] = array[left]; // перемещаем элемент [left] на место [right]
            right--; // сдвигаем правую границу влево
        }
    }
    array[left] = pivot; // ставим разрешающий элемент на место
    index = left;
    left = l_hold;
    right = r_hold;
    if (left < index) // Рекурсивно вызываем сортировку для левой и правой части массива
        Quick_Sort(array, left, index - 1);
    if (right > index)
        Quick_Sort(array, index + 1, right);
}

