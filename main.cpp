#include "SudokuBoard.h"
#include "SudokuSolver.h"

int main() {
    SudokuBoard sudokuBoard;
    if (sudokuBoard.loadFromFile("test.txt")) {
        SudokuSolver solver(sudokuBoard);
        solver.solve();
    }
    return 0;
}
