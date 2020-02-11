#include "ArrayTemplateFunctionsLibrary.h"

template<typename T>
void flipflop(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

bool inLength(int length, int index)
{
	return (index >= 0 && index < length);
}

template<typename T>
bool sortingRule(T a, T b, string rule)
{
	return rule == "ASC" ? (a < b) : rule == "DESC" ? (b < a) : false;
}

template<typename T>
void fillArrayRandomValues(T* array, int& length)
{
	for (int i = 0; i < length; i++) {
		int rnd = 0;
		while (rnd == 0) {
			rnd = rand();
		}
		array[i] = (T) (1.0 * rand() / rnd);
	}
}

template<typename T>
void push(T*& array, int& length, int index, T value)
{
	if (!inLength(length, index)) {
		return;
	}

	T *tmp_array = new T[length + 1];

	for (int i = 0; i < index; i++) {
		tmp_array[i] = array[i];
	}

	tmp_array[index] = value;

	length++;

	for (int i = index + 1; i < length; i++) {
		tmp_array[i] = array[i - 1];
	}

	delete[] array;
	array = tmp_array;
}

template<typename T>
void pushBack(T*& array, int& length, T value)
{
	T* tmp_array = new T[length + 1];

	for (int i = 0; i < length; i++) {
		tmp_array[i] = array[i];
	}

	tmp_array[length] = value;

	length++;

	delete[] array;
	array = tmp_array;
}

template<typename T>
void bubbleSortArray(T* array, int length, string sorting_rule = "ASC")
{
	for (int i = 0; i < length; i++) {
		for (int j = length - 1; j > i; j--) {
			if (sortingRule(array[j - 1], array[j], sorting_rule)) {
				flipflop(array[j - 1], array[j]);
			}
		}
	}
}

template<typename T>
void shakerSortArray(T* array, int length, string sorting_rule = "ASC")
{
	int leftEnd = 1;
	int rightEnd = length - 1;
	while (leftEnd <= rightEnd) {
		for (int i = rightEnd; i >= leftEnd; i--) {
			if (sortingRule(array[i - 1], array[i], sorting_rule)) {
				flipflop(array[i - 1], array[i]);
			}
		}
		leftEnd++;

		for (int i = leftEnd; i <= rightEnd; i++) {
			if (sortingRule(array[i - 1], array[i], sorting_rule)) {
				flipflop(array[i - 1], array[i]);
			}
		}
		rightEnd--;
	}
}

template<typename T>
void insertionSortArray(T* array, int length, string sorting_rule)
{
	for (int i = 1; i < length; i++) {
		int tmp_i = i;
		for (int j = i - 1; j >= 0; j--) {
			if (sortingRule(array[i - 1], array[i], sorting_rule)) {
				flipflop(array[tmp_i], array[j]);
				tmp_i--;
			}
		}
	}
}

template<typename T>
void optimizedBubbleSortArray(T* array, int length, string sorting_rule)
{
	bool flipped;
	for (int i = 0; i < length; i++) {
		flipped = false;
		for (int j = length - 1; j > i; j--) {
			if (sortingRule(array[j - 1], array[j], sorting_rule)) {
				flipflop(array[j - 1], array[j]);
				fipped = true;
			}
		}
		if (!flipped) {
			return;
		}
	}
}
