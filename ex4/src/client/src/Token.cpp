//
// Created by shulamit on 10/30/17.
//

#include "Token.h"

void Token :: toggle() {
    if(tv == White) {
        tv = Black;
    }
    else {
        tv = White;
    }
}

void Token :: setValue(TokenValue tv1) {
    tv = tv1;
}

TokenValue Token :: getOppositeValue(TokenValue tv) {
    if(tv == Black)
    {
        return White;
    }
    else if(tv == White)
    {
        return Black;
    }
    else
    {
        return Empty;
    }
}

bool Token :: isWhite() {
    if(tv == White) {
        return true;
    }
    else {
        return false;
    }
}

bool Token :: isEmpty() const{
    if(tv == Empty) {
        return true;
    }
    else {
        return false;
    }
}

bool Token :: isBlack() {
    if(tv == Black) {
        return true;
    }
    else {
        return false;
    }
}

TokenValue Token :: getValue() {
    return tv;
}
//