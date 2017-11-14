//
// Created by shulamit on 10/30/17.
//

#ifndef OTHELLO_BOARDGRAPHIC_H
#define OTHELLO_BOARDGRAPHIC_H

#include "Token.h"

class BoardGraphic {
public:
    virtual void draw(Token** tokenArr) const = 0;
};

#endif //OTHELLO_BOARDGRAPHIC_H
