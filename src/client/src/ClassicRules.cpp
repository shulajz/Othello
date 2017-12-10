//
// Created by shulamit on 10/31/17.
//
#include "Cell.h"
#include "ClassicRules.h"

/**
 *
 * @param dim the dim of the board.
 * @return the initial values for the start of the game
 */
Cell* ClassicRules :: getInitialValues(int dim) const {
    Cell* cells = new Cell[4];
//    vector<Cell>* initCells;



    cells[0].coordinate.row = dim/2;
    cells[0].coordinate.col = dim/2;
    cells[0].tv = White;

    cells[1].coordinate.row = dim/2 + 1;
    cells[1].coordinate.col = dim/2 + 1;
    cells[1].tv = White;

    cells[2].coordinate.row = dim/2 + 1;
    cells[2].coordinate.col = dim/2;
    cells[2].tv = Black;

    cells[3].coordinate.row = dim/2;
    cells[3].coordinate.col = dim/2 + 1;
    cells[3].tv = Black;

    return cells;
}
/**
 *
 * @param player the player which is playing
 * @return a token value
 */
TokenValue ClassicRules :: getOppositeValue(Player* player) const{
    if(player->getValue() == Black) {
        return White;
    } else if (player->getValue() == White) {
        return Black;
    }
}
/**
 * gets the legal coordinates for the player
 * @param b the board
 * @param player the player playing
 */
void ClassicRules :: getLegalCoordinates
        (Board &b, Player *player,
         vector<Coordinate> &validCoordinates) {

    TokenValue oppositeValue;
    oppositeValue = getOppositeValue(player);

    Token** tokens = b.getTokens();
    int dim = b.getDimensions();
    for(int i = 1; i < dim; i++) {
        for (int j = 1; j < dim; j++) {
            if(tokens[i][j].isEmpty()) {
                checkIfCellValid(tokens, i, j,
                                 -1, -1,
                                 validCoordinates, dim,
                                 oppositeValue);

                checkIfCellValid(tokens, i, j,
                                 0, -1,
                                 validCoordinates, dim,
                                 oppositeValue);

                checkIfCellValid(tokens, i, j,
                                 1, -1,
                                 validCoordinates, dim,
                                 oppositeValue);

                checkIfCellValid(tokens, i, j,
                                 -1, 0,
                                 validCoordinates, dim,
                                 oppositeValue);

                checkIfCellValid(tokens, i, j,
                                 1, 0,
                                 validCoordinates, dim,
                                 oppositeValue);

                checkIfCellValid(tokens, i, j,
                                 -1, 1,
                                 validCoordinates, dim,
                                 oppositeValue);

                checkIfCellValid(tokens, i, j,
                                 0, 1,
                                 validCoordinates, dim,
                                 oppositeValue);

                checkIfCellValid(tokens, i, j,
                                 1, 1,
                                 validCoordinates, dim,
                                 oppositeValue);
            }
        }
    }
}

void ClassicRules :: checkEightOptions(Coordinate inputCoordinate,
                                       Board &board, Player *player,
                                       vector<Coordinate> &coordinatesToFlip) {
    checkIfToFlipCell(
            inputCoordinate, -1, -1, coordinatesToFlip,
            board.getDimensions(), board.getTokens(), player);

    checkIfToFlipCell(
            inputCoordinate, 0, -1, coordinatesToFlip,
            board.getDimensions(), board.getTokens(),player);

    checkIfToFlipCell(
            inputCoordinate, 1, -1, coordinatesToFlip,
            board.getDimensions(), board.getTokens(),player);

    checkIfToFlipCell(
            inputCoordinate, -1, 0, coordinatesToFlip,
            board.getDimensions(), board.getTokens(),player);

    checkIfToFlipCell(
            inputCoordinate, 1, 0, coordinatesToFlip,
            board.getDimensions(), board.getTokens(),player);

    checkIfToFlipCell(
            inputCoordinate, -1, 1, coordinatesToFlip,
            board.getDimensions(), board.getTokens(),player);

    checkIfToFlipCell(
            inputCoordinate, 0, 1, coordinatesToFlip,
            board.getDimensions(), board.getTokens(),player);

    checkIfToFlipCell(inputCoordinate, 1, 1, coordinatesToFlip,
                      board.getDimensions(), board.getTokens(),player);

}
/**
 * flips the tokens of the player playing
 */
void ClassicRules :: flipTokens(Coordinate inputCoordinate, Board &board, Player *player) {
    vector<Coordinate> coordinatesToFlip;
    checkEightOptions(inputCoordinate, board, player,coordinatesToFlip);

    int i = 0;
    while (i != coordinatesToFlip.size()) {
        board.getTokens()[coordinatesToFlip[i].row][coordinatesToFlip[i].col].toggle();
        i++;
    }
}
/**
 * A method we call 8 times in order to check if to flip the cell
 * @param rowDir - the direction of the row going
 * @param colDir - the direction of the col going
 */
void ClassicRules :: checkIfToFlipCell(Coordinate inputCoordinate, int rowDir, int colDir,
                                       vector<Coordinate> &coordinatesToFlip, int dim,
                                       Token** tokens, Player *player) {
    vector<Coordinate> tempCoordinates;
    bool isValid = false;
    TokenValue oppositeValue = getOppositeValue(player);

    int paramRow = inputCoordinate.row + rowDir;
    int paramCol = inputCoordinate.col + colDir;

    do {
        if (paramRow >= 1 && paramRow <= dim - 1
            && paramCol >= 1 && paramCol <= dim - 1) //if its in a valid place
        {
            if(tokens[paramRow][paramCol].getValue() != oppositeValue && isValid)
            {// we found the cell of the same kind + after we found at least one from the opposite

                int i = 0;
                while(i != tempCoordinates.size()) {
                    Coordinate coordinate;
                    coordinate.row = tempCoordinates[i].row;
                    coordinate.col = tempCoordinates[i].col;
                    coordinatesToFlip.push_back(coordinate);
                    i++;
                }
                return;
            }
            else if(tokens[paramRow][paramCol].getValue() == oppositeValue)
            {
                Coordinate coordinate;
                coordinate.row = paramRow;
                coordinate.col = paramCol;
                tempCoordinates.push_back(coordinate);
                paramRow += rowDir;
                paramCol += colDir;
                isValid = true; // we got a token in the array
            }
            else if(tokens[paramRow][paramCol].getValue() != oppositeValue) {
                return;
            }
        }
        else
        {
            return; // cell not valid
        }
        if(!(paramRow >= 1 && paramRow <= dim - 1 && paramCol >= 1 && paramCol <= dim - 1))
        {
            //if its not in a valid place
            return;
        }
    }while(!tokens[paramRow][paramCol].isEmpty());
}
/**
 * checks if a cell is valid for the valid coordinates
 * @param rowDir - the direction the row is going
 * @param colDir - the direction the col is going
 */
void ClassicRules :: checkIfCellValid(Token **token, int row, int col,
                                      int rowDir, int colDir, vector<Coordinate> &pValidCoordinates, int dim,
                                      TokenValue oppositeValue) {
    bool alreadyExist = false;
    bool isValid = false;
    int paramRow = row + rowDir;
    int paramCol = col + colDir;
    if(!(paramRow >= 1 && paramRow <= dim - 1 && paramCol >= 1 && paramCol <= dim - 1))
    {
        //if its not in a valid place
        return;
    }
    while(token[paramRow][paramCol].getValue() == oppositeValue) {
        if (paramRow >= 1 && paramRow <= dim - 1 && paramCol >= 1 && paramCol <= dim - 1)
        {//if its in a valid place
            paramRow += rowDir;
            paramCol += colDir;
            isValid = true;
        } else {
            return; // cell not valid
        }

        if(!(paramRow >= 1 && paramRow <= dim - 1 && paramCol >= 1 && paramCol <= dim - 1)) {
            return;
        }
        else if (token[paramRow][paramCol].isEmpty())
        {
            return;
        }

        if (token[paramRow][paramCol].getValue() != oppositeValue && isValid)
            // we found an optional cell
        {
            int x = 0;
            while(x != pValidCoordinates.size()) {
                // checking if it exists already
                if(pValidCoordinates[x].row == row
                   && pValidCoordinates[x].col == col) {
                    alreadyExist = true;
                    break;
                }
                x++;
            }
            if(!alreadyExist) {
                Coordinate coordinate;
                coordinate.row = row;
                coordinate.col = col;
                pValidCoordinates.push_back(coordinate);
            }
        }
    }
}