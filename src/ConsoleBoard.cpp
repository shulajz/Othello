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

void ConsoleBoard :: printSpecialSituation(Situation message) const{
    if (message==Next){
        char temp;
        cout<<"No possible moves.Play passes back to the other player.press any key to continue."<<endl;
        cin>>temp;
    }else if (message==NoMovesForAll){
        cout<<"No possible moves."<<endl;
    }else if(message==IllegelMove) {
        cout<<"Illegal move.Please try again."<<endl<<endl;
    }else{
        cout<<endl<<"Please enter your move row,col:";
    }
}

void ConsoleBoard :: printWhosMove(Player *player) const{
    player->drawValue();
    cout << " ,It's your move" << endl;
}

void ConsoleBoard :: printMoves(vector<Coordinate> validCoordinates) const{
    int i = 0;
    cout << "Your possible moves:";
    while (i != validCoordinates.size()) {
        cout << "(" << validCoordinates[i].row << "," << validCoordinates[i].col << ") ";
        i++;
    }
    cout << endl;


}

void ConsoleBoard::drawStatus(int black, int white)const{
    cout <<"Black: "<<black<<", "<<"White: "<<white<<endl;
    if (black > white)
    {
        cout << "Black wins!";
    }
    else if (white > black)
    {
        cout << "White wins!";
    }
    else
    {
        cout << "It's a tie!";
    }
}

void ConsoleBoard :: printThePlayersChoice(Coordinate coordinate, Player *player) const {
    player->drawValue();
    cout << ", played" << "(" <<  coordinate.row << "," << coordinate.col << ")" << endl;

}

void ConsoleBoard :: printAfterRealPlayer() const {
    char temp;
    cout << "you played your turn, please enter any key to display computers turn " << endl;
    cin>>temp;
}