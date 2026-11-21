#include <iostream>
using namespace std;

void print_board(char board[3][3]) {
    // game board
    cout << "   |   |   " << endl;
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "   |   |   " << endl;
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    const char playerX = 'X';
    const char playerO = 'O';
    char currentPlayer = playerX;
    int row = -1, column = -1;
    char winner = ' ';

    for (int i = 0; i < 9; i++) {
        print_board(board);

        if (winner != ' ') {
            break;
        }

        // asking for player input
        cout << "Current Player is " << currentPlayer << endl;
        while (true) {
            cout << "Enter Row and Column from 1-3." << endl;
            cout << "Row, Column: "; cin >> row >> column;

            if (row < 1 || row > 3 || column < 1 || column > 3) {
                cout << "Invalid input, try again." << endl;
            }
            else if (board[row - 1][column - 1] != ' ') {
                cout << "Tile is full, try again." << endl;
            }
            else {
                break;
            }

            // resetting values
            row = column = -1;
            cin.clear(); // clears error flags
            cin.ignore(10000, '\n'); // discards values
            // skips to the next new line up to 10000 characters
        }

        board[row - 1][column - 1] = currentPlayer;
        currentPlayer = (currentPlayer == playerX ? playerO : playerX);

        // checking winners

        // rows - horizontal
        for (int row = 0; row < 3; row++) {
            if (board[row][0] != ' ' && board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
                winner = board[row][0];
                break;
            }
        }

        //columns - vertical
        for (int column = 0; column < 3; column++) {
            if (board[0][column] != 0 && board[0][column] == board[1][column] && board[1][column] == board[2][column]) {
                winner = board[0][column];
                break;
            }
        }

        // diagonals
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            winner = board[0][0];
        }
        else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            winner = board [0][2];
        }
    }

    if (winner != ' ') {
        print_board(board);
        cout << "Game is over. \nPlayer" << winner << " is the winner!" << endl;
    }
    else {
        print_board(board);
        cout << "Draw!" << endl;
    }

    return 0;
}