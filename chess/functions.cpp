#include "mainwindow.h"
#include <qdebug.h>
#include <QMap>


QMap <QString,QVector<int>> notationToIndexMap;
QMap <QString,QString> testar;

/*
 * Each field consists of two letters "AB"
 * A = Color of piece
 *      w = white
 *      b = black
 * B = Type of piece
 *      r = rock
 *      h = horse
 *      b = bishop
 *      q = queen
 *      k = king
 *      p = pawn
 */
void createField(QString outString[8][8]){
    // Initialize field
    QString row1[8] = {"wr","wh","wb","wq","wk","wb","wh","wr"};
    QString row2[8] = {"wp","wp","wp","wp","wp","wp","wp","wp"};
    QString row7[8] = {"bp","bp","bp","bp","bp","bp","bp","bp"};
    QString row8[8] = {"br","bh","bb","bq","bk","bb","bh","br"};
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            outString[i][j] = "xx";
        }
    }
    for (int i = 0; i < 8; i++) {
        outString[0][i] = row1[i];
        outString[1][i] = row2[i];
        outString[6][i] = row7[i];
        outString[7][i] = row8[i];
    }
}

void printField(QString outString[8][8]) {
    qDebug() << "----------------------------------------";

    for (int i = 7; i >= 0; i--) {
        qDebug() << outString[i][0] << outString[i][1] << outString[i][2] << outString[i][3]
                 << outString[i][4] << outString[i][5] << outString[i][6] << outString[i][7];
    }
}
