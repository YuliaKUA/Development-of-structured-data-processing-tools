// Only breaks the string and sets the values of its fields without checking
#pragma once 
#include <iostream>
#include <string>
#include "ÑompositionName.h"

using namespace std;

class SplitString
{
public:
	int numberOfLines_; // current line in file
	bool successfulFlag_;

	string compositionName_;
	string authorName_;
	string genre_;
	string audienceRating_;
	string ageRestrictions_;

	SplitString();
	~SplitString();

	// Set the current line number
	void setNumberOfLines(int numer);

	// The function checks the amount of data in a row
	bool amountOfData(string some_str);
	// The function breaks the string into elements
	void split(string some_str);

	bool isSuccessfulSplit();
};
