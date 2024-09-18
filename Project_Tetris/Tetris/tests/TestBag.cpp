#include <catch2/catch_test_macros.hpp>
#include "Bag.h"

TEST_CASE("Bag tests") {
    Bag bag;

    SECTION("getRandomBrick() returns a different brick each time") {
        Brick brick1 = bag.getRandomBrick();
        Brick brick2 = bag.getRandomBrick();
        REQUIRE(brick1.getShapeType() != brick2.getShapeType());
    }
    SECTION("refillBag() refills the bag with bricks") {
        Brick brick1 = bag.getRandomBrick();
        Brick brick2 = bag.getRandomBrick();
        Brick brick3 = bag.getRandomBrick();
        Brick brick4 = bag.getRandomBrick();
        Brick brick5 = bag.getRandomBrick();
        Brick brick6 = bag.getRandomBrick();
        Brick brick7 = bag.getRandomBrick();
        Brick brick8 = bag.getRandomBrick();
        Brick brick9 = bag.getRandomBrick();
        Brick brick10 = bag.getRandomBrick();
        Brick brick11 = bag.getRandomBrick();
        Brick brick12 = bag.getRandomBrick();
        REQUIRE(brick1.getShapeType() != brick2.getShapeType());
        REQUIRE(brick2.getShapeType() != brick3.getShapeType());
        REQUIRE(brick3.getShapeType() != brick4.getShapeType());
        REQUIRE(brick4.getShapeType() != brick5.getShapeType());
        REQUIRE(brick5.getShapeType() != brick6.getShapeType());
        REQUIRE(brick6.getShapeType() != brick7.getShapeType());
        REQUIRE(brick7.getShapeType() != brick8.getShapeType());
        REQUIRE(brick8.getShapeType() != brick9.getShapeType());
        REQUIRE(brick9.getShapeType() != brick10.getShapeType());
        REQUIRE(brick10.getShapeType() != brick11.getShapeType());
        REQUIRE(brick11.getShapeType() != brick12.getShapeType());
    }

    }

