#include "pawn.h"
#include <qdebug.h>

Pawn::Pawn(QObject *parent) : QObject(parent)
{

}

//Movement
bool Pawn::movement(QString oldPosition, QString newPosition, QString playingField[8][8]) {
    int oldIndices[2];
    int newIndices[2];
    // Populate indices
    notationToIndex(newPosition,newIndices);
    notationToIndex(oldPosition,oldIndices);
    QChar color = playingField[oldIndices[0]][oldIndices[1]][0];

    QString tempPlayingField[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tempPlayingField[i][j] = playingField[i][j];
        }
    }
    resetUnPassant(color, tempPlayingField);

    if (tempPlayingField[oldIndices[0]][oldIndices[1]] == "xx") {
        // No piece to move
        return false;
    }

    // Check if field is occupied by own pieces, if so return false
    if (tempPlayingField[newIndices[0]][newIndices[1]][0] == color) {
        return false;
    }

    // Relevant if piece is black or white for movement of piece
    // Is movement allowed by rules? (remember un passant) if not return false
    if (color == 'w') { // -----------------WHITE MOVEMENT-----------------
        qDebug() << "white";
        // Allowed to move one or two steps forward
        if (oldIndices[0] == 1) {
            // Is move valid for a pawn allowed to take two steps
            if(oldIndices[1] == newIndices[1] && newIndices[0] - oldIndices[0] <= 2 && newIndices[0] - oldIndices[0] > 0) {
                if (canMoveHorizontalVertical(oldIndices, newIndices, tempPlayingField)
                        && tempPlayingField[newIndices[0]][newIndices[1]] == "xx") {
                    performMovement(oldIndices, newIndices, tempPlayingField);
                    // if took two steps leave after "wu" behind new position for opponents pawn to take which will capture this pawn
                    if (newIndices[0] - oldIndices[0] == 2) {
                        tempPlayingField[oldIndices[0]+1][oldIndices[1]] = "wu";
                    }
                    if (isInCheck(color, tempPlayingField)) {
                        return false;
                    }
                    for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                            playingField[i][j] = tempPlayingField[i][j];
                        }
                    }
                    return true;
                }
            }
        } else {// Only allowed to move one step
            if(oldIndices[1] == newIndices[1] && newIndices[0] - oldIndices[0] <= 1 && newIndices[0] - oldIndices[0] > 0) {
                if (canMoveHorizontalVertical(oldIndices, newIndices, tempPlayingField)
                        && tempPlayingField[newIndices[0]][newIndices[1]] == "xx") {
                    performMovement(oldIndices, newIndices, tempPlayingField);
                    if (isInCheck(color, tempPlayingField)) {
                        return false;
                    }
                    for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                            playingField[i][j] = tempPlayingField[i][j];
                        }
                    }
                    return true;
                }
            }
        }

        // Check if trying to take diagonally as pawn and if there is a piece there to take
        if (abs(oldIndices[1]-newIndices[1]) == 1 && (oldIndices[0]+1) == newIndices[0]
                && tempPlayingField[newIndices[0]][newIndices[1]][0] != color) {
            if (tempPlayingField[newIndices[0]][newIndices[1]] == "bu") {
                tempPlayingField[newIndices[0]-1][newIndices[1]] = "xx";
            }
            performMovement(oldIndices, newIndices, tempPlayingField);
            if (isInCheck(color, tempPlayingField)) {
                return false;
            }
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    playingField[i][j] = tempPlayingField[i][j];
                }
            }
            return true;
        }
    } else { // -----------------BLACK MOVEMENT-----------------
        qDebug() << "black";
        // Allowed to move one or two steps forward
        if (oldIndices[0] == 6) {
            // Is move valid for a pawn allowed to take two steps
            if(oldIndices[1] == newIndices[1] && oldIndices[0] - newIndices[0] <= 2 && oldIndices[0] - newIndices[0] > 0) {
                if (canMoveHorizontalVertical(oldIndices, newIndices, tempPlayingField)
                        && tempPlayingField[newIndices[0]][newIndices[1]] == "xx") {
                    performMovement(oldIndices, newIndices, tempPlayingField);
                    // if took two steps leave after "bu" behind new position for opponents pawn to take which will capture this pawn
                    if (oldIndices[0] - newIndices[0] == 2) {
                        tempPlayingField[oldIndices[0]-1][oldIndices[1]] = "bu";
                    }
                    if (isInCheck(color, tempPlayingField)) {
                        return false;
                    }
                    for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                            playingField[i][j] = tempPlayingField[i][j];
                        }
                    }
                    return true;
                }
            }
        } else {// Only allowed to move one step
            if((oldIndices[1] == newIndices[1]) && (oldIndices[0] - newIndices[0]) <= 1 && (oldIndices[0] - newIndices[0] > 0)) {
                if (canMoveHorizontalVertical(oldIndices, newIndices, tempPlayingField)
                        && tempPlayingField[newIndices[0]][newIndices[1]] == "xx") {
                    performMovement(oldIndices, newIndices, tempPlayingField);
                    if (isInCheck(color, tempPlayingField)) {
                        return false;
                    }
                    for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                            playingField[i][j] = tempPlayingField[i][j];
                        }
                    }
                    return true;
                }
            }
        }

        // Check if trying to take diagonally as pawn and if there is a piece there to take
        if (abs(oldIndices[1]-newIndices[1]) == 1 && (oldIndices[0]-1) == newIndices[0]
                && tempPlayingField[newIndices[0]][newIndices[1]][0] != color) {
            if (tempPlayingField[newIndices[0]][newIndices[1]] == "wu") {
                tempPlayingField[newIndices[0]+1][newIndices[1]] = "xx";
            }
            performMovement(oldIndices, newIndices, tempPlayingField);
            if (isInCheck(color, tempPlayingField)) {
                return false;
            }
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    playingField[i][j] = tempPlayingField[i][j];
                }
            }
            return true;
        }
    }


    // Create new field with suggested position
        // Evaluate position as to not move oneself into check, if so return false
        // Check if on back rank, prompt user to select promotion piece (where to do this?)
        // return true
    return false;
}
