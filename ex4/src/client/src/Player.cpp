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
    if (isWhitePlayer())
    {
        tokenValue = Black;
    }
    else
    {
        tokenValue = White;
    }
}

void Player :: printWhatThePlayerPlayed(Coordinate coordinate,
                                        BoardGraphic *boardGraphic) {}

void Player ::printAfterTheRealPlayerMove(BoardGraphic *boardGraphic,
                                          bool need_to_print) const {}

bool Player ::isRealPlayer() const {
    return false;
}

void Player :: setTokenValue(TokenValue tv1) {
    tv = tv1;
}

void Player ::sendMove(Coordinate coordinate){}

void Player ::printNoMoves(BoardGraphic&  m_boardGraphic){
    m_boardGraphic.printWhosMove(this->getValue());
    m_boardGraphic.printSpecialSituation(Next);
}

void Player ::sendEndOfGame(Coordinate inputCoordinate){}


void Player ::sendNoMove(){}

Player ::~ Player(){}

void Player :: setNeedToSendMove(bool boolean){}
