#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Spectacle.h"

using namespace std;


class Playbook
{
public:
	vector <Spectacle> playbook_; // all plays
	vector <Spectacle> mostPopularPlays_; // most popular plays
	vector <Spectacle> genreList_; // list of genres without repetition
	vector <Spectacle> ratingList_; // average rating corresponding to the genre

	int count_; // Number of items in playbook_
	int numberOfLines_; // number of lines in the file

	// For output to the column (table)
	int maxComp_;
	int maxAuth_;
	int maxGen_;
	int maxAud_;
	int maxAge_;

	Playbook();
	~Playbook();

	// Function Adds The Piece To The Array
	void addSpectacle(string str);

	// Function returning the current line number
	int getNumberStr();

	// Function for sorting descending viewer ratings using the insert method
	void insertSort();

	// Function that writes the most popular play / s to a vector
	void mostPopular();

	// Function recording a list of genres of plays and audience ratings
	// to vector
	void genreList();

	// The function determines the maximum length of each field
	void setMaxLength();
};
