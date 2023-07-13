#ifndef PIECES_H
#define PIECES_H

#include <QObject>
#include "pawn.h"
#include "piecebase.h"

class Pieces : public QObject, public pieceBase
{
    Q_OBJECT
public:
    explicit Pieces(QObject *parent = nullptr);
    bool movement(QString oldPosition, QString newPosition, QString playingField[8][8]);

private:
    // All instances of pieces
    Pawn mPawn;
signals:

};

#endif // PIECES_H
