#pragma once
#include <iostream>
#include <string>

using namespace std;
class AuthorName : public string
{
private:
	// <Letter> :: = а || б a || z
	bool isLetter(char** some_str);

	// <Uppercase letter> :: = А || Я A || Z
	bool isCapitalLetter(char** some_str);

	// <Word>:: = <Letter> | | <Word>
	bool isWord(char** some_str);

	// <UWord> :: = <Uppercase letter> <Word>
	bool isHeadWord(char** some_str);

	// <Surname> :: = <UWord> | <UWord> ’-’ <UWord>
	bool isSername(char** some_str);

	// <FULL NAME> :: = <Surname> ‘_’ <Uppercase letter> ’.’ <Uppercase letter> ’.’
	// | <Surname> ‘_’ <Uppercase letter> ’. '
	bool isAuthorName(char** some_str);

	// Convert string to char array
	bool stringToCharName(string str);

public:
	string authorName_;

	int numberOfLines_; // current line in file

	AuthorName();
	~AuthorName();

	void setNumberOfLines(int numer);

	void setValue(string str);

	const AuthorName &operator = (const AuthorName &ob);
	friend ostream& operator << (ostream& out, AuthorName ob);
};
