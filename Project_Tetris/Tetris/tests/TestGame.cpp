#include <catch2/catch_test_macros.hpp>
#include "Game.h"

TEST_CASE("Test suite for the Game class", "[Game]") {

    Board board(10, 20);
    Game game(board);

    SECTION("Initialization of the game") {
        REQUIRE_FALSE(game.isGameOver());
        REQUIRE(game.getScore() == 0);
        REQUIRE(game.getLevel() == 1);
        REQUIRE(game.getCurrentBrick().getShapeType() != Shapes::NO_SHAPE);
        REQUIRE(game.getNextBrick().getShapeType() != Shapes::NO_SHAPE);
    }

    SECTION("Move left") {
        int initialX = game.getCurrentBrick().getPositionCentral().getX();
        game.move(Direction::LEFT);
        REQUIRE(game.getCurrentBrick().getPositionCentral().getX() == initialX - 1);
    }

    SECTION("Move right") {
        int initialX = game.getCurrentBrick().getPositionCentral().getX();
        game.move(Direction::RIGHT);
        REQUIRE(game.getCurrentBrick().getPositionCentral().getX() == initialX + 1);
    }

    SECTION("Move down") {
        int initialY = game.getCurrentBrick().getPositionCentral().getY();
        game.move(Direction::DOWN);
        REQUIRE(game.getCurrentBrick().getPositionCentral().getY() == initialY + 1);
    }
}

TEST_CASE("Game updateScore() function") {
    Board board(10, 20);
    Game game(board);

    SECTION("No lines cleared") {
        int initialScore = game.getScore();
        game.testUpdateScore(0,0,0);
        REQUIRE(game.getScore() == initialScore);
    }

    SECTION("One line cleared and drop is equals to five") {
        int initialScore = game.getScore();
        int linesCleared = 1;
        int dropHeight = 5;
        int level = 2;
        int expectedPoints = 40 * linesCleared + 100 * dropHeight + 10 * level;
        game.testUpdateScore(linesCleared, dropHeight, level);
        REQUIRE(game.getScore() == initialScore + expectedPoints);
    }

    SECTION("Two lines cleared and drop is equals to seven") {
        int initialScore = game.getScore();
        int linesCleared = 2;
        int dropHeight = 7;
        int level = 3;
        int expectedPoints = 100 * linesCleared + 100 * dropHeight + 10 * level;
        game.testUpdateScore(linesCleared,dropHeight, level);
        REQUIRE(game.getScore() == initialScore + expectedPoints);
    }
}

TEST_CASE("Test Game::setVictorie") {
    Board board(10, 20);
    Game game(board);


    SECTION("Test when current score is greater than or equal to the given score") {
        game.setScore(100);
        int score = 50;
        int level = 2;
        int linesCleared = 10;
        game.setVictorie(score, level, linesCleared);
        REQUIRE(game.getVictorie() == true);
    }

    SECTION("Test when current level is the same as the given level") {
        game.setLevel(3);
        int score = 150;
        int level = 4;
        int linesCleared = 10;
        game.setVictorie(score, level, linesCleared);
        REQUIRE(game.getVictorie() == false);
    }

    SECTION("Test when current cleared lines is greater than or equal to the given linesCleared") {
        game.setClearedLines(20);
        int score = 150;
        int level = 4;
        int linesCleared = 15;
        game.setVictorie(score, level, linesCleared);
        REQUIRE(game.getVictorie() == true);
    }

    SECTION("Test when none of the conditions are met") {
        game.setScore(50);
        game.setLevel(1);
        game.setClearedLines(5);
        int score = 100;
        int level = 3;
        int linesCleared = 10;
        game.setVictorie(score, level, linesCleared);
        REQUIRE(game.getVictorie() == false);
    }
}

TEST_CASE("Test Game::canMoveRight") {
    Board board(10, 20);
    Game game(board);

    SECTION("No obstacles, brick can move right") {
        Brick brick(Position(4, 5));
        game.setCurrentBrick(brick);
        bool result = game.canMoveRight();
        REQUIRE(result == true);
    }
}
TEST_CASE("Test Game::canMoveDown") {
    Board board(10, 20);
    Game game(board);

    SECTION("No obstacles, brick can move down") {
        Brick brick(Position(4, 5));
        game.setCurrentBrick(brick);
        bool result = game.canMoveDown();
        REQUIRE(result == true);
    }
}

TEST_CASE("Test Game::canMoveLeft") {
    Board board(10, 20);
    Game game(board);

    SECTION("No obstacles, brick can move left") {
        Brick brick(Position(4, 5));
        game.setCurrentBrick(brick);
        bool result = game.canMoveLeft();
        REQUIRE(result == true);
    }
}





