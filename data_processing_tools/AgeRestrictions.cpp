#include "AgeRestrictions.h"
#include "Exception.h"

//БНФ возрастные ограничения
//<Знак> :: = ‘+’
bool AgeRestrictions::isSign(char ** some_str) {
	if (**some_str == '+') {
		(*some_str)++;
		return true;
	}
	return false;
}

//<Цифра> :: = 0 || 9
bool AgeRestrictions::isNumer(char ** some_str) {
	if (**some_str >= '0' && **some_str <= '9') {
		(*some_str)++;
		return true;
	}
	return false;
}

//<Целое число> :: = <Цифра>| |<Число>
bool AgeRestrictions::isInteger(char ** some_str) {
	if (isNumer(some_str)) {
		if (**some_str == '_')
			return true;
		if (isNumer(some_str)) {
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

//<Возрастные ограничения> :: = <Целое число>’_’<Знак>
bool AgeRestrictions::isAgeRestriction(char ** some_str) {
	if (isInteger(some_str)) {
		if (**some_str == '_') {
			(*some_str)++;
			if (isSign(some_str)) {
				return true;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

//Преобразовать string в массив char и проверить БНФ
//!!!?
bool AgeRestrictions::stringToCharRestrictions(string str) {
	int len = str.length() + 1;
	char *copyStr = new char[len];
	strcpy_s(copyStr, len, str.c_str());

	char* p = copyStr;
	char ** pCopy = &p;
	return isAgeRestriction(pCopy);
}

//Конструктор без параметров
AgeRestrictions::AgeRestrictions() :
	ageRestrictions_(""),
	numberOfLines_(0) {}

//Деструктор
AgeRestrictions::~AgeRestrictions() {
}

//Устанавливаем номер текущей строки
void AgeRestrictions::setNumberOfLines(int numer) {
	numberOfLines_ = numer;
}

//!!? вывод строки
//Установить значение поля
void AgeRestrictions::setValue(string str) {
	try {
		if (str.empty())
			throw ExceptionAgeRestrictions(numberOfLines_,
				", пустая строка, возрастные ограничения не заданы");
		else if (!stringToCharRestrictions(str))
			throw ExceptionAgeRestrictions(numberOfLines_,
				", Неверно заданы возрастные ограничения");
		else
			ageRestrictions_ = str;
	}
	catch (ExceptionAgeRestrictions &ex) {
		cerr << ex.getMsgLines() << ex.getNumberOfLines() << ex.getErrorMsg() << endl;
	}
}

//Перегрузка оператора = !!!
const AgeRestrictions & AgeRestrictions::operator=(const AgeRestrictions & ob) {
	// проверка на самоприсваивание
	if (&ob == this) return *this;
	else {
		ageRestrictions_ = ob.ageRestrictions_;
	}
	return *this;
}

//Перегрузка оператора вывода !!!
ostream & operator<<(ostream & out, AgeRestrictions ob) {
	out << ob.ageRestrictions_;
	return out;
}