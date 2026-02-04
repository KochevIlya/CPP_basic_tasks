#pragma once
#include <iostream>

template <typename T>
void initialize_array(T** &arr, const int rows, const int cols)
{
    arr = new T * [rows];
    for (int i = 0; i < rows; i++)
        arr[i] = new T[cols];
}

template <typename T>
void initialize_array(T*& arr, const int size)
{
    arr = new T[size];
}

template <typename T>
void delete_array(T** arr, const int rows, const int cols) {
    for (int i = 0; i < rows; i++) delete[] arr[i];
    delete[] arr;
}

void make_dictionary(char* str, char**& dictionary, int& count, const int SIZE);

double find_average(int** arr, int rows, int cols);

void fill_array(int** arr, int rows, int cols);

void fill_array(char* arr, int size);

void output_array(int** arr, int rows, int cols);

void swap_first_neg_last_zero(int** arr, int rows, int cols);
