#include "Game.h"
#include"Board.h"
#include"Direction.h"
#include"Level.h"
#include"State.h"
#include"RotationClock.h"
#include"Bag.h"



Game::Game(Board & board):board{board},gameOver{false},score{0}
{
    level = Level();
    gameState = State::PLAY;
    currentBrick = bag.getRandomBrick();
    nextBrick = bag.getRandomBrick();
    currentBrick.setPositionCentral( board.getWidth()/2,0);
    nextBrick.setPositionCentral(board.getWidth()/2,0);
    dropHeight=0;
    score=0;
    clearedLines=0;
    victorie=false;

}
const Board & Game::getBoard() const {
    return board;
}
bool Game::isGameOver() const {
    return gameOver;
}
int Game::getScore() const {
    return score;
}
double Game::getSpeed() {
    return level.getSpeed();
}
int Game::getLevel() const {
    return level.getCurrentLevel();
}
const Brick& Game::getCurrentBrick()const{
    return currentBrick;

}

const Brick & Game::getNextBrick()const{
    return nextBrick;
}

bool Game::getVictorie() const {
    return victorie;
}

bool Game::canMoveRight() {
    std::vector<Position> brickPositions=currentBrick.getShapeBricks();
    for (const auto& pos : brickPositions) {
        int x =  pos.getX()+currentBrick.getPositionCentral().getX()+1;
        int y =  pos.getY()+currentBrick.getPositionCentral().getY();
        if (x >= board.getWidth() || board.getBoard()[y][x] != Shapes::NO_SHAPE) {
            return false;
        }
    }

    return true;
}

bool Game::canMoveDown() {
    // Get the shape bricks of the current brick
    std::vector<Position> brickPositions = currentBrick.getShapeBricks();
    // Check if the block will collide with any already placed blocks on the board
    for (const auto& pos : brickPositions) {
        int x = pos.getX()+currentBrick.getPositionCentral().getX() ;
        int y = pos.getY() +currentBrick.getPositionCentral().getY()+1; // Try moving the block down
        // Check if the position is out of bounds or overlaps with another block
        if (y > board.getHeight()-1 || (y < board.getHeight() && board.getBoard()[y][x] != Shapes::NO_SHAPE)) {
            return false;
        }
    }
    return true; // The block can move down without collisions
}

bool Game::canMoveLeft() {
    std::vector<Position> brickPositions=currentBrick.getShapeBricks();
    for (const auto& pos : brickPositions) {
        int x =  pos.getX()+currentBrick.getPositionCentral().getX()-1 ;
        int y =  pos.getY()+currentBrick.getPositionCentral().getY();
        if (x < 0 || board.getBoard()[y][x] != Shapes::NO_SHAPE) {
            return false;
        }
    }
    return true;
}

void Game::moveLeft(){
    if(canMoveLeft()){
        currentBrick.move(Direction::LEFT);
    }
}

void  Game::moveRight(){
    if(canMoveRight()) {
        currentBrick.move(Direction::RIGHT);
    }
}

void  Game::moveDown(){
    if (canMoveDown()) {
        currentBrick.move(Direction::DOWN);
    }else {
        updateScore(board.addBrickToBoard(currentBrick), dropHeight,level.getCurrentLevel());
        clearedLines=board.getClearLines();
        if(clearedLines/10==getLevel()){
            LevelUp();
        }
        dropHeight=0;
        currentBrick = nextBrick;
        nextBrick = bag.getRandomBrick();
        currentBrick.setPositionCentral( board.getWidth()/2,0);
        if (!canInsertCurrentBlock()) {
            this->gameOver=true;
        }
    }
}

bool Game::canRotate(RotationClock rotationClock) {
    // Clone the current block to perform the rotation check
    Brick clonedBlock = currentBrick;
    // Perform the rotation on the cloned block
    clonedBlock.rotate(rotationClock);
    // Get the positions of all bricks in the rotated block
    std::vector<Position> brickPositions = clonedBlock.getShapeBricks();
    // Check if the rotated block will collide with any already placed blocks on the board
    for (const auto& pos : brickPositions) {
        // Calculate the position of the current brick on the board after rotation
        int x =  pos.getX()+currentBrick.getPositionCentral().getX() ;
        int y =  pos.getY()+currentBrick.getPositionCentral().getY();
        // Check if the position is within the bounds of the board
        if (x < 0 || x >= board.getWidth() || y < 0 || y >= board.getHeight())
            return false;
        // Check if the position is already occupied by another block
        if (board.getBoard()[y][x] != Shapes::NO_SHAPE)
            return false;
    }
    return true; // The block can be rotated without collisions
}

void Game::rotateCurrentBrick(RotationClock rotation){
    if(canRotate(rotation)){
        currentBrick.rotate(rotation);
    }
    notifyObservers();
}

bool Game::canInsertCurrentBlock() {
    std::vector<Position> brickPositions = currentBrick.getShapeBricks();
    for (const auto& pos : brickPositions) {
        int row =  pos.getX()+currentBrick.getPositionCentral().getX();
        int col =  pos.getY()+currentBrick.getPositionCentral().getY();
        if (row < 0 || row >= board.getWidth() || col < 0 || col >= board.getHeight()) {
            return false;
        }
        if (board.getBoard()[col][row] != Shapes::NO_SHAPE) {
            return false;
        }
    }
    return true;
}

void Game::updateScore(int linesCleared, int dropHeight, int level) {
    int points = 0;

    if (linesCleared >= 1) {
        switch (linesCleared) {
        case 1:
            points = (40 * linesCleared +  dropHeight )  * level;
            break;
        case 2:
            points = (100 * linesCleared +  dropHeight) * level;
            break;
        case 3:
            points = (300 * linesCleared +  dropHeight) * level;
            break;
        case 4:
            points = (1200 * linesCleared +  dropHeight) * level;
            break;
        default:
            break;
        }
    }
    score += points;
}

void Game::pause() {
    gameState = State::PAUSE;
}

void Game::play() {
    gameState = State::PLAY;

    notifyObservers();

}

void Game::LevelUp() {
    level.increaseLevel();
    notifyObservers();
}


void Game::drop() {
    dropHeight=0;
    while (canMoveDown()) {
        moveDown();
        dropHeight++;
    }
    notifyObservers();


}
State Game::getGameState() const {
    return gameState;
}

void Game::move(Direction direction) {

    if(gameState==State::PLAY){
        switch (direction) {
        case Direction::LEFT:
            moveLeft();
            break;
        case Direction::RIGHT:
            moveRight();
            break;
        case Direction::DOWN:
            moveDown();
            break;
        }
    }
    notifyObservers();
}

void Game::handleInput(char input) {

    switch (input) {
    case 'p':
        pause();
        break;
    case 'r':
        play();
        break;
    case 'x':
        drop();
        break;
    case 'q':
        move(Direction::LEFT);
        break;
    case 's':
        move(Direction::DOWN);
        break;
    case 'd':
        move(Direction::RIGHT);
        break;
    case 'e':
       rotateCurrentBrick(RotationClock::CLOCKWISE);
        break;
    case 'a':
        rotateCurrentBrick(RotationClock::COUNTER_CLOCKWISE);
        break;
    case'l':
        exit(0);
        break;
    }
}
// functions for testing purposes
void Game::setScore(int score) {
    this->score = score;
}
void Game::setLevel(int level) {
    this->level.setLevel(level);
}
void Game::setClearedLines(int clearedLines) {
    this->clearedLines = clearedLines;
}

void Game::setCurrentBrick(const Brick & brick) {
    currentBrick = brick;
}

void Game::setVictorie(int  score,int level,int clearedLines){
    if(this->getScore()>=score || this->getLevel()>=level ||this->clearedLines>=clearedLines){
        this->victorie=true;
    }
}
void Game::testUpdateScore(int linesCleared, int dropHeight, int level) {
    updateScore(linesCleared, dropHeight, level);
}

int  Game::getClearedLines()const  {
    return  board.getClearLines();
}

void Game::setBoard(const Board & board) {
    this->board = board;
}

void Game::restart(){

    board.clearBoard();
    gameOver=false;
    victorie=false;
    level.setLevel(1);
    score=0;
    clearedLines=0;
    currentBrick = bag.getRandomBrick();
    nextBrick = bag.getRandomBrick();
    currentBrick.setPositionCentral( board.getWidth()/2,0);

}

