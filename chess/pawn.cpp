#include "pawn.h"
#include <qdebug.h>

Pawn::Pawn(QObject *parent) : QObject(parent)
{

}

//Movement
bool Pawn::movement(QString oldPosition, QString newPosition, QString playingField[8][8]) {
    // Relevant if piece is black or white for movement of piece
    // Is movement allowed by rules? (remember un passant) if not return false
    // Create new field with suggested position
        // Evaluate position as to not move oneself into check, if so return false
        // Check if on back rank, prompt user to select promotion piece (where to do this?)
        // return true
    return true;
}
