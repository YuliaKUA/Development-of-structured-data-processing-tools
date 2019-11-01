#include "СompositionName.h"
#include "Exception.h"
#include <iostream>
using namespace std;

//БНФ для Названия пьесы
//Возвращает true если конец массива
bool СompositionName::isEnd(char ** some_str) {
	if (**some_str == '\0') {
		return true;
	}
	return false;
}

//<Знак> :: = ‘.’ |’,’|’-’|’:’|’;’|’!’|’&’|’?’|’№’
bool СompositionName::isSign(char ** some_str) {
	if (**some_str == '.' || **some_str == ',' || **some_str == '-' || **some_str == ':'
		|| **some_str == ';' || **some_str == '!' || **some_str == '&'
		|| **some_str == '?' || **some_str == '№')
	{
		(*some_str)++;
		return true;
	}
	return false;
}

//<Цифра> :: = 0||9
bool СompositionName::isNumer(char ** some_str) {
	if (**some_str >= '0' && **some_str <= '9') {
		(*some_str)++;
		return true;
	}
	return false;
}

//<Число> :: = <Цифра>| |<Число>
bool СompositionName::isInteger(char ** some_str) {
	if (**some_str == ' ') {
		return true;
	}

	if (isNumer(some_str)) {
		isInteger(some_str);
		return true;
	}

	return false;
}

//<Заглавная буква> :: = A || Я A || Z
bool СompositionName::isCapitalLetter(char ** some_str) {
	if ((**some_str >= 'А' && **some_str <= 'Я')
		|| (**some_str >= 'A' && **some_str <= 'Z'))
	{
		(*some_str)++;
		return true;
	}
	return false;
}

//<Буква> :: = а| |я a| |z
bool СompositionName::isLetter(char ** some_str) {
	if ((**some_str >= 'a' && **some_str <= 'z')
		|| (**some_str >= 'а' && **some_str <= 'я'))
	{
		(*some_str)++;
		return true;
	}
	return false;
}

//<Слово> : := <Буква>| |<Слово>
bool СompositionName::isWord(char ** some_str) {
	if (**some_str == ' ') {
		return true;
	}

	if (isLetter(some_str)) {
		isWord(some_str);
		return true;
	}
	return false;
}

//<ЗСлово> :: = <Заглавная буква> <Слово>
bool СompositionName::isHeadWord(char** some_str) {
	if (isCapitalLetter(some_str)) {
		//cout << "test 0" << endl;
		if (isWord(some_str)) {
			//cout << "test 1" << endl;
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

//<Предложение> :: = <ЗСлово> | <ЗСлово> ‘_’<Знак> | <ЗСлово> ‘_’<Знак> ‘_’<Слово>
//| <ЗСлово>‘_’<Слово>| <Число>| <Число> ‘_’<Слово> | <Число> ‘_’<Знак>

bool СompositionName::isSentence(char ** some_str) {
	if (isInteger(some_str)) {
		if (**some_str == ' ') {
			(*some_str)++;
			if (isSign(some_str)) {
				return true;
			}
			else if (isWord(some_str)) {
				return true;
			}
			else if (isNumer(some_str)) {
				(*some_str)--;
				(*some_str)--;
				return true;
			}
			else
				return false;
		}
		else
			return true;
	}
	else if (isHeadWord(some_str)) {
		if (**some_str == ' ') {
			//cout << "test 5" << endl;
			(*some_str)++;
			if (isSign(some_str)) {
				//cout << "test 6" << endl;
				if (**some_str == ' ') {
					(*some_str)++;
					if (isWord(some_str)) {
						return true;
					}
					else if (isNumer(some_str)) {
						(*some_str)--;
						(*some_str)--;
						//cout << "test " << endl;
						return true;
					}
					else
						return false;
				}
				else
					return true;
			}
			else
				if (isWord(some_str)) {
					//cout << "test 3" << endl;
					return true;
				}
				else if (isNumer(some_str)) {
					//cout << "test 3" << endl;
					(*some_str)--;
					(*some_str)--;
					return true;
				}
				else {
					//cout << "!1" << endl;
					return false;
				}
		}
		else {
			//cout << "!2" << endl;
			return true;
		}
	}
	else {
		//cout << "!3" << endl;
		return false;
	}

}

//<Название пьесы> :: = ‘»’<Предложение>’»’| ‘»’<Предложение> ‘_’<Число>’»’

bool СompositionName::isCompositionName(char** some_str) {
	if (isSentence(some_str)) {
		if (**some_str == ' ') {
			(*some_str)++;
			if (isInteger(some_str)) {
				if (isEnd(some_str)) {
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		else if (isEnd(some_str))
			return true;
		else
			return false;

	}
	else
		return false;
}

//Преобразовать string в массив char и проверить БНФ
bool СompositionName::stringToCharComposition(string str) {
	int len = str.length() + 1;
	char *copyStr = new char[len];
	strcpy_s(copyStr, len, str.c_str());

	char* p = copyStr;
	char ** pCopy = &p;
	return isCompositionName(pCopy);
}

//Конструктор без параметров
СompositionName::СompositionName() :
	compositionName_(""),
	numberOfLines_(0) {}

//Деструктор
СompositionName::~СompositionName() {
}

//Установить значение поля
void СompositionName::setValue(string str) {
	try {
		string copyStr = str;
		copyStr.erase(copyStr.begin());
		copyStr.erase(copyStr.begin() + copyStr.length() - 1);

		if (copyStr.empty())
			throw ExceptionCompositionName(numberOfLines_,
				", пустая строка, название не задано");
		else if (str[0] != '"' && str[str.length() - 1] != '"')
			throw ExceptionCompositionName(numberOfLines_,
				", название композиции должно быть задано в кавычках");
		else if (!stringToCharComposition(copyStr))
			throw ExceptionCompositionName(numberOfLines_,
				", Неверно задано название композиции");
		else {
			compositionName_ = str;
		}
	}
	catch (ExceptionCompositionName &ex) {
		cerr << ex.getMsgLines() << ex.getNumberOfLines() << ex.getErrorMsg() << endl;
	}
}
//Устанавливаем номер текущей строки
void СompositionName::setNumberOfLines(int numer) {
	numberOfLines_ = numer;
}

//Перегрузка оператора =  !!!
const СompositionName & СompositionName::operator = (const СompositionName & ob) {
	// проверка на самоприсваивание
	if (&ob == this)
		return *this;
	else {
		this->compositionName_ = ob.compositionName_;
	}
	return *this;
}

//Перегрузка оператора вывода !!!
ostream & operator<<(ostream & out, СompositionName ob) {
	out << ob.compositionName_;
	return out;
}