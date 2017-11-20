//
// Created by shulamit on 10/31/17.
//

#include "RealPlayer.h"
#include <iostream>
#include <list>
#include <limits>

using namespace std;

RealPlayer :: RealPlayer(TokenValue tv) {
    this->tv = tv;
}


/**
 * the turn of one of the players.
 */

void RealPlayer :: doOneTurn(GameRules *gameRules, Board &board,
                             vector<Coordinate> &coordinates,
                             Coordinate &input, BoardGraphic *boardGraphic, Player *player) {
    bool inputValid = false;
    while (!inputValid) {
        boardGraphic->printWhosMove(player);
        boardGraphic->printMoves(coordinates);
//        players[currentTurn]->printWhatThePlayerPlayed(inputCoordinate, &m_boardGraphic);

        boardGraphic->printSpecialSituation(AskForRowAndCol);

//        int i = 0;
//        drawValue();
//        cout << " ,It's your move" << endl;
//        cout << "Your possible moves:";
//        while (i != coordinates.size()) {
//            cout << "(" << coordinates[i].row << "," << coordinates[i].col << ") ";
//            i++;
//        }
//        cout << endl;
//        cout << "Please enter your move row,col:";
        //start here

//        cin >> input.row >> input.col;
//        cout << endl;
        while(!(cin>>input.row>>input.col)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            boardGraphic->printSpecialSituation(IllegelMove);
        }
//        if(!input.row || !input.col){
//            cin.clear();
//            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
////            continue;
////            break;
//        }
        for (int i = 0; i < board.getDimensions(); i++) {
           //checks if the input is one of the legal coordinates
            if (input.row == coordinates[i].row && input.col == coordinates[i].col) {
                inputValid = true;
                break;
            }
        }
//        if((input.row >= 'A' && input.row <= 'z' ) || (input.col >= 'A' && input.col <= 'z')) {
//            inputValid = false;
//        }
        if (inputValid) {
            break;
        } else {
//            cout << "Invalid input, please try again" << endl;
            boardGraphic->printSpecialSituation(IllegelMove);
        }
    }
//    board.draw();

}




