#include <qdebug.h>
#include <QApplication>
#include "mainwindow.h"
#include "pawn.h"
#include "functions.cpp"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // Create field
    QString playingField[8][8];
    createField(playingField);
    printField(playingField);
    Pawn mPawn;

//    qDebug() << mPawn.movement("B2","B4",playingField);
//    printField(playingField);
//    qDebug() << mPawn.movement("B7","B5",playingField);
//    printField(playingField);
//    qDebug() << mPawn.movement("B5","B6",playingField);
//    printField(playingField);
//    qDebug() << mPawn.movement("B5","B4",playingField);
//    printField(playingField);
//    qDebug() << mPawn.movement("C2","C4",playingField);
//    printField(playingField);
//    qDebug() << mPawn.movement("B5","C4",playingField);
//    printField(playingField);



    return a.exec();
}
