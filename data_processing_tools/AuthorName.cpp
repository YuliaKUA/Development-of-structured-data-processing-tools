#include "AuthorName.h"
#include "Exception.h"

//����������� ��� ����������
AuthorName::AuthorName() :
	authorName_(""),
	numberOfLines_(0) {}

//����������
AuthorName::~AuthorName() {
}
//������������� ����� ������� ������
void AuthorName::setNumberOfLines(int numer) {
	numberOfLines_ = numer;
}

//���
//<�����> :: = �| |� a| |z
bool AuthorName::isLetter(char** some_str) {
	if ((**some_str >= 'a' && **some_str <= 'z')
		|| (**some_str >= '�' && **some_str <= '�'))
	{
		(*some_str)++;
		return true;
	}
	return false;
}

//<��������� �����> :: = A || � A || Z
bool AuthorName::isCapitalLetter(char** some_str) {
	if ((**some_str >= '�' && **some_str <= '�')
		|| (**some_str >= 'A' && **some_str <= 'Z'))
	{
		(*some_str)++;
		return true;
	}
	return false;

}

//<�����> : : = <�����>| |<�����>
bool AuthorName::isWord(char** some_str) {
	if (isLetter(some_str)) {
		isWord(some_str);
		return true;
	}
	return false;
}

//<������> :: = <��������� �����> <�����>
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

//<�������> :: = <������>| <������>�-�<������>
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

//<���> :: = <�������> �_�<��������� �����>�.�<��������� �����>�.�
//| <�������> �_�<��������� �����>�.'
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

//������������� string � ������ char � ��������� ���
bool AuthorName::stringToCharName(string str) {
	int len = str.length() + 1;
	char *copyStr = new char[len];
	strcpy_s(copyStr, len, str.c_str());

	char* p = copyStr;
	char ** pCopy = &p;
	return isAuthorName(pCopy);
}

//���������� �������� ����
void AuthorName::setValue(string str) {
	try {
		if (str.empty())
			throw ExceptionAuthorName(numberOfLines_,
				", ������ ������, ��� ������ �� ������");
		else if (!stringToCharName(str))
			throw ExceptionAuthorName(numberOfLines_,
				", ������� ������ ��� ������");
		else
			authorName_ = str;
	}
	catch (ExceptionAuthorName &ex) {
		cerr << ex.getMsgLines() << ex.getNumberOfLines() << ex.getErrorMsg() << endl;
	}
}

//���������� ��������� =  !!!
const AuthorName & AuthorName::operator=(const AuthorName & ob) {
	// �������� �� ����������������
	if (&ob == this) return *this;
	else {
		authorName_ = ob.authorName_;
	}
	return *this;
}

//���������� ��������� ������ !!!
ostream & operator<<(ostream & out, AuthorName ob) {
	out << ob.authorName_;
	return out;
}