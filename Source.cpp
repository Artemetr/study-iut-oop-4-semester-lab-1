#include "ArrayTemplateFunctionsLibrary.h"
#include <string>
#include <iostream>

using namespace std;

void main() {
	int length = 10;
	int* array = new int[length];
	fillArrayRandomValues(array, length);
	showArray(array, length);
	int* nullable_index_array = getArrayOfPredicatIndexElementsOfArray(array, length, [](int value) {return value == 0; });
	int nullable_index_array_length = getCountPredicatElementsOfArray(array, length, [](int value) {return value == 0; });
	int* negative_index_array = getArrayOfPredicatIndexElementsOfArray(array, length, [](int value) {return value < 0; });
	int negative_index_array_length = getCountPredicatElementsOfArray(array, length, [](int value) {return value < 0; });
	int count_nullable_after_negative = 0;
	for (int i = 0; i < nullable_index_array_length; i++) {
		if (iterationBinaryFindElementOfArrayByValue(negative_index_array, negative_index_array_length, nullable_index_array[i] - 1) != -1) {
			count_nullable_after_negative++;
		}
	}
	cout << count_nullable_after_negative << endl;

	int multiply = 1;
	for (int i = 0; i < negative_index_array[negative_index_array_length - 1]; i++) {
		multiply *= array[i];
	}
	cout << multiply << endl;
	system("pause");
}