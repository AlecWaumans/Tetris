#include <catch2/catch_test_macros.hpp>
#include "Board.h"
#include"Bricks/brick.h"

TEST_CASE("Test class Board", "[Board]") {
    SECTION("Test du constructeur") {
        Board board(10, 20);
        REQUIRE(board.getWidth() == 20);
        REQUIRE(board.getHeight() == 10);
        REQUIRE(board.getClearLines() == 0);
    }

    SECTION("Test the  deleteLines()") {
        Board board(10, 20);
        for (int i = 0; i < 20; ++i) {
            board.getBoard()[9][i] = Shapes::O_SHAPE;
        }
        int linesDeleted = board.deleteLines();
        REQUIRE(linesDeleted == 0);
        REQUIRE(board.getClearLines() == 0);
    }

    SECTION("Test the  addBrickToBoard()") {
        // Test when the brick is added to the board

        Board board(10, 20);
        Brick brick(Position(5, 5));
        int linesDeleted = board.addBrickToBoard(brick);
        REQUIRE(linesDeleted == 0);

    }
    SECTION("Test the  addBrickToBoard()") {
        // Test when the brick is added to the board

        Board board(10, 20);
        Brick brick(Position(5, 5));
        int linesDeleted = board.addBrickToBoard(brick);
        REQUIRE(linesDeleted == 0);

    }
}



