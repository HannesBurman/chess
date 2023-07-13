#include "pieces.h"
#include <qdebug.h>

Pieces::Pieces(QObject *parent) : QObject(parent)
{

}

bool Pieces::movement(QString oldPosition, QString newPosition, QString playingField[8][8])
{
    qDebug() << "oldPos" << oldPosition << "newPos" << newPosition;
    qDebug() << "playingFieldOld" << mMapNotationToIndex[oldPosition];
    qDebug() << "playingFieldNew" << mMapNotationToIndex[newPosition];
}


