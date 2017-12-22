//
// Created by shulamit on 10/31/17.
//

#ifndef OTHELLO_TOOLS_H
#define OTHELLO_TOOLS_H
#define DIM 9

#include <string>

using namespace std;


enum TokenValue {
    Black,
    White,
    Empty,
};
enum Situation {
    IllegelMove,NoMovesForAll,Next,AskForRowAndCol,WaitToMove,WaitToJoin,NoMoveForTheRival
};

enum StatusForClient {
    NoMove = -2, End = -3,
};

class Tools {

};



#endif //OTHELLO_TOOLS_H
