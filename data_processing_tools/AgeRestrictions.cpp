#include "AgeRestrictions.h"
#include "Exception.h"

//��� ���������� �����������
//<����> :: = �+�
bool AgeRestrictions::isSign(char ** some_str) {
	if (**some_str == '+') {
		(*some_str)++;
		return true;
	}
	return false;
}

//<�����> :: = 0 || 9
bool AgeRestrictions::isNumer(char ** some_str) {
	if (**some_str >= '0' && **some_str <= '9') {
		(*some_str)++;
		return true;
	}
	return false;
}

//<����� �����> :: = <�����>| |<�����>
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

//<���������� �����������> :: = <����� �����>�_�<����>
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

//������������� string � ������ char � ��������� ���
//!!!?
bool AgeRestrictions::stringToCharRestrictions(string str) {
	int len = str.length() + 1;
	char *copyStr = new char[len];
	strcpy_s(copyStr, len, str.c_str());

	char* p = copyStr;
	char ** pCopy = &p;
	return isAgeRestriction(pCopy);
}

//����������� ��� ����������
AgeRestrictions::AgeRestrictions() :
	ageRestrictions_(""),
	numberOfLines_(0) {}

//����������
AgeRestrictions::~AgeRestrictions() {
}

//������������� ����� ������� ������
void AgeRestrictions::setNumberOfLines(int numer) {
	numberOfLines_ = numer;
}

//!!? ����� ������
//���������� �������� ����
void AgeRestrictions::setValue(string str) {
	try {
		if (str.empty())
			throw ExceptionAgeRestrictions(numberOfLines_,
				", ������ ������, ���������� ����������� �� ������");
		else if (!stringToCharRestrictions(str))
			throw ExceptionAgeRestrictions(numberOfLines_,
				", ������� ������ ���������� �����������");
		else
			ageRestrictions_ = str;
	}
	catch (ExceptionAgeRestrictions &ex) {
		cerr << ex.getMsgLines() << ex.getNumberOfLines() << ex.getErrorMsg() << endl;
	}
}

//���������� ��������� = !!!
const AgeRestrictions & AgeRestrictions::operator=(const AgeRestrictions & ob) {
	// �������� �� ����������������
	if (&ob == this) return *this;
	else {
		ageRestrictions_ = ob.ageRestrictions_;
	}
	return *this;
}

//���������� ��������� ������ !!!
ostream & operator<<(ostream & out, AgeRestrictions ob) {
	out << ob.ageRestrictions_;
	return out;
}