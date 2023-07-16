#pragma once
#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include <vector>
#include "SudokuBoard.h"

class SudokuSolver {
public:
    SudokuSolver(SudokuBoard& sudokuBoard);
    bool solve();

private:
    std::vector<std::vector<int>> board;
    bool isSafe(int row, int col, int num);
    bool solveSudoku();
};

#endif
