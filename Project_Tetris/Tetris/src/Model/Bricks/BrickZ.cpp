
#include"BrickZ.h"

BrickZ::BrickZ(): BrickZ(Position(2, 2)){
}

BrickZ::BrickZ(Position centralPosition):Brick{centralPosition}  {

    shape = std::vector<Position>{
        Position(-1,0),
        Position(0,0),
        Position(0,1),
        Position(1,1)
    };

    shapeType = Shapes::Z_SHAPE;
    normalize();

}

