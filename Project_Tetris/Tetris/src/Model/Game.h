#ifndef GAME_H
#define GAME_H

#include "Bag.h"
#include "Board.h"
#include "State.h"
#include"Level.h"
#include "Observable.h"


class Game : public Observable{
public:
    Game(Board & board);


    void pause();
    void play();
    void LevelUp();
    int getScore()const ;
    void move(Direction direction);
    void handleInput(char input);
    bool isGameOver()const;
    void createCustomBrick(std::vector<std::vector<Shapes>> shape);
    const Board & getBoard()const;
    State getGameState()const;
    int getLevel()const;
    const Brick &getCurrentBrick()const ;
    const   Brick &getNextBrick()const;
    bool canMoveLeft();
    bool canMoveRight();
    bool canMoveDown();
    bool canRotate(RotationClock rotationClock);
    void moveLeft();
    void moveRight();
    void moveDown();
    void rotateCurrentBrick(RotationClock rotationClock);

    bool canInsertCurrentBlock();
    void drop();
    void setVictorie(int score,int level,int clearedLines);
    bool getVictorie()const;

    int getClearedLines()const;

    //used for MainWindow.h  and cpp
    void setBoard(const Board & board);
    void restart();
    double getSpeed();



// functions to test
    void setLevel(int level);
    void setScore(int score);
    void setCurrentBrick(const Brick &brick);
    void setClearedLines(int clearedLines);
    void testUpdateScore(int clearedLines,int dropHeight,int level);




private:
    Bag bag;
    Board board;
    State gameState;
    Level level;
    Brick currentBrick;
    Brick nextBrick;
    bool gameOver;
    int score;
    void updateScore(int clearedLines,int dropHeight,int level);
    int dropHeight;
    int clearedLines;
    bool victorie;
};


#endif //GAME_H
