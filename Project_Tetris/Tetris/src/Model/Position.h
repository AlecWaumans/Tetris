// Position.h
#ifndef POSITION_H
#define POSITION_H

class Position {
public:
    Position(int x = 0, int y = 0);
    Position getPosition(int x, int y);
    void setPosition(int x, int y);
    int getX() const;
    int getY() const;
    void move(int x ,int y);



private:
    int x;
    int y;
};

#endif // POSITION_H
