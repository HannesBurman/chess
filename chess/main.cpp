#include <qdebug.h>
#include <QApplication>
#include <qobject.h>
#include "mainwindow.h"
#include "pawn.h"
#include "functions.cpp"
#include "board.h"

void newFunc(){
    qDebug() << "itworks";
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    // Create field
    board mBoard;
    QObject::connect(&w, &MainWindow::signalButtonCheckedAndPosition,
                     &mBoard, &board::slotButtonCheckedAndPosition);
//    qDebug() << mPawn.movement("B7","B5",playingField);
//    printField(playingField);
//    qDebug() << mPawn.movement("B5","B4",playingField);
//    printField(playingField);

    return a.exec();
}
