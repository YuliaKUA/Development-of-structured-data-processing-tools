#pragma once
#include <iostream>
#include <string>

using namespace std;

class �ompositionName : public string
{
private:
	//���������� true ���� ����� �������
	bool isEnd(char ** some_str);

	//< ���� > :: = �.� | �, � | � - � | � : � | �; � | �!� | � & � | � ? � | ���
	bool isSign(char** some_str);

	//<�����> :: = 0 || 9
	bool isNumer(char** some_str);

	//<�����> :: = <�����>| |<�����>
	bool isInteger(char** some_str);

	//<��������� �����> :: = A || � A || Z
	bool isCapitalLetter(char** some_str);

	//<�����> :: = �| |� a| |z
	bool isLetter(char** some_str);

	//<�����> : : = <�����>| |<�����>
	bool isWord(char** some_str);

	//<������> :: = <��������� �����> <�����>
	bool isHeadWord(char** some_str);

	//<�����������> :: = <������> | <������> �_�<����> | <������> �_�<����> �_�<�����>
	//| <������>�_�<�����>| <�����>| <�����> �_�<�����> | <�����> �_�<����>
	bool isSentence(char** some_str);

	//<�������� �����> :: = ���<�����������>���| ���<�����������> �_�<�����>���
	bool isCompositionName(char** some_str);

	//������������� string � ������ char � ��������� ���
	bool stringToCharComposition(string str);

public:
	string compositionName_;

	int numberOfLines_; // ������� ������ � �����

	//����������� ��� ����������
	�ompositionName();
	//����������
	~�ompositionName();

	//���������� �������� ����
	void setValue(string str);

	//������������� ����� ������� ������
	void setNumberOfLines(int numer);

	//���������� ��������� = !!!
	const �ompositionName &operator = (const �ompositionName &ob);
	//���������� ��������� ������ !!!
	friend ostream& operator << (ostream& out, �ompositionName ob);
};