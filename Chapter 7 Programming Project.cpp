// Chapter 7 Programming Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

// Constants for game states
const int PLAY = 0;
const int X_WIN = 1;
const int O_WIN = 2;
const int TIE = 3;
const int WINNER = 4;
const int SPACE_LEFT = 5;
const int NO_SPACE = 6;

// Function prototypes
void initializeBoard(char board[3][3]);
void displayBoard(const char board[3][3]);
void placeToken(char board[3][3], char token);
void getLocation(int& row, int& col, const char board[3][3]);
int getBoardState(const char board[3][3], char token);
int checkForWinner(const char board[3][3], char token);

int main() {
    char board[3][3];
    char player1_token = 'X';
    char player2_token = 'O';
    int boardState = PLAY;

    initializeBoard(board);
    displayBoard(board);

    while (boardState == PLAY) {
        // Player 1's turn
        cout << "Player 1's turn (X)\n";
        placeToken(board, player1_token);
        displayBoard(board);
        boardState = getBoardState(board, player1_token);

        if (boardState != PLAY) break;

        // Player 2's turn
        cout << "Player 2's turn (O)\n";
        placeToken(board, player2_token);
        displayBoard(board);
        boardState = getBoardState(board, player2_token);
    }

    // Game over - display results
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

void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '*';
        }
    }
}

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

void placeToken(char board[3][3], char token) {
    int row, col;
    getLocation(row, col, board);
    board[row][col] = token;
}

void getLocation(int& row, int& col, const char board[3][3]) {
    bool valid = false;

    while (!valid) {
        // Get row input
        cout << "Enter row (1-3): ";
        cin >> row;
        while (row < 1 || row > 3) {
            cout << "Invalid row. Enter row (1-3): ";
            cin >> row;
        }

        // Get column input
        cout << "Enter column (1-3): ";
        cin >> col;
        while (col < 1 || col > 3) {
            cout << "Invalid column. Enter column (1-3): ";
            cin >> col;
        }

        // Convert to 0-based index
        row--;
        col--;

        // Check if space is available
        if (board[row][col] == '*') {
            valid = true;
        }
        else {
            cout << "That space is already taken. Please choose another.\n";
        }
    }
}

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

























