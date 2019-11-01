#pragma once
#include <iostream>
#include <string>
using namespace std;

class Genre : public string
{
private:
	bool isEnd(char ** some_str);

	//<�����> :: = �| |� a| |z
	bool isLetter(char** some_str);

	//<�����> : : = <�����>| |<�����>
	bool isWord(char** some_str);

	//<����> ::= <�����> | <�����> �-� <�����>
	bool isGenre(char ** some_str);

public:
	string genre_;

	int numberOfLines_; // ������� ������ � �����

	//�����������
	Genre();
	//����������
	~Genre();

	//������������� ����� ������� ������
	void setNumberOfLines(int numer);

	//���������� �������� ����
	void setValue(string str);

	//������������� string � ������ char 
	bool stringToCharGenre(string str);


	bool operator == (Genre &ob);
	//���������� ��������� = !!!
	const Genre &operator = (const Genre &ob);
	//���������� ��������� ������ !!!
	friend ostream& operator << (ostream& out, Genre ob);
};