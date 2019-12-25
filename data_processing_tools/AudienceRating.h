#pragma once
#include <iostream>
#include <string>

using namespace std;
class AudienceRating : public string
{
private:
	// BPF
	// Returns true if the end of the array
	bool isEnd(char ** some_str);

	//<Digit> :: = 0||9
	bool isNumer(char ** some_str);

	// <Number> :: = <Digit> | | <Number>
	bool isInteger(char ** some_str);

	// <Viewer rating> :: = <integer> ‘.’ <Integer>
	bool isAudienceRating(char** some_str);

	// Checks that a number in the range (0, 10)
	bool isCorrectNumber(string some_str);

public:
	int numberOfLines_; // current line in file

	double audienceRating_;

	AudienceRating();
	~AudienceRating();

	void setNumberOfLines(int numer);

	bool stringToCharRating(string str);

	void setValue(string str);

	const AudienceRating &operator = (const AudienceRating &ob);
	friend AudienceRating operator += (AudienceRating &ob1, AudienceRating &ob2);

	bool operator > (AudienceRating & ob);
	bool operator < (AudienceRating & ob);
	bool operator >= (AudienceRating & ob);
	bool operator == (AudienceRating & ob);
	
	friend ostream& operator << (ostream& out, AudienceRating ob);
};
