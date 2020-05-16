// Copyright 2020 Ivan Yunin
#include <algorithm>
#include <cmath>
#include <ctime>
#include <numeric>
#include <random>
#include <stdexcept>
#include "../../modules/task_1/yunin_i_gaussian_image_filtering/gaussian_image_filtering.h"


static int offset = 0;
static const double filter[9] = { 1.0/16, 1.0/8, 1.0/16,
    1.0/8, 1.0/4, 1.0/8,
    1.0/16, 1.0/8, 1.0/16 };

inline int get_left_border(int curr_coord, int min_coord) {
    if (curr_coord - 1 < 0)
        return 0;
    else
        return -1;
}

inline int get_right_border(int curr_coord, int max_coord) {
    if (curr_coord - max_coord == -1)
        return 0;
    else
        return 1;
}

void filter_on_line(uint8_t* img, uint8_t* res, int cols_num, int rows_num, int curr_row) {
    for (int i = 0; i < cols_num; ++i) {
        double curr_pixel = 0;
        int x_left = get_left_border(i, 0);
        int y_left = get_left_border(curr_row, 0);
        int x_right = get_right_border(i, cols_num);
        int y_right = get_right_border(curr_row, rows_num);

        for (int x = x_left; x <= x_right; ++x) {
            for (int y = y_left; y <= y_right; ++y) {
                curr_pixel += filter[x+1 + (y+1)*3]*img[i+x  + (y)*cols_num];
            }
        }
        res[i] = static_cast<uint8_t>(curr_pixel);
    }
}


void apply_filter(uint8_t* img, uint8_t* res, int cols_num, int rows_num) {
    for (int i = 0; i < rows_num; ++i) {
        filter_on_line(&img[i*cols_num], &res[i*cols_num], cols_num, rows_num, i);
    }
}

void generate_random_image(uint8_t* img, int rows, int cols) {
    std::mt19937 gen;
    gen.seed((unsigned)time(0) + ++offset);
    std::uniform_int_distribution<int> dis(0, 255);
    for (int i = 0; i < rows * cols; ++i) {
        img[i] = static_cast<uint8_t>(dis(gen));
    }
}
