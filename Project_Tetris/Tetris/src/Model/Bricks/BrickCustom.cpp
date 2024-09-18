#include "BrickCustom.h"

BrickCustom::BrickCustom() : BrickCustom (Position(0,0)) {
normalize();
}

BrickCustom::BrickCustom(Position centrale) : Brick{centrale},created(false) {
    shapeType = Shapes::CUSTOM_SHAPE;
}


void BrickCustom::createBlock(Brick* brick) {
    if (brick) {

        shape = brick->getShapeBricks();
        centralPosition = brick->getPositionCentral();
        created = true;

    }
}


bool BrickCustom::isCreated() {
    return created;
}
