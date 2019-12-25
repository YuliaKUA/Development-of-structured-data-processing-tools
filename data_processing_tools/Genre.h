#pragma once
#include <iostream>
#include <string>
using namespace std;

class Genre : public string
{
private:
	bool isEnd(char ** some_str);

	// <Letter> :: = а || б a || z
	bool isLetter(char** some_str);

	// <Word>:: = <Letter> | | <Word>
	bool isWord(char** some_str);

	// <Genre> :: = <Word> | <Word> ’-‘ <Word>
	bool isGenre(char ** some_str);

public:
	string genre_;

	int numberOfLines_; // current line in file

	Genre();
	~Genre();

	void setNumberOfLines(int numer);

	void setValue(string str);

	bool stringToCharGenre(string str);


	bool operator == (Genre &ob);
	const Genre &operator = (const Genre &ob);
	friend ostream& operator << (ostream& out, Genre ob);
};
