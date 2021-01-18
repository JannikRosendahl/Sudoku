#include <iostream>
#include <set>
#include <vector>
#include <bitset>

using namespace std;

void print_sudoku(vector<vector<int>> sudoku) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cout << sudoku[i][j] << ' ';
        }
        cout << endl;
    }
}

bool check_bitset(bitset<9> b) {
    for(int i=0; i<9; i++) {
        if(!b[i])
            return false;
    }
    return true;
}

bool check_sudoku(vector<vector<int>> sudoku, bool debug = false) {
    // fast check if checksums are correct, unnecessary work to verify all numbers else
    int checksum = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9;
    int check = 0;
    int check2 = 0;

    for(int i=0; i<9; i++) {
        for (int j = 0; j < 9; j++) {
            check += sudoku[i][j];
            check2 += sudoku[j][i];
        }
        if (check != checksum || check2 != checksum)
            return false;
        check = 0;
        check2 = 0;
    }

    //row bitsets
    if(debug) cout << "printing row bitsets" << endl;
    for(int i=0; i<9; i++) {
        bitset<9> bit_row(0);
        for(int j=0; j<9; j++) {
            bit_row[sudoku[i][j]-1] = 1;
        }

        if(debug) cout << bit_row << endl;
        if(!check_bitset(bit_row))
            return false;
    }
    //column bitsets
    if(debug) cout << "printing column bitsets" << endl;
    for(int i=0; i<9; i++) {
        bitset<9> bit_column(0);
        for(int j=0; j<9; j++) {
            bit_column[sudoku[j][i]-1] = 1;
        }
        if(debug) cout << bit_column << endl;
        if(!check_bitset(bit_column))
            return false;

    }
    //square bitsets
    if(debug) cout << "printing square bitsets" << endl;
    for(int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            bitset<9> bit_square(0);
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    bit_square[sudoku[i+k*3][j+l*3]-1] = 1;
                }
            }
            if(debug) cout << bit_square << endl;
            if(!check_bitset(bit_square))
                return false;

        }
    }

    return true;
}

bool number_is_valid_here(vector<vector<int>> const& sudoku, int x, int y, int k) {
    //check row
    for(int i=0; i<9; i++) {
        if(sudoku[x][i] == k)
            return false;
    }
    //check column
    for(int i=0; i<9; i++) {
        if(sudoku[i][y] == k)
            return false;
    }
    //check square


    return true;
}
vector<vector<int>> solve_sudoku(vector<vector<int>> sudoku) {
    vector<bitset<9>> input_mask;

    for(int i=0; i<9; i++) {
        input_mask.emplace_back(0);
        for(int j=0; j<9; j++) {
            input_mask[i][j] = sudoku[i][j] == 0;
        }
    }

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(input_mask[i][j]) {
                for(int k=1; k<=9; k++) {
                    if(check_sudoku(sudoku)) {
                        cout << "success" << endl;
                        return sudoku;
                    }
                    if(!number_is_valid_here(sudoku, i, j, k)) {
                        sudoku[i][j]++;
                    }
                }
            }
        }
    }



}

int main() {

    std::vector<std::vector<int>> sudoku_1 = {
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
    std::vector<std::vector<int>> sudoku_2 = {
            /*{1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9},
            {1, 2, 3, 4, 5, 6, 7, 8, 9}
            */
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
    std::vector<std::vector<int>> sudoku_3 = {
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

    /*
    print_sudoku(sudoku_1);
    std::cout << (check_sudoku(sudoku_1) ? "True" : "False") << std::endl << std::endl;

    print_sudoku(sudoku_2);
    std::cout << (check_sudoku(sudoku_2) ? "True" : "False") << std::endl << std::endl;

    print_sudoku(sudoku_3);
    std::cout << (check_sudoku(sudoku_3) ? "True" : "False") << std::endl << std::endl;
    */

    solve_sudoku(sudoku_3);


    return 0;
}
