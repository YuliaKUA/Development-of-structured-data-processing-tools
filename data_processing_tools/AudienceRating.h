#pragma once
#include <iostream>
#include <string>

using namespace std;
class AudienceRating : public string
{
private:
	//БНФ
	//Возвращает true если конец массива
	bool isEnd(char ** some_str);

	//<Цифра> :: = 0||9
	bool isNumer(char ** some_str);

	//<Число> :: = <Цифра>| |<Число>
	bool isInteger(char ** some_str);

	//<Оценка зрителей> :: = <целое число> ‘.’ <целое число>
	bool isAudienceRating(char** some_str);

	// Проверяет, что число в диапазоне (0, 10)
	bool isCorrectNumber(string some_str);

public:
	int numberOfLines_; // текущая строка в файле

	double audienceRating_;

	//Конструктор без параметров
	AudienceRating();
	//Деструктор
	~AudienceRating();

	//Устанавливаем номер текущей строки
	void setNumberOfLines(int numer);

	//Преобразовать string в массив char 
	//!!!?
	bool stringToCharRating(string str);

	//Установить значение поля
	void setValue(string str);

	//Перегрузка оператора = !!!
	const AudienceRating &operator = (const AudienceRating &ob);
	friend AudienceRating operator += (AudienceRating &ob1, AudienceRating &ob2);

	bool operator > (AudienceRating & ob);
	bool operator < (AudienceRating & ob);
	bool operator >= (AudienceRating & ob);
	bool operator == (AudienceRating & ob);
	//Перегрузка оператора вывода !!!
	friend ostream& operator << (ostream& out, AudienceRating ob);
};