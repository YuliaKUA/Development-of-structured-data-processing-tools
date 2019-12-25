#pragma once
#include <iostream>
#include <string>
#include "SplitString.h"

#include "ÑompositionName.h"
#include "AuthorName.h"
#include "Genre.h"
#include "AudienceRating.h"
#include "AgeRestrictions.h"

using namespace std;

class Spectacle : public string
{
public:
	int numberOfLines_; // current line in file

	ÑompositionName compositionName_;
	AuthorName authorName_;
	Genre genre_;
	AudienceRating audienceRating_;
	AgeRestrictions ageRestrictions_;

	Spectacle();
	Spectacle(string compositionName, string authorName, string genre,
		string audienceRating, string ageRestrictions);
	~Spectacle();

	Spectacle(const Spectacle & copy);

	// Set the current line number
	void setNumberOfLines(int numer);

	// Set the field values
	void setValues(string str);

	// The function checks the correctness of the data
	bool isDefectiveSpectacle();

	const Spectacle & operator = (const Spectacle & ob);

	// Overload relationship operators
	bool operator > (Spectacle &ob);
	bool operator < (Spectacle &ob);
	friend bool operator <= (const Spectacle &ob1, const Spectacle &ob2);
	friend bool operator == (const Spectacle &ob1, const Spectacle &ob2);

	friend ostream& operator << (ostream& out, Spectacle ob);
	friend istream& operator >> (istream& in, Spectacle &ob);

	// Overloading binary operations as a method and as friendly functions
	friend Spectacle operator += (const Spectacle &ob1, const Spectacle &ob2);
	Spectacle operator += (const Spectacle &ob);

	// Overload the prefix increment as a method
	Spectacle &operator ++();

	// Overload postfix increment as friendly functions
	//Spectacle &operator ++( int value);
	friend Spectacle &operator ++(Spectacle& ob, int);
};
