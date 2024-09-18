#ifndef VIEW_H
#define VIEW_H
#include"../Model/Board.h"
#include"../Model/Game.h"
#include<string>



class View: public Observer{
public:
    View(Game &game);
    void drawBoard(const Board & board);
    void displayInfosGame( const Game *game);
    void displayCurrentBrick(const Brick &currentBrick);
    void displayNextBrick( const Brick &nextBrick);
    void update(const Observable *obs) override;
    void render();
    int getValidInput(const std::string& prompt, int min, int max);
    void commandHelp();




private:
    Game &game;
    std::vector<std::string> buffer;

};


#endif // VIEW_H
