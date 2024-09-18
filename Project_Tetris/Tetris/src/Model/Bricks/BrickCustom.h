#ifndef BRICKCUSTOM_H
#define BRICKCUSTOM_H
#include "brick.h"
class BrickCustom: public Brick
{
public:

   BrickCustom(Position p);
   BrickCustom();
    void createBlock(Brick* brick);
   bool isCreated();
    private:
    bool created;
};

#endif // BRICKCUSTOM_H
