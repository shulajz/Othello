//
// Created by shulamit on 07/11/17.
//

#include <iostream>
#include "Tools.h"
#include "Player.h"



TokenValue Player :: getValue() const {
    return tv;
}
/**
 * checks if its the white turn
 */
bool Player :: isWhitePlayer() const {
    if(tv == White) {
        return true;
    } else {
        return false;
    }
}
/**
 * draws the value of the player
 */
void Player :: drawValue() const {
    if(tv == White) {
        cout << "O";
    } else if (tv == Black){
        cout << "X";
    } else {
        cout << " ";
    }
}
/**
 * switches between the players
 */
void Player :: togglePlayer(TokenValue &tokenValue) {
    if (isWhitePlayer()) {
        tokenValue = Black;
    }
    else
    {
        tokenValue = White;
    }
}

void Player :: printWhatThePlayerPlayed(Coordinate coordinate, BoardGraphic *boardGraphic) {

}

void Player ::printAfterTheRealPlayerMove(BoardGraphic *boardGraphic) const {

}