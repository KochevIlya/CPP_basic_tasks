//12. Найти количество “счастливых” шестизначных билетиков на автобус.Счастливым билетик считается, если сумма первых трех цифр равна сумме второй тройки цифр.



#include "Functions.h"
using namespace std;


void run_task12()
{
	int MAX_SIZE = 1000000;
	int* arr = new int[MAX_SIZE];
	int index = 0;

	for (int i = 100000; i < 1000000; i++)
	{
		int first_left_letter = i / 100000;
		int second_left_letter = i / 10000 % 10;
		int third_left_letter = i / 1000 % 10;
		int first_right_letter = i % 10;
		int second_right_letter = i % 100 / 10;
		int third_right_letter = i % 1000 / 100;
		if (first_left_letter + second_left_letter + third_left_letter == first_right_letter + second_right_letter + third_right_letter)
			arr[index++] = i;
	}

	cout << "Result Array:\n";
	for (int i = 0; i < index; i++)
		cout << arr[i] << " ";
	



}