// ������ ��������� ������ � ������������� �������� ����� ����� ��� ��������
#pragma once 
#include <iostream>
#include <string>
#include "�ompositionName.h"

using namespace std;

class SplitString
{
public:
	int numberOfLines_; // ������� ������ � �����
	bool successfulFlag_;

	string compositionName_;
	string authorName_;
	string genre_;
	string audienceRating_;
	string ageRestrictions_;

	//����������� ��� ����������
	SplitString();
	//����������
	~SplitString();

	//������������� ����� ������� ������
	void setNumberOfLines(int numer);

	//������� ��������� ���������� ������ � ������
	bool amountOfData(string some_str);
	//������� ��������� ������ �� ��������
	void split(string some_str);

	bool isSuccessfulSplit();
};