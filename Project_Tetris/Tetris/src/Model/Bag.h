#ifndef BAG_H
#define BAG_H


#include "Bricks/Brick.h"
#include <vector>
#include "Shapes.h"
class Bag {
public:
    Bag();


    Brick getRandomBrick();
    void refillBag();
    void createCustomBlock(std::vector<std::vector<Shapes>> shape);
    Brick  sevenBricks();



private:

    std::vector<Brick> bricks;

};

#endif //BAG_H
