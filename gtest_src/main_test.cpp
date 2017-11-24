//
// Created by shulamit on 23/11/17.
//

#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

int main(int argc, char *argv[]) {
    InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
       return 0;
}