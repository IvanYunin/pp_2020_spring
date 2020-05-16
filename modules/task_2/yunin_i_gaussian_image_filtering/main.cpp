// Copyright 2020 Ivan Yunin
#include <gtest/gtest.h>
#include <omp.h>
#include "./gaussian_image_filtering.h"

TEST(Gaussian_Image_Filtering_seq, Can_Filter_Small_Image) {
    const int width = 10;
    const int height = 10;
    uint8_t* img = new uint8_t(width*height);
    uint8_t* res = new uint8_t(width*height);
    generate_random_image(img , width, height);
    apply_filter(img, res, width, height);
    for (int i = 0; i < width * height; ++i) {
        ASSERT_NE(res[i], img[i]);
    }
}

TEST(Gaussian_Image_Filtering_seq, Can_Handle_Images_With_Width_Less_Than_Kernel_Size) {
    const int width = 2;
    const int height = 50;

    uint8_t* img = new uint8_t(width*height);
    uint8_t* res = new uint8_t(width*height);
    generate_random_image(img , width, height);
    apply_filter(img, res, width, height);
    for (int i = 0; i < width * height; ++i) {
        ASSERT_NE(res[i], img[i]);
    }
}

TEST(Gaussian_Image_Filtering_seq, Can_Handle_Images_With_Height_Less_Than_Kernel_Size) {
    const int width = 50;
    const int height = 2;

    uint8_t* img = new uint8_t(width*height);
    uint8_t* res = new uint8_t(width*height);
    generate_random_image(img , width, height);
    apply_filter(img, res, width, height);
    for (int i = 0; i < width * height; ++i) {
        ASSERT_NE(res[i], img[i]);
    }
}

TEST(Gaussian_Image_Filtering_seq, is_correct_for3x3) {
    const int width = 3;
    const int height = 3;

    uint8_t* img = new uint8_t(width*height);
    uint8_t* res = new uint8_t(width*height);
    uint8_t ans[9] = { 15, 31, 15, 31, 63, 31, 15, 31, 15};
    for (int i = 0; i < width * height; ++i) {
        img[i] = 0;
    }
    img[4] = 255;
    apply_filter(img, res, width, height);
    for (int i = 0; i < width * height; ++i) {
        ASSERT_EQ(res[i], ans[i]);
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
