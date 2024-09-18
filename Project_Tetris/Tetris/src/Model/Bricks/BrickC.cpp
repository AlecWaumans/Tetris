

#include"BrickC.h"
BrickC::BrickC(): BrickC(Position(2, 2)){
}

BrickC::BrickC(Position centralPosition): Brick {centralPosition}  {


    // Set the positions relative to the central position
    shape = std::vector<Position>{

        Position(0,-1),
        Position(1,-1),
        Position(0,0),
        Position(1,0),
    };
    shapeType = Shapes::O_SHAPE;
    normalize();

}


