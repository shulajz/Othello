//
// Created by shulamit on 10/31/17.
//

#ifndef OTHELLO_TOOLS_H
#define OTHELLO_TOOLS_H
#define DIM 5

enum TokenValue {
    Black,
    White,
    Empty,
};
enum Situation {
    IllegelMove,NoMovesForAll,Next,AskForRowAndCol,Wait
};

enum StatusForClient {
    NoMove = -2, End = -3
};

class Tools {

};


#endif //OTHELLO_TOOLS_H
