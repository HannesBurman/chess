#include "board.h"
#include <qdebug.h>

board::board()
{
    createField();
    printField();
}

void board::createField(){
    // Initialize field
    QString row1[8] = {"wr","wh","wb","wq","wk","wb","wh","wr"};
    QString row2[8] = {"wp","wp","wp","wp","wp","wp","wp","wp"};
    QString row7[8] = {"bp","bp","bp","bp","bp","bp","bp","bp"};
    QString row8[8] = {"br","bh","bb","bq","bk","bb","bh","br"};
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            playingField[i][j] = "xx";
        }
    }
    for (int i = 0; i < 8; i++) {
        playingField[0][i] = row1[i];
        playingField[1][i] = row2[i];
        playingField[6][i] = row7[i];
        playingField[7][i] = row8[i];
    }
}

void board::printField() {
    qDebug() << "----------------------------------------";

    for (int i = 7; i >= 0; i--) {
        qDebug() << playingField[i][0] << playingField[i][1] << playingField[i][2] << playingField[i][3]
                 << playingField[i][4] << playingField[i][5] << playingField[i][6] << playingField[i][7];
    }
}

// SLOTS

void board::slotButtonCheckedAndPosition(bool checked, QString position)
{
    qDebug() << "checked" << checked << "position" << position;
    //mPieces.movement()
}
