// Пример ввода: 
//book apple hook bee hello never ever even heaven peace book with banana



#include "Functions.h"

void add_word_to_dictionary(char* word, char** pdict)
{
	char* pwordletter = word;
	char* pdictword = *pdict;
	pwordletter = word;

	while (*pwordletter != '\0')
	{
		*pdictword = *pwordletter;
		pwordletter++;
		pdictword++;
	}

	*pdictword = '\0';

}

void output_dictionary(char** dictionary, const int count_word)
{
	for (int i = 0; i < count_word; i++)
	{
		int j = 0;
		while (dictionary[i][j] != '\0')
		{
			std::cout << dictionary[i][j];
			j++;
		}
		std::cout << '\n';
	}
}

void make_dictionary(char* str, char**& dictionary, int& count, const int SIZE)
{

	count = 0;
	if (dictionary == nullptr)
		initialize_array(dictionary, SIZE);
	char* word = new char[SIZE];

	char** pdict = dictionary;

	char* pdictword = *pdict;
	char* pstrletter = str;
	char* pwordletter = word;

	while (*pstrletter != '\0')
	{
		*pwordletter = *pstrletter;

		if (*pstrletter == ' ')
		{
			*pwordletter = '\0';
			count++;
			add_word_to_dictionary(word, pdict);
			pwordletter = word;
			pdict++;
			pstrletter++;
			continue;
		}


		pwordletter++;
		pstrletter++;
	}

	count++;
	*pwordletter = '\0';
	add_word_to_dictionary(word, pdict);

}

// if first_word > second_word -> true
bool compare_words(char* first_word, char* second_word)
{
	char* pletter_first = first_word;
	char* pletter_second = second_word;

	while (*pletter_first != '\0')
	{
		if (*pletter_second == '\0')
			return true;
		if (*pletter_first > *pletter_second)
			return true;
		if (*pletter_first < *pletter_second)
			return false;
		pletter_second++;
		pletter_first++;
	}
}

void swap_words(char*& first_word, char*& second_word)
{
	char* temp;
	temp = second_word;
	second_word = first_word;
	first_word = temp;
}


void sort_dictionary(char** &dictionary, const int count_word, const int SIZE)
{
	

	for (int i = 0; i < count_word - 1; i++)
	{
		for (int j = 0; j < count_word - i - 1; j++)
		{
			if (compare_words(dictionary[j], dictionary[j + 1]))
			{
				swap_words(dictionary[j], dictionary[j + 1]);
			}
		}
	}

}


void run_WordAlphabet()
{

	char** dictionary;
	const int SIZE = 1000;

	initialize_array(dictionary, SIZE, SIZE);

	char* str;

	initialize_array(str, SIZE);

	fill_array(str, SIZE);

	int count_word = 0;

	make_dictionary(str, dictionary, count_word, SIZE);

	output_dictionary(dictionary, count_word);

	sort_dictionary(dictionary, count_word, SIZE);

	output_dictionary(dictionary, count_word);
}