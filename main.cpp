//
// Created by JannikRosendahl on 18/01/2021.
//

#include <vector>
#include <iostream>
#include "Sudoku.h"

using namespace std;

int main(int argc, char** argv) {
    //solved sudoku
    vector<vector<int>> grid_1 = {
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {4, 5, 6, 7, 8, 9, 1, 2, 3},
            {7, 8, 9, 1, 2, 3, 4, 5, 6},
            {2, 3, 4, 5, 6, 7, 8, 9, 1},
            {5, 6, 7, 8, 9, 1, 2, 3, 4},
            {8, 9, 1, 2, 3, 4, 5, 6, 7},
            {3, 4, 5, 6, 7, 8, 9, 1, 2},
            {6, 7, 8, 9, 1, 2, 3, 4, 5},
            {9, 1, 2, 3, 4, 5, 6, 7, 8}
    };
    //incorrectly solved sudoku, rows+cols finished, squares not
    vector<vector<int>> grid_2 = {
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {2, 3, 4, 5, 6, 7, 8, 9, 1},
            {3, 4, 5, 6, 7, 8, 9, 1, 2},
            {4, 5, 6, 7, 8, 9, 1, 2, 3},
            {5, 6, 7, 8, 9, 1, 2, 3, 4},
            {6, 7, 8, 9, 1, 2, 3, 4, 5},
            {7, 8, 9, 1, 2, 3, 4, 5, 6},
            {8, 9, 1, 2, 3, 4, 5, 6, 7},
            {9, 1, 2, 3, 4, 5, 6, 7, 8}
    };
    //unfinished sudoku
    vector<vector<int>> grid_3 = {
            {8, 4, 9, 0, 1, 0, 0, 0, 0, },
            {2, 3, 0, 6, 4, 7, 1, 8, 9, },
            {1, 0, 6, 9, 2, 8, 5, 4, 3, },
            {6, 9, 7, 1, 8, 4, 3, 0, 0, },
            {3, 8, 2, 0, 0, 6, 9, 1, 0, },
            {4, 0, 0, 0, 9, 2, 8, 6, 7, },
            {7, 1, 0, 4, 3, 0, 6, 0, 2, },
            {5, 0, 4, 8, 0, 9, 7, 3, 1, },
            {9, 6, 3, 0, 7, 1, 4, 0, 0, }
    };
    //unfinished sudoku hard
    vector<vector<int>> grid_4 = {
        {0, 0, 0, 0, 8, 0, 4, 0, 0, },
        {0, 0, 9, 0, 3, 1, 0, 8, 0, },
        {0, 0, 0, 0, 6, 0, 0, 0, 2, },
        {9, 0, 0, 0, 0, 4, 0, 0, 0, },
        {0, 0, 5, 8, 0, 0, 0, 2, 0, },
        {2, 8, 0, 0, 0, 0, 0, 0, 1, },
        {6, 0, 0, 3, 0, 0, 9, 0, 0, },
        {0, 0, 0, 0, 0, 0, 0, 3, 0, },
        {0, 0, 8, 0, 0, 0, 2, 4, 0, }
    };
    vector<vector<int>> grid_5 = {
        {0, 0, 6, 7, 0, 9, 2, 3, 0, },
        {0, 0, 0, 0, 1, 0, 7, 0, 0, },
        {0, 0, 0, 0, 0, 3, 0, 0, 0, },
        {8, 0, 0, 0, 0, 0, 3, 2, 5, },
        {0, 4, 0, 2, 0, 8, 0, 9, 0, },
        {1, 2, 7, 0, 0, 0, 0, 0, 8, },
        {0, 0, 0, 5, 0, 0, 0, 0, 0, },
        {0, 0, 3, 0, 7, 0, 0, 0, 0, },
        {0, 7, 4, 3, 0, 1, 6, 0, 0, }
    };

    vector<vector<int>> grid_6 = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, },
        {0, 0, 0, 0, 0, 3, 0, 8, 5, },
        {0, 0, 1, 0, 2, 0, 0, 0, 0, },
        {0, 0, 0, 5, 0, 7, 0, 0, 0, },
        {0, 0, 4, 0, 0, 0, 1, 0, 0, },
        {0, 9, 0, 0, 0, 0, 0, 0, 0, },
        {5, 0, 0, 0, 0, 0, 0, 7, 3, },
        {0, 0, 2, 0, 1, 0, 0, 0, 0, },
        {0, 0, 0, 0, 4, 0, 0, 0, 9, },
    };

    /*
    Sudoku sudoku_1 = Sudoku(grid_1);
    sudoku_1.print();
    cout << "sudoku.check() = " << (sudoku_1.check() ? "true" : "false") << endl << endl;
    sudoku_1.solve();
    sudoku_1.print();
    cout << "sudoku.check() = " << (sudoku_1.check() ? "true" : "false") << endl << endl;


    Sudoku sudoku_2 = Sudoku(grid_2);
    sudoku_2.print();
    cout << "sudoku.check() = " << (sudoku_2.check() ? "true" : "false") << endl << endl;
    sudoku_2.solve();
    sudoku_2.print();
    cout << "sudoku.check() = " << (sudoku_2.check() ? "true" : "false") << endl << endl;
    */

    Sudoku sudoku_3 = Sudoku(grid_3);
    sudoku_3.print();
    cout << "sudoku.check() = " << (sudoku_3.check() ? "true" : "false") << endl << endl;
    sudoku_3.solve();
    sudoku_3.print();
    cout << "sudoku.check() = " << (sudoku_3.check() ? "true" : "false") << endl << endl;


    Sudoku sudoku_4 = Sudoku(grid_4);
    sudoku_4.print();
    cout << "sudoku.check() = " << (sudoku_4.check() ? "true" : "false") << endl << endl;
    sudoku_4.solve();
    sudoku_4.print();
    cout << "sudoku.check() = " << (sudoku_4.check() ? "true" : "false") << endl << endl;

    /*
    Sudoku sudoku_5 = Sudoku(grid_5);
    sudoku_5.print();
    cout << "sudoku.check() = " << (sudoku_5.check() ? "true" : "false") << endl << endl;
    sudoku_5.solve();
    sudoku_5.print();
    cout << "sudoku.check() = " << (sudoku_5.check() ? "true" : "false") << endl << endl;
    */

    return 0;
}