#include <catch2/catch_test_macros.hpp>
#include "Position.h"

TEST_CASE("Test of the class of positions", "[Position]") {

    SECTION("Test of move()") {
        Position pos(100, 100);
        pos.move(10, 20);
        REQUIRE(pos.getX() == 110);
        REQUIRE(pos.getY() == 120);
    }
    SECTION("Test of move()") {
        Position pos(100, 100);
        pos.move(-10, -20);
        REQUIRE(pos.getX() == 90);
        REQUIRE(pos.getY() == 80);
    }
}
