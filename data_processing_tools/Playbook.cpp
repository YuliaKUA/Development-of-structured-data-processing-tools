#include "Playbook.h"
#include "Spectacle.h"
#include "Exception.h"

////Конструктор без параметров
Playbook::Playbook() :
	count_(0),
	numberOfLines_(0),

	maxComp_(12),
	maxAuth_(9),
	maxGen_(8),
	maxAud_(7),
	maxAge_(11) {}

//Деструктор
Playbook::~Playbook()
{}

//Функция, добавляющая пьесу в массив
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
				", некорректные данные для добавления спектакля в афишу");
	}
	catch (ExceptionPlaybook &ex) {
		cerr << ex.getMsgLines() << ex.getNumberOfLines() << ex.getErrorMsg() << endl << endl;
	}
}

//Функция возвращающая номер текущей строки
int Playbook::getNumberStr() {
	return numberOfLines_;
}

//Функция проверяющая отсортирован ли массив
bool isSort(vector <Spectacle> vec) {
	int len = vec.size();
	for (int i = 0; i < len - 1; i++) {
		if (vec[i] < vec[i + 1]) {
			return false;
		}
	}
	return true;
}

//Функция сортировки по убыванию зрительских оценок по методу вставок
void Playbook::insertSort() {
	try {
		if (count_ > 0) {
			if (!isSort(playbook_)) { //Проверяем отсортирован ли массив
				Spectacle temp; // временная переменная для хранения значения элемента сортируемого массива
				int item; // индекс предыдущего элемента
				int len = playbook_.size();
				for (int i = 1; i < len; i++) {
					temp = playbook_[i]; // инициализируем временную переменную текущим значением элемента массива
					item = i - 1; // запоминаем индекс предыдущего элемента массива
					while (item >= 0 && playbook_[item] < temp) { // пока индекс не равен 0 и предыдущий элемент массива меньше текущего
						playbook_[item + 1] = playbook_[item]; // перестановка элементов массива
						playbook_[item] = temp;
						item--;
					}
				}
			}
		}
		else
			throw ExceptionPlaybook("Ошибка, нет пьес для сортировки");
	}
	catch (ExceptionPlaybook &ex) {
		cerr << ex.what() << endl;
	}
}

//Функция записывающая самую популярную пьесу\ы в вектор
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
			ExceptionPlaybook("Ошибка, нет пьес для выбора самой популярной");
	}
	catch (ExceptionPlaybook &ex) {
		cerr << ex.what() << endl;
	}
}

//Функция записывающая список жанров пьес и зрительских оценок
// в вектор
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
			ExceptionPlaybook("Ошибка, нет пьес для вывода жанров");
	}
	catch (ExceptionPlaybook &ex) {
		cerr << ex.what() << endl;
	}
}

//Функция определяет максимальную длину каждого поля
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