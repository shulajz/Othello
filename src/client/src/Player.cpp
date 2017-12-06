//
// Created by shulamit on 07/11/17.
//

#include <iostream>
#include "Tools.h"
#include "Player.h"
#include "BoardGraphic.h"


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
 * @return the value of the current player.
 */
TokenValue Player :: getIdentity() {
    return tv;
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

void Player ::printAfterTheRealPlayerMove(BoardGraphic *boardGraphic,bool need_to_print) const {

}

bool Player ::isRealPlayer() const {
    return false;
}

bool Player ::isRemotePlayer() const {
    return false;
}

ReversiClient* Player :: getClient()const{}

bool Player :: isMyTurn() {
    return true;
}

bool Player::isDemoPlayer(){
    return false;
}


