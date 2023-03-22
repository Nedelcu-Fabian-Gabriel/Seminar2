#include <iostream>
#include "Dinamic Array.h"
#include "Movie.h"

void printIntiger(void* integer)
{
	std::cout << *(int*)integer;
}
void printMovie(void* movie)
{
	std::cout << ((Movie*)movie)->name << " released in ";
	std::cout << ((Movie*)movie)->releaseDate << '\n';
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

	DinamicArray* movies = create(1);

	Movie m1{ 2000, "Shrek"  };
	Movie m2{ 2020, "C est la vie"  };
	Movie m3{ 2022, "Everything, everywhere"  };
	
	Movie* newMovie1 = (Movie*)malloc(sizeof(Movie));
	*newMovie1 = m1;
	add(movies, (void*)newMovie1);
	Movie* newMovie2 = (Movie*)malloc(sizeof(Movie));
	*newMovie2 = m2;
	add(movies, (void*)newMovie2);
	Movie* newMovie3 = (Movie*)malloc(sizeof(Movie));
	*newMovie3 = m3;
	add(movies, (void*)newMovie3);
	std::cout << "\n";
	print(movies, printMovie);

	_CrtDumpMemoryLeaks();
}