//
// Created by shulamit on 10/30/17.
//

#ifndef OTHELLO_CONSOLETOKEN_H
#define OTHELLO_CONSOLETOKEN_H
#include "Token.h"
#include "Board.h"
#include "Tools.h"
#include "string"

using namespace std;




class ConsoleToken: public Token{

public:
    static void drawTokenValue(TokenValue tv);
    ConsoleToken();
    ~ConsoleToken(){};
    //draws the token
    virtual void draw() const;
};



#endif //OTHELLO_CONSOLETOKEN_H
