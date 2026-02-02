//4. Дан двумерный.В каждом столбце поменять местами первый отрицательный элемент и последний нулевой
// пример матрицы:
//1   3  -5
//0  -1   0
//-3  0   0 
//Пример ввода:
//3
//3
//1
//3
//-5
//0
//-1
//0
//-3
//0
//0


#include <iostream>
#include "Functions.h"
using namespace std;

void run_task4()
{
    int rows, cols;
    cin >> rows;
    cin >> cols;
    int** arr = new int* [rows];

    for (int i = 0; i < rows; i++)
        arr[i] = new int[cols];

    fill_array(arr, rows, cols);
    
    swap_first_neg_last_zero(arr, rows, cols);

    output_array(arr, rows, cols);

    delete_array(arr, rows, cols);

}

