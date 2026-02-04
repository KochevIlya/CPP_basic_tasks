#include "Functions.h"
#include <iostream>

using namespace std;





double find_average(int** arr, int rows, int cols)
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            sum += arr[i][j];
    return (double)sum / (rows * cols);
}

void fill_array(int** arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> arr[i][j];
}

void fill_array(char* arr, int size)
{
    fgets(arr, size, stdin);
}


void output_array(int** arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << "\t";
        cout << "\n";
    }
}

void swap_first_neg_last_zero(int** arr, int rows, int cols)
{
    for (int j = 0; j < cols; j++)
    {
        int first_negative_index = -1;
        int last_zero_index = -1;
        for (int i = 0; i < rows; i++)
        {
            if (arr[i][j] < 0 && first_negative_index == -1)
                first_negative_index = i;
            else if (arr[i][j] == 0)
                last_zero_index = i;
        }
        if (first_negative_index != -1 && last_zero_index != -1)
        {
            int temp = arr[first_negative_index][j];
            arr[first_negative_index][j] = arr[last_zero_index][j];
            arr[last_zero_index][j] = temp;
        }
    }
}

