//
// Created by shulamit on 10/31/17.
//

#ifndef OTHELLO_TOKENFACTORY_H
#define OTHELLO_TOKENFACTORY_H


#include "Token.h"

class TokenFactory {
public:
    virtual Token* Create(int) = 0;
    //
};


#endif //OTHELLO_TOKENFACTORY_H
