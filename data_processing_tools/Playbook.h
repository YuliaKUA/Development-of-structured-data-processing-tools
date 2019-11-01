#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Spectacle.h"

using namespace std;


class Playbook
{
public:
	vector <Spectacle> playbook_;//все пьесы
	vector <Spectacle> mostPopularPlays_; //самые популярные пьесы
	vector <Spectacle> genreList_; //список жанров без повторов
	vector <Spectacle> ratingList_; //средний рейтинг соответствующий жанру

	int count_; //Количество элементов в playbook_
	int numberOfLines_; // количество строк в файле

	//Для вывода в столбик (таблица)
	int maxComp_;
	int maxAuth_;
	int maxGen_;
	int maxAud_;
	int maxAge_;

	//Конструктор без параметров
	Playbook();
	//Деструктор
	~Playbook();

	//Функция, добавляющая пьесу в массив
	void addSpectacle(string str);

	//Функция возвращающая номер текущей строки
	int getNumberStr();

	//Функция сортировки по убыванию зрительских оценок по методу вставок
	void insertSort();

	//Функция записывающая самую популярную пьесу/ы в вектор
	void mostPopular();

	//Функция записывающая список жанров пьес и зрительских оценок
	// в вектор
	void genreList();

	//Функция определяет максимальную длину каждого поля
	void setMaxLength();
};