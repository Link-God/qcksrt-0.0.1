#include "stdafx.h"
#include < iostream>
#include <utility>
#include<sstream>
using namespace std;
void print(double * array, unsigned int size);

void q_sort(double * array,  int first,  int last)
{
	int left = first, right = last;
	double middle = array[(left + right) / 2];
	while (left <= right)
	{
		while (array[left] < middle) { left++; }
		while (array[right] > middle) { right--; }
		if (left <= right)
		{
			swap(array[left], array[right]);
			left++;
			right--;
		}
	}
	if (first < last)
	{
		q_sort(array, first, right); 
		q_sort(array, left, last); 
	}
}
bool read(double * array, unsigned int size)
{
	string mas;
	unsigned int i = 0, array_count = 0;
	getline(cin, mas);
	istringstream stream(mas);
	for (i; i < size; i++)
	{
		if (stream >> array[i])
		{
			array_count++;
		}
	}
	if (array_count == size && stream.eof()) return true;
	else return false;
}
void print(double * array, unsigned int size)
{
	for (unsigned int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
}
bool size_s(unsigned int &size)
{
	string str;
	getline(cin, str);
	istringstream stream(str);
	if (!(stream >> size))
	{
		return false;
	}
	else
	{
		if (stream.eof()) { return true; }
		else { return false; }
	}
}

int main()
{
	double * array;
	unsigned int size;
	if (size_s(size) && size>0)
	{
		array = new double[size];
		if (read(array, size))
		{
			q_sort(array, 0 ,size-1);
			print(array, size);
			cin.get();
		}
		else
		{
			cout << "fail input ";
			cin.get();
		}
		delete[] array;
	}
	else { cout << "size error"; cin.get(); }
	return 0;
}
