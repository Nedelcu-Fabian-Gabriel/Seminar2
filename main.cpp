#include <iostream>
#include "Dinamic Array.h"
void printIntiger(void* integer)
{
	std::cout << *(int*)integer;
}
int main()
{
	DinamicArray* arr = create(50);
	for (int i = 0; i < 100; i++)
	{
		int* element = (int*)malloc(sizeof(int));
		*element = i * 2;
		add(arr, (void*)element);
	}
	print(arr, printIntiger);
	destroy(arr);
	std::cout << arr;
	_CrtDumpMemoryLeaks();
}