#pragma once

struct DinamicArray
{
	unsigned int length, capacity;
	int* data;
};

DinamicArray* create(int capacity = 0);
unsigned int getLength(const DinamicArray* arr);
unsigned int getCapacity(const DinamicArray* arr);
void add(DinamicArray* arr, int element);
void resize(DinamicArray* arr, unsigned int newSize);
void destroy(DinamicArray* &arr);
void print(DinamicArray* arr);