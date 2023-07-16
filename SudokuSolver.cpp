#include "SudokuSolver.h"
#include <fstream>
#include <iostream>

SudokuSolver::SudokuSolver(SudokuBoard& sudokuBoard) {
    board = sudokuBoard.getBoard();
    //sudokuBoard.printBoard();
}

bool SudokuSolver::isSafe(int row, int col, int num) {
    // Checking the row
    for (int x = 0; x <= 8; x++) {
        if (board[row][x] == num) {
            return false;
        }
    }

    // Checking the column
    for (int x = 0; x <= 8; x++) {
        if (board[x][col] == num) {
            return false;
        }
    }

    // Checking the square
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

bool SudokuSolver::solveSudoku() {
    int row = 0;
    int col = 0;
    bool isEmpty = true;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) {
            break;
        }
    }

    if (isEmpty) {
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (isSafe(row, col, num)) {
            board[row][col] = num;
            if (solveSudoku()) {
                return true;
            }
            else {
                board[row][col] = 0;
            }
        }
    }
    return false;
}

bool SudokuSolver::solve() {
    if (solveSudoku() == true) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
        return true;
    }
    else {
        std::cout << "No solution exists" << std::endl;
        return false;
    }
}
