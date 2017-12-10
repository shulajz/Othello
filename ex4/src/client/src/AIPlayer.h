/*
 * ex3.c
 *
 *  Created on: Nov 25, 2017
 *      Author:  Shulamit & Or Sha'ashua
*/

#ifndef OTHELLO_AIPLAYER_H
#define OTHELLO_AIPLAYER_H


#include "Cell.h"
#include "Board.h"
#include "GameRules.h"

class AIPlayer : public Player{

    public:

    /**
     * @return true if is real player, false otherwise.
     */
//    bool isRealPlayer()const;

    /**
     * Constructor of AIPLayer.
     * @param tv - get Token Value (Black or White)
     */
    AIPlayer(TokenValue tv);

    /**
     * Do one turn turn of AIPlayer.
     * @param gameRules
     * @param board
     * @param coordinates
     * @param input
     * @param boardGraphic
     * @param player
     */
    virtual void doOneTurn(GameRules *gameRules, Board &board,
                           vector<Coordinate> &coordinates, Coordinate &input,
                           BoardGraphic *boardGraphic, Player *player);
    /**
     * Print the move the AIPlayer did.
     * @param coordinate
     * @param boardGraphic
     */
    virtual void printWhatThePlayerPlayed(Coordinate coordinate, BoardGraphic *boardGraphic);

    /**
     * This function calculate the max score of the real player
     * for one move turn of the AI player.
     * @param gameRules
     * @param tempBoard
     * @param validCoordinates
     * @param maxLocal
     */
    virtual void calcTheMaxScoreForOneTurn(GameRules *gameRules, Board &tempBoard,
                                   vector<Coordinate> &validCoordinates, int &maxLocal);

    /**
     * Print message after the real player move.
     * @param boardGraphic
     * @param need_to_print
     */
    void printAfterTheRealPlayerMove(BoardGraphic *boardGraphic, bool need_to_print) const;
};

#endif //OTHELLO_AIPLAYER_H