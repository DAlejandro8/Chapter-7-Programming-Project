// Chapter 7 Programming Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;


const int NUMQ = 20;
const double PASSPERC = 70;



void getAnswers(const string& filename, char ANSWERS[]);
int gradeExam(const char CORRECT[], const char STUA[], int MISSQ[], char MISSA[][2]);
void writeReport(const int MISSQ[], int NUMMISS, const char MISSA[][2]);










int main()
{
   
	char CORRECT[NUMQ];
	char STUA[NUMQ];
	int MISSQ[NUMQ];
	char MISSA[NUMQ][2];

	getAnswers("correctAnswers.txt", CORRECT);
	getAnswers("StudentAnswers.txt", STUA);

	int WRONGA = gradeExam(CORRECT, STUA, MISSQ, MISSA);

	writeReport(MISSQ, WRONGA, MISSA);

	return 0;



}



void getAnswers(const string& filename, char ANSWERS[]) {

	ifstream File(filename);


	if (!File) {

		cout << "File Error\n";
			exit(1);






	}

	for (int i = 0; i < NUMQ; i++) {


		File >> ANSWERS[i];
		




	}


	File.close();//closes file to not cause issues







}



int gradeExam(const char CORRECT[], const char STUA[], int MISSQ[], char MISSA[][2]) {


	int START = 0;//didn't want to choose a name too similar, starts the number of incorrect at 0

	for (int f = 0; f < NUMQ; f++) {

		if (CORRECT[f] != STUA[f]) {


			MISSQ[START] = f + 1;//MAKES QUESTION START AT 1


			MISSA[START][0] = CORRECT[f];
			MISSA[START][0] = STUA[f];

			START++;
		}





	}



	return START;




}



void writeReport(const int MISSQ[], int NUMMISS, const char MISSA[][2]) {




	double PERCENTAGE = (NUMQ - NUMMISS) * 100 / NUMQ;


	cout << "Exam Report\n\n";//for formatting at the end
	cout << "# of Missed Questions:\t" << NUMMISS << endl;

	if (NUMMISS > 0) {

		cout << "Missed Questions and Correct Answers:\n\n";
		cout << "Question\tCorrect Answer\tYour Answer\n";

		for (int i = 0; i < NUMMISS; i++) {

			cout << setw(4) << MISSQ[i] << "\t\t";
			cout << setw(8) << MISSA[i][0] << "\t\t";
			cout << setw(8) << MISSA[i][1] << endl;


		}



	}

	else{
		cout << "No Answers Incorrect";

	}


	cout << fixed << setprecision(2);
	cout << "\nTest Scores:\t" << PERCENTAGE << "%\n";


	if (PERCENTAGE >= PASSPERC) {


		cout << "Pass/n";



	}

	else {

		cout << "Fail";

	}













}





