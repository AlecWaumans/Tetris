// Level.h
#ifndef LEVEL_H
#define LEVEL_H


class Level {
public:
    Level();

    void increaseLevel();
    int getCurrentLevel() const;
    double getSpeed() const;
    void setLevel(int level);
    void updateSpeed();


private:
    int currentLevel=1;
    double speed;


};

#endif // LEVEL_H
