cmake_minimum_required(VERSION 3.5)

add_executable(TetrisTests
    TestPosition.cpp
    ../src/Model/Position.cpp
    TestBoard.cpp
    ../src/Model/Board.cpp
    ../src/Model/Bricks/Brick.cpp
    TestBrick.cpp
    ../src//Model/Game.cpp
    ../src/Model/Bag.cpp
    ../src/Model/Level.cpp
    ../src/Model/Bricks/BrickC.cpp
    ../src/Model/Bricks/BrickCustom.cpp
    ../src/Model/Bricks/BrickI.cpp
    ../src/Model/Bricks/BrickJ.cpp
    ../src/Model/Bricks/BrickL.cpp
    ../src/Model/Bricks/BrickS.cpp
    ../src/Model/Bricks/BrickT.cpp
    ../src/Model/Bricks/BrickZ.cpp
    ../src/Model/Observable.cpp
    TestGame.cpp
    TestBag.cpp


)
target_include_directories(TetrisTests PRIVATE
    ../src/Model
)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.3.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)
#list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

target_link_libraries(TetrisTests Catch2::Catch2WithMain)
