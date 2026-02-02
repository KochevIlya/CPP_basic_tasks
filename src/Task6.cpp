//6. Определить координаты элемента, наиболее близкого к среднему значению всех элементов массива.
//1   2   3
//4   5   6
//7   8   9 
//Пример ввода:
//3
//3
//1
//2
//3
//4
//5
//6
//7
//8
//9



#include "Functions.h"
#include <iostream>
using namespace std;



void find_most_closest_with_average(int** arr, int rows, int cols, int& i_coordinate, int& j_coordinate)
{
    double average = find_average(arr, rows, cols);
    double current_closesed_distance = DBL_MAX;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (abs(arr[i][j] - average) < current_closesed_distance)
            {
                i_coordinate = i;
                j_coordinate = j;
                current_closesed_distance = abs(arr[i][j] - average);
            }
}

void run_task6()
{
    int rows, cols;
    cin >> rows;
    cin >> cols;

    int** arr = nullptr;
     
    initialize_array(arr, rows, cols);

    fill_array(arr, rows, cols);

    int i_result, j_result;

    find_most_closest_with_average(arr, rows, cols, i_result, j_result);

    output_array(arr, rows, cols);

    cout << "Average: " << find_average(arr, rows, cols) << "\n";
    cout << "Coordinate i: " << i_result << "\n";
    cout << "Coordinate j: " << j_result << "\n";

    delete_array(arr, rows, cols);
}

