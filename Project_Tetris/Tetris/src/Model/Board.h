#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Shapes.h"


class Brick;

class Board{
public:
  Board(int height, int width);


   void fillRandomlyBoard(int nbCase) ;
   std::vector<std::vector<Shapes>> getBoard() const ;
   int getWidth()const;
   int getHeight()const;
   int getClearLines()const;
   int addBrickToBoard(const Brick &currentBrick);
   int deleteLines();

   void setHeigth(int height);
   void setWidth(int width);
   void clearBoard();





private:

   int height;
    int width ;
    std::vector<std::vector<Shapes>> board;

    int clearLines;

};

#endif //BOARD_H
