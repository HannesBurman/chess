#ifndef PAWN_H
#define PAWN_H
#include "piecebase.h"
#include <QObject>

class Pawn : public QObject, public pieceBase
{
    Q_OBJECT
public:
    explicit Pawn(QObject *parent = nullptr);

    // Pawn rules
    /*
     * Check if suggested movement of pawn is allowed
     * return true if so and false otherwise.
     */
    bool movement(QString oldPosition, QString newPosition, QString playingField[8][8]);

signals:

};

#endif // PAWN_H
