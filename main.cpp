#include <iostream>
#include "Dinamic Array.h"

int main()
{
	DinamicArray* arr = create(50);
	for (int i = 0; i < 100; i++)
		add(arr, i * 2);
	print(arr);
	destroy(arr);
	std::cout << arr;
	_CrtDumpMemoryLeaks();
}