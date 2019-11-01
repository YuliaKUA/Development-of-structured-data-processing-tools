#include "Spectacle.h"

//Конструктор для создания нового элемента пьесы
Spectacle::Spectacle() {}//Обьявление полей прописаны в своих классах

//Конструктор с параметрами
Spectacle::Spectacle(string compositionName, string authorName,
	string genre, string audienceRating, string ageRestrictions) {

	compositionName_.setValue(compositionName);
	authorName_.setValue(authorName);
	genre_.setValue(genre);
	audienceRating_.setValue(audienceRating);
	ageRestrictions_.setValue(ageRestrictions);

	numberOfLines_ = 0;
}

//Деструктор
Spectacle::~Spectacle() {
}

//Конструктор копирования
Spectacle::Spectacle(const Spectacle & copy) {
	if (&copy != this) {
		compositionName_ = copy.compositionName_;
		authorName_ = copy.authorName_;
		genre_ = copy.genre_;
		audienceRating_ = copy.audienceRating_;
		ageRestrictions_ = copy.ageRestrictions_;

		numberOfLines_ = copy.numberOfLines_;
	}
}

void Spectacle::setNumberOfLines(int numer) {
	numberOfLines_ = numer;
}

//Устанавливаем значения полей
void Spectacle::setValues(string str) {
	SplitString ob; //Обьект класса Сплит
	ob.setNumberOfLines(numberOfLines_);
	ob.split(str); //Функция разбивает строку на элементы и заполняет поля обьекта

	if (ob.isSuccessfulSplit()) {
		compositionName_.setNumberOfLines(numberOfLines_);
		compositionName_.setValue(ob.compositionName_);

		authorName_.setNumberOfLines(numberOfLines_);
		authorName_.setValue(ob.authorName_);

		genre_.setNumberOfLines(numberOfLines_);
		genre_.setValue(ob.genre_);

		audienceRating_.setNumberOfLines(numberOfLines_);
		audienceRating_.setValue(ob.audienceRating_);

		ageRestrictions_.setNumberOfLines(numberOfLines_);
		ageRestrictions_.setValue(ob.ageRestrictions_);
	}
}

//Функция проверяет корректность данных
bool Spectacle::isDefectiveSpectacle() {
	if (compositionName_.compositionName_ == "" || authorName_.authorName_ == ""
		|| genre_.genre_ == "" || audienceRating_.audienceRating_ == -1
		|| ageRestrictions_.ageRestrictions_ == "") {
		return true;
	}
	else
		return false;
}

//Перегрузка оператора =  !!!
const Spectacle & Spectacle::operator = (const Spectacle & ob) {
	// проверка на самоприсваивание
	if (&ob == this) return *this;
	else {
		compositionName_ = ob.compositionName_;
		authorName_ = ob.authorName_;
		genre_ = ob.genre_;
		audienceRating_ = ob.audienceRating_;
		ageRestrictions_ = ob.ageRestrictions_;
	}
	return *this;
}

bool Spectacle::operator > (Spectacle & ob) {
	if (audienceRating_ > ob.audienceRating_)
		return true;
	else
		return false;
}

bool Spectacle::operator < (Spectacle & ob) {
	if (audienceRating_ < ob.audienceRating_)
		return true;
	else
		return false;
}

Spectacle Spectacle::operator += (const Spectacle & ob) {
	this->audienceRating_.audienceRating_ = this->audienceRating_.audienceRating_
		+ ob.audienceRating_.audienceRating_;
	return *this;
}

//Перегрузка префиксного инкремента как метод
Spectacle & Spectacle::operator++() {
	this->audienceRating_.audienceRating_++;
	return *this;
}

//Spectacle & Spectacle::operator++(int value){
//	Spectacle temp(*this);
//	++(*this);
//	return *this;
//}

bool operator<=(const Spectacle & ob1, const Spectacle & ob2) {
	if (ob1.audienceRating_.audienceRating_ <= ob2.audienceRating_.audienceRating_)
		return true;
	else
		return false;
}

bool operator == (const Spectacle & ob1, const Spectacle & ob2) {
	bool compositN = ob1.compositionName_.compositionName_ == ob2.compositionName_.compositionName_;
	bool authN = ob1.authorName_.authorName_ == ob2.authorName_.authorName_;
	bool gen = ob1.genre_.genre_ == ob2.genre_.genre_;
	bool rating = ob1.audienceRating_.audienceRating_ == ob2.audienceRating_.audienceRating_;
	bool restr = ob1.ageRestrictions_.ageRestrictions_ == ob2.ageRestrictions_.ageRestrictions_;

	if (compositN && authN && gen && rating && restr)
		return true;
	else
		return false;
}

//Перегрузка оператора вывода !!!
ostream & operator<<(ostream & out, Spectacle ob) {
	out << ob.compositionName_ << " " << ob.authorName_ << " " << ob.genre_ << " " << ob.audienceRating_
		<< " " << ob.ageRestrictions_;
	return out;
}

//Перегрузка оператора ввода !!!
istream & operator>>(istream & in, Spectacle & ob) {
	in >> ob.compositionName_.compositionName_ >> ob.authorName_.authorName_ >>
		ob.genre_.genre_ >> ob.audienceRating_.audienceRating_ >> ob.ageRestrictions_.ageRestrictions_;

	return in;
}

Spectacle operator+=(const Spectacle & ob1, const Spectacle & ob2) {
	Spectacle ob;
	ob.audienceRating_.audienceRating_ = ob1.audienceRating_.audienceRating_
		+ ob2.audienceRating_.audienceRating_;
	return ob;
}

Spectacle & operator++(Spectacle& ob, int) {
	Spectacle temp;
	temp = ob;
	++ob;
	return temp;
}