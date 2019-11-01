#pragma once
#include <iostream>
#include <string>

using namespace std;
class AgeRestrictions : public string
{
private:
	//БНФ
	//<Знак> :: = ‘+’
	bool isSign(char ** some_str);

	//<Цифра> :: = 0 || 9
	bool isNumer(char ** some_str);

	//<Целое число> :: = <Цифра>| |<Число>
	bool isInteger(char ** some_str);

	//<Возрастные ограничения> :: = <Целое число>’_’<Знак>
	bool isAgeRestriction(char ** some_str);

	//Преобразовать string в массив char и проверить БНФ
	bool stringToCharRestrictions(string str);

public:
	string ageRestrictions_;

	int numberOfLines_; // текущая строка в файле

	//Конструктор без параметров
	AgeRestrictions();
	//Деструктор
	~AgeRestrictions();

	//Устанавливаем номер текущей строки
	void setNumberOfLines(int numer);

	//Установить значение поля
	void setValue(string str);

	//Перегрузка оператора = !!!
	const AgeRestrictions &operator = (const AgeRestrictions &ob);
	//Перегрузка оператора вывода !!!
	friend ostream& operator << (ostream& out, AgeRestrictions ob);
};