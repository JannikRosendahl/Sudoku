//
// Created by JannikRosendahl on 18/01/2021.
//

#include <vector>
#include <iostream>
#include <fstream>
#include "Sudoku.h"

using namespace std;

void test_sudoku(Sudoku &sudoku) {
    sudoku.print();
    cout << "sudoku.check() = " << (sudoku.check() ? "true" : "false") << endl << endl;
    sudoku.solve();
    sudoku.print();
    cout << "sudoku.check() = " << (sudoku.check() ? "true" : "false") << endl << endl << endl << endl;
}

void test_showcase() {
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
            {8, 4, 9, 0, 1, 0, 0, 0, 0,},
            {2, 3, 0, 6, 4, 7, 1, 8, 9,},
            {1, 0, 6, 9, 2, 8, 5, 4, 3,},
            {6, 9, 7, 1, 8, 4, 3, 0, 0,},
            {3, 8, 2, 0, 0, 6, 9, 1, 0,},
            {4, 0, 0, 0, 9, 2, 8, 6, 7,},
            {7, 1, 0, 4, 3, 0, 6, 0, 2,},
            {5, 0, 4, 8, 0, 9, 7, 3, 1,},
            {9, 6, 3, 0, 7, 1, 4, 0, 0,}
    };
    //unfinished sudoku hard
    vector<vector<int>> grid_4 = {
            {0, 0, 0, 0, 8, 0, 4, 0, 0,},
            {0, 0, 9, 0, 3, 1, 0, 8, 0,},
            {0, 0, 0, 0, 6, 0, 0, 0, 2,},
            {9, 0, 0, 0, 0, 4, 0, 0, 0,},
            {0, 0, 5, 8, 0, 0, 0, 2, 0,},
            {2, 8, 0, 0, 0, 0, 0, 0, 1,},
            {6, 0, 0, 3, 0, 0, 9, 0, 0,},
            {0, 0, 0, 0, 0, 0, 0, 3, 0,},
            {0, 0, 8, 0, 0, 0, 2, 4, 0,}
    };
    //unfinished sudoku hard 1
    vector<vector<int>> grid_5 = {
            {0, 0, 6, 7, 0, 9, 2, 3, 0,},
            {0, 0, 0, 0, 1, 0, 7, 0, 0,},
            {0, 0, 0, 0, 0, 3, 0, 0, 0,},
            {8, 0, 0, 0, 0, 0, 3, 2, 5,},
            {0, 4, 0, 2, 0, 8, 0, 9, 0,},
            {1, 2, 7, 0, 0, 0, 0, 0, 8,},
            {0, 0, 0, 5, 0, 0, 0, 0, 0,},
            {0, 0, 3, 0, 7, 0, 0, 0, 0,},
            {0, 7, 4, 3, 0, 1, 6, 0, 0,}
    };
    //unfinished sudoku specifically engineered to counter backtracking algorithms
    vector<vector<int>> grid_6 = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0,},
            {0, 0, 0, 0, 0, 3, 0, 8, 5,},
            {0, 0, 1, 0, 2, 0, 0, 0, 0,},
            {0, 0, 0, 5, 0, 7, 0, 0, 0,},
            {0, 0, 4, 0, 0, 0, 1, 0, 0,},
            {0, 9, 0, 0, 0, 0, 0, 0, 0,},
            {5, 0, 0, 0, 0, 0, 0, 7, 3,},
            {0, 0, 2, 0, 1, 0, 0, 0, 0,},
            {0, 0, 0, 0, 4, 0, 0, 0, 9,},
    };

    Sudoku sudoku = Sudoku(grid_1);
    cout << "already solved sudoku" << endl;
    test_sudoku(sudoku);

    sudoku = Sudoku(grid_2);
    cout << "wrongly filled sudoku" << endl;
    test_sudoku(sudoku);


    sudoku = Sudoku(grid_3);
    cout << "easy sudoku" << endl;
    test_sudoku(sudoku);


    sudoku = Sudoku(grid_4);
    cout << "hard sudoku" << endl;
    test_sudoku(sudoku);


    sudoku = Sudoku(grid_5);
    cout << "harder sudoku" << endl;
    test_sudoku(sudoku);

    /*  this one will take too long taking the standard backtracking approach
    sudoku = Sudoku(grid_6);
    cout << "sudoku build to resist backtracking" << endl;
    test_sudoku(sudoku);
    */
}

int main(int argc, char **argv) {

    if (argc == 1) {
        //no argument given: show off some tests
        test_showcase();
        return 0;
    }

    if (argc > 1) {
        if (std::string(argv[1]) == "-help" || std::string(argv[1]) == "--help") {
            cout << "usage:\t./main\t\t\t|\tshow some tests" << endl;
            cout
                    << "\t./main [filename]\t|\tsolve sudoku from file. file has to contain 81 integers, '0' for 'empty' spots"
                    << endl;
            return 0;
        }
    }

    //try to read sudoku from file
    ifstream input_file(argv[1]);
    if (!input_file.is_open()) {
        cout << "Could not open file - '" << argv[1] << "'" << endl;
        return 1;
    }

    int number;
    vector<int> numbers;
    while (input_file >> number) {
        numbers.push_back(number);
    }

    Sudoku sudoku = Sudoku(numbers);
    test_sudoku(sudoku);


    input_file.close();
    return 0;
}