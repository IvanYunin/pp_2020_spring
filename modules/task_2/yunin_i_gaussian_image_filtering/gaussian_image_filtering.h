// Copyright 2020 Ivan Yunin
#ifndef MODULES_TASK_2_YUNIN_I_GAUSSIAN_IMAGE_FILTERING_GAUSSIAN_IMAGE_FILTERING_H_
#define MODULES_TASK_2_YUNIN_I_GAUSSIAN_IMAGE_FILTERING_GAUSSIAN_IMAGE_FILTERING_H_
#include <cstdint>
#include <vector>

inline int get_left_border(int, int);
inline int get_right_border(int, int);
void filter_on_line(double*, uint8_t*, uint8_t*, int, int, int);
void generate_random_image(uint8_t*, int, int);
void apply_filter(uint8_t*, uint8_t*, int, int);

#endif  // MODULES_TASK_2_YUNIN_I_GAUSSIAN_IMAGE_FILTERING_GAUSSIAN_IMAGE_FILTERING_H_
