//10. Дан массив, удалить все повторяющиеся элементы, оставив первый ввод этих элементов, получится массив из различных элементов(пример: был 0912264920, стал 091264)
//Пример ввода:
// 0912264920


#include "Functions.h"
using namespace std;

char* make_unique_array(char* str, const int MAX_SIZE)
{
	char* result_word = new char[MAX_SIZE];
	char* p_last_letter = result_word;
	char* p_current_letter_in_str = str;

	while (*p_current_letter_in_str != '\0')
	{
		char* p_letter_in_search = result_word;
		bool is_once = true;
		while (p_letter_in_search != p_last_letter)
		{
			if (*p_current_letter_in_str == *p_letter_in_search)
				is_once = false;
			p_letter_in_search++;
		}
		if (is_once)
		{
			*p_last_letter = *p_current_letter_in_str;
			p_last_letter++;
		}
		p_current_letter_in_str++;

	}
	*p_last_letter = '\0';
	return result_word;
}

void run_task10()
{
	const int MAX_SIZE = 1000;
	char* str;

	initialize_array(str, MAX_SIZE);
	
	fill_array(str, MAX_SIZE);

	char* result = make_unique_array(str, MAX_SIZE);

	std::cout << "Result: " << result;
}

