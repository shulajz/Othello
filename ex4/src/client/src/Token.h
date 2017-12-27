//
// Created by shulamit on 10/30/17.
//

#ifndef OTHELLO_TOKEN_H
#define OTHELLO_TOKEN_H

#include "Tools.h"
#include "Token.h"

class Token {
protected:
    TokenValue tv;
public:
    virtual void draw() const = 0;
    TokenValue getOppositeValue(TokenValue tv);
    TokenValue getValue();
    void toggle();//toggle the token
    void setValue(TokenValue tv1);
    bool isWhite();
    bool isBlack();
    bool isEmpty() const;
    virtual ~Token(){};

};


#endif //OTHELLO_TOKEN_H
