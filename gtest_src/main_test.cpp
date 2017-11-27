/*
 * ex3.c
 *
 *  Created on: Nov 16, 2017
 *      Author:  Shulamit & Or Sha'ashua
 *      ID-Or:311148811
 *      ID-Shulamit:313485690
*/

#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

int main(int argc, char *argv[]) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}