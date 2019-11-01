#include "AuthorName.h"
#include "Exception.h"

//Конструктор без параметров
AuthorName::AuthorName() :
	authorName_(""),
	numberOfLines_(0) {}

//Деструктор
AuthorName::~AuthorName() {
}
//Устанавливаем номер текущей строки
void AuthorName::setNumberOfLines(int numer) {
	numberOfLines_ = numer;
}

//БНФ
//<Буква> :: = а| |я a| |z
bool AuthorName::isLetter(char** some_str) {
	if ((**some_str >= 'a' && **some_str <= 'z')
		|| (**some_str >= 'а' && **some_str <= 'я'))
	{
		(*some_str)++;
		return true;
	}
	return false;
}

//<Заглавная буква> :: = A || Я A || Z
bool AuthorName::isCapitalLetter(char** some_str) {
	if ((**some_str >= 'А' && **some_str <= 'Я')
		|| (**some_str >= 'A' && **some_str <= 'Z'))
	{
		(*some_str)++;
		return true;
	}
	return false;

}

//<Слово> : : = <Буква>| |<Слово>
bool AuthorName::isWord(char** some_str) {
	if (isLetter(some_str)) {
		isWord(some_str);
		return true;
	}
	return false;
}

//<ЗСлово> :: = <Заглавная буква> <Слово>
bool AuthorName::isHeadWord(char** some_str) {
	if (isCapitalLetter(some_str)) {
		if (**some_str != NULL && **some_str != '_' && **some_str != '-')
			return isWord(some_str);
		else
			return true;
	}
	else
		return false;
}

//<Фамилия> :: = <ЗСлово>| <ЗСлово>’-’<ЗСлово>
bool AuthorName::isSername(char** some_str) {
	if (isHeadWord(some_str)) {
		if (**some_str == '-') {
			(*some_str)++;
			if (isHeadWord(some_str))
				return true;
			else
				return false;
		}
		else
			return true;
	}
	else
		return false;
}

//<ФИО> :: = <Фамилия> ‘_’<Заглавная буква>’.’<Заглавная буква>’.’
//| <Фамилия> ‘_’<Заглавная буква>’.'
bool AuthorName::isAuthorName(char** some_str) {
	if (isSername(some_str)) {
		if (**some_str == '_') {
			(*some_str)++;
			if (isCapitalLetter(some_str)) {
				if (**some_str == '.') {
					(*some_str)++;
					if (isCapitalLetter(some_str)) {
						if (**some_str == '.') {
							(*some_str)++;
							if (**some_str == NULL)
								return true;
							else
								return false;
						}
						else
							return false;
					}
					else if (**some_str == NULL)
						return true;
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
	else
		return false;
}

//Преобразовать string в массив char и проверить БНФ
bool AuthorName::stringToCharName(string str) {
	int len = str.length() + 1;
	char *copyStr = new char[len];
	strcpy_s(copyStr, len, str.c_str());

	char* p = copyStr;
	char ** pCopy = &p;
	return isAuthorName(pCopy);
}

//Установить значение поля
void AuthorName::setValue(string str) {
	try {
		if (str.empty())
			throw ExceptionAuthorName(numberOfLines_,
				", пустая строка, имя автора не задано");
		else if (!stringToCharName(str))
			throw ExceptionAuthorName(numberOfLines_,
				", Неверно задано имя автора");
		else
			authorName_ = str;
	}
	catch (ExceptionAuthorName &ex) {
		cerr << ex.getMsgLines() << ex.getNumberOfLines() << ex.getErrorMsg() << endl;
	}
}

//Перегрузка оператора =  !!!
const AuthorName & AuthorName::operator=(const AuthorName & ob) {
	// проверка на самоприсваивание
	if (&ob == this) return *this;
	else {
		authorName_ = ob.authorName_;
	}
	return *this;
}

//Перегрузка оператора вывода !!!
ostream & operator<<(ostream & out, AuthorName ob) {
	out << ob.authorName_;
	return out;
}