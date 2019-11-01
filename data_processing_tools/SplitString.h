// Только разбивает строку и устанавливает значения своих полей без проверки
#pragma once 
#include <iostream>
#include <string>
#include "СompositionName.h"

using namespace std;

class SplitString
{
public:
	int numberOfLines_; // текущая строка в файле
	bool successfulFlag_;

	string compositionName_;
	string authorName_;
	string genre_;
	string audienceRating_;
	string ageRestrictions_;

	//Конструктор без параметров
	SplitString();
	//Деструктор
	~SplitString();

	//Устанавливаем номер текущей строки
	void setNumberOfLines(int numer);

	//Функция проверяет количество данных в строке
	bool amountOfData(string some_str);
	//Функция разбивает строку на элементы
	void split(string some_str);

	bool isSuccessfulSplit();
};