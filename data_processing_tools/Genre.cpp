#include "Genre.h"
#include "Exception.h"

bool Genre::isEnd(char ** some_str) {
	if (**some_str == '\0') {
		return true;
	}
	return false;
}

//<�����> :: = �| |� a| |z
bool Genre::isLetter(char** some_str) {
	if ((**some_str >= 'a' && **some_str <= 'z')
		|| (**some_str >= '�' && **some_str <= '�'))
	{
		(*some_str)++;
		return true;
	}
	return false;
}

//<�����> : : = <�����>| |<�����>
bool Genre::isWord(char** some_str) {
	if (isLetter(some_str) && **some_str != '-') {
		isWord(some_str);
		return true;
	}
	return false;
}

//<����> ::= <�����> | <�����> �-� <�����>
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


//����������� ��� ����������
Genre::Genre() :
	genre_(""),
	numberOfLines_(0) {}

//����������
Genre::~Genre() {
}

//������������� ����� ������� ������
void Genre::setNumberOfLines(int numer) {
	numberOfLines_ = numer;
}

//������������� string � ������ char � ��������� ���
bool Genre::stringToCharGenre(string str) {
	int len = str.length() + 1;
	char *copyStr = new char[len];
	strcpy_s(copyStr, len, str.c_str());

	char* p = copyStr;
	char ** pCopy = &p;
	return isGenre(pCopy);
}

//���������� �������� ����
void Genre::setValue(string str) {
	try {
		if (str.empty())
			throw ExceptionGenre(numberOfLines_,
				", ������ ������, ���� �� �����");
		else if (!stringToCharGenre(str))
			throw ExceptionGenre(numberOfLines_,
				", ������� ����� ����");
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

//���������� ��������� =  !!!
const Genre & Genre::operator=(const Genre & ob) {
	// �������� �� ����������������
	if (&ob == this) return *this;
	else {
		genre_ = ob.genre_;
	}
	return *this;
}

//���������� ��������� ������ !!!
ostream & operator<<(ostream & out, Genre ob) {
	out << ob.genre_;
	return out;
}