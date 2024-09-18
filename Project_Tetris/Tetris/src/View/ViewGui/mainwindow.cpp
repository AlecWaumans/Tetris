#include "mainwindow.h"
#include <QKeyEvent>
#include <QGraphicsRectItem>
#include <QColor>
#include <QPainter>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_MainWindow.h"
#include <QTimer>

// MainWindow constructor definition
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), _scene(this), _scene_NextBrick(this), _board(20, 10), _game{_board} {
    ui->setupUi(this);

    // Setting the main scene display area
    QRect viewContentsRect = ui->graphicsView->contentsRect();
    QRect viewContentsRectNextBrick = ui->graphicsView_NextBrick->contentsRect();
    _scene.setSceneRect(viewContentsRect);
    _scene_NextBrick.setSceneRect(viewContentsRectNextBrick);

    // Adding observers to the game
    _game.addObservers(this);

    // Setting timers for automatic block movement
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(moveBrickDown()));
    timerGame = new QTimer(this);
    timeUp = false;
    connect(timerGame, SIGNAL(timeout()), this, SLOT(updateGameTimer()));
    timer->start(_game.getSpeed());

    // Initializing user interface values
    reset = false;
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView_NextBrick->setRenderHint(QPainter::Antialiasing);
    ui->lineEdit_Level->setText(QString::number(_game.getLevel()));
    ui->lineEdit_Score->setText(QString::number(_game.getScore()));
    ui->lineEdit_Lines->setText(QString::number(_game.getClearedLines()));
    makeInvisibleTab();
    ui->lineEdit_question_prefill->setEnabled(false);
    ui->lineEdit_blocksToFillValue->setEnabled(false);
    _game.pause();
}

// Definition of the destructor of the MainWindow class
MainWindow::~MainWindow(){
    delete ui;
    delete timer;
    delete timerGame;
}

// How to quit the application
void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

// How to update the timer
void MainWindow::updateTimer(){
    timer->start(_game.getSpeed());
}

// Method for defining the game board
void MainWindow::setBoard (const Board & board){
    this->_board = board;
    _game.setBoard(_board);
}

// How to update the game timer
void MainWindow::updateGameTimer()
{
    // Checking remaining game time
    if (!timeUp && _game.getGameState() == State::PLAY && ui->pushButton_Play->text() == "Pause") {
        static int initialValue = ui->lineEdit_setter_time_value->text().toInt() * 60000;
        static int counterDown = initialValue;

        counterDown = counterDown - 1000;

        if (counterDown >= 0)
        {
            timeUp = false;
            ui->lcdNumber_timer->display(counterDown / 1000);
        }
        else
        {
            timeUp = true;
            counterDown = initialValue; //  Reset to initial value
            _game.notifyObservers();
        }

        // Resetting the counter at the end of a game or victory
        if (_game.isGameOver() || _game.getVictorie() || reset) {
            counterDown = initialValue;
            reset = false;
        }
    }
}

// Method for updating the display according to observers
void MainWindow::update(const Observable *obs)
{
    // Retrieving victory values from the user interface
    int score = ui->lineEdit_vicotory_score_value->text().toInt();
    int level = ui->lineEdit_victory_level_value->text().toInt();
    int clearedLines = ui->lineEdit_victory_lines_values->text().toInt();
    _game.setVictorie(score, level, clearedLines);

    // Converting observables into Game objects
    const Game * game {static_cast<const Game*>(obs)};
    paintEvent(&_scene, game->getBoard());
    paintCurrentBrick(&_scene, game->getCurrentBrick());
    paintEventNextBrick(&_scene_NextBrick, game->getNextBrick());
    updateTimer();

    // Game status management (game over, win, etc.)
    if (game->isGameOver()) {
        // Displaying an end-of-game message
        QMessageBox::information(this, "Game Over", "Game Over  \n Your Score : "+QString::number(game->getScore())+" points" );
        timerGame->stop();
        _game.restart();
        setBoard(_board);
        updateTimer();
        paintEvent(&_scene,_game.getBoard());
        paintCurrentBrick(&_scene, game->getCurrentBrick());
        paintEventNextBrick(&_scene_NextBrick,_game.getNextBrick());
        ui->lineEdit_Level->setText(QString::number(_game.getLevel()));
        ui->lineEdit_Score->setText(QString::number(_game.getScore()));
        ui->lineEdit_Lines->setText(QString::number(_game.getClearedLines()));
        _game.pause();
        ui->pushButton_Play->setText("Play");
        timerGame->start(1000);
    }

    // Elapsed time management
    if (timeUp) {
        QMessageBox::information(this, "Time Up", "Time Up  \n Your Score : "+QString::number(game->getScore())+" points" );
        timerGame->stop();
        timeUp = false;
        _game.restart();
        setBoard(_board);
        updateTimer();
        paintEvent(&_scene,_game.getBoard());
        paintCurrentBrick(&_scene, game->getCurrentBrick());
        paintEventNextBrick(&_scene_NextBrick,_game.getNextBrick());
        ui->lineEdit_Level->setText(QString::number(_game.getLevel()));
        ui->lineEdit_Score->setText(QString::number(_game.getScore()));
        ui->lineEdit_Lines->setText(QString::number(_game.getClearedLines()));
        _game.pause();
        ui->pushButton_Play->setText("Play");
    }

    // Victory management
    if (game->getVictorie()) {
        QMessageBox::information(this, "VICTORY", "VICTORY Congratulations you win \n Your score : "+QString::number(game->getScore())+" points");
        _game.restart();
        setBoard(_board);
        updateTimer();
        int score = ui->lineEdit_vicotory_score_value->text().toInt();
        int level = ui->lineEdit_victory_level_value->text().toInt();
        int clearedLines = ui->lineEdit_victory_lines_values->text().toInt();
        _game.setVictorie(score, level, clearedLines);
        paintEvent(&_scene,_game.getBoard());
        paintCurrentBrick(&_scene, game->getCurrentBrick());
        paintEventNextBrick(&_scene_NextBrick,_game.getNextBrick());
        ui->lineEdit_Level->setText(QString::number(_game.getLevel()));
        ui->lineEdit_Score->setText(QString::number(_game.getScore()));
        ui->lineEdit_Lines->setText(QString::number(_game.getClearedLines()));
        _game.pause();
        ui->pushButton_Play->setText("Play");
        timerGame->start(1000);
    }

    // Update display information
    ui->lineEdit_Level->setText(QString::number(game->getLevel()));
    ui->lineEdit_Score->setText(QString::number(game->getScore()));
    ui->lineEdit_Lines->setText(QString::number(game->getClearedLines()));
}

//  Method for moving the block down
void MainWindow::moveBrickDown(){
    if (_game.getGameState() == State::PLAY && ui->pushButton_Play->text() == "Pause" && !_game.isGameOver() && !_game.getVictorie() && !timeUp) {
        _game.move(Direction::DOWN);
    }
}

// How to start or pause the game
void MainWindow::on_pushButton_Play_clicked()
{
    _game.play();

    if(ui->pushButton_Play->text() == "Pause") {
        _game.pause();
        ui->pushButton_Play->setText("Play");
        timerGame->stop();
    } else {
        _game.play();
        ui->pushButton_Play->setText("Pause");
        timerGame->start(1000);
    }
}

// How to restart the game
void MainWindow::on_pushButton_Restart_clicked()
{
    reset = true;
    timerGame->stop();
    _game.restart();
    setBoard(_board);
    updateTimer();

    paintEvent(&_scene,_game.getBoard());
    paintEventNextBrick(&_scene_NextBrick,_game.getNextBrick());
    ui->lineEdit_Level->setText(QString::number(_game.getLevel()));
    ui->lineEdit_Score->setText(QString::number(_game.getScore()));
    ui->lineEdit_Lines->setText(QString::number(_game.getClearedLines()));
    _game.pause();
    ui->pushButton_Play->setText("Play");
    timerGame->start(1000);
}

// How to manage key events
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Q:
        _game.move(Direction::LEFT);
        break;
    case Qt::Key_D:
        _game.move(Direction::RIGHT);
        break;
    case Qt::Key_S:
        _game.move(Direction::DOWN);
        break;
    case Qt::Key_E:
        _game.rotateCurrentBrick(RotationClock::CLOCKWISE);
        break;
    case Qt::Key_X:
        _game.drop();
        break;
    case Qt::Key_A:
        _game.rotateCurrentBrick(RotationClock::COUNTER_CLOCKWISE);
        break;
    default:
        break;
    }
}

// How to validate custom parameters
void MainWindow::on_pushButton_submit_personalise_clicked()
{
    if(ui->lineEdit_vicotory_score_value->text().toInt() <= 100){
        QMessageBox::information(this, "Warning", "The victory score must be greater than 100");
        return;
    }
    if(ui->lineEdit_victory_level_value->text().toInt() < 2 || ui->lineEdit_victory_level_value->text().toInt() > 20){
        QMessageBox::information(this, "Warning", "The level must be between 2 and 20");
        return;
    }
    if(ui->lineEdit_victory_lines_values->text().toInt() <= 9){
        QMessageBox::information(this, "Warning", "The lines must be greater than 9");
        return;
    }
    if(ui->checkBox_perso_size_yes->checkState()){
        ui->tabWidget->setTabVisible(0,false);
        ui->tabWidget->setTabVisible(2,true);
        ui->tabWidget->removeTab(0);
    }
    if(ui->checkBox_perso_size_no->checkState()){
        ui->tabWidget->setTabVisible(0,false);
        ui->tabWidget->setTabVisible(1,true);
        ui->tabWidget->removeTab(0);
    }
}

// Method for validating the new tray size
void MainWindow::on__submit_new_size_clicked()
{
    QString heightStr = ui->lineEdit_height_value->text().trimmed();
    QString widthStr = ui->lineEdit_width_value->text().trimmed();

    if (!heightStr.isEmpty() && !widthStr.isEmpty()){
        int height = ui->lineEdit_height_value->text().toInt();
        int width = ui->lineEdit_width_value->text().toInt();

        if (height >= 10 && height <= 30 && width  >= 10 && width  <= 25 ){
            Board newBoard(height, width);
            _game.setBoard(newBoard);
            setBoard(newBoard);
            ui->tabWidget->setTabVisible(1, true);
            ui->tabWidget->removeTab(0);
        }
    }
}

// How to make a tab invisible
void MainWindow::makeInvisibleTab(){
    ui->tabWidget->setTabVisible(0,true);
    ui->tabWidget->setTabVisible(1,false);
    ui->tabWidget->setTabVisible(2,false);
    ui->tabWidget->setTabVisible(3,false);
}

// Method for validating tray filling configuration
void MainWindow::on_pushButton_submit_prefil_board_clicked()
{
    ui->graphicsView->setScene(&_scene);
    ui->graphicsView_NextBrick->setScene(&_scene_NextBrick);
    if(ui->checkBox_yesPrefill->checkState()){
        if(ui->lineEdit_blocksToFillValue->text().toInt() >= (_board.getHeight()*_board.getWidth())/2){
            QMessageBox::information(this, "Warning", "The number of blocks to fill is too high. Please enter a number less than "+QString::number((_board.getHeight()*_board.getWidth())/2));
            return;
        }
        _board.fillRandomlyBoard(ui->lineEdit_blocksToFillValue->text().toInt());
        _game.setBoard(_board);
        setBoard(_board);
        ui->tabWidget->setTabVisible(2,false);
        ui->tabWidget->setTabVisible(1,true);
        paintEvent(&_scene,_board);
        paintEventNextBrick(&_scene_NextBrick,_game.getNextBrick());
        ui->tabWidget->removeTab(0);
    }
    if(ui->checkBox_noPrefill->checkState()){
        ui->tabWidget->setTabVisible(2,false);
        ui->tabWidget->setTabVisible(1,true);
        paintEvent(&_scene,_board);
        paintEventNextBrick(&_scene_NextBrick,_game.getNextBrick());
        ui->tabWidget->removeTab(0);
    }
}

// How to activate input fields for tray filling
void MainWindow::on_checkBox_yesPrefill_clicked()
{
    ui->lineEdit_question_prefill->setEnabled(true);
    ui->lineEdit_blocksToFillValue->setEnabled(true);
}

// How to disable input fields for tray filling
void MainWindow::on_checkBox_noPrefill_clicked()
{
    ui->lineEdit_question_prefill->setEnabled(false);
    ui->lineEdit_blocksToFillValue->setEnabled(false);
}

// Method for designing the game board
void MainWindow::paintEvent(QGraphicsScene * scene , const Board &board) const {
    int boardHeight = board.getHeight();
    int boardWidth = board.getWidth();
    int cellWidth = ui->graphicsView->size().width()/boardWidth;
    int cellHeight= ui->graphicsView->size().height()/boardHeight;

    for (int row = 0; row < board.getHeight(); ++row) {
        for (int col = 0; col < board.getWidth(); ++col) {
            QGraphicsRectItem * rect = scene->addRect(col * cellWidth, row * cellHeight, cellWidth, cellHeight);
            QColor color;
            switch (board.getBoard()[row][col]) {
            case Shapes::NO_SHAPE:
                color = Qt::white;
                break;
            case Shapes::J_SHAPE:
                color = Qt::black;
                break;
            case Shapes::I_SHAPE:
                color = Qt::blue;
                break ;
            case Shapes::L_SHAPE:
                color = Qt::red;
                break;
            case Shapes::S_SHAPE:
                color = Qt::yellow;
                break;
            case Shapes::O_SHAPE:
                color = Qt::green;
                break;
            case Shapes::T_SHAPE:
                color = Qt::cyan;
                break ;
            case Shapes::Z_SHAPE:
                color = Qt::gray;
                break;
            }
            rect->setBrush(color);
        }
    }
}

// How to draw the next block
void MainWindow::paintEventNextBrick(QGraphicsScene *scene, const Brick &brick) const {
    scene->clear();
    int boardHeight = _board.getHeight()/2;
    int boardWidth = _board.getWidth()/2;
    int sceneWidth = scene->width();
    int sceneHeight = scene->height();
    int cellWidth = sceneWidth / boardWidth;
    int cellHeight = sceneHeight / boardHeight;
    int centerX = sceneWidth / 2;
    int centerY = sceneHeight / 2;
    int nextBrickWidth = 5 * cellWidth;
    int nextBrickHeight = 5 * cellHeight;
    int startX = centerX - nextBrickWidth /4;
    int startY = centerY - nextBrickHeight /4;

    for (const auto& block : brick.getShapeBricks()) {
        int row = block.getY();
        int col = block.getX();
        int x = startX + col * cellWidth;
        int y = startY + row * cellHeight;
        QGraphicsRectItem *rect = scene->addRect(x, y, cellWidth, cellHeight);
        QColor color;
        switch (brick.getShapeType()) {
        case Shapes::J_SHAPE:
            color = Qt::black;
            break;
        case Shapes::I_SHAPE:
            color = Qt::blue;
            break ;
        case Shapes::L_SHAPE:
            color = Qt::red;
            break;
        case Shapes::S_SHAPE:
            color = Qt::yellow;
            break;
        case Shapes::O_SHAPE:
            color = Qt::green;
            break;
        case Shapes::T_SHAPE:
            color = Qt::cyan;
            break ;
        case Shapes::Z_SHAPE:
            color = Qt::gray;
            break;
        default:
            color = Qt::white; // Default color
            break;
        }
        rect->setBrush(color);
    }
}

// How to draw the current block
void MainWindow::paintCurrentBrick(QGraphicsScene *scene, const Brick &currentBrick ) const {
    int boardHeight = _board.getHeight();
    int boardWidth = _board.getWidth();
    int cellWidth = ui->graphicsView->size().width()/boardWidth;
    int cellHeight= ui->graphicsView->size().height()/boardHeight;

    for (const auto& block : currentBrick.getShapeBricks()) {
        int row = block.getY() + currentBrick.getPositionCentral().getY();
        int col = block.getX() + currentBrick.getPositionCentral().getX();

        if (row >= 0 && row < _board.getHeight() && col >= 0 && col < _board.getWidth()) {
            int x = col * cellWidth;
            int y = row * cellHeight;
            QGraphicsRectItem *rect = scene->addRect(x, y, cellWidth, cellHeight);
            QColor color;
            switch (currentBrick.getShapeType() ){
            case Shapes::J_SHAPE:
                color = Qt::black;
                break;
            case Shapes::I_SHAPE:
                color = Qt::blue;
                break ;
            case Shapes::L_SHAPE:
                color = Qt::red;
                break;
            case Shapes::S_SHAPE:
                color = Qt::yellow;
                break;
            case Shapes::O_SHAPE:
                color = Qt::green;
                break;
            case Shapes::T_SHAPE:
                color = Qt::cyan;
                break ;
            case Shapes::Z_SHAPE:
                color = Qt::gray;
                break;
            default:
                color = Qt::white;
                break;
            }
            rect->setBrush(color);
        }
    }
}
