/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab_settings;
    QCheckBox *checkBox_perso_size_yes;
    QCheckBox *checkBox_perso_size_no;
    QLineEdit *lineEdit_PhrasePerso;
    QPushButton *pushButton_submit_personalise;
    QLineEdit *lineEdit_2_victory_score;
    QLineEdit *lineEdit_vicotry_level;
    QLineEdit *lineEdit_victoryLines;
    QLineEdit *lineEdit_vicotory_score_value;
    QLineEdit *lineEdit_victory_level_value;
    QLineEdit *lineEdit_victory_lines_values;
    QLineEdit *lineEdit_setter_timer;
    QLineEdit *lineEdit_setter_time_value;
    QWidget *tab_personlise_board;
    QLineEdit *lineEdit_insert_height;
    QLineEdit *lineEdit_height_value;
    QLineEdit *lineEdit_insert_width;
    QLineEdit *lineEdit_width_value;
    QTextEdit *textEdit_rappelSize;
    QPushButton *_submit_new_size;
    QWidget *tab_2;
    QLineEdit *lineEdit;
    QCheckBox *checkBox_yesPrefill;
    QCheckBox *checkBox_noPrefill;
    QLineEdit *lineEdit_question_prefill;
    QLineEdit *lineEdit_blocksToFillValue;
    QPushButton *pushButton_submit_prefil_board;
    QWidget *tab_game;
    QGraphicsView *graphicsView;
    QGraphicsView *graphicsView_NextBrick;
    QLabel *label_NextBrick;
    QLabel *label_Score;
    QLineEdit *lineEdit_Score;
    QLabel *label_Level;
    QLineEdit *lineEdit_Level;
    QLabel *label_Lines;
    QLineEdit *lineEdit_Lines;
    QPushButton *pushButton_Restart;
    QPushButton *pushButton_Play;
    QTextEdit *textEdit_rappelCommands;
    QLCDNumber *lcdNumber_timer;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menuOptios;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(904, 647);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionExit->setMenuRole(QAction::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMaximumSize(QSize(1202, 729));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 891, 571));
        tab_settings = new QWidget();
        tab_settings->setObjectName("tab_settings");
        checkBox_perso_size_yes = new QCheckBox(tab_settings);
        checkBox_perso_size_yes->setObjectName("checkBox_perso_size_yes");
        checkBox_perso_size_yes->setGeometry(QRect(20, 50, 77, 22));
        checkBox_perso_size_yes->setAutoExclusive(true);
        checkBox_perso_size_no = new QCheckBox(tab_settings);
        checkBox_perso_size_no->setObjectName("checkBox_perso_size_no");
        checkBox_perso_size_no->setGeometry(QRect(20, 90, 77, 22));
        checkBox_perso_size_no->setAutoExclusive(true);
        lineEdit_PhrasePerso = new QLineEdit(tab_settings);
        lineEdit_PhrasePerso->setObjectName("lineEdit_PhrasePerso");
        lineEdit_PhrasePerso->setGeometry(QRect(10, 20, 271, 24));
        lineEdit_PhrasePerso->setReadOnly(true);
        pushButton_submit_personalise = new QPushButton(tab_settings);
        pushButton_submit_personalise->setObjectName("pushButton_submit_personalise");
        pushButton_submit_personalise->setGeometry(QRect(120, 80, 80, 24));
        lineEdit_2_victory_score = new QLineEdit(tab_settings);
        lineEdit_2_victory_score->setObjectName("lineEdit_2_victory_score");
        lineEdit_2_victory_score->setGeometry(QRect(20, 130, 141, 24));
        lineEdit_2_victory_score->setReadOnly(true);
        lineEdit_vicotry_level = new QLineEdit(tab_settings);
        lineEdit_vicotry_level->setObjectName("lineEdit_vicotry_level");
        lineEdit_vicotry_level->setGeometry(QRect(20, 160, 131, 24));
        lineEdit_vicotry_level->setReadOnly(true);
        lineEdit_victoryLines = new QLineEdit(tab_settings);
        lineEdit_victoryLines->setObjectName("lineEdit_victoryLines");
        lineEdit_victoryLines->setGeometry(QRect(20, 190, 291, 24));
        lineEdit_victoryLines->setReadOnly(true);
        lineEdit_vicotory_score_value = new QLineEdit(tab_settings);
        lineEdit_vicotory_score_value->setObjectName("lineEdit_vicotory_score_value");
        lineEdit_vicotory_score_value->setGeometry(QRect(170, 130, 111, 24));
        lineEdit_victory_level_value = new QLineEdit(tab_settings);
        lineEdit_victory_level_value->setObjectName("lineEdit_victory_level_value");
        lineEdit_victory_level_value->setGeometry(QRect(170, 160, 113, 24));
        lineEdit_victory_lines_values = new QLineEdit(tab_settings);
        lineEdit_victory_lines_values->setObjectName("lineEdit_victory_lines_values");
        lineEdit_victory_lines_values->setGeometry(QRect(320, 190, 113, 24));
        lineEdit_setter_timer = new QLineEdit(tab_settings);
        lineEdit_setter_timer->setObjectName("lineEdit_setter_timer");
        lineEdit_setter_timer->setGeometry(QRect(20, 220, 161, 24));
        lineEdit_setter_timer->setReadOnly(true);
        lineEdit_setter_time_value = new QLineEdit(tab_settings);
        lineEdit_setter_time_value->setObjectName("lineEdit_setter_time_value");
        lineEdit_setter_time_value->setGeometry(QRect(210, 220, 113, 24));
        tabWidget->addTab(tab_settings, QString());
        tab_personlise_board = new QWidget();
        tab_personlise_board->setObjectName("tab_personlise_board");
        lineEdit_insert_height = new QLineEdit(tab_personlise_board);
        lineEdit_insert_height->setObjectName("lineEdit_insert_height");
        lineEdit_insert_height->setGeometry(QRect(20, 30, 171, 24));
        lineEdit_insert_height->setReadOnly(true);
        lineEdit_height_value = new QLineEdit(tab_personlise_board);
        lineEdit_height_value->setObjectName("lineEdit_height_value");
        lineEdit_height_value->setGeometry(QRect(220, 30, 113, 24));
        lineEdit_insert_width = new QLineEdit(tab_personlise_board);
        lineEdit_insert_width->setObjectName("lineEdit_insert_width");
        lineEdit_insert_width->setGeometry(QRect(20, 70, 171, 24));
        lineEdit_insert_width->setReadOnly(true);
        lineEdit_width_value = new QLineEdit(tab_personlise_board);
        lineEdit_width_value->setObjectName("lineEdit_width_value");
        lineEdit_width_value->setGeometry(QRect(220, 70, 113, 24));
        textEdit_rappelSize = new QTextEdit(tab_personlise_board);
        textEdit_rappelSize->setObjectName("textEdit_rappelSize");
        textEdit_rappelSize->setGeometry(QRect(20, 140, 104, 111));
        textEdit_rappelSize->setReadOnly(true);
        _submit_new_size = new QPushButton(tab_personlise_board);
        _submit_new_size->setObjectName("_submit_new_size");
        _submit_new_size->setGeometry(QRect(180, 170, 80, 24));
        tabWidget->addTab(tab_personlise_board, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(40, 30, 201, 24));
        lineEdit->setReadOnly(true);
        checkBox_yesPrefill = new QCheckBox(tab_2);
        checkBox_yesPrefill->setObjectName("checkBox_yesPrefill");
        checkBox_yesPrefill->setGeometry(QRect(40, 70, 77, 22));
        checkBox_yesPrefill->setAutoExclusive(true);
        checkBox_noPrefill = new QCheckBox(tab_2);
        checkBox_noPrefill->setObjectName("checkBox_noPrefill");
        checkBox_noPrefill->setGeometry(QRect(100, 70, 77, 22));
        checkBox_noPrefill->setAutoExclusive(true);
        lineEdit_question_prefill = new QLineEdit(tab_2);
        lineEdit_question_prefill->setObjectName("lineEdit_question_prefill");
        lineEdit_question_prefill->setGeometry(QRect(40, 130, 341, 24));
        lineEdit_question_prefill->setReadOnly(true);
        lineEdit_blocksToFillValue = new QLineEdit(tab_2);
        lineEdit_blocksToFillValue->setObjectName("lineEdit_blocksToFillValue");
        lineEdit_blocksToFillValue->setGeometry(QRect(400, 130, 113, 24));
        pushButton_submit_prefil_board = new QPushButton(tab_2);
        pushButton_submit_prefil_board->setObjectName("pushButton_submit_prefil_board");
        pushButton_submit_prefil_board->setGeometry(QRect(50, 180, 80, 24));
        tabWidget->addTab(tab_2, QString());
        tab_game = new QWidget();
        tab_game->setObjectName("tab_game");
        graphicsView = new QGraphicsView(tab_game);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(20, 10, 421, 521));
        graphicsView_NextBrick = new QGraphicsView(tab_game);
        graphicsView_NextBrick->setObjectName("graphicsView_NextBrick");
        graphicsView_NextBrick->setGeometry(QRect(480, 30, 251, 221));
        label_NextBrick = new QLabel(tab_game);
        label_NextBrick->setObjectName("label_NextBrick");
        label_NextBrick->setGeometry(QRect(480, 10, 61, 16));
        label_Score = new QLabel(tab_game);
        label_Score->setObjectName("label_Score");
        label_Score->setGeometry(QRect(480, 270, 49, 16));
        lineEdit_Score = new QLineEdit(tab_game);
        lineEdit_Score->setObjectName("lineEdit_Score");
        lineEdit_Score->setGeometry(QRect(480, 290, 113, 24));
        lineEdit_Score->setReadOnly(true);
        label_Level = new QLabel(tab_game);
        label_Level->setObjectName("label_Level");
        label_Level->setGeometry(QRect(480, 320, 49, 16));
        lineEdit_Level = new QLineEdit(tab_game);
        lineEdit_Level->setObjectName("lineEdit_Level");
        lineEdit_Level->setGeometry(QRect(480, 350, 113, 24));
        lineEdit_Level->setReadOnly(true);
        label_Lines = new QLabel(tab_game);
        label_Lines->setObjectName("label_Lines");
        label_Lines->setGeometry(QRect(480, 390, 49, 16));
        lineEdit_Lines = new QLineEdit(tab_game);
        lineEdit_Lines->setObjectName("lineEdit_Lines");
        lineEdit_Lines->setGeometry(QRect(480, 420, 113, 24));
        lineEdit_Lines->setReadOnly(true);
        pushButton_Restart = new QPushButton(tab_game);
        pushButton_Restart->setObjectName("pushButton_Restart");
        pushButton_Restart->setGeometry(QRect(450, 480, 80, 31));
        pushButton_Play = new QPushButton(tab_game);
        pushButton_Play->setObjectName("pushButton_Play");
        pushButton_Play->setGeometry(QRect(550, 480, 80, 31));
        textEdit_rappelCommands = new QTextEdit(tab_game);
        textEdit_rappelCommands->setObjectName("textEdit_rappelCommands");
        textEdit_rappelCommands->setGeometry(QRect(620, 260, 231, 161));
        textEdit_rappelCommands->setTabletTracking(true);
        textEdit_rappelCommands->setReadOnly(true);
        lcdNumber_timer = new QLCDNumber(tab_game);
        lcdNumber_timer->setObjectName("lcdNumber_timer");
        lcdNumber_timer->setGeometry(QRect(620, 440, 231, 23));
        tabWidget->addTab(tab_game, QString());
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 904, 24));
        menuOptios = new QMenu(menuBar);
        menuOptios->setObjectName("menuOptios");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuOptios->menuAction());
        menuOptios->addAction(actionExit);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        checkBox_perso_size_yes->setText(QCoreApplication::translate("MainWindow", "yes", nullptr));
        checkBox_perso_size_no->setText(QCoreApplication::translate("MainWindow", "no", nullptr));
        lineEdit_PhrasePerso->setText(QCoreApplication::translate("MainWindow", "Would like to have the regular Size of the board ?", nullptr));
        pushButton_submit_personalise->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        lineEdit_2_victory_score->setText(QCoreApplication::translate("MainWindow", "Insert the winning  score :", nullptr));
        lineEdit_vicotry_level->setText(QCoreApplication::translate("MainWindow", "Insert the victory level :", nullptr));
        lineEdit_victoryLines->setText(QCoreApplication::translate("MainWindow", "How many lines  you want to delete to win the game :", nullptr));
        lineEdit_setter_timer->setText(QCoreApplication::translate("MainWindow", "Set the   timer  in minutes :  ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_settings), QCoreApplication::translate("MainWindow", "Tab 0", nullptr));
        lineEdit_insert_height->setText(QCoreApplication::translate("MainWindow", "Insert the height of the board : ", nullptr));
        lineEdit_insert_width->setText(QCoreApplication::translate("MainWindow", "Insert the width of the board :", nullptr));
        textEdit_rappelSize->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI'; font-size:9pt;\">make sure to choose a  size between 10x10 </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI'; font-size:9pt;\">and 30x25</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margi"
                        "n-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        _submit_new_size->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_personlise_board), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "Do you want to prefill the board ?", nullptr));
        checkBox_yesPrefill->setText(QCoreApplication::translate("MainWindow", "Yes ", nullptr));
        checkBox_noPrefill->setText(QCoreApplication::translate("MainWindow", "No", nullptr));
        lineEdit_question_prefill->setText(QCoreApplication::translate("MainWindow", "How many blocks you want to use to prefill your board with ?", nullptr));
        pushButton_submit_prefil_board->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        label_NextBrick->setText(QCoreApplication::translate("MainWindow", "Next Brick", nullptr));
        label_Score->setText(QCoreApplication::translate("MainWindow", "Score", nullptr));
        label_Level->setText(QCoreApplication::translate("MainWindow", "Level", nullptr));
        label_Lines->setText(QCoreApplication::translate("MainWindow", "Lines", nullptr));
        pushButton_Restart->setText(QCoreApplication::translate("MainWindow", "Restart", nullptr));
        pushButton_Play->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        textEdit_rappelCommands->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI'; font-size:9pt;\"> Commands : </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI'; font-size:9pt;\">                     Q  : move left</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px;"
                        " -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI'; font-size:9pt;\">                     D : move right </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI'; font-size:9pt;\">                     S : move down</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI'; font-size:9pt;\">                     E: rotate clockwise	</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI'; font-size:9pt;\">                     X : drop the brick</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI'; font-size:9pt;\">       "
                        "             A : rotate anticlockwise</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI'; font-size:9pt;\">                   </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI'; font-size:9pt;\">    </span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_game), QCoreApplication::translate("MainWindow", "Tab 3", nullptr));
        menuOptios->setTitle(QCoreApplication::translate("MainWindow", "Optios", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
