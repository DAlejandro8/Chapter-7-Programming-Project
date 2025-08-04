// Chapter 7 Programming Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include<vector>
#include<string>
using namespace std;




//functional prototyprs 





void getTeams(const string& FILE, vector<string>& TEAMA);
//Reads team names from a file and adds to vector
//outputs all name from file
//program ends if file openning error


int findWinner(const string& TEAMB, const vector<string>& WINNER);
//counts the times the team chosen has won




int main()
{
    //stores team name and winners
    vector<string> TEAMA;
    vector<string> WINNER;

    //reads data files
    //calls onto that module
    getTeams("Teams.txt", TEAMA);
    getTeams("WorldSeriesWinners.txt", WINNER);


    //header for the teams, may be hidden because of how long the team list is
    cout << "Teams\n";

    
    for (const string& TEAMB : TEAMA) {


        cout << TEAMB << endl;

      

    }
    cout << endl;

    //chose to end program or not
    string input;
    while (true) {
        cout << "Enter a team name or quit\n";
        getline(cin, input);

        //has to be exactly "quit" to end it
        if (input == "quit") {

            break;
        }

        bool VALID = false;
        for (const string& TEAMB : TEAMA) {

            if (TEAMB == input) {


                VALID = true;
                break;
            }


        }
        //validating team name
        if (VALID) {

            int WIN = findWinner(input, WINNER);//module call
            cout << "The " << input << " won the World Series " << WIN << " times\n\n";


        }
        else {
            cout << "Invalid Team Name ";


        }




    }

    //check to see that program ended 
    cout << "Done\n";
    return 0;








}






void getTeams(const string& FILE, vector<string>& TEAMA) {
    ifstream inputFILE(FILE);
    //checks if file opened correctly
    if (!inputFILE) {

        cout << "File Error\n";
        exit(1);

    }

    string teamName;
    while (getline(inputFILE, teamName)) {



        TEAMA.push_back(teamName);


    }



    inputFILE.close();
    //always close the file








}






int findWinner(const string& TEAMB, const vector<string>& WINNER) {



    int i = 0;
    //loops to count how many times team won
    for (const string& WON : WINNER) {

        if (WON == TEAMB) {

            i++;
        }

    }





    return i;//returns total wins 






}