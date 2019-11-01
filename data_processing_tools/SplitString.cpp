#include "SplitString.h"
#include "Exception.h"
#include <iostream>
#include <string>
#include <fstream>

//����������� ��� ����������
SplitString::SplitString() :
	compositionName_(""),
	authorName_(""),
	genre_(""),
	audienceRating_(""),
	ageRestrictions_(""),
	successfulFlag_(1),
	numberOfLines_(0) {}

//����������
SplitString::~SplitString() {
}

//������������� ����� ������� ������
void SplitString::setNumberOfLines(int numer) {
	numberOfLines_ = numer;
}

//������� ��������� ���������� ������ � ������
//������ ������ ��������� 5 ���� ����������� 4 ���������
bool SplitString::amountOfData(string some_str) {
	try {
		some_str += " ";
		string tmp;
		int begin = some_str.find('"', 0);

		if (some_str[0] != '"') {
			throw ExceptionSplitString(numberOfLines_,
				", �������� ���������� ������ ���� ������ � ��������, ��������� ������ ����������");
		}

		int count = 0;
		int pos = some_str.find('"', begin + 1);
		if (pos > -1) {
			pos = some_str.find(' ', pos + 1);
		}

		if (some_str[0] == '"' && pos < 0)
			throw ExceptionSplitString(numberOfLines_,
				", �� ������� 2 ������� � ��������, ��������� ������ ����������");

		while (pos > -1) {
			tmp.assign(some_str, begin, pos);
			if (!tmp.empty()) {
				count++;
			}
			tmp.clear();
			begin = pos;
			pos = some_str.find(' ', pos + 1);
		}
		if (count == 5) {
			return true;
		}
		else
			return false;
	}
	catch (ExceptionSplitString &ex) {
		cerr << ex.getMsgLines() << ex.getNumberOfLines() << ex.getErrorMsg() << endl;
		return false;
	}
}

//������� ��������� ������ �� ��������
void SplitString::split(string some_str) {
	// � ������ ���� �������� ����� ������, ����������� ���������
	try {
		if (!amountOfData(some_str)) {
			successfulFlag_ = 0;
			throw ExceptionSplitString(numberOfLines_,
				", ������������ ���������� ������ ��� ��������� ������");
		}
		else {
			string tmp;
			if (some_str[0] == '"') {
				int begin = 1; //������ �����
				int end = some_str.find('"', begin); //����� �����

				if (end != -1) {

					//�������� �������� �����
					tmp.assign(some_str, 0, end + 1);
					compositionName_ = tmp;
					tmp.clear();
					end++;

					for (int i = 2; i < 6; i++) {
						begin = end + 1;
						end = some_str.find(' ', begin);

						tmp.assign(some_str, begin, end - begin);
						if (i == 2) //�������� ��� ������
							authorName_ = tmp;
						else if (i == 3) //�������� ���� �����
							genre_ = tmp;
						else if (i == 4) //�������� ����������� ������
							audienceRating_ = tmp;
						else if (i == 5) //�������� ���������� �����������
							ageRestrictions_ = tmp;
						tmp.clear();
					}
				}
				else {
					successfulFlag_ = 0;
					throw ExceptionSplitString(numberOfLines_,
						", �� ������� 2 ������� � ��������, ��������� ������ ����������");
				}
			}
			else {
				successfulFlag_ = 0;
				throw ExceptionSplitString(numberOfLines_,
					", �������� ���������� ������ ���� ������ � ��������, ��������� ������ ����������");

			}
		}
	}
	catch (ExceptionSplitString &ex) {
		cerr << ex.getMsgLines() << ex.getNumberOfLines() << ex.getErrorMsg() << endl;
	}
}

bool SplitString::isSuccessfulSplit() {
	return successfulFlag_;
}