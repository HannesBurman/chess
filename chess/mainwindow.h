#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_A1_toggled(bool checked);
    void on_pushButton_A2_toggled(bool checked);
    void on_pushButton_A3_toggled(bool checked);
    void on_pushButton_A4_toggled(bool checked);
    void on_pushButton_A5_toggled(bool checked);
    void on_pushButton_A6_toggled(bool checked);
    void on_pushButton_A7_toggled(bool checked);
    void on_pushButton_A8_toggled(bool checked);

    void on_pushButton_B1_toggled(bool checked);
    void on_pushButton_B2_toggled(bool checked);
    void on_pushButton_B3_toggled(bool checked);
    void on_pushButton_B4_toggled(bool checked);
    void on_pushButton_B5_toggled(bool checked);
    void on_pushButton_B6_toggled(bool checked);
    void on_pushButton_B7_toggled(bool checked);
    void on_pushButton_B8_toggled(bool checked);

    void on_pushButton_C1_toggled(bool checked);
    void on_pushButton_C2_toggled(bool checked);
    void on_pushButton_C3_toggled(bool checked);
    void on_pushButton_C4_toggled(bool checked);
    void on_pushButton_C5_toggled(bool checked);
    void on_pushButton_C6_toggled(bool checked);
    void on_pushButton_C7_toggled(bool checked);
    void on_pushButton_C8_toggled(bool checked);

    void on_pushButton_D1_toggled(bool checked);
    void on_pushButton_D2_toggled(bool checked);
    void on_pushButton_D3_toggled(bool checked);
    void on_pushButton_D4_toggled(bool checked);
    void on_pushButton_D5_toggled(bool checked);
    void on_pushButton_D6_toggled(bool checked);
    void on_pushButton_D7_toggled(bool checked);
    void on_pushButton_D8_toggled(bool checked);

    void on_pushButton_E1_toggled(bool checked);
    void on_pushButton_E2_toggled(bool checked);
    void on_pushButton_E3_toggled(bool checked);
    void on_pushButton_E4_toggled(bool checked);
    void on_pushButton_E5_toggled(bool checked);
    void on_pushButton_E6_toggled(bool checked);
    void on_pushButton_E7_toggled(bool checked);
    void on_pushButton_E8_toggled(bool checked);

    void on_pushButton_F1_toggled(bool checked);
    void on_pushButton_F2_toggled(bool checked);
    void on_pushButton_F3_toggled(bool checked);
    void on_pushButton_F4_toggled(bool checked);
    void on_pushButton_F5_toggled(bool checked);
    void on_pushButton_F6_toggled(bool checked);
    void on_pushButton_F7_toggled(bool checked);
    void on_pushButton_F8_toggled(bool checked);

    void on_pushButton_G1_toggled(bool checked);
    void on_pushButton_G2_toggled(bool checked);
    void on_pushButton_G3_toggled(bool checked);
    void on_pushButton_G4_toggled(bool checked);
    void on_pushButton_G5_toggled(bool checked);
    void on_pushButton_G6_toggled(bool checked);
    void on_pushButton_G7_toggled(bool checked);
    void on_pushButton_G8_toggled(bool checked);

    void on_pushButton_H1_toggled(bool checked);
    void on_pushButton_H2_toggled(bool checked);
    void on_pushButton_H3_toggled(bool checked);
    void on_pushButton_H4_toggled(bool checked);
    void on_pushButton_H5_toggled(bool checked);
    void on_pushButton_H6_toggled(bool checked);
    void on_pushButton_H7_toggled(bool checked);
    void on_pushButton_H8_toggled(bool checked);

private:
    Ui::MainWindow *ui;

signals:
    void signalButtonCheckedAndPosition(bool, QString);

};
#endif // MAINWINDOW_H
