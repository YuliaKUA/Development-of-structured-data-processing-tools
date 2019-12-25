#include "CompositionName.h"
#include "Exception.h"
#include <iostream>
using namespace std;

// BPF for the Title of the play
// Returns true if the end of the array
bool CompositionName::isEnd(char ** some_str) {
	if (**some_str == '\0') {
		return true;
	}
	return false;
}

//<Sign> :: = ‘.’ |’,’|’-’|’:’|’;’|’!’|’&’|’?’|’№’
bool CompositionName::isSign(char ** some_str) {
	if (**some_str == '.' || **some_str == ',' || **some_str == '-' || **some_str == ':'
		|| **some_str == ';' || **some_str == '!' || **some_str == '&'
		|| **some_str == '?' || **some_str == '¹')
	{
		(*some_str)++;
		return true;
	}
	return false;
}

//<Numer> :: = 0||9
bool CompositionName::isNumer(char ** some_str) {
	if (**some_str >= '0' && **some_str <= '9') {
		(*some_str)++;
		return true;
	}
	return false;
}

// <Integer> :: = <Numer> | | <Integer>
bool CompositionName::isInteger(char ** some_str) {
	if (**some_str == ' ') {
		return true;
	}

	if (isNumer(some_str)) {
		isInteger(some_str);
		return true;
	}

	return false;
}

// <Uppercase letter> :: = А || Я A || Z
bool CompositionName::isCapitalLetter(char ** some_str) {
	if ((**some_str >= 'À' && **some_str <= 'ß')
		|| (**some_str >= 'A' && **some_str <= 'Z'))
	{
		(*some_str)++;
		return true;
	}
	return false;
}

// <Letter> :: = а || я a || z
bool CompositionName::isLetter(char ** some_str) {
	if ((**some_str >= 'a' && **some_str <= 'z')
		|| (**some_str >= 'à' && **some_str <= 'ÿ'))
	{
		(*some_str)++;
		return true;
	}
	return false;
}

// <Word>:: = <Letter> | | <Word>
bool CompositionName::isWord(char ** some_str) {
	if (**some_str == ' ') {
		return true;
	}

	if (isLetter(some_str)) {
		isWord(some_str);
		return true;
	}
	return false;
}

// <UWord> :: = <Uppercase letter> <Word>
bool CompositionName::isHeadWord(char** some_str) {
	if (isCapitalLetter(some_str)) {
		//cout << "test 0" << endl;
		if (isWord(some_str)) {
			//cout << "test 1" << endl;
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

// <Sentence> :: = <UWord> | <UWord> ‘_’ <Sign> | <UWord> ‘_’ <Sign> ‘_’ <Word>
// | <UWord> ‘_’ <Word> | <Integer> | <Integer> ‘_’ <Word> | <Integer> ‘_’ <Sign>

bool CompositionName::isSentence(char ** some_str) {
	if (isInteger(some_str)) {
		if (**some_str == ' ') {
			(*some_str)++;
			if (isSign(some_str)) {
				return true;
			}
			else if (isWord(some_str)) {
				return true;
			}
			else if (isNumer(some_str)) {
				(*some_str)--;
				(*some_str)--;
				return true;
			}
			else
				return false;
		}
		else
			return true;
	}
	else if (isHeadWord(some_str)) {
		if (**some_str == ' ') {
			//cout << "test 5" << endl;
			(*some_str)++;
			if (isSign(some_str)) {
				//cout << "test 6" << endl;
				if (**some_str == ' ') {
					(*some_str)++;
					if (isWord(some_str)) {
						return true;
					}
					else if (isNumer(some_str)) {
						(*some_str)--;
						(*some_str)--;
						//cout << "test " << endl;
						return true;
					}
					else
						return false;
				}
				else
					return true;
			}
			else
				if (isWord(some_str)) {
					//cout << "test 3" << endl;
					return true;
				}
				else if (isNumer(some_str)) {
					//cout << "test 3" << endl;
					(*some_str)--;
					(*some_str)--;
					return true;
				}
				else {
					//cout << "!1" << endl;
					return false;
				}
		}
		else {
			//cout << "!2" << endl;
			return true;
		}
	}
	else {
		//cout << "!3" << endl;
		return false;
	}

}

// <CompositionName> :: = ‘" ’<Sentence>’ "’ | ‘» ’<Sentence>‘ _ ’<Integer>’ »’

bool CompositionName::isCompositionName(char** some_str) {
	if (isSentence(some_str)) {
		if (**some_str == ' ') {
			(*some_str)++;
			if (isInteger(some_str)) {
				if (isEnd(some_str)) {
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		else if (isEnd(some_str))
			return true;
		else
			return false;

	}
	else
		return false;
}

bool CompositionName::stringToCharComposition(string str) {
	int len = str.length() + 1;
	char *copyStr = new char[len];
	strcpy_s(copyStr, len, str.c_str());

	char* p = copyStr;
	char ** pCopy = &p;
	return isCompositionName(pCopy);
}

CompositionName::CompositionName() :
	compositionName_(""),
	numberOfLines_(0) {}

CompositionName::~CompositionName() {
}

// Set the field value
void CompositionName::setValue(string str) {
	try {
		string copyStr = str;
		copyStr.erase(copyStr.begin());
		copyStr.erase(copyStr.begin() + copyStr.length() - 1);

		if (copyStr.empty())
			throw ExceptionCompositionName(numberOfLines_,
				", empty string, no name specified");
		else if (str[0] != '"' && str[str.length() - 1] != '"')
			throw ExceptionCompositionName(numberOfLines_,
				", the name of the composition must be given in quotation marks");
		else if (!stringToCharComposition(copyStr))
			throw ExceptionCompositionName(numberOfLines_,
				", the title of the composition is incorrect");
		else {
			compositionName_ = str;
		}
	}
	catch (ExceptionCompositionName &ex) {
		cerr << ex.getMsgLines() << ex.getNumberOfLines() << ex.getErrorMsg() << endl;
	}
}
// Set the current line number
void CompositionName::setNumberOfLines(int numer) {
	numberOfLines_ = numer;
}

const CompositionName & CompositionName::operator = (const CompositionName & ob) {
	// check for self-assignment
	if (&ob == this)
		return *this;
	else {
		this->compositionName_ = ob.compositionName_;
	}
	return *this;
}

ostream & operator<<(ostream & out, CompositionName ob) {
	out << ob.compositionName_;
	return out;
}
