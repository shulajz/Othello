//
// Created by shulamit on 10/31/17.
//
#include <iostream>
#include <limits>

using namespace std;
#include "ConsoleBoard.h"
#include "ConsoleToken.h"
//

#define SPACE "  "

ConsoleBoard :: ConsoleBoard(int dimensions) {
    this->dimensions = dimensions;
};
/**
 * draws the board
 * @param tokenArr the board
 */
void ConsoleBoard :: draw (Token** tokenArr) const {
    cout<<"Current board:"<<endl<<endl;
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
    if (message == Next){
        char temp;
        cout<<"No possible moves.Play passes back to the other player."
                "press any key to continue."<<endl;
        cin>>temp;
    }else if (message == NoMovesForAll){
        cout<<"No possible moves."<<endl;
    }else if(message == IllegelMove) {
        cout<<"Illegal move.Please try again."<<endl<<endl;
    }else if (message == WaitToMove){
        cout << "please wait for other player to do his move" << endl;
    }else if(message == NoMoveForTheRival) {
        char temp;
        cout << "No possible moves for the other player." << endl
             << "Play passes back to you."
                     "press any key to continue." << endl;
        cin >> temp;
    }else{
        cout<<endl<<"Please enter your move row,col:";
    }
}

void ConsoleBoard :: printWhosMove(TokenValue tv) const{
    ConsoleToken :: drawTokenValue(tv);
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

void ConsoleBoard :: printThePlayersChoice(TokenValue tv,
                                           Coordinate coordinate) const {
    ConsoleToken :: drawTokenValue(tv);
    cout << ", played"
         << "("
         <<  coordinate.row
         << "," <<
                coordinate.col
         << ")"
         << endl
         << endl;

}

void ConsoleBoard :: printAfterRealPlayer() const {
    char temp;
    cout << "you played your turn, please enter any key to display computers turn " << endl;
    cin>>temp;
}
/**
 * receives coordinate input from the user.
 * @param input
 */
void ConsoleBoard :: receivePlayersAnswer(Coordinate &input) {
//    char temp;
    while(!(cin>> input.row >> input.col)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        printSpecialSituation(IllegelMove);
    }
}

