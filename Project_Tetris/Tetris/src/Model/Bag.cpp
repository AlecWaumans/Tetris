#include <vector>
#include "Bricks/Brick.h"
#include "Bricks/BrickC.h"
#include "Bricks/BrickJ.h"
#include "Bricks/BrickL.h"
#include "Bricks/BrickI.h"
#include "Bricks/BrickS.h"
#include "Bricks/BrickZ.h"
#include "Bricks/BrickT.h"
#include "Bricks/BrickCustom.h"
#include "Shapes.h"
#include "Bag.h"
#include <cstdlib>
#include <ctime>

// Constructeur
Bag::Bag() {
    // Initialize the bag with predefined bricks
    bricks.push_back(BrickC());
    bricks.push_back(BrickJ());
    bricks.push_back(BrickS());
    bricks.push_back(BrickI());
    bricks.push_back(BrickL());
    bricks.push_back(BrickZ());
    bricks.push_back(BrickT());
}


// Method to get a random brick from the bag
Brick Bag::getRandomBrick() {
    if (bricks.empty()) {
        refillBag();
    }
    // Generate a random index
    srand(time(NULL));
    int index = rand() % bricks.size() + 0;
    // Select a random brick from the bag
    Brick randomBlock = bricks[index];
    // Remove the selected brick from the bag
    bricks.erase(bricks.begin() + index);
    return randomBlock;
}

// Method to refill the bag with predefined bricks
void Bag::refillBag() {
    bricks.clear();
    bricks.push_back(BrickC());
    bricks.push_back(BrickJ());
    bricks.push_back(BrickS());
    bricks.push_back(BrickI());
    bricks.push_back(BrickL());
    bricks.push_back(BrickZ());
    bricks.push_back(BrickT());
}
// Method to create a custom block and add it to the bag
void Bag::createCustomBlock(std::vector<std::vector<Shapes>> shape) {
    bricks.push_back(BrickCustom());
}

