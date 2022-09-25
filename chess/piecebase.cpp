#include "piecebase.h"

pieceBase::pieceBase()
{

}

void pieceBase::notationToIndex(QString notationInText,int notationInIndex[2]) {
    std::vector<int> tempIntArray;
    tempIntArray = mMapNotationToIndex[notationInText];
    notationInIndex[0] = tempIntArray[0];
    notationInIndex[1] = tempIntArray[1];
}

bool pieceBase::canMoveHorizontalVertical(int oldIndices[2], int newindices[2], QString playingField[8][8]) {

    if (oldIndices[0] != newindices[0] && oldIndices[1] != newindices[1]) {
        // Invalid input.. Not horizontal or vertical movement
        return false;
    }

    /* Removing check of last position as that field is evaluated as "friend or foe" in a earlier stage
     * so only check the path until the "new position"
     */
    for (int i = oldIndices[0]; i < (newindices[0]-1); i++) {
        for (int j = oldIndices[1]; j < (newindices[1]-1); j++) {
            if (playingField[i][j] != "xx") {
                // A piece is in the way
                return false;
            }
        }
    }

    return true;
}

void pieceBase::performMovement(int oldIndices[2], int newIndices[2], QString playingField[8][8]) {
    qDebug() << "performMovement";
    playingField[newIndices[0]][newIndices[1]] = playingField[oldIndices[0]][oldIndices[1]];
    playingField[oldIndices[0]][oldIndices[1]] = "xx";
}

bool pieceBase::isInCheck(int oldIndices[2], int newindices[2], QChar color,QString playingField[8][8]) {

    // Check what the king "sees" verticaly/horitontaly/diagonally and from a horse perspective...
    int kingPosition[2];
    QString tempPlayingField[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tempPlayingField[i][j] = playingField[i][j];
        }
    }
    // Update tempPlayingField with new suggested position to evaluate
    performMovement(oldIndices, newindices, tempPlayingField);
    // Find kings position
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (tempPlayingField[i][j][1] == 'k' && tempPlayingField[i][j][0] == color) {
                kingPosition[0] = i;
                kingPosition[1] = j;
            }
        }
    }

   // Horizontal check right
    for (int i = 1; i < 8-kingPosition[1]; i++) {
        if (tempPlayingField[kingPosition[0]][kingPosition[1]+i] == "xx") {
            continue;
        } else {
            if (verbose()) {
                qDebug() << "Horizontal right. piece found:" << tempPlayingField[kingPosition[0]][kingPosition[1]+i];
            }
            if ((tempPlayingField[kingPosition[0]][kingPosition[1]+i][1] == 'q' || tempPlayingField[kingPosition[0]][kingPosition[1]+i][1] == 'r')
                    && tempPlayingField[kingPosition[0]][kingPosition[1]+i][0] != color) {
                return true;
            }
            // Found a piece in direction that won't check me
            break;
        }
    }
    // Horizontal check left
    for (int i = 1; i < kingPosition[1]+1; i++) {
        if (tempPlayingField[kingPosition[0]][kingPosition[1]-i] == "xx") {
            continue;
        } else {
            if (verbose()) {
                qDebug() << "Horizontal left. piece found:" << tempPlayingField[kingPosition[0]][kingPosition[1]-i];
            }
            if ((tempPlayingField[kingPosition[0]][kingPosition[1]-i][1] == 'q' || tempPlayingField[kingPosition[0]][kingPosition[1]-i][1] == 'r')
                    && tempPlayingField[kingPosition[0]][kingPosition[1]-i][0] != color) {
                return true;
            }
            // Found a piece in direction that won't check me
            break;
        }
    }
    // Vertical check up
    for (int i = 1; i < 8-kingPosition[0]; i++) {
        if (tempPlayingField[kingPosition[0]+i][kingPosition[1]] == "xx") {
            continue;
        } else {
            if (verbose()) {
                qDebug() << "Vertical up. piece found:" << tempPlayingField[kingPosition[0]+i][kingPosition[1]];
            }
            if ((tempPlayingField[kingPosition[0]+i][kingPosition[1]][1] == 'q' || tempPlayingField[kingPosition[0]+i][kingPosition[1]][1] == 'r')
                    && tempPlayingField[kingPosition[0]+i][kingPosition[1]][0] != color) {
                return true;
            }
            // Found a piece in direction that won't check me
            break;
        }
    }
    // Vertical check down
    for (int i = 1; i < kingPosition[0]+1; i++) {
        if (tempPlayingField[kingPosition[0]-i][kingPosition[1]] == "xx") {
            continue;
        } else {
            if (verbose()) {
                qDebug() << "Vertical down. piece found:" << tempPlayingField[kingPosition[0]-i][kingPosition[1]];
            }
            if ((tempPlayingField[kingPosition[0]-i][kingPosition[1]][1] == 'q' || tempPlayingField[kingPosition[0]-i][kingPosition[1]][1] == 'r')
                    && tempPlayingField[kingPosition[0]-i][kingPosition[1]][0] != color) {
                return true;
            }
            // Found a piece in direction that won't check me
            break;
        }
    }

    // Diagonal check up right
    for (int i = 1; i < std::min(8-kingPosition[0],8-kingPosition[1]); i++) {
        if (tempPlayingField[kingPosition[0]+i][kingPosition[1]+i] == "xx") {
            continue;
        } else {
            if (verbose()) {
                qDebug() << "Diagonal up right. piece found:" << tempPlayingField[kingPosition[0]+i][kingPosition[1]+i];
            }
            if ((tempPlayingField[kingPosition[0]+i][kingPosition[1]+i][1] == 'q'
                 || tempPlayingField[kingPosition[0]+i][kingPosition[1]+i][1] == 'b')
                    && tempPlayingField[kingPosition[0]+i][kingPosition[1]+i][0] != color) {
                return true;
            }
            // Found a piece in direction that won't check me
            break;
        }
    }
    // Diagonal check down left
    for (int i = 1; i < std::min(kingPosition[0]+1,kingPosition[1]+1); i++) {
        if (tempPlayingField[kingPosition[0]-i][kingPosition[1]-i] == "xx") {
            continue;
        } else {
            if (verbose()) {
                qDebug() << "Diagonal down left. piece found:" << tempPlayingField[kingPosition[0]-i][kingPosition[1]-i];
            }
            if ((tempPlayingField[kingPosition[0]-i][kingPosition[1]-i][1] == 'q'
                 || tempPlayingField[kingPosition[0]-i][kingPosition[1]-i][1] == 'b')
                    && tempPlayingField[kingPosition[0]-i][kingPosition[1]-i][0] != color) {
                return true;
            }
            // Found a piece in direction that won't check me
            break;
        }
    }
    // Diagonal check down right
    for (int i = 1; i < std::min(kingPosition[0]+1,8-kingPosition[1]); i++) {
        if (tempPlayingField[kingPosition[0]-i][kingPosition[1]+i] == "xx") {
            continue;
        } else {
            if (verbose()) {
                qDebug() << "Diagonal down right. piece found:" << tempPlayingField[kingPosition[0]-i][kingPosition[1]+i];
            }
            if ((tempPlayingField[kingPosition[0]-i][kingPosition[1]+i][1] == 'q'
                 || tempPlayingField[kingPosition[0]-i][kingPosition[1]+i][1] == 'b')
                    && tempPlayingField[kingPosition[0]-i][kingPosition[1]+i][0] != color) {
                return true;
            }
            // Found a piece in direction that won't check me
            break;
        }
    }
    // Diagonal check up left
    for (int i = 1; i < std::min(8-kingPosition[0],kingPosition[1]+1); i++) {
        if (tempPlayingField[kingPosition[0]+i][kingPosition[1]-i] == "xx") {
            continue;
        } else {
            if (verbose()) {
                qDebug() << "Diagonal up left. piece found:" << tempPlayingField[kingPosition[0]+i][kingPosition[1]-i];
            }
            if ((tempPlayingField[kingPosition[0]+i][kingPosition[1]-i][1] == 'q'
                 || tempPlayingField[kingPosition[0]+i][kingPosition[1]-i][1] == 'b')
                    && tempPlayingField[kingPosition[0]+i][kingPosition[1]-i][0] != color) {
                return true;
            }
            // Found a piece in direction that won't check me
            break;
        }
    }

    // Horse check in all 8 positions around the king
    int horsePosCheck[8][2];
    horsePosCheck[0][0] = kingPosition[0]+1;
    horsePosCheck[0][1] = kingPosition[1]-2;

    horsePosCheck[1][0] = kingPosition[0]+2;
    horsePosCheck[1][1] = kingPosition[1]-1;

    horsePosCheck[2][0] = kingPosition[0]+2;
    horsePosCheck[2][1] = kingPosition[1]+1;

    horsePosCheck[3][0] = kingPosition[0]+1;
    horsePosCheck[3][1] = kingPosition[1]+2;

    horsePosCheck[4][0] = kingPosition[0]-1;
    horsePosCheck[4][1] = kingPosition[1]+2;

    horsePosCheck[5][0] = kingPosition[0]-2;
    horsePosCheck[5][1] = kingPosition[1]+1;

    horsePosCheck[6][0] = kingPosition[0]-2;
    horsePosCheck[6][1] = kingPosition[1]-1;

    horsePosCheck[7][0] = kingPosition[0]-1;
    horsePosCheck[7][1] = kingPosition[1]-2;

    for (int i = 0; i < 8; i++) {
        if (horsePosCheck[i][0] < 0 || horsePosCheck[i][1] < 0
                ||horsePosCheck[i][0] > 7 || horsePosCheck[i][0] > 7) {
            // invalid index dont check it
            continue;
        }
        if (tempPlayingField[horsePosCheck[i][0]][horsePosCheck[i][1]][1] == 'h'
                && tempPlayingField[horsePosCheck[i][0]][horsePosCheck[i][1]][0] != color) {
            return true;
        }
    }

    // Check pawns
    if (color == 'w') {
        if ((tempPlayingField[kingPosition[0]+1][kingPosition[1]+1][1] == 'p'
             && tempPlayingField[kingPosition[0]+1][kingPosition[1]+1][0] != color)
                || (tempPlayingField[kingPosition[0]+1][kingPosition[1]-1][1] == 'p'
                && tempPlayingField[kingPosition[0]+1][kingPosition[1]-1][0] != color)) {
            return true;
        }
    } else {
        if ((tempPlayingField[kingPosition[0]-1][kingPosition[1]+1][1] == 'p'
             && tempPlayingField[kingPosition[0]-1][kingPosition[1]+1][0] != color)
                || (tempPlayingField[kingPosition[0]-1][kingPosition[1]-1][1] == 'p'
                && tempPlayingField[kingPosition[0]-1][kingPosition[1]-1][0] != color)) {
            return true;
        }
    }

    return false;
}
