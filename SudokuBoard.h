#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

#include <vector>

class SudokuBoard {
public:
    SudokuBoard();
    bool loadFromFile(const char* filename);
    void printBoard();
    std::vector<std::vector<int>> getBoard();

private:
    std::vector<std::vector<int>> board;
};

#endif