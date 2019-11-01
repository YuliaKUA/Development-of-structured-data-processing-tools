#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include "Spectacle.h"
#include "SplitString.h"
#include "Playbook.h"
#include <iomanip>
#include "Exception.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	try {
		string fileName;
		cout << "Введите название файла " << endl;
		getline(cin, fileName);

		ifstream fileIn(fileName);

		fileIn.seekg(0, ios::end);
		int fileSize = fileIn.tellg();//для проверки, пустой ли файл
		fileIn.seekg(0);

		if (!fileIn.is_open())
			throw ExceptionFile("Файл не найден. Путь и/или имя указаны неверно");
		else if (fileSize == 0) {
			throw ExceptionFile("Пустой файл");
		}
		else {
			Playbook list;
			string str;
			while (getline(fileIn, str)) {
				try {
					if (str.empty()) {
						throw ExceptionFile(++list.numberOfLines_,
							", строка пуста");
					}
					else {
						list.addSpectacle(str);//добавляем пьесу
					}
				}
				catch (ExceptionFile &ex) {
					cerr << ex.getMsgLines() << ex.getNumberOfLines() << ex.getErrorMsg() << endl << endl;
				}
			}
			fileIn.close();

			list.insertSort(); //сортируем элементы массива
			list.mostPopular(); //Создаем вектор с максимальным рейтингов внутри класса
			list.genreList(); // создаем вектора с жанрами и рейтингом без повтора
			list.setMaxLength(); //определяем максимальную длину каждого поля

			//Вывод в таблицу 
			ofstream{ "result.txt" };
			ofstream fileOut("result.txt");

			if (list.mostPopularPlays_.size() != 0) {
				fileOut << "Самая популярная/ые пьеса/ы" << endl;

				fileOut << "+";
				for (int i = 0; i < list.maxComp_; i++)
					fileOut << "-";
				fileOut << '+';

				for (int i = 0; i < list.maxAud_; i++)
					fileOut << "-";
				fileOut << '+' << endl;

				fileOut << "|Название";
				for (int i = 0; i < list.maxComp_ - 8; i++)
					fileOut << " ";

				fileOut << "|Рейтинг|" << endl;

				fileOut << "+";
				for (int i = 0; i < list.maxComp_; i++)
					fileOut << "-";
				fileOut << '+';

				for (int i = 0; i < list.maxAud_; i++)
					fileOut << "-";
				fileOut << '+' << endl;

				for (int i = 0; i < list.mostPopularPlays_.size(); i++) {
					fileOut << "|" << list.mostPopularPlays_[i].compositionName_;

					int temp = list.mostPopularPlays_[i].compositionName_.compositionName_.length();
					for (int i = 0; i < list.maxComp_ - temp; i++)
						fileOut << " ";

					fileOut << "|  " << list.mostPopularPlays_[i].audienceRating_ << "  |" << endl;

					fileOut << "+";
					for (int i = 0; i < list.maxComp_; i++)
						fileOut << "-";
					fileOut << '+';

					for (int i = 0; i < list.maxAud_; i++)
						fileOut << "-";
					fileOut << '+' << endl;
				}
			}

			if (list.count_ != 0) {
				fileOut << endl << "Отсортированные пьесы" << endl;
				fileOut << "+";
				for (int i = 0; i < list.maxComp_; i++)
					fileOut << "-";
				fileOut << '+';

				for (int i = 0; i < list.maxAuth_; i++)
					fileOut << "-";
				fileOut << '+';

				for (int i = 0; i < list.maxGen_; i++)
					fileOut << "-";
				fileOut << '+';

				for (int i = 0; i < list.maxAud_; i++)
					fileOut << "-";
				fileOut << '+';

				for (int i = 0; i < list.maxAge_; i++)
					fileOut << "-";
				fileOut << '+' << endl;

				fileOut << "|Название";
				for (int i = 0; i < list.maxComp_ - 8; i++)
					fileOut << " ";

				fileOut << "|Автор";
				for (int i = 0; i < list.maxAuth_ - 5; i++)
					fileOut << " ";

				fileOut << "|Жанр";
				for (int i = 0; i < list.maxGen_ - 4; i++)
					fileOut << " ";

				fileOut << "|Рейтинг|Ограничения|" << endl;

				fileOut << "+";
				for (int i = 0; i < list.maxComp_; i++)
					fileOut << "-";
				fileOut << '+';

				for (int i = 0; i < list.maxAuth_; i++)
					fileOut << "-";
				fileOut << '+';

				for (int i = 0; i < list.maxGen_; i++)
					fileOut << "-";
				fileOut << '+';

				for (int i = 0; i < list.maxAud_; i++)
					fileOut << "-";
				fileOut << '+';

				for (int i = 0; i < list.maxAge_; i++)
					fileOut << "-";
				fileOut << '+' << endl;

				int temp;
				for (int i = 0; i < list.count_; i++) {
					fileOut << "|" << list.playbook_[i].compositionName_;
					temp = list.playbook_[i].compositionName_.compositionName_.length();
					for (int i = 0; i < list.maxComp_ - temp; i++)
						fileOut << ' ';

					fileOut << "|" << list.playbook_[i].authorName_;
					temp = list.playbook_[i].authorName_.authorName_.length();
					for (int i = 0; i < list.maxAuth_ - temp; i++)
						fileOut << ' ';

					fileOut << "|" << list.playbook_[i].genre_;
					temp = list.playbook_[i].genre_.genre_.length();
					for (int i = 0; i < list.maxGen_ - temp; i++)
						fileOut << ' ';

					fileOut << "|  " << list.playbook_[i].audienceRating_ << "  |";

					fileOut << "    " << list.playbook_[i].ageRestrictions_;
					temp = list.playbook_[i].ageRestrictions_.ageRestrictions_.length();
					for (int i = 0; i < list.maxAge_ - temp - 4; i++)
						fileOut << ' ';
					fileOut << "|" << endl;

					fileOut << "+";
					for (int i = 0; i < list.maxComp_; i++)
						fileOut << "-";
					fileOut << '+';

					for (int i = 0; i < list.maxAuth_; i++)
						fileOut << "-";
					fileOut << '+';

					for (int i = 0; i < list.maxGen_; i++)
						fileOut << "-";
					fileOut << '+';

					for (int i = 0; i < list.maxAud_; i++)
						fileOut << "-";
					fileOut << '+';

					for (int i = 0; i < list.maxAge_; i++)
						fileOut << "-";
					fileOut << '+' << endl;
				}
			}

			if (list.count_ != 0) {
				fileOut << endl << "Список жанров и средняя зрительская оценка" << endl;

				fileOut << "+";
				for (int i = 0; i < list.maxGen_; i++)
					fileOut << "-";
				fileOut << '+';

				for (int i = 0; i < list.maxAud_; i++)
					fileOut << "-";
				fileOut << '+' << endl;

				fileOut << "|Жанр";
				for (int i = 0; i < list.maxGen_ - 4; i++)
					fileOut << " ";

				fileOut << "|Рейтинг|" << endl;

				fileOut << "+";
				for (int i = 0; i < list.maxGen_; i++)
					fileOut << "-";
				fileOut << '+';

				for (int i = 0; i < list.maxAud_; i++)
					fileOut << "-";
				fileOut << '+' << endl;

				int temp;
				for (int i = 0; i < list.genreList_.size(); i++) {
					fileOut << "|" << list.genreList_[i].genre_;
					temp = list.genreList_[i].genre_.genre_.length();
					for (int i = 0; i < list.maxGen_ - temp; i++)
						fileOut << ' ';

					fileOut << "|  " << setprecision(2) << list.ratingList_[i].audienceRating_ << "  |" << endl;

					fileOut << "+";
					for (int i = 0; i < list.maxGen_; i++)
						fileOut << "-";
					fileOut << '+';

					for (int i = 0; i < list.maxAud_; i++)
						fileOut << "-";
					fileOut << '+' << endl;

				}

				// тест перегруженных операций
				//Spectacle ob1, ob2;
				//ob1.audienceRating_.audienceRating_ = 8;
				//ob2.audienceRating_.audienceRating_ = 8;

				//fileOut << " <= " << (ob1 <= ob2 ) << endl; //1
				//fileOut << " == " << (ob1 == ob2) << endl; // 1

				//ob1.audienceRating_.audienceRating_ = 6;//0
				//ob2.audienceRating_.audienceRating_ = 4;//0

				//fileOut << " <= " << (ob1 <= ob2) << endl;
				//fileOut << " == " << (ob1 == ob2) << endl;
				//fileOut << " += m" << (ob1 += ob2) << endl;
				//fileOut << " ++1 " << (++ob1) << endl;
				//fileOut << " 2++ " << (ob2++) << endl;
			}
			fileOut.close();

			cout << "Новый файл: " << endl;
			fileIn.open("result.txt");
			while (getline(fileIn, str)) {
				cout << str << endl;
			}
			fileIn.close();
		}

	}
	catch (ExceptionFile &ex) {
		cerr << ex.what() << endl;
	}

	system("pause");
	return 0;
}