#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Spectacle.h"

using namespace std;


class Playbook
{
public:
	vector <Spectacle> playbook_;//��� �����
	vector <Spectacle> mostPopularPlays_; //����� ���������� �����
	vector <Spectacle> genreList_; //������ ������ ��� ��������
	vector <Spectacle> ratingList_; //������� ������� ��������������� �����

	int count_; //���������� ��������� � playbook_
	int numberOfLines_; // ���������� ����� � �����

	//��� ������ � ������� (�������)
	int maxComp_;
	int maxAuth_;
	int maxGen_;
	int maxAud_;
	int maxAge_;

	//����������� ��� ����������
	Playbook();
	//����������
	~Playbook();

	//�������, ����������� ����� � ������
	void addSpectacle(string str);

	//������� ������������ ����� ������� ������
	int getNumberStr();

	//������� ���������� �� �������� ����������� ������ �� ������ �������
	void insertSort();

	//������� ������������ ����� ���������� �����/� � ������
	void mostPopular();

	//������� ������������ ������ ������ ���� � ����������� ������
	// � ������
	void genreList();

	//������� ���������� ������������ ����� ������� ����
	void setMaxLength();
};