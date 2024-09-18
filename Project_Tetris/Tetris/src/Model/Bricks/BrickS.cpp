
#include"BrickS.h"

BrickS::BrickS(): BrickS(Position(2, 2)){
}

BrickS::BrickS(Position centralPosition):Brick{centralPosition}  {

    shape = std::vector<Position>{
        Position(1,0),
        Position(0,0),
        Position(0,1),
        Position(-1,1)


    };

    shapeType = Shapes::S_SHAPE;
    normalize();

}

