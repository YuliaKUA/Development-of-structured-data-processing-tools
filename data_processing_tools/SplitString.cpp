#include "SplitString.h"
#include "Exception.h"
#include <iostream>
#include <string>
#include <fstream>

SplitString::SplitString() :
	compositionName_(""),
	authorName_(""),
	genre_(""),
	audienceRating_(""),
	ageRestrictions_(""),
	successfulFlag_(1),
	numberOfLines_(0) {}

SplitString::~SplitString() {
}

// Set the current line number
void SplitString::setNumberOfLines(int numer) {
	numberOfLines_ = numer;
}

// The function checks the amount of data in a row
// The string should contain 5 words separated by 4 spaces
bool SplitString::amountOfData(string some_str) {
	try {
		some_str += " ";
		string tmp;
		int begin = some_str.find('"', 0);

		if (some_str[0] != '"') {
			throw ExceptionSplitString(numberOfLines_,
				", the name of the composition must be given in quotation marks, line breaking is not possible");
		}

		int count = 0;
		int pos = some_str.find('"', begin + 1);
		if (pos > -1) {
			pos = some_str.find(' ', pos + 1);
		}

		if (some_str[0] == '"' && pos < 0)
			throw ExceptionSplitString(numberOfLines_,
				", 2 quotation marks not found, no line break possible");

		while (pos > -1) {
			tmp.assign(some_str, begin, pos);
			if (!tmp.empty()) {
				count++;
			}
			tmp.clear();
			begin = pos;
			pos = some_str.find(' ', pos + 1);
		}
		if (count == 5) {
			return true;
		}
		else
			return false;
	}
	catch (ExceptionSplitString &ex) {
		cerr << ex.getMsgLines() << ex.getNumberOfLines() << ex.getErrorMsg() << endl;
		return false;
	}
}

// The function breaks the string into elements
void SplitString::split(string some_str) {
	// in each field, copy part of the string, separated by spaces
	try {
		if (!amountOfData(some_str)) {
			successfulFlag_ = 0;
			throw ExceptionSplitString(numberOfLines_,
				", invalid amount of data to split line");
		}
		else {
			string tmp;
			if (some_str[0] == '"') {
				int begin = 1; // start of word
				int end = some_str.find('"', begin); // end of word

				if (end != -1) {

					// Select the name of the play
					tmp.assign(some_str, 0, end + 1);
					compositionName_ = tmp;
					tmp.clear();
					end++;

					for (int i = 2; i < 6; i++) {
						begin = end + 1;
						end = some_str.find(' ', begin);

						tmp.assign(some_str, begin, end - begin);
						if (i == 2) // Select the name of the author
							authorName_ = tmp;
						else if (i == 3) // Select the genre of the play
							genre_ = tmp;
						else if (i == 4) // Highlight the audience rating
							audienceRating_ = tmp;
						else if (i == 5) // Select age limits
							ageRestrictions_ = tmp;
						tmp.clear();
					}
				}
				else {
					successfulFlag_ = 0;
					throw ExceptionSplitString(numberOfLines_,
						", 2 quotation marks not found, no line break possible");
				}
			}
			else {
				successfulFlag_ = 0;
				throw ExceptionSplitString(numberOfLines_,
					", the name of the composition must be given in quotation marks, line breaking is not possible");

			}
		}
	}
	catch (ExceptionSplitString &ex) {
		cerr << ex.getMsgLines() << ex.getNumberOfLines() << ex.getErrorMsg() << endl;
	}
}

bool SplitString::isSuccessfulSplit() {
	return successfulFlag_;
}
