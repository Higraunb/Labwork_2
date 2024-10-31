#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int counter = 0, counter_2 = 0;
int auxiliary_variable = 0;

int make_random_number(int min_ch, int max_ch, int sid_variable)
{
  int random_number = 0;
  srand(clock() + sid_variable * 3452);
  random_number = (int)rand() * (max_ch - min_ch) / RAND_MAX + min_ch;
  return random_number;
}
void Bubble_Sort(int* array, int len_of_array)
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
void Insertion_Sort(int* array, int len_of_array)
{
  int newElement;
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
void Choice_Sort(int* array, int len_of_array)
{
  int counter_2 = 0;
  int auxiliary_varibale_2 = 0;
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
void Quick_Sort(int* array, int left, int right)
{
  int pivot; // разрешающий элемент
  int index; // индекс разрешающего элемента
  int l_hold = left; //левая граница
  int r_hold = right; // правая граница
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
void Merge_Sort(int* a, int l, int r)
{
  {
    if (l == r) return; // границы сомкнулись
    int mid = (l + r) / 2; // определяем середину последовательности
    // и рекурсивно вызываем функцию сортировки для каждой половины
    Merge_Sort(a, l, mid);
    Merge_Sort(a, mid + 1, r);
    int i = l;  // начало первого пути
    int j = mid + 1; // начало второго пути
    int* tmp = (int*)malloc(r * sizeof(int)); // дополнительный массив
    for (int step = 0; step < r - l + 1; step++) // для всех элементов дополнительного массива
    {
      // записываем в формируемую последовательность меньший из элементов двух путей
      // или остаток первого пути если j > r
      if ((j > r) || ((i <= mid) && (a[i] < a[j])))
      {
        tmp[step] = a[i];
        i++;
      }
      else
      {
        tmp[step] = a[j];
        j++;
      }
    }
    // переписываем сформированную последовательность в исходный массив
    for (int step = 0; step < r - l + 1; step++)
      a[l + step] = tmp[step];
  }
}
void Shell_Sort(int* array, int len_of_array)
{
  /*При сортировке Шелла сначала сравниваются и сортируются между собой значения,
  стоящие один от другого на некотором расстоянии d После этого процедура
  повторяется для некоторых меньших значений d, а завершается сортировка Шелла
  упорядочиванием элементов при d = 1 (то есть обычной сортировкой вставками)*/
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
void Count_Sort(int *array, int len_of_array)
{

  //Нахождение максимального элемента массив
  int maximum_element = 0;
  for (int i = 0; i < len_of_array; i++)
    if (array[i] > maximum_element)
      maximum_element = array[i];

  // Выделение памяти для Массива
  int* countArray = (int*)calloc(maximum_element + 1, sizeof(int));

  // Сопоставление каждого элемента inputArray[] 
  // как индекс массива countArray[]
  for (int i = 0; i < len_of_array; i++)
    countArray[array[i]]++;
  //Вычисление суммы префикса по каждому индексу
    // массива countArray[]
  for (int i = 1; i <= maximum_element; i++)
    countArray[i] += countArray[i - 1];

  //Создание выходного массива[] из массива countArray[]
  int* outputArray = (int*)malloc(len_of_array * sizeof(int));
  for (int i = len_of_array - 1; i >= 0; i--) {
    outputArray[countArray[array[i]] - 1] = array[i];
    countArray[array[i]]--;
  }

  // Копирование отсортированных элементов обратно в inputArray[]
  for (int i = 0; i < len_of_array; i++)
    array[i] = outputArray[i];

  // Освобождение динамически выделяемой памяти
  free(countArray);
  free(outputArray);
}