#pragma once
#include <iostream>
#include <string>
#include "SplitString.h"

#include "�ompositionName.h"
#include "AuthorName.h"
#include "Genre.h"
#include "AudienceRating.h"
#include "AgeRestrictions.h"

using namespace std;

class Spectacle : public string
{
public:
	int numberOfLines_; // ������� ������ � �����

	�ompositionName compositionName_;
	AuthorName authorName_;
	Genre genre_;
	AudienceRating audienceRating_;
	AgeRestrictions ageRestrictions_;

	//����������� ��� ����������
	Spectacle();
	//����������� � �����������
	Spectacle(string compositionName, string authorName, string genre,
		string audienceRating, string ageRestrictions);
	//����������
	~Spectacle();

	//����������� �����������
	Spectacle(const Spectacle & copy);

	//������������� ����� ������� ������
	void setNumberOfLines(int numer);

	//������������� �������� �����
	void setValues(string str);

	//������� ��������� ������������ ������
	bool isDefectiveSpectacle();

	//���������� ��������� =  !!!
	const Spectacle & operator = (const Spectacle & ob);

	//���������� ���������� ���������
	bool operator > (Spectacle &ob);
	bool operator < (Spectacle &ob);
	friend bool operator <= (const Spectacle &ob1, const Spectacle &ob2);
	friend bool operator == (const Spectacle &ob1, const Spectacle &ob2);

	//���������� ��������� ������ !!!
	friend ostream& operator << (ostream& out, Spectacle ob);
	//���������� ��������� ����� !!!
	friend istream& operator >> (istream& in, Spectacle &ob);

	//���������� �������� �������� ��� ����� � ��� ���� �����
	friend Spectacle operator += (const Spectacle &ob1, const Spectacle &ob2);
	Spectacle operator += (const Spectacle &ob);

	//���������� ����������� ���������� ��� �����
	Spectacle &operator ++();

	//���������� ������������ ���������� ��� ���� �����
	//Spectacle &operator ++( int value);
	friend Spectacle &operator ++(Spectacle& ob, int);
};