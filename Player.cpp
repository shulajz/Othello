//
// Created by shulamit on 07/11/17.
//

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