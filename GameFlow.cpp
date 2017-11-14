//
// Created by shulamit on 10/31/17.
//

#include "GameFlow.h"
#include <iostream>
#include <vector>

using namespace std;

GameFlow ::GameFlow(GameRules &gameRules, Player **players, Board &board):
        m_gameRules(gameRules),m_board(board) {
    this->players = players;
    this->currentTurn = Black;
}


/**
 * where the game runs
 */
void GameFlow :: run () {
    while (true) {
        if(m_board.isFullOfTokens()) {
            m_board.draw();
            break;
        }
        m_board.draw();
        vector<Coordinate> validCoordinates;
//        Coordinate validCoordinates[64] = {0};
        m_gameRules.getLegalCoordinates(m_board, players[currentTurn],
                                        validCoordinates);
        if (validCoordinates.size() == 0) {
            //switching to the other player in order to check
            // if he's got any legal moves
            players[currentTurn]->togglePlayer(currentTurn);
            m_gameRules.getLegalCoordinates(m_board, players[currentTurn],validCoordinates);
            if (validCoordinates.size() == 0) // checking if the other player has any legal moves
            { // theres no options for either of the players
                cout << "gameover";
                cout << endl;
                break;
            }
            {
                players[currentTurn]->togglePlayer(currentTurn);
                players[currentTurn]->drawValue();
                cout << " ,It's your move" << endl;
                cout << "No possible moves. Play passes back to the other player. "
                        "Press any key to continue";
                char key;
                cin >> key;
            }
        } else {
            Coordinate inputCoordinate;
            players[currentTurn]->doOneTurn(&m_gameRules, &m_board,
                                            validCoordinates, inputCoordinate);
            m_board.updateValue(inputCoordinate, currentTurn);
            m_gameRules.flipTokens(inputCoordinate, m_board, players[currentTurn]);

        }
//        break;

        players[currentTurn]->togglePlayer(currentTurn);

    }
    int black = 0;
    int white = 0;
    calcResults(black, white);
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
        "It's a tie!";
    }

}
/**
 * calculates who wins the game.
 */
void GameFlow :: calcResults(int &black, int &white) {
    for(int i = 1; i < m_board.getDimensions(); i ++) {
        for (int j = 1; j < m_board.getDimensions(); j++) {
            if (m_board.getTokens()[i][j].getValue() == Black) {
                black++;
            } else if (m_board.getTokens()[i][j].getValue() == White) {
                white++;
            } else if ((m_board.getTokens()[i][j].getValue() == Empty)) {
                continue;
            }
        }
    }
}