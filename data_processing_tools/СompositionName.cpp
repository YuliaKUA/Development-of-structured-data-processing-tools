#include "�ompositionName.h"
#include "Exception.h"
#include <iostream>
using namespace std;

//��� ��� �������� �����
//���������� true ���� ����� �������
bool �ompositionName::isEnd(char ** some_str) {
	if (**some_str == '\0') {
		return true;
	}
	return false;
}

//<����> :: = �.� |�,�|�-�|�:�|�;�|�!�|�&�|�?�|���
bool �ompositionName::isSign(char ** some_str) {
	if (**some_str == '.' || **some_str == ',' || **some_str == '-' || **some_str == ':'
		|| **some_str == ';' || **some_str == '!' || **some_str == '&'
		|| **some_str == '?' || **some_str == '�')
	{
		(*some_str)++;
		return true;
	}
	return false;
}

//<�����> :: = 0||9
bool �ompositionName::isNumer(char ** some_str) {
	if (**some_str >= '0' && **some_str <= '9') {
		(*some_str)++;
		return true;
	}
	return false;
}

//<�����> :: = <�����>| |<�����>
bool �ompositionName::isInteger(char ** some_str) {
	if (**some_str == ' ') {
		return true;
	}

	if (isNumer(some_str)) {
		isInteger(some_str);
		return true;
	}

	return false;
}

//<��������� �����> :: = A || � A || Z
bool �ompositionName::isCapitalLetter(char ** some_str) {
	if ((**some_str >= '�' && **some_str <= '�')
		|| (**some_str >= 'A' && **some_str <= 'Z'))
	{
		(*some_str)++;
		return true;
	}
	return false;
}

//<�����> :: = �| |� a| |z
bool �ompositionName::isLetter(char ** some_str) {
	if ((**some_str >= 'a' && **some_str <= 'z')
		|| (**some_str >= '�' && **some_str <= '�'))
	{
		(*some_str)++;
		return true;
	}
	return false;
}

//<�����> : := <�����>| |<�����>
bool �ompositionName::isWord(char ** some_str) {
	if (**some_str == ' ') {
		return true;
	}

	if (isLetter(some_str)) {
		isWord(some_str);
		return true;
	}
	return false;
}

//<������> :: = <��������� �����> <�����>
bool �ompositionName::isHeadWord(char** some_str) {
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

//<�����������> :: = <������> | <������> �_�<����> | <������> �_�<����> �_�<�����>
//| <������>�_�<�����>| <�����>| <�����> �_�<�����> | <�����> �_�<����>

bool �ompositionName::isSentence(char ** some_str) {
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

//<�������� �����> :: = ���<�����������>���| ���<�����������> �_�<�����>���

bool �ompositionName::isCompositionName(char** some_str) {
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

//������������� string � ������ char � ��������� ���
bool �ompositionName::stringToCharComposition(string str) {
	int len = str.length() + 1;
	char *copyStr = new char[len];
	strcpy_s(copyStr, len, str.c_str());

	char* p = copyStr;
	char ** pCopy = &p;
	return isCompositionName(pCopy);
}

//����������� ��� ����������
�ompositionName::�ompositionName() :
	compositionName_(""),
	numberOfLines_(0) {}

//����������
�ompositionName::~�ompositionName() {
}

//���������� �������� ����
void �ompositionName::setValue(string str) {
	try {
		string copyStr = str;
		copyStr.erase(copyStr.begin());
		copyStr.erase(copyStr.begin() + copyStr.length() - 1);

		if (copyStr.empty())
			throw ExceptionCompositionName(numberOfLines_,
				", ������ ������, �������� �� ������");
		else if (str[0] != '"' && str[str.length() - 1] != '"')
			throw ExceptionCompositionName(numberOfLines_,
				", �������� ���������� ������ ���� ������ � ��������");
		else if (!stringToCharComposition(copyStr))
			throw ExceptionCompositionName(numberOfLines_,
				", ������� ������ �������� ����������");
		else {
			compositionName_ = str;
		}
	}
	catch (ExceptionCompositionName &ex) {
		cerr << ex.getMsgLines() << ex.getNumberOfLines() << ex.getErrorMsg() << endl;
	}
}
//������������� ����� ������� ������
void �ompositionName::setNumberOfLines(int numer) {
	numberOfLines_ = numer;
}

//���������� ��������� =  !!!
const �ompositionName & �ompositionName::operator = (const �ompositionName & ob) {
	// �������� �� ����������������
	if (&ob == this)
		return *this;
	else {
		this->compositionName_ = ob.compositionName_;
	}
	return *this;
}

//���������� ��������� ������ !!!
ostream & operator<<(ostream & out, �ompositionName ob) {
	out << ob.compositionName_;
	return out;
}