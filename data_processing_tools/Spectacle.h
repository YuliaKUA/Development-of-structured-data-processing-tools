#pragma once
#include <iostream>
#include <string>
#include "SplitString.h"

#include "СompositionName.h"
#include "AuthorName.h"
#include "Genre.h"
#include "AudienceRating.h"
#include "AgeRestrictions.h"

using namespace std;

class Spectacle : public string
{
public:
	int numberOfLines_; // текущая строка в файле

	СompositionName compositionName_;
	AuthorName authorName_;
	Genre genre_;
	AudienceRating audienceRating_;
	AgeRestrictions ageRestrictions_;

	//Конструктор без параметров
	Spectacle();
	//Конструктор с параметрами
	Spectacle(string compositionName, string authorName, string genre,
		string audienceRating, string ageRestrictions);
	//Деструктор
	~Spectacle();

	//Конструктор копирования
	Spectacle(const Spectacle & copy);

	//Устанавливаем номер текущей строки
	void setNumberOfLines(int numer);

	//Устанавливаем значения полей
	void setValues(string str);

	//Функция проверяет корректность данных
	bool isDefectiveSpectacle();

	//Перегрузка оператора =  !!!
	const Spectacle & operator = (const Spectacle & ob);

	//Перегрузка операторов отношений
	bool operator > (Spectacle &ob);
	bool operator < (Spectacle &ob);
	friend bool operator <= (const Spectacle &ob1, const Spectacle &ob2);
	friend bool operator == (const Spectacle &ob1, const Spectacle &ob2);

	//Перегрузка оператора вывода !!!
	friend ostream& operator << (ostream& out, Spectacle ob);
	//Перегрузка оператора ввода !!!
	friend istream& operator >> (istream& in, Spectacle &ob);

	//Перегрузка бинарных операций как метод и как друж функц
	friend Spectacle operator += (const Spectacle &ob1, const Spectacle &ob2);
	Spectacle operator += (const Spectacle &ob);

	//Перегрузка префиксного инкремента как метод
	Spectacle &operator ++();

	//Перегрузка постфиксного инкремента как друж функц
	//Spectacle &operator ++( int value);
	friend Spectacle &operator ++(Spectacle& ob, int);
};