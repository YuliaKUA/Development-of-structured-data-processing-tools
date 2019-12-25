#include "Playbook.h"
#include "Spectacle.h"
#include "Exception.h"

Playbook::Playbook() :
	count_(0),
	numberOfLines_(0),

	maxComp_(12),
	maxAuth_(9),
	maxGen_(8),
	maxAud_(7),
	maxAge_(11) {}

Playbook::~Playbook()
{}

// Function Adds The Piece To The Array
void Playbook::addSpectacle(string str) {
	numberOfLines_++;

	Spectacle spectacle;
	spectacle.setNumberOfLines(numberOfLines_);
	spectacle.setValues(str);

	try {
		if (!spectacle.isDefectiveSpectacle()) {
			playbook_.push_back(spectacle);
			count_++;
		}
		else
			throw ExceptionPlaybook(numberOfLines_,
				", incorrect data for adding the play to the poster");
	}
	catch (ExceptionPlaybook &ex) {
		cerr << ex.getMsgLines() << ex.getNumberOfLines() << ex.getErrorMsg() << endl << endl;
	}
}

// Function returning the current line number
int Playbook::getNumberStr() {
	return numberOfLines_;
}

// Function checking if the array is sorted
bool isSort(vector <Spectacle> vec) {
	int len = vec.size();
	for (int i = 0; i < len - 1; i++) {
		if (vec[i] < vec[i + 1]) {
			return false;
		}
	}
	return true;
}

// Function for sorting descending viewer ratings using the insert method
void Playbook::insertSort() {
	try {
		if (count_ > 0) {
			if (!isSort(playbook_)) { // Check if the array is sorted
				Spectacle temp; // temporary variable to store the value of the element of the sorted array
				int item; // index of the previous element
				int len = playbook_.size();
				for (int i = 1; i < len; i++) {
					temp = playbook_[i]; // initialize the temporary variable with the current value of the array element
					item = i - 1; // remember the index of the previous element of the array
					while (item >= 0 && playbook_[item] < temp) { // while the index is not 0 and the previous element of the array is less than the current
						playbook_[item + 1] = playbook_[item]; // rearrange array elements
						playbook_[item] = temp;
						item--;
					}
				}
			}
		}
		else
			throw ExceptionPlaybook("Error, no pieces to sort");
	}
	catch (ExceptionPlaybook &ex) {
		cerr << ex.what() << endl;
	}
}

// Function that writes the most popular play \ 's to the vector
void Playbook::mostPopular() {
	if (!isSort(playbook_)) {
		insertSort();
	}
	try {
		if (count_ > 0) {
			Spectacle temp = playbook_[0];
			mostPopularPlays_.push_back(playbook_[0]);
			int i = 1;
			while (i < count_ && temp.audienceRating_ == playbook_[i].audienceRating_) {
				mostPopularPlays_.push_back(playbook_[i]);
				i++;
			}
		}
		else
			ExceptionPlaybook("Error, there are no plays to choose the most popular");
	}
	catch (ExceptionPlaybook &ex) {
		cerr << ex.what() << endl;
	}
}

// Function recording a list of genres of plays and audience ratings
// to vector
void Playbook::genreList() {
	try {
		if (count_ > 0) {
			vector <Spectacle> copyPlaybook = playbook_;
			Spectacle temp;
			int index = 0;
			int k = 0;

			while (copyPlaybook.size() > 0) {
				genreList_.push_back(copyPlaybook[0]);
				ratingList_.push_back(copyPlaybook[0]);
				ratingList_[index].audienceRating_.audienceRating_ = 0;
				temp = copyPlaybook[0];
				k = 0;

				for (int i = 0; i < copyPlaybook.size(); i++) {
					if (temp.genre_ == copyPlaybook[i].genre_) {
						k++;
						ratingList_[index].audienceRating_ += copyPlaybook[i].audienceRating_;
						copyPlaybook.erase(copyPlaybook.begin() + i);
						i--;
					}

				}
				ratingList_[index].audienceRating_.audienceRating_ /= k;
				index++;
			}
		}
		else
			ExceptionPlaybook("Error, there are no plays for the conclusion of genres");
	}
	catch (ExceptionPlaybook &ex) {
		cerr << ex.what() << endl;
	}
}

// The function determines the maximum length of each field
void Playbook::setMaxLength() {
	if (count_ > 0) {
		for (int i = 0; i < count_; i++) {
			if (playbook_[i].compositionName_.compositionName_.length() > maxComp_)
				maxComp_ = playbook_[i].compositionName_.compositionName_.length();
			if (playbook_[i].authorName_.authorName_.length() > maxAuth_)
				maxAuth_ = playbook_[i].authorName_.authorName_.length();
			if (playbook_[i].genre_.genre_.length() > maxGen_)
				maxGen_ = playbook_[i].genre_.genre_.length();
		}
	}
}
