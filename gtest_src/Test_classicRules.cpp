//
// Created by shulamit on 24/11/17.
//

#include "Test_classicRules.h"
#include "../src/RealPlayer.h"

TEST_F(Test_classicRules, getlegalCoordinates){

    vector<Coordinate> validCoordinates;
    Player *realPlayer = new RealPlayer(Black);
    classicRules.getLegalCoordinates(*board_8x8, realPlayer,
                                    validCoordinates);
    ASSERT_TRUE(validCoordinates[0].row ==  3 && validCoordinates[0].col == 4
                && validCoordinates[1].row ==  4 && validCoordinates[1].col == 3
                && validCoordinates[2].row ==  5 && validCoordinates[2].col == 6
                && validCoordinates[3].row ==  6 && validCoordinates[3].col == 5);
}
