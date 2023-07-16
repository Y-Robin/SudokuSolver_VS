#include "SudokuBoard.h"
#include <fstream>
#include <iostream>

SudokuBoard::SudokuBoard() {
    board = std::vector<std::vector<int>>(9, std::vector<int>(9, 0));
}

bool SudokuBoard::loadFromFile(const char* filename) {
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return false;
    }

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            file >> board[i][j];
        }
    }

    file.close();
    return true;
}

void SudokuBoard::printBoard() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<int>> SudokuBoard::getBoard() {
    return board;
}
