#include <iostream>
#include <cstdlib>
#include "Dinamic Array.h"

DinamicArray* create(int capacity)
{
	DinamicArray* arr = (DinamicArray*)malloc(sizeof(DinamicArray));
	arr->length = 0;
	arr->capacity = capacity;
	arr->data = (void**)malloc(capacity * sizeof(void*));
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
void add(DinamicArray* arr, void* element)
{
	if (getLength(arr) == getCapacity(arr))
		resize(arr, arr->capacity * 2);
	arr->data[arr->length] = element;
	arr->length++;
}
void resize(DinamicArray* arr, unsigned int newCapacity)
{
	void** newData = (void**)realloc(arr->data, newCapacity * sizeof(void*));
	arr->capacity = newCapacity;
	arr->data = newData;
}
void destroy(DinamicArray* &arr)
{
	//TODO: free memory for elements
	free(arr->data);
	arr->data = nullptr;
	free(arr);
	arr = nullptr;
}
void print(DinamicArray* arr, void(*printElement)(void*))
{
	for (int i = 0; i < arr->length; i++)
	{
		printElement(arr->data[i]);
		std::cout << ' ';
	}
	std::cout << '\n';
}