
#include"BrickJ.h"

BrickJ::BrickJ(): BrickJ(Position(2, 2)){
}

BrickJ::BrickJ(Position centralPosition):Brick{centralPosition}  {

    shape = std::vector<Position>{
        Position(0,-1),
        Position(0,0),
        Position(0,1),
        Position(-1,1)
    };
    shapeType = Shapes::J_SHAPE;
    normalize();

}
