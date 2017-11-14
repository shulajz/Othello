//
// Created by shulamit on 10/31/17.
//
#include <iostream>
using namespace std;
#include "ConsoleBoard.h"
#define SPACE "  "

ConsoleBoard :: ConsoleBoard(int dimensions) {
    this->dimensions = dimensions;
};
/**
 * draws the board
 * @param tokenArr the board
 */
void ConsoleBoard :: draw (Token** tokenArr) const {

    for ( int i = 0; i < dimensions; i++ ) {
        for ( int j = 0; j < dimensions; j++ ) {
            if (j != 0){
                if(i == 0) {
                    cout << SPACE;
                    cout << j;
                    cout << SPACE << "|";
                } else {
                    cout << SPACE;
                    tokenArr[i][j].draw();
                    cout << SPACE << "|"; //the board itself
                }
            } else {
                if(i != 0){
                    cout << i;
                    cout << "|";
                } else {
                    cout << " |";
                }

            }
        }
        cout << endl;
        for (int i = 0; i < dimensions * 5 + 5; i++) {
            cout << "-";
        }
        cout << endl;
    }
}
