//
// Created by JannikRosendahl on 18/01/2021.
//

#ifndef UNTITLED2_SUDOKU_H
#define UNTITLED2_SUDOKU_H


#include <vector>
#include <bitset>

typedef struct point {
    int x, y;
} point;


class Sudoku {

private:

    bool debug = false;

    int iterations = 0;

    std::vector<std::vector<int>> grid;

    std::vector<std::bitset<9>> row_bitsets;
    std::vector<std::bitset<9>> col_bitsets;
    std::vector<std::bitset<9>> sqr_bitsets;

    std::vector<std::bitset<9>> input_mask;

    std::vector<point> input_points;

    void set_bitsets();

    void set_input_mask();

    bool solve_rec();

    bool check_position(int x, int y, int k);

    point first_empty();

public:
    explicit Sudoku(std::vector<std::vector<int>>);

    explicit Sudoku(std::vector<int>);

    void print();

    bool check();

    void solve();

};


#endif //UNTITLED2_SUDOKU_H
