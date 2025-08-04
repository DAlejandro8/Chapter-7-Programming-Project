
#include <iostream>
#include <fstream>
#include<vector>
#include<string>
using namespace std;

// global constants
const int PLAY = 0;
const int X_WIN = 1;//player one
const int O_WIN = 2;//player two
const int TIE = 3;
const int WINNER = 4;
const int SPACE_LEFT = 5;
const int NO_SPACE = 6;

// Function prototypes
void initializeBoard(char board[3][3]);//3 by 3 board to play on module
void displayBoard(const char board[3][3]);
void placeToken(char board[3][3], char token);
void getLocation(int& row, int& col, const char board[3][3]);
int getBoardState(const char board[3][3], char token);
int checkForWinner(const char board[3][3], char token);





int main() {
    //usually, I make them capitalized, but I changed it up because it was causing mistakes in previous programs 
    char board[3][3];
    char player1_token = 'X';
    char player2_token = 'O';
    int boardState = PLAY;







    initializeBoard(board);
    displayBoard(board);






    while (boardState == PLAY) {//looping till game ends
        // Player 1
        cout << "Player 1's turn (X)\n";



        placeToken(board, player1_token);
        displayBoard(board);


        boardState = getBoardState(board, player1_token);

        if (boardState != PLAY) break;




        // Player 2
        cout << "Player 2's turn (O)\n";



        placeToken(board, player2_token);
        displayBoard(board);



        boardState = getBoardState(board, player2_token);
    }







    // Game over 
    //results from game
    //all of these call from global constants
    //the output depending on the results of game
    if (boardState == X_WIN) {
        cout << "Player 1 (X) wins!\n";
    }







    else if (boardState == O_WIN) {

        cout << "Player 2 (O) wins!\n";
    }









    else if (boardState == TIE) {


        cout << "The game is a tie!\n";
    }

    return 0;
}











//3 by 3 board to play on module
void initializeBoard(char board[3][3]) {





    //looping to create star 3x3 grid
    for (int i = 0; i < 3; i++) {




        for (int j = 0; j < 3; j++) {






            board[i][j] = '*';



       
        
        
        }



    }






}












// this odule gives the other information like labelling the columns and rows
void displayBoard(const char board[3][3]) {




    cout << "\n   1 2 3\n"; // Column numbers




    for (int i = 0; i < 3; i++) {




        cout << i + 1 << " "; // Row number


        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j];
        }



        cout << endl;
    }





    cout << endl;


}








//this module is to place the star in the correct location
//it calls on getLocation to actually find out where the player would place it 
void placeToken(char board[3][3], char token) {



    int row, col;


    getLocation(row, col, board);
    board[row][col] = token;


}













//gets the players input on where to place star
void getLocation(int& row, int& col, const char board[3][3]) {




    bool valid = false;
    //loops if invalid response
    while (!valid) {




        // Get row input
        cout << "Enter row (1-3): ";
        cin >> row;//input of player




        while (row < 1 || row > 3) {


            cout << "Invalid row. Enter row (1-3): ";
            cin >> row;

        }

        // Get column input
        cout << "Enter column (1-3): ";
        cin >> col;//input of player



        while (col < 1 || col > 3) {


            cout << "Invalid column. Enter column (1-3): ";
            cin >> col;

        }

        // Converting to 0-based index
        row--;
        col--;







        // This Checks if space is available just incase
        if (board[row][col] == '*') {


            valid = true;
        }





        else {


            cout << "That space is already taken. Please choose another.\n";
        }






    }



}







//returns who the winner is and the state of the board
//based on what checkForWinner outputs
int getBoardState(const char board[3][3], char token) {


    int state = checkForWinner(board, token);




    if (state == WINNER) {


        return (token == 'X') ? X_WIN : O_WIN;
    }




    else if (state == NO_SPACE) {

        return TIE;
    }




    else {


        return PLAY;
    }






}









//This module checks to see if someone has won
//return WINNER if someone actully won
//Space left and no space are what is called back respectively 
//no space left is tie and game ends
//space left means the games continue
int checkForWinner(const char board[3][3], char token) {




    // Check rows for winner
    for (int i = 0; i < 3; i++) {


        if (board[i][0] == token && board[i][1] == token && board[i][2] == token) {
            return WINNER;


        }




    }

    // Check columns for winner
    for (int j = 0; j < 3; j++) {



        if (board[0][j] == token && board[1][j] == token && board[2][j] == token) {
            return WINNER;



        }



    }




    // Check diagonals for winner
    if (board[0][0] == token && board[1][1] == token && board[2][2] == token) {
        return WINNER;



    }





    if (board[0][2] == token && board[1][1] == token && board[2][0] == token) {


        return WINNER;

    }





    // Check for empty spaces
    for (int i = 0; i < 3; i++) {



        for (int j = 0; j < 3; j++) {



            if (board[i][j] == '*') {


                return SPACE_LEFT;
            }
        }
    }





    // No winner and no spaces left
    return NO_SPACE;




}

























