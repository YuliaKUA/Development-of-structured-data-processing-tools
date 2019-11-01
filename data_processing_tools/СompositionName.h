#pragma once
#include <iostream>
#include <string>

using namespace std;

class —ompositionName : public string
{
private:
	//¬озвращает true если конец массива
	bool isEnd(char ** some_str);

	//< «нак > :: = С.Т | Т, Т | Т - Т | Т : Т | Т; Т | Т!Т | Т & Т | Т ? Т | ТєТ
	bool isSign(char** some_str);

	//<÷ифра> :: = 0 || 9
	bool isNumer(char** some_str);

	//<„исло> :: = <÷ифра>| |<„исло>
	bool isInteger(char** some_str);

	//<«аглавна€ буква> :: = A || я A || Z
	bool isCapitalLetter(char** some_str);

	//<Ѕуква> :: = а| |€ a| |z
	bool isLetter(char** some_str);

	//<—лово> : : = <Ѕуква>| |<—лово>
	bool isWord(char** some_str);

	//<«—лово> :: = <«аглавна€ буква> <—лово>
	bool isHeadWord(char** some_str);

	//<ѕредложение> :: = <«—лово> | <«—лово> С_Т<«нак> | <«—лово> С_Т<«нак> С_Т<—лово>
	//| <«—лово>С_Т<—лово>| <„исло>| <„исло> С_Т<—лово> | <„исло> С_Т<«нак>
	bool isSentence(char** some_str);

	//<Ќазвание пьесы> :: = СїТ<ѕредложение>ТїТ| СїТ<ѕредложение> С_Т<„исло>ТїТ
	bool isCompositionName(char** some_str);

	//ѕреобразовать string в массив char и проверить ЅЌ‘
	bool stringToCharComposition(string str);

public:
	string compositionName_;

	int numberOfLines_; // текуща€ строка в файле

	// онструктор без параметров
	—ompositionName();
	//ƒеструктор
	~—ompositionName();

	//”становить значение пол€
	void setValue(string str);

	//”станавливаем номер текущей строки
	void setNumberOfLines(int numer);

	//ѕерегрузка оператора = !!!
	const —ompositionName &operator = (const —ompositionName &ob);
	//ѕерегрузка оператора вывода !!!
	friend ostream& operator << (ostream& out, —ompositionName ob);
};