#include"View.h"
#include"../Model/Board.h"
#include <unistd.h>
#include <iostream>
#include"../Model/Game.h"
#include<limits>

View::View(Game &game):game(game) {}

void View::drawBoard( const  Board & board) {
     buffer.resize(game.getBoard().getHeight(),std::string(game.getBoard().getWidth(),'.'));
    for (int i = 0; i < board.getHeight(); ++i) {
        for (int j = 0; j <board.getWidth(); ++j) {
            switch (board.getBoard()[i][j]) {
            case Shapes::NO_SHAPE:
                buffer[i][j] = '.';
                break;
            case Shapes::I_SHAPE:
                buffer[i][j] = 'I';
                break;
            case Shapes::J_SHAPE:
                buffer[i][j] = 'J';
                break;
            case Shapes::L_SHAPE:
                buffer[i][j] = 'L';
                break;
            case Shapes::O_SHAPE:
                buffer[i][j] = 'O';
                break;
            case Shapes::S_SHAPE:
                buffer[i][j] = 'S';
                break;
            case Shapes::T_SHAPE:
                buffer[i][j] = 'T';
                break;
            case Shapes::Z_SHAPE:
                buffer[i][j] = 'Z';
                break;
            case Shapes::CUSTOM_SHAPE:
                buffer[i][j] = 'C';
                break;

            }
        }
    }

}
void View::displayCurrentBrick( const Brick &currentBrick) {

    const std::vector<Position> brickPositions = currentBrick.getShapeBricks();
    for (const auto& pos : brickPositions) {
        Position netPos = Position(
            pos.getX() + currentBrick.getPositionCentral().getX(),
            pos.getY() + currentBrick.getPositionCentral().getY()
        );
        buffer[netPos.getY()][netPos.getX()] = 'a';
    }
}
//will use this later for the graphic part
void View::displayNextBrick(const Brick &nextBrick) {
  const   std::vector<Position> brickPositions = nextBrick.getShapeBricks();
    for (const auto& pos : brickPositions) {
    }
}

void View::displayInfosGame( const Game *game){
    std::cout<<std::endl;
    if(game->getGameState()==State::PAUSE){
        std::cout<<"--- GAME ON PAUSE---"<<std::endl;
    }else{
        std::cout<<"---score : "<<game->getScore()<<" ---"<<std::endl;
        std::cout<<"---level : "<<game->getLevel()<<" ---"<<std::endl;
        std::cout<<"---cleared lines : "<<game->getBoard().getClearLines()<<" ---"<<std::endl;
std::cout<<std::endl;
    }
}

void View::render() {
    // Draw the board
    for (const auto& row : buffer) {
for (const char & c : row) {
            std::cout << c<<'|';
}

std::cout<<std::endl;
    }
}

void View::update(const  Observable * obs) {
   const Game * game {static_cast<const Game*>(obs)} ;
    drawBoard(game->getBoard());
    displayInfosGame(game);
    displayCurrentBrick(game->getCurrentBrick()) ;
    displayNextBrick(game->getNextBrick());
    render();
    if(game->isGameOver()){
        std::cout<<"GAME OVER"<<std::endl;
    }
    if(game->getVictorie()){
        std::cout<<"VICTORY"<<std::endl;
    }
    std::cout<<"Insert command : ";
}

int View::getValidInput(const std::string& prompt, int minVal, int  maxVal) {
    int input;
    bool validInput = false;
    do {
        std::cout << prompt;
        std::cin >> input;
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            std::cin.clear(); // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the input buffer
        } else if (input < minVal || input > maxVal) {
            std::cout << "Invalid input. Please enter a number between " << minVal << " and " << maxVal << "." << std::endl;
        } else {
            validInput = true;
        }
    } while (!validInput);
    return input;
}

void View::commandHelp(){
    std::cout<<"Commands : "<<std::endl;
    std::cout<<"q : move left"<<std::endl;
    std::cout<<"d : move right"<<std::endl;
    std::cout<<"s : move down"<<std::endl;
    std::cout<<"e : rotate clockwise"<<std::endl;
    std::cout<<"p : pause"<<std::endl;
    std::cout<<"x : to drop the brick"<<std::endl;
    std::cout<<"h : help"<<std::endl;
    std::cout<<"r : continue game"<<std::endl;
    std::cout<<"u : level up"<<std::endl;
    std::cout<<"a : rotate anticlockwise"<<std::endl;
    std::cout<<"l : to quit the game"<<std::endl;
    std::cout<<"Insert command : ";
}

