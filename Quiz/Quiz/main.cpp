#include <iostream>
#include <fstream>
#include <string>

int main() {
	int loop;
	std::string conti?;

	//for draw
	std::string set;
	int draw;

	//questions and answers
	std::string question[5];
	std::string anser_a[5], anser_b[5], anser_c[5], anser_d[5];
	std::string corect[5];
	std::string anser;

	int points = 0;

	//to the display mechanism
	int line_number = 1;
	std::string line;
	int question_number = 0;
	int nr = 1;

	std::string choice;
	int set_choice;


	//file opener
	std::fstream quiz;
	quiz.open(set, std::ios::in);

	//open check
	if (quiz.good() == false) {
		std::cout << "failed to open file";
		exit(0);
	}

	while (true) {

		if (loop == 0) {

			std::cout << "Welcome to the quiz\n";
			std::cout << "you will answer 5 questions\n";
			std::cout << "there will by four questions\n";
			std::cout << "A,B,C and D\n";
			std::cout << "you must write your answers in capital letters\n";
			std::cout << "\n";
		}

		if (loop == 0) {
			std::cout << "whether you want to continue playing?\n";
			std::cout << "yes or not\n";
			std::cin >> conti;
			if (conti == "no"){
				break;
			}
		}
		loop++;

		std::cout << "do you want to choose a set ?\n";
		std::cout << "write yes or no\n";
		std::cin >> choice;
		system("cls");

		if (choice == "yes") {

			std::cout << "which set you want to use?\n";
			std::cout << "1,2,3,4,5\n";
			std::cin >> set_choice;

			switch (set_choice) {
			case 1: set = "set1.txt"; break;
			case 2: set = "set2.txt"; break;
			case 3: set = "set3.txt"; break;
			case 4: set = "set4.txt"; break;
			case 5: set = "set5.txt"; break;
			default:
				std::cout << "there is no such option"; break;
			}
		}
		else

			//set drawing mechanism
			srand(time(NULL));
		draw = rand() % 5;

		switch (draw) {
		case 0: set = "set1.txt"; break;
		case 1: set = "set2.txt"; break;
		case 2: set = "set3.txt"; break;
		case 3: set = "set4.txt"; break;
		case 4: set = "set5.txt"; break;
		}


		std::cout << "Question" << nr << "\n";

		if (nr == 5) {
			nr = 1;
		}
		nr++;

		//mechanism for extracting text from files
		while (getline(quiz, line)) {
			switch (line_number) {
			case 1: question[question_number] = line; break;
			case 2: anser_a[question_number] = line;  break;
			case 3: anser_b[question_number] = line;  break;
			case 4: anser_c[question_number] = line;  break;
			case 5: anser_d[question_number] = line;  break;
			case 6: corect[question_number] = line;   break;
			}

			if (line_number == 6) {
				line_number = 0;
				question_number++;
			}
			line_number++;
		}

		//a mechanism for displaying questions and answers
		for (int i = 0; i < 5; i++) {

			std::cout << question[i] << "\n";
			std::cout << "A. " << anser_a[i] << "\n";
			std::cout << "B. " << anser_b[i] << "\n";
			std::cout << "C. " << anser_c[i] << "\n";
			std::cout << "D. " << anser_d[i] << "\n";

			std::cout << "your answer:\n";
			std::cin >> anser;

			if (anser == corect[i]) {
				std::cout << "bravo you got a point\n";
				points++;

			}
			else
				std::cout << "wrong no point. correct answer:" << corect[i] << "\n";
		}

		std::cout << "end of quiz. points scored:" << points;

	}

	quiz.close();
}