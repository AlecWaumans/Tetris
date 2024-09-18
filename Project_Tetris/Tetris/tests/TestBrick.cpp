#include <catch2/catch_test_macros.hpp>
#include"Bricks/brick.h"

TEST_CASE("Test Brick functions", "[Brick]") {
    SECTION("Test move()") {
        Brick brick;
        brick.setPositionCentral(5, 5);
        brick.move(Direction::DOWN);
        REQUIRE(brick.getPositionCentral().getX() == 5);
        REQUIRE(brick.getPositionCentral().getY() == 6);
    }

    SECTION("Test reverse()") {
        Brick brick;
        brick.setPositionCentral(5, 5);
        brick.reverse();
        REQUIRE(brick.getPositionCentral().getX() == 5);
        REQUIRE(brick.getPositionCentral().getY() == 5);
    }

    SECTION("Test flipHorizontally()") {
        Brick brick;
        brick.setPositionCentral(5, 5);
        brick.flipHorizontally();
        REQUIRE(brick.getPositionCentral().getX() == 5);


    }


    SECTION("Test flipVertically()") {
        Brick brick;
        brick.setPositionCentral(5, 5);
        brick.flipVertically();
        REQUIRE(brick.getPositionCentral().getY() == 5);

    }

    SECTION("Test normalize()") {
        Brick brick;
        REQUIRE(brick.getPositionCentral().getX() == 0);
    }

}
