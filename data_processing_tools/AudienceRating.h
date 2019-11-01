#pragma once
#include <iostream>
#include <string>

using namespace std;
class AudienceRating : public string
{
private:
	//���
	//���������� true ���� ����� �������
	bool isEnd(char ** some_str);

	//<�����> :: = 0||9
	bool isNumer(char ** some_str);

	//<�����> :: = <�����>| |<�����>
	bool isInteger(char ** some_str);

	//<������ ��������> :: = <����� �����> �.� <����� �����>
	bool isAudienceRating(char** some_str);

	// ���������, ��� ����� � ��������� (0, 10)
	bool isCorrectNumber(string some_str);

public:
	int numberOfLines_; // ������� ������ � �����

	double audienceRating_;

	//����������� ��� ����������
	AudienceRating();
	//����������
	~AudienceRating();

	//������������� ����� ������� ������
	void setNumberOfLines(int numer);

	//������������� string � ������ char 
	//!!!?
	bool stringToCharRating(string str);

	//���������� �������� ����
	void setValue(string str);

	//���������� ��������� = !!!
	const AudienceRating &operator = (const AudienceRating &ob);
	friend AudienceRating operator += (AudienceRating &ob1, AudienceRating &ob2);

	bool operator > (AudienceRating & ob);
	bool operator < (AudienceRating & ob);
	bool operator >= (AudienceRating & ob);
	bool operator == (AudienceRating & ob);
	//���������� ��������� ������ !!!
	friend ostream& operator << (ostream& out, AudienceRating ob);
};