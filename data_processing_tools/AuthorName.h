#pragma once
#include <iostream>
#include <string>

using namespace std;
class AuthorName : public string
{
private:
	//<�����> :: = �| |� a| |z
	bool isLetter(char** some_str);

	//<��������� �����> :: = A || � A || Z
	bool isCapitalLetter(char** some_str);

	//<�����> : : = <�����>| |<�����>
	bool isWord(char** some_str);

	//<������> :: = <��������� �����> <�����>
	bool isHeadWord(char** some_str);

	//<�������> :: = <������> | <������>� - �<������>
	bool isSername(char** some_str);

	//<���> :: = <�������> �_�<��������� �����>�.�<��������� �����>�.�
	//| <�������> �_�<��������� �����>�.'
	bool isAuthorName(char** some_str);

	//������������� string � ������ char 
	bool stringToCharName(string str);

public:
	string authorName_;

	int numberOfLines_; // ������� ������ � �����

	//�����������
	AuthorName();
	//����������
	~AuthorName();

	//������������� ����� ������� ������
	void setNumberOfLines(int numer);

	//���������� �������� ����
	void setValue(string str);

	//���������� ��������� = !!!
	const AuthorName &operator = (const AuthorName &ob);
	//���������� ��������� ������ !!!
	friend ostream& operator << (ostream& out, AuthorName ob);
};