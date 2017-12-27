//
// Created by shulamit on 10/31/17.
////

#ifndef OTHELLO_CONSOLETOKENFACTORY_H
#define OTHELLO_CONSOLETOKENFACTORY_H

#include "TokenFactory.h"

class ConsoleTokenFactory: public TokenFactory {
public:

    virtual Token* Create(int);
};


#endif //OTHELLO_CONSOLETOKENFACTORY_H
