#pragma once
#include <iostream>
#include <string>
using namespace std;

class Genre : public string
{
private:
	bool isEnd(char ** some_str);

	//<Буква> :: = а| |я a| |z
	bool isLetter(char** some_str);

	//<Слово> : : = <Буква>| |<Слово>
	bool isWord(char** some_str);

	//<Жанр> ::= <Слово> | <Слово> ’-‘ <Слово>
	bool isGenre(char ** some_str);

public:
	string genre_;

	int numberOfLines_; // текущая строка в файле

	//Конструктор
	Genre();
	//Деструктор
	~Genre();

	//Устанавливаем номер текущей строки
	void setNumberOfLines(int numer);

	//Установить значение поля
	void setValue(string str);

	//Преобразовать string в массив char 
	bool stringToCharGenre(string str);


	bool operator == (Genre &ob);
	//Перегрузка оператора = !!!
	const Genre &operator = (const Genre &ob);
	//Перегрузка оператора вывода !!!
	friend ostream& operator << (ostream& out, Genre ob);
};