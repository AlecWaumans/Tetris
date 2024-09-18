#include "Board.h"
#include <algorithm>
#include <ctime>
#include"Position.h"
#include"Bricks/brick.h"

// Constructor
Board::Board(int height, int width)
    : height(height), width(width ), board(height, std::vector<Shapes>(width,Shapes::NO_SHAPE)) {
    clearLines=0;

}

int Board::getWidth()const {
    return width;
}

int  Board::getHeight() const {
    return height;
}

std::vector<std::vector<Shapes>> Board::getBoard()const {
    return board;
}

int Board::getClearLines() const {
    return clearLines;
}

void Board::fillRandomlyBoard(int nbr_blocks) {
    srand(time(nullptr));
    int minRowIndex = 15;
    int maxRowIndex = board.size() - 1;
    int maxColIndex = board[0].size() - 1;
    for (int i = 0; i < nbr_blocks; ++i) {
        int rowIndex = rand() % (maxRowIndex - minRowIndex + 1) + minRowIndex;
        int colIndex = rand() % (maxColIndex + 1);

        board[rowIndex][colIndex] = Shapes::O_SHAPE;
    }

}

int Board::deleteLines() {
    int linesDeleted = 0;
    //here we go through the table to check if there is not an empty case.
    for (int i = 0; i < board.size(); ++i) {
        bool isFullLine = true;
        for (const auto& cell : board[i]) {
            if (cell == Shapes::NO_SHAPE) {
                isFullLine = false;
                break;
            }
        }
        if (isFullLine) {
            linesDeleted++;
            this->clearLines++;
            for (int k = i; k > 0; --k) {
                board[k] = board[k - 1];
            }
            std::fill(board[0].begin(), board[0].end(), Shapes::NO_SHAPE);
        }
    }
    return linesDeleted;
}

// Method to add the current block to the board
int  Board::addBrickToBoard(const Brick &currentBrick) {
    std::vector<Position> brickPositions = currentBrick.getShapeBricks();
    for (const auto& pos : brickPositions) {
        Position netPos = Position(pos.getX() + currentBrick.getPositionCentral().getX(),
                                   pos.getY() + currentBrick.getPositionCentral().getY());
        int x =   netPos.getX();
        int y = netPos.getY();
        board[y][x] = currentBrick.getShapeType();
    }
    return deleteLines();



}

void Board::setHeigth(int height) {
    this->height = height;
}
void Board::setWidth(int width) {
    this->width = width;

}
void Board::clearBoard() {
    board.clear();
    board.resize(height, std::vector<Shapes>(width, Shapes::NO_SHAPE));
    clearLines = 0;
}
