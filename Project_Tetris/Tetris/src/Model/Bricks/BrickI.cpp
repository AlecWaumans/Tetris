
#include"BrickI.h"

BrickI::BrickI(): BrickI(Position(2, 2)){
}


BrickI::BrickI(Position centralPosition): Brick{centralPosition} {

    shape = std::vector<Position>{
        Position(0, 0),
        Position(0, 1),
        Position(0, 2),
        Position(0, 3)
    };

    shapeType = Shapes::I_SHAPE;
    normalize();


}
