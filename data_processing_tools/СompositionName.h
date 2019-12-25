#pragma once
#include <iostream>
#include <string>

using namespace std;

class CompositionName : public string
{
private:
	// Returns true if the end of the array
	bool isEnd(char ** some_str);

	//<Sign> :: = ‘.’ |’,’|’-’|’:’|’;’|’!’|’&’|’?’|’№’
	bool isSign(char** some_str);

	//<Numer> :: = 0||9
	bool isNumer(char** some_str);

	// <Integer> :: = <Numer> | | <Integer>
	bool isInteger(char** some_str);

	// <Uppercase letter> :: = А || Я A || Z
	bool isCapitalLetter(char** some_str);

	// <Letter> :: = а || я a || z
	bool isLetter(char** some_str);

	// <Word>:: = <Letter> | | <Word>
	bool isWord(char** some_str);

	// <UWord> :: = <Uppercase letter> <Word>
	bool isHeadWord(char** some_str);

	// <Offer> :: = <UWord> | <UWord> ‘_’ <Sign> | <UWord> ‘_’ <Sign> ‘_’ <Word>
	// | <UWord> ‘_’ <Word> | <Number> | <Number> ‘_’ <Word> | <Number> ‘_’ <Sign>
	bool isSentence(char** some_str);

	// <Name of the play> :: = ‘" ’<Offer>’ "’ | ‘» ’<Offer>‘ _ ’<Number>’ »’
	bool isCompositionName(char** some_str);

	bool stringToCharComposition(string str);

public:
	string compositionName_;

	int numberOfLines_; // current line in file
	
	CompositionName();
	~CompositionName();

	void setValue(string str);

	// Set the current line number
	void setNumberOfLines(int numer);

	const CompositionName &operator = (const CompositionName &ob);
	friend ostream& operator << (ostream& out, CompositionName ob);
};
