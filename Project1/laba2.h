#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int counter = 0;
double auxiliary_variable = 0;
clock_t begin = 0, end = 0;

double make_random_number(double min_ch, double max_ch, int sid_variable)
{
	double random_number = 0;
	srand(clock() + sid_variable * 3452);
	random_number = (double)rand() * (max_ch - min_ch) / RAND_MAX + min_ch;
	return random_number;
}
void Bubble_Sort(double *array,int len_of_array)
{
    int counter = 0;
    int counter_2 = len_of_array - 2;
	for (counter = 0; counter < len_of_array - 1; counter++)
	{
		for (counter_2 = len_of_array - 2; counter_2 >= counter; counter_2--)
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
    for (counter = 1; counter < len_of_array; counter++)
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
void Choice_Sort(double *array, int len_of_array)
{
    int counter_2 = 0;
    double auxiliary_varibale_2 = 0;
    for (counter = 0; counter < len_of_array; counter++)
    {
        auxiliary_variable = counter;
        for (counter_2 = counter + 1; counter_2 < len_of_array; counter_2++)
        {
            if (array[counter_2] < array[counter])
            {
                auxiliary_variable = array[counter_2];
            }
        }
        if (auxiliary_variable != counter)
        {
            array[counter] = auxiliary_varibale_2;
            array[counter] = array[(int)auxiliary_variable];
            array[(int)auxiliary_variable] = auxiliary_varibale_2;
        }
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
void Merge_Sort(double *array, int len_of_array)
{
    int mid_of_array = len_of_array / 2; // находим середину сортируемой последовательности
    if (len_of_array % 2 == 1)
    {
       mid_of_array++;
    }
    int move = 1; // шаг
    // выделяем память под формируемую последовательность
    double *array_for_sequence = (double*)malloc(len_of_array * sizeof(double));
    int step;
    while (move < len_of_array)
    {
        step = move;
        int first_path_index = 0;   // индекс первого пути
        int second_path_index = mid_of_array; // индекс второго пути
        int element_index = 0;   // индекс элемента в результирующей последовательности
        while (step <= mid_of_array)
        {
            while ((first_path_index < step) && (second_path_index < len_of_array) && (second_path_index < (mid_of_array + step)))
            { // пока не дошли до конца пути
              // заполняем следующий элемент формируемой последовательности
              // меньшим из двух просматриваемых
                if (array[first_path_index] < array[second_path_index])
                {
                    array_for_sequence[element_index] = array[first_path_index];
                    first_path_index++; element_index++;
                }
                else {
                    array_for_sequence[element_index] = array[second_path_index];
                    second_path_index++; element_index++;
                }
            }
            while (first_path_index < step)
            { // переписываем оставшиеся элементы первого пути (если второй кончился раньше)
                array_for_sequence[element_index] = array[first_path_index];
                first_path_index++; element_index++;
            }
            while ((second_path_index < (mid_of_array + step)) && (second_path_index < len_of_array))
            {  // переписываем оставшиеся элементы второго пути (если первый кончился раньше)
                array_for_sequence[element_index] = array[second_path_index];
                second_path_index++; element_index++;
            }
            step = step + move; // переходим к следующему этапу
        }
        step = move * 2;
        // Переносим упорядоченную последовательность (промежуточный вариант) в исходный массив
        for (first_path_index = 0; first_path_index < len_of_array; first_path_index++)
        {
            array[first_path_index] = array_for_sequence[first_path_index];
        }
    }
}
void Shell_Sort(double* array, int len_of_array)
{
    int counter_2;
    for (int step = len_of_array / 2; step > 0; step /= 2)
    {
        for (counter = step; counter < len_of_array; counter += 1)
        {
            counter_2 = counter;
            while (counter_2 >= step && array[counter_2 - step] > array[counter])
            {
                auxiliary_variable = array[counter_2];
                array[counter_2] = array[counter_2 - step];
                array[counter_2 - step] = auxiliary_variable;
                counter_2 -= step;      
            }
        }
    }
}
