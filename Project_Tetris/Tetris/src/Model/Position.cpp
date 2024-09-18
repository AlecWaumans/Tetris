#include "Position.h"

Position::Position(int x, int y) : x(x), y(y) {}
Position Position::getPosition(int x, int y) {
    return Position(x, y);
}
void Position::setPosition(int x, int y) {
     this->x = x;
     this->y = y;
}

int Position::getX() const {
    return x;
}
int Position::getY() const {
    return y;
}
void Position::move(int x, int y) {
    this->x += x;
    this->y += y;
}
