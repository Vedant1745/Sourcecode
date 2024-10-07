#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << " | ";
        }
        cout << "\n---------\n";
    }
}

char checkWinner(const vector<vector<char>>& board) {
    // Check rows
    for (const auto& row : board) {
        if (row[0] == row[1] && row[1] == row[2] && row[0] != ' ') {
            return row[0];
        }
    }

    // Check columns
    for (int col = 0; col < 3; ++col) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col] && board[0][col] != ' ') {
            return board[0][col];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }

    return ' ';
}

bool isBoardFull(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';

    while (true) {
        printBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        
        int row, col;
        cin >> row >> col;

        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        board[row][col] = currentPlayer;
        
        char winner = checkWinner(board);
        if (winner != ' ') {
            printBoard(board);
            cout << "Player " << winner << " wins!\n";
            break;
        }

        if (isBoardFull(board)) {
            printBoard(board);
            cout << "It's a draw!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
