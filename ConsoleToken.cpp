//
// Created by shulamit on 10/30/17.
//

#include <iostream>
#include "ConsoleToken.h"

#include "ConsoleToken.h"
#include "Board.h"
#include "Tools.h"

#define SPACES " "
using namespace std;


ConsoleToken::ConsoleToken() {
    tv = Empty;
}

/**
 * draws the token
 */
void ConsoleToken :: draw() const{
    if(tv == Black) {
        cout << "X";
    }
    else if (tv == White){
        cout << "O";
    } else {
        cout << SPACES;
    }
}
