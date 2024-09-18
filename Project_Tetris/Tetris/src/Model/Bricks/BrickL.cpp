#include"BrickL.h"
BrickL::BrickL(): BrickL(Position(2, 2)){
}

BrickL::BrickL(Position centralPosition):Brick{centralPosition}  {

    shape = std::vector<Position>{

        Position(0,-1),
        Position(0,0),
        Position(0,1),
        Position(1,1)

    };

    shapeType = Shapes::L_SHAPE;
    normalize();

}
