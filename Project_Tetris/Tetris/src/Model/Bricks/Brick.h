#ifndef BRICK_H
#define BRICK_H

#include"../Position.h"
#include <vector>
#include "../Direction.h"
#include"../RotationClock.h"
#include "../Shapes.h"
class Brick{
public:
    Brick(Position p);
    Brick();

    virtual ~Brick() = default;
    const std::vector<Position> getShapeBricks()const ;
    Position getPositionCentral() const;
    void move(Direction direction);
    void rotate(RotationClock rotation);
    Shapes getShapeType() const;
    void setPositionCentral(int x, int y);
    void reverse();
    void flipHorizontally();
    void flipVertically();
    void normalize();





private:

protected:
    std::vector<Position> shape;
     Position centralPosition;
     Shapes shapeType;

};

#endif //BRICK_H
