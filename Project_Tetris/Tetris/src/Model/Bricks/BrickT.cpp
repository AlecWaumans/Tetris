

#include "brickt.h"

BrickT::BrickT(): BrickT(Position(2, 2)){
}

BrickT::BrickT(Position centralPosition):Brick{centralPosition}  {

    shape = std::vector<Position>{
                                  Position(-1,0),
                                  Position(0,0),
                                  Position(1,0),
                                  Position(0,1)


    };

    shapeType = Shapes::T_SHAPE;
    normalize();

}
