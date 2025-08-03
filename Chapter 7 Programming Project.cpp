// Chapter 7 Programming Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

//global variables I will use later in various modules
const int NUMQ = 20;
const double PASSPERC = 70;//70% is the minimum passing grade

//function prototypes


void getAnswers(const string& filename, char ANSWERS[]);
//loads data from a file
int gradeExam(const char CORRECT[], const char STUA[], int MISSQ[], char MISSA[][2]);
//compares students against the answer key
void writeReport(const int MISSQ[], int NUMMISS, const char MISSA[][2]);
//formats and outputs the response 
//checks if student passes or fails from percentage 









int main()
{
   
	char CORRECT[NUMQ];//the answer key from the file
	char STUA[NUMQ];//student response from the file
	int MISSQ[NUMQ];//the question number that is incorrect
	char MISSA[NUMQ][2];//pair of answers
	//loads the file and accesses the appropiate module
	getAnswers("CorrectAnswers.txt", CORRECT);
	getAnswers("StudentAnswers.txt", STUA);
	//the grader of the exam 
	int WRONGA = gradeExam(CORRECT, STUA, MISSQ, MISSA);
	//the output of the report
	writeReport(MISSQ, WRONGA, MISSA);

	return 0;



}



void getAnswers(const string& filename, char ANSWERS[]) {

	ifstream File(filename);

	//file check if it opened correctly
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
	//compares each answers
	for (int f = 0; f < NUMQ; f++) {

		if (CORRECT[f] != STUA[f]) {


			MISSQ[START] = f + 1;//MAKES QUESTION START AT 1


			MISSA[START][0] = CORRECT[f];
			MISSA[START][1] = STUA[f];

			START++;
		}





	}



	return START;




}


//the output module
void writeReport(const int MISSQ[], int NUMMISS, const char MISSA[][2]) {




	double PERCENTAGE = (NUMQ - NUMMISS) * 100 / NUMQ;


	cout << "Exam Report\n\n";//for formatting at the end
	cout << "# of Missed Questions:\t" << NUMMISS << endl;

	if (NUMMISS > 0) {

		cout << "Missed Questions and Correct Answers:\n\n";
		cout << "Question\tCorrect Answer\tYour Answer\n";

		for (int i = 0; i < NUMMISS; i++) {
			//generates the coreection/grading
			cout << setw(4) << MISSQ[i] << "\t\t"<< setw(8) << MISSA[i][0] << "\t\t" << setw(8) << MISSA[i][1] << endl;
			 


		}



	}

	else{
		cout << "No Answers Incorrect";

	}


	cout << fixed << setprecision(2);
	cout << "\nTest Scores:\t" << PERCENTAGE << "%\n";


	if (PERCENTAGE >= PASSPERC) {


		cout << "Pass";



	}

	else {

		cout << "Fail";

	}













}





