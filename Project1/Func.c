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
  int pivot; // ����������� �������
  int index; // ������ ������������ ��������
  int l_hold = left; //����� �������
  int r_hold = right; // ������ �������
  pivot = array[left];
  while (left < right) // ���� ������� �� ���������
  {
    while ((array[right] > pivot) && (left < right))
      right--; // �������� ������ ������� ���� ������� [right] ������ [pivot]
    if (left != right) // ���� ������� �� ����������
    {
      array[left] = array[right]; // ���������� ������� [right] �� ����� ������������
      left++; // �������� ����� ������� ������
    }
    while ((array[left] < pivot) && (left < right))
      left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
    if (left != right) // ���� ������� �� ����������
    {
      array[right] = array[left]; // ���������� ������� [left] �� ����� [right]
      right--; // �������� ������ ������� �����
    }
  }
  array[left] = pivot; // ������ ����������� ������� �� �����
  index = left;
  left = l_hold;
  right = r_hold;
  if (left < index) // ���������� �������� ���������� ��� ����� � ������ ����� �������
    Quick_Sort(array, left, index - 1);
  if (right > index)
    Quick_Sort(array, index + 1, right);
}
void Merge_Sort(int* a, int l, int r)
{
  {
    if (l == r) return; // ������� ����������
    int mid = (l + r) / 2; // ���������� �������� ������������������
    // � ���������� �������� ������� ���������� ��� ������ ��������
    Merge_Sort(a, l, mid);
    Merge_Sort(a, mid + 1, r);
    int i = l;  // ������ ������� ����
    int j = mid + 1; // ������ ������� ����
    int* tmp = (int*)malloc(r * sizeof(int)); // �������������� ������
    for (int step = 0; step < r - l + 1; step++) // ��� ���� ��������� ��������������� �������
    {
      // ���������� � ����������� ������������������ ������� �� ��������� ���� �����
      // ��� ������� ������� ���� ���� j > r
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
    // ������������ �������������� ������������������ � �������� ������
    for (int step = 0; step < r - l + 1; step++)
      a[l + step] = tmp[step];
  }
}
void Shell_Sort(int* array, int len_of_array)
{
  /*��� ���������� ����� ������� ������������ � ����������� ����� ����� ��������,
  ������� ���� �� ������� �� ��������� ���������� d ����� ����� ���������
  ����������� ��� ��������� ������� �������� d, � ����������� ���������� �����
  ��������������� ��������� ��� d = 1 (�� ���� ������� ����������� ���������)*/
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

  //���������� ������������� �������� ������
  int maximum_element = 0;
  for (int i = 0; i < len_of_array; i++)
    if (array[i] > maximum_element)
      maximum_element = array[i];

  // ��������� ������ ��� �������
  int* countArray = (int*)calloc(maximum_element + 1, sizeof(int));

  // ������������� ������� �������� inputArray[] 
  // ��� ������ ������� countArray[]
  for (int i = 0; i < len_of_array; i++)
    countArray[array[i]]++;
  //���������� ����� �������� �� ������� �������
    // ������� countArray[]
  for (int i = 1; i <= maximum_element; i++)
    countArray[i] += countArray[i - 1];

  //�������� ��������� �������[] �� ������� countArray[]
  int* outputArray = (int*)malloc(len_of_array * sizeof(int));
  for (int i = len_of_array - 1; i >= 0; i--) {
    outputArray[countArray[array[i]] - 1] = array[i];
    countArray[array[i]]--;
  }

  // ����������� ��������������� ��������� ������� � inputArray[]
  for (int i = 0; i < len_of_array; i++)
    array[i] = outputArray[i];

  // ������������ ����������� ���������� ������
  free(countArray);
  free(outputArray);
}