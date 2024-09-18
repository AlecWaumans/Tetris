#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtWidgets/qgraphicsscene.h>
#include "../../Model/Board.h"
#include "../../Model/Game.h"

#include<QPushButton>
#include<QMessageBox>

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow, public Observer
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
   void update(const Observable *obs) override;

   void keyReleaseEvent(QKeyEvent *event)override;
   void makeInvisibleTab();
   void paintEvent(QGraphicsScene * scene , const Board &board) const;
   void paintEventNextBrick(QGraphicsScene * scene, const Brick &nextBrick) const;
   void paintCurrentBrick(QGraphicsScene * scene, const Brick &currentBrick) const;
    void setBoard( const Board & board);
   void updateTimer();






private slots:


    void moveBrickDown();
    void on_actionExit_triggered();
    void on_pushButton_Play_clicked();
    void on_pushButton_Restart_clicked();


    void on_pushButton_submit_personalise_clicked();

    void on__submit_new_size_clicked();

    void on_pushButton_submit_prefil_board_clicked();

    void on_checkBox_yesPrefill_clicked();

    void on_checkBox_noPrefill_clicked();

    void updateGameTimer();



private:
    Ui::MainWindow *ui;
    QGraphicsScene _scene;
    QGraphicsScene _scene_NextBrick;
    QTimer *timer;
    QTimer *timerGame;


QMap<Shapes, QColor> blockColors;
    QMessageBox* m_messageBox;
    Board _board;
    Game _game;
    bool timeUp;
    bool reset;







};

#endif // MAINWINDOW_H
