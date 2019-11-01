#include "SplitString.h"
#include "Exception.h"
#include <iostream>
#include <string>
#include <fstream>

//Конструктор без параметров
SplitString::SplitString() :
	compositionName_(""),
	authorName_(""),
	genre_(""),
	audienceRating_(""),
	ageRestrictions_(""),
	successfulFlag_(1),
	numberOfLines_(0) {}

//Деструктор
SplitString::~SplitString() {
}

//Устанавливаем номер текущей строки
void SplitString::setNumberOfLines(int numer) {
	numberOfLines_ = numer;
}

//Функция проверяет количество данных в строке
//Строка должна содержать 5 слов разделенных 4 пробелами
bool SplitString::amountOfData(string some_str) {
	try {
		some_str += " ";
		string tmp;
		int begin = some_str.find('"', 0);

		if (some_str[0] != '"') {
			throw ExceptionSplitString(numberOfLines_,
				", название композиции должно быть задано в кавычках, разбиение строки невозможно");
		}

		int count = 0;
		int pos = some_str.find('"', begin + 1);
		if (pos > -1) {
			pos = some_str.find(' ', pos + 1);
		}

		if (some_str[0] == '"' && pos < 0)
			throw ExceptionSplitString(numberOfLines_,
				", не найдена 2 кавычка у названия, разбиение строки невозможно");

		while (pos > -1) {
			tmp.assign(some_str, begin, pos);
			if (!tmp.empty()) {
				count++;
			}
			tmp.clear();
			begin = pos;
			pos = some_str.find(' ', pos + 1);
		}
		if (count == 5) {
			return true;
		}
		else
			return false;
	}
	catch (ExceptionSplitString &ex) {
		cerr << ex.getMsgLines() << ex.getNumberOfLines() << ex.getErrorMsg() << endl;
		return false;
	}
}

//Функция разбивает строку на элементы
void SplitString::split(string some_str) {
	// в каждое поле копируем часть строки, разделенной пробелами
	try {
		if (!amountOfData(some_str)) {
			successfulFlag_ = 0;
			throw ExceptionSplitString(numberOfLines_,
				", некорректное количество данных для разбиения строки");
		}
		else {
			string tmp;
			if (some_str[0] == '"') {
				int begin = 1; //начало слова
				int end = some_str.find('"', begin); //конец слова

				if (end != -1) {

					//Выделяем название пьесы
					tmp.assign(some_str, 0, end + 1);
					compositionName_ = tmp;
					tmp.clear();
					end++;

					for (int i = 2; i < 6; i++) {
						begin = end + 1;
						end = some_str.find(' ', begin);

						tmp.assign(some_str, begin, end - begin);
						if (i == 2) //Выделяем имя автора
							authorName_ = tmp;
						else if (i == 3) //Выделяем жанр пьесы
							genre_ = tmp;
						else if (i == 4) //Выделяем зрительскую оценку
							audienceRating_ = tmp;
						else if (i == 5) //Выделяем возрастные ограничения
							ageRestrictions_ = tmp;
						tmp.clear();
					}
				}
				else {
					successfulFlag_ = 0;
					throw ExceptionSplitString(numberOfLines_,
						", не найдена 2 кавычка у названия, разбиение строки невозможно");
				}
			}
			else {
				successfulFlag_ = 0;
				throw ExceptionSplitString(numberOfLines_,
					", название композиции должно быть задано в кавычках, разбиение строки невозможно");

			}
		}
	}
	catch (ExceptionSplitString &ex) {
		cerr << ex.getMsgLines() << ex.getNumberOfLines() << ex.getErrorMsg() << endl;
	}
}

bool SplitString::isSuccessfulSplit() {
	return successfulFlag_;
}