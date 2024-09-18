#include "Level.h"

Level::Level(){
    currentLevel=1;
    speed=1000;
}

void Level::increaseLevel(){
    currentLevel++;
    updateSpeed();
}

void Level::updateSpeed(){
    switch(currentLevel){
    case 1:
        speed = 1000;
        break;
    case 2:
        speed = (53.0/60) * 1000;
        break;
    case 3:
        speed = (49.0/60) * 1000;
        break;
    case 4:
        speed = (45.0/60) * 1000;
        break;
    case 5:
        speed = (41.0/60) * 1000;
        break;
    case 6:
        speed = (37.0/60) * 1000;
        break;
    case 7:
        speed = (33.0/60) * 1000;
        break;
    case 8:
        speed = (28.0/60) * 1000;
        break;
    case 9:
        speed = (23.0/60) * 1000;
        break;
    case 10:
        speed = (18.0/60) * 1000;
        break;
    case 11:
        speed = (13.0/60) *1000;
        break;
    case 12:
        speed = (8.0/60) * 1000;
        break;
    case 13:
        speed = (9.0/60) * 1000;
        break;
    case 14:
        speed = (8.0/60) * 1000;
        break;
    case 15:
        speed = (7.0/60) * 1000;
        break;
    case 16:
        speed = (6.0/60) * 1000;
        break;
    case 17:
        speed = (5.0/60) * 1000;
        break;
    case 18:
        speed= (4.0/60) * 1000;
        break;
    case 19:
        speed = (3.0/60) * 1000;
        break;
    case 20:
        speed = (2.0/60) * 1000;
        break;

    }
}

int Level::getCurrentLevel()const{
    return currentLevel;
}

double Level::getSpeed()const{
    return speed;
}
void Level::setLevel(int lvl){
    this->currentLevel=lvl;
    updateSpeed();
}
