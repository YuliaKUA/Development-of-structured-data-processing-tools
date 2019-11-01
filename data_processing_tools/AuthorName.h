#pragma once
#include <iostream>
#include <string>

using namespace std;
class AuthorName : public string
{
private:
	//<Буква> :: = а| |я a| |z
	bool isLetter(char** some_str);

	//<Заглавная буква> :: = A || Я A || Z
	bool isCapitalLetter(char** some_str);

	//<Слово> : : = <Буква>| |<Слово>
	bool isWord(char** some_str);

	//<ЗСлово> :: = <Заглавная буква> <Слово>
	bool isHeadWord(char** some_str);

	//<Фамилия> :: = <ЗСлово> | <ЗСлово>’ - ’<ЗСлово>
	bool isSername(char** some_str);

	//<ФИО> :: = <Фамилия> ‘_’<Заглавная буква>’.’<Заглавная буква>’.’
	//| <Фамилия> ‘_’<Заглавная буква>’.'
	bool isAuthorName(char** some_str);

	//Преобразовать string в массив char 
	bool stringToCharName(string str);

public:
	string authorName_;

	int numberOfLines_; // текущая строка в файле

	//Конструктор
	AuthorName();
	//Деструктор
	~AuthorName();

	//Устанавливаем номер текущей строки
	void setNumberOfLines(int numer);

	//Установить значение поля
	void setValue(string str);

	//Перегрузка оператора = !!!
	const AuthorName &operator = (const AuthorName &ob);
	//Перегрузка оператора вывода !!!
	friend ostream& operator << (ostream& out, AuthorName ob);
};