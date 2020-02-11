#pragma once
#include <string>

using namespace std;

template<typename T>
void flipflop(T& a, T& b);

bool inLength(int length, int index);

template <typename T>
bool sortingRule(T a, T b, string rule);

template<typename T>
void fillArrayRandomValues(T* array, int& length);

template<typename T>
void push(T*& array, int& length, int index, T value);

template <typename T>
void pushBack(T*& array, int& length, T value);

//sort methods

template<typename T>
void bubbleSortArray(T* array, int length, string sorting_rule);

template<typename T>
void shakerSortArray(T* array, int length, string sorting_rule);

template<typename T>
void insertionSortArray(T* array, int length, string sorting_rule = "ASC");

template<typename T>
void optimizedBubbleSortArray(T* array, int length, string sorting_rule = "ASC");

