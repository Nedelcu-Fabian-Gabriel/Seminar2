#include <iostream>
#include <cstdlib>
#include "Dinamic Array.h"

DinamicArray* create(int capacity)
{
	DinamicArray* arr = new DinamicArray;
	arr->length = 0;
	arr->capacity = capacity;
	arr->data = new int[capacity];
	return arr;
}
unsigned int getLength(const DinamicArray* arr)
{
	return arr->length;
}
unsigned int getCapacity(const DinamicArray* arr)
{
	return arr->capacity;
}
void add(DinamicArray* arr, int element)
{
	if (getLength(arr) == getCapacity(arr))
		resize(arr, arr->capacity * 2);
	arr->data[arr->length] = element;
	arr->length++;
}
void resize(DinamicArray* arr, unsigned int newSize)
{
	int* newData = new int[newSize];
	if (newData == nullptr)
		exit(-1);
	for (int i = 0; i < arr->length; i++)
		newData[i] = arr->data[i];

	delete[] arr->data;
	arr->data = newData;
}
void destroy(DinamicArray* &arr)
{
	delete[] arr->data;
	arr->data = nullptr;
	delete arr;
	arr = nullptr;
}
void print(DinamicArray* arr)
{
	for (int i = 0; i < arr->length; i++)
		std::cout << arr->data[i] << ' ';
	std::cout << '\n';
}