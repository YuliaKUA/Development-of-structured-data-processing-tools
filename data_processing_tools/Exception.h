#pragma once
#include <stdexcept>
using namespace std;

class Exception : public exception
{
public:
	int numberOfLines_;
	const char * msg_;
	const char * msg2_ = "Error in line № ";

	Exception(int numberOfLines, const char * msg) {
		this->numberOfLines_ = numberOfLines;
		this->msg_ = msg;
	}
	Exception(const char * msg) : exception(msg) {}

	~Exception() {}

	int getNumberOfLines() {
		return numberOfLines_;
	}

	string getMsgLines() {
		return msg2_;
	}

	string getErrorMsg() {
		return msg_;
	}
};

class ExceptionCompositionName : public Exception
{
public:
	ExceptionCompositionName(int numberOfLines, const char * msg) :
		Exception(numberOfLines, msg) {}

	~ExceptionCompositionName() {}
};

class ExceptionAuthorName : public Exception
{
public:
	ExceptionAuthorName(int numberOfLines, const char * msg) :
		Exception(numberOfLines, msg) {}

	~ExceptionAuthorName() {}
};

class ExceptionGenre : public Exception
{
public:
	ExceptionGenre(int numberOfLines, const char * msg) :
		Exception(numberOfLines, msg) {}

	~ExceptionGenre() {}
};

class ExceptionAudienceRating : public Exception
{
public:
	ExceptionAudienceRating(int numberOfLines, const char * msg) :
		Exception(numberOfLines, msg) {}

	~ExceptionAudienceRating() {}
};

class ExceptionAgeRestrictions : public Exception
{
public:
	ExceptionAgeRestrictions(int numberOfLines, const char * msg) :
		Exception(numberOfLines, msg) {}

	~ExceptionAgeRestrictions() {}
};

class ExceptionSplitString : public Exception
{
public:
	ExceptionSplitString(int numberOfLines, const char * msg) :
		Exception(numberOfLines, msg) {}

	~ExceptionSplitString() {}
};

class ExceptionPlaybook : public Exception
{
public:
	ExceptionPlaybook(int numberOfLines, const char * msg) :
		Exception(numberOfLines, msg) {}
	ExceptionPlaybook(const char * msg) : Exception(msg) {}

	~ExceptionPlaybook() {}
};

class ExceptionFile : public Exception
{
public:
	ExceptionFile(int numberOfLines, const char * msg) :
		Exception(numberOfLines, msg) {}
	ExceptionFile(const char * msg) : Exception(msg) {}

	~ExceptionFile() {}
};
