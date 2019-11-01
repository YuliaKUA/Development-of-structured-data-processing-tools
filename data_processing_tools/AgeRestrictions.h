#pragma once
#include <iostream>
#include <string>

using namespace std;
class AgeRestrictions : public string
{
private:
	//���
	//<����> :: = �+�
	bool isSign(char ** some_str);

	//<�����> :: = 0 || 9
	bool isNumer(char ** some_str);

	//<����� �����> :: = <�����>| |<�����>
	bool isInteger(char ** some_str);

	//<���������� �����������> :: = <����� �����>�_�<����>
	bool isAgeRestriction(char ** some_str);

	//������������� string � ������ char � ��������� ���
	bool stringToCharRestrictions(string str);

public:
	string ageRestrictions_;

	int numberOfLines_; // ������� ������ � �����

	//����������� ��� ����������
	AgeRestrictions();
	//����������
	~AgeRestrictions();

	//������������� ����� ������� ������
	void setNumberOfLines(int numer);

	//���������� �������� ����
	void setValue(string str);

	//���������� ��������� = !!!
	const AgeRestrictions &operator = (const AgeRestrictions &ob);
	//���������� ��������� ������ !!!
	friend ostream& operator << (ostream& out, AgeRestrictions ob);
};