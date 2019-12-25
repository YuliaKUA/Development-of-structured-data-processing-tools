#pragma once
#include <iostream>
#include <string>

using namespace std;
class AgeRestrictions : public string
{
private:
	// BPF
	// <Sign> :: = ‘+’
	bool isSign(char ** some_str);

	// <Digit> :: = 0 || 9
	bool isNumer(char ** some_str);

	// <Integer> :: = <Digit> | | <number>
	bool isInteger(char ** some_str);

	// <Age restrictions> :: = <Integer> ’_’ <Sign>
	bool isAgeRestriction(char ** some_str);

	// Convert string to char array and check bnf
	bool stringToCharRestrictions(string str);

public:
	string ageRestrictions_;

	int numberOfLines_; // current line in file

	AgeRestrictions();
	~AgeRestrictions();

	// Set the current line number
	void setNumberOfLines(int numer);

	// Set the field value
	void setValue(string str);

	const AgeRestrictions &operator = (const AgeRestrictions &ob);
	friend ostream& operator << (ostream& out, AgeRestrictions ob);
};
