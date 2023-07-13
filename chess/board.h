#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include "pieces.h"

class board : public QObject
{
    Q_OBJECT
public:
    board();
    void createField();
    void updatePlayingField(QString, QString);
    void printField();
private:
    QString playingField[8][8];
    QString oldSpot = "";
    QString newSpot = "";
    Pieces mPieces;
public slots:
    void slotButtonCheckedAndPosition(bool, QString);
};

#endif // BOARD_H
