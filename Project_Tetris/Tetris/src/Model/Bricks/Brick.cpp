#include "../Direction.h"
#include "../Position.h"
#include "../RotationClock.h"
#include <vector>
#include "Brick.h"

Brick::Brick() {
}

Brick::Brick(Position centralPosition):centralPosition{centralPosition} {
}

void Brick::setPositionCentral(int x, int y) {
    centralPosition.setPosition(x, y);
}

 const std::vector<Position> Brick::getShapeBricks()const  {
    return shape;
}

Position Brick::getPositionCentral() const {
    return centralPosition;
}

Shapes Brick::getShapeType() const {
    return shapeType;
}

//Methode to move the brick on the board
void Brick::move(Direction dir) {
    int deltaX = 0;
    int deltaY = 0;

    switch (dir) {
    case Direction::DOWN:
        deltaY = 1;
        break;
    case Direction::LEFT:
        deltaX = -1;
        break;
    case Direction::RIGHT:
        deltaX = 1;
        break;
    }
    centralPosition.setPosition(centralPosition.getX() + deltaX, centralPosition.getY() + deltaY);
   }


   // Reverse the X and Y coordinates of each block in the brick's shape
   void Brick::reverse() {
    for (Position& block : shape)
        block.setPosition(block.getY(),block.getX());
   }

   void Brick::flipHorizontally() {
    for (Position& block : shape)
        block.setPosition(-block.getX(),block.getY());
   }

   void Brick::flipVertically() {
    for (Position& block : shape)
        block.setPosition(block.getX(),-block.getY());
   }

   // Normalize the coordinates of blocks by shifting all blocks to have non-negative coordinates
   void Brick::normalize() {
    int minX = shape[0].getX();
    int minY = shape[0].getY();
    for (const Position& block : shape) {
        minX = std::min(minX, block.getX());
        minY = std::min(minY, block.getY());
    }
    for (Position& block : shape)
        block.setPosition( block.getX()-minX,block.getY()- minY);
   }


void Brick::rotate(RotationClock rot) {
    reverse();

        if (rot == RotationClock::CLOCKWISE) {
            flipHorizontally();

        } else {
            flipVertically();
        }
        normalize();
    }





