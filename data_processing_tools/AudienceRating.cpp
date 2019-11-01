#include "AudienceRating.h"
#include "Exception.h"

//БНФ оценка зрителей

//Возвращает true если конец массива
bool AudienceRating::isEnd(char ** some_str) {
	if (**some_str == '\0') {
		return true;
	}
	return false;
}

//<Цифра> :: = 0||9
bool AudienceRating::isNumer(char ** some_str) {
	if (**some_str >= '0' && **some_str <= '9') {
		(*some_str)++;
		return true;
	}
	return false;
}

//<Число> :: = <Цифра>| |<Число>
bool AudienceRating::isInteger(char ** some_str) {
	if (**some_str != ',' && isNumer(some_str)) {
		isInteger(some_str);
		return true;
	}
	return false;
}

//<Оценка зрителей> :: = <целое число> ‘.’ <целое число>
bool AudienceRating::isAudienceRating(char** some_str) {
	if (isInteger(some_str)) {
		if (**some_str == ',') {
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
		else
			return false;
	}
	else
		return false;
}

// Проверяет, что число в диапазоне (0, 10)
bool AudienceRating::isCorrectNumber(string some_str) {
	double tmp = atof(some_str.c_str());
	if (tmp >= 0.0 && tmp <= 10.0) {
		return true;
	}
	else
		return false;
}

//Конструктор без параметров
AudienceRating::AudienceRating() :
	audienceRating_(-1),
	numberOfLines_(0) {}

//Деструктор
AudienceRating::~AudienceRating() {
}

//Устанавливаем номер текущей строки
void AudienceRating::setNumberOfLines(int numer) {
	numberOfLines_ = numer;
}

//Преобразовать string в массив char и проверить БНФ
//!!!?
bool AudienceRating::stringToCharRating(string str) {
	int len = str.length() + 1;
	char *copyStr = new char[len];
	strcpy_s(copyStr, len, str.c_str());

	char* p = copyStr;
	char ** pCopy = &p;
	return isAudienceRating(pCopy);
}

//!!? вывод строки
//Установить значение поля
void AudienceRating::setValue(string str) {
	try {
		if (str.empty())
			throw  ExceptionAudienceRating(numberOfLines_,
				", пустая строка, рейтинг не задан");
		else if (!stringToCharRating(str))
			throw  ExceptionAudienceRating(numberOfLines_,
				", Неверно задан рейтинг");
		else if (isCorrectNumber(str))
			audienceRating_ = atof(str.c_str());
		else
			throw  ExceptionAudienceRating(numberOfLines_,
				", рейтинг должен быть в диапазоне (0,0; 10,0)");
	}
	catch (ExceptionAudienceRating &ex) {
		cerr << ex.getMsgLines() << ex.getNumberOfLines() << ex.getErrorMsg() << endl;
	}
}

//Перегрузка оператора = !!!
const AudienceRating & AudienceRating::operator=(const AudienceRating & ob) {
	// проверка на самоприсваивание
	if (&ob == this) return *this;
	else {
		audienceRating_ = ob.audienceRating_;
	}
	return *this;
}

bool AudienceRating:: operator > (AudienceRating & ob) {
	if (audienceRating_ > ob.audienceRating_)
		return true;
	else
		return false;
}

bool AudienceRating::operator < (AudienceRating & ob) {
	if (audienceRating_ < ob.audienceRating_)
		return true;
	else
		return false;
}

bool AudienceRating::operator>=(AudienceRating & ob) {
	if (audienceRating_ >= ob.audienceRating_)
		return true;
	else
		return false;
}

bool AudienceRating::operator==(AudienceRating & ob) {
	if (audienceRating_ == ob.audienceRating_)
		return true;
	else
		return false;
}

AudienceRating operator+=(AudienceRating & ob1, AudienceRating & ob2) {
	ob1.audienceRating_ = ob1.audienceRating_ + ob2.audienceRating_;
	return ob1;
}

//Перегрузка оператора вывода !!!
ostream & operator<<(ostream & out, AudienceRating ob) {
	if (!fmod(ob.audienceRating_, 1) == 0) {
		out << ob.audienceRating_;
	}
	else
		out << ob.audienceRating_ << ".0";
	return out;
}