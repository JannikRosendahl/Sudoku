//
// Created by JannikRosendahl on 18/01/2021.
//

#include "Sudoku.h"

#include <iostream>
#include <chrono>

Sudoku::Sudoku(std::vector<std::vector<int>> grid) {
    this->grid = std::move(grid);
    set_bitsets();
    set_input_mask();
}

void Sudoku::set_bitsets() {
    //set row bitsets
    row_bitsets.clear();
    for(int i=0; i<9; i++) {
        std::bitset<9> bit_row(0);
        for(int j=0; j<9; j++) {
            bit_row[grid[i][j]-1] = true;
        }
        row_bitsets.push_back(bit_row);
    }

    //set column bitsets
    col_bitsets.clear();
    for(int i=0; i<9; i++) {
        std::bitset<9> bit_column(0);
        for(int j=0; j<9; j++) {
            bit_column[grid[j][i]-1] = true;
        }
        col_bitsets.push_back(bit_column);
    }

    //set square bitsets
    sqr_bitsets.clear();
    for(int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            std::bitset<9> bit_square(0);
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    bit_square[grid[i+k*3][j+l*3]-1] = true;
                }
            }
            sqr_bitsets.push_back(bit_square);
        }
    }
}

void Sudoku::set_input_mask() {
    for(int i=0; i<9; i++) {
        input_mask.emplace_back(0);
        for(int j=0; j<9; j++) {
            input_mask[i][j] = grid[i][j] == 0;
        }
    }
}

void Sudoku::print() {
    std::cout << "-------------------" << std::endl;
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(grid[i][j]) {
                std::cout << grid[i][j];
            } else {
                std::cout << '_';
            }
            std::cout << ' ';

            if(!((j+1)%3))
                std::cout << " ";
        }
        std::cout << std::endl;
        if(!((i+1)%3) && (i+1)<9) {
            std::cout << std::endl;
        }
    }
    std::cout << "-------------------" << std::endl;
}

bool Sudoku::check() {
    set_bitsets();
    for(auto bitset : row_bitsets) {
        for(int i=0; i<9; i++) {
            if(!bitset[i])
                return false;
        }
    }
    for(auto bitset : col_bitsets) {
        for(int i=0; i<9; i++) {
            if(!bitset[i])
                return false;
        }
    }
    for(auto bitset : sqr_bitsets) {
        for(int i=0; i<9; i++) {
            if(!bitset[i])
                return false;
        }
    }
    return true;
}

bool Sudoku::check_position(int x, int y, int k) {
    int n=k-1;
    int temp_row = x/3;
    int temp_col = y/3;
    int sqr_pos = temp_row*3 + temp_col;

    if(row_bitsets[x][n]) {
        if(debug) std::cout << "\t" << k << " already in row " << x << std::endl;
        return false;
    }
    if(col_bitsets[y][n]) {
        if(debug) std::cout << "\t" << k << " already in col " << y << std::endl;
        return false;
    }
    if(sqr_bitsets[sqr_pos][n]) {
        if(debug) std::cout << "\t" << k << " already in sqr " << sqr_pos << std::endl;
        return false;
    }


    return true;
}

void Sudoku::solve() {
    std::cout << "starting to solve sudoku..." << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    solve_rec();
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "finished solving sudoku in " << iterations << " iterations (" << elapsed.count() << "s)" << std::endl;
}


bool Sudoku::solve_rec() {
    iterations++;

    int x = -1;
    int y = -1;

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(grid[i][j]==0) {
                x = i;
                y = j;
                break;
            }
        }
    }
    if(x == -1 && y == -1) {
        return true;
    }

    for(int k=1; k<=9; k++) {
        if(check_position(x, y, k)) {
            grid[x][y] = k;
            set_bitsets();
            if(solve_rec()) {
                return true;
            }
            grid[x][y] = 0;
            set_bitsets();
        }
    }
    return false;
}

