#include "AgeRestrictions.h"
#include "Exception.h"

// BPF age restrictions
// <Sign> :: = ‘+’
bool AgeRestrictions::isSign(char ** some_str) {
	if (**some_str == '+') {
		(*some_str)++;
		return true;
	}
	return false;
}

//<Digit> :: = 0 || 9
bool AgeRestrictions::isNumer(char ** some_str) {
	if (**some_str >= '0' && **some_str <= '9') {
		(*some_str)++;
		return true;
	}
	return false;
}

// <Integer> :: = <Digit> | | <number>
bool AgeRestrictions::isInteger(char ** some_str) {
	if (isNumer(some_str)) {
		if (**some_str == '_')
			return true;
		if (isNumer(some_str)) {
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

// <Age restrictions> :: = <Integer> ’_’ <Sign>
bool AgeRestrictions::isAgeRestriction(char ** some_str) {
	if (isInteger(some_str)) {
		if (**some_str == '_') {
			(*some_str)++;
			if (isSign(some_str)) {
				return true;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

// Convert string to char array and check bnf
bool AgeRestrictions::stringToCharRestrictions(string str) {
	int len = str.length() + 1;
	char *copyStr = new char[len];
	strcpy_s(copyStr, len, str.c_str());

	char* p = copyStr;
	char ** pCopy = &p;
	return isAgeRestriction(pCopy);
}

AgeRestrictions::AgeRestrictions() :
	ageRestrictions_(""),
	numberOfLines_(0) {}

AgeRestrictions::~AgeRestrictions() {
}

// Set the current line number
void AgeRestrictions::setNumberOfLines(int numer) {
	numberOfLines_ = numer;
}

// Set the field value
void AgeRestrictions::setValue(string str) {
	try {
		if (str.empty())
			throw ExceptionAgeRestrictions(numberOfLines_,
				", ïóñòàÿ ñòðîêà, âîçðàñòíûå îãðàíè÷åíèÿ íå çàäàíû");
		else if (!stringToCharRestrictions(str))
			throw ExceptionAgeRestrictions(numberOfLines_,
				", Íåâåðíî çàäàíû âîçðàñòíûå îãðàíè÷åíèÿ");
		else
			ageRestrictions_ = str;
	}
	catch (ExceptionAgeRestrictions &ex) {
		cerr << ex.getMsgLines() << ex.getNumberOfLines() << ex.getErrorMsg() << endl;
	}
}

const AgeRestrictions & AgeRestrictions::operator=(const AgeRestrictions & ob) {
	// ïðîâåðêà íà ñàìîïðèñâàèâàíèå
	if (&ob == this) return *this;
	else {
		ageRestrictions_ = ob.ageRestrictions_;
	}
	return *this;
}

ostream & operator<<(ostream & out, AgeRestrictions ob) {
	out << ob.ageRestrictions_;
	return out;
}
