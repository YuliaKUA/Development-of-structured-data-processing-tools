#include "Genre.h"
#include "Exception.h"

bool Genre::isEnd(char ** some_str) {
	if (**some_str == '\0') {
		return true;
	}
	return false;
}

//<Буква> :: = а| |я a| |z
bool Genre::isLetter(char** some_str) {
	if ((**some_str >= 'a' && **some_str <= 'z')
		|| (**some_str >= 'а' && **some_str <= 'я'))
	{
		(*some_str)++;
		return true;
	}
	return false;
}

//<Слово> : : = <Буква>| |<Слово>
bool Genre::isWord(char** some_str) {
	if (isLetter(some_str) && **some_str != '-') {
		isWord(some_str);
		return true;
	}
	return false;
}

//<Жанр> ::= <Слово> | <Слово> ’-‘ <Слово>
bool Genre::isGenre(char** some_str) {
	if (isWord(some_str)) {
		if (**some_str == '-') {
			(*some_str)++;
			if (isWord(some_str)) {
				if (isEnd(some_str))
					return true;
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


//Конструктор без параметров
Genre::Genre() :
	genre_(""),
	numberOfLines_(0) {}

//Деструктор
Genre::~Genre() {
}

//Устанавливаем номер текущей строки
void Genre::setNumberOfLines(int numer) {
	numberOfLines_ = numer;
}

//Преобразовать string в массив char и проверить БНФ
bool Genre::stringToCharGenre(string str) {
	int len = str.length() + 1;
	char *copyStr = new char[len];
	strcpy_s(copyStr, len, str.c_str());

	char* p = copyStr;
	char ** pCopy = &p;
	return isGenre(pCopy);
}

//Установить значение поля
void Genre::setValue(string str) {
	try {
		if (str.empty())
			throw ExceptionGenre(numberOfLines_,
				", пустая строка, жанр не задан");
		else if (!stringToCharGenre(str))
			throw ExceptionGenre(numberOfLines_,
				", Неверно задан жанр");
		else
			genre_ = str;
	}
	catch (ExceptionGenre &ex) {
		cerr << ex.getMsgLines() << ex.getNumberOfLines() << ex.getErrorMsg() << endl;
	}
}

bool Genre::operator == (Genre & ob) {
	if (genre_ == ob.genre_) {
		return true;
	}
	else
		return false;
}

//Перегрузка оператора =  !!!
const Genre & Genre::operator=(const Genre & ob) {
	// проверка на самоприсваивание
	if (&ob == this) return *this;
	else {
		genre_ = ob.genre_;
	}
	return *this;
}

//Перегрузка оператора вывода !!!
ostream & operator<<(ostream & out, Genre ob) {
	out << ob.genre_;
	return out;
}