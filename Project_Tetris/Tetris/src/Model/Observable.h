#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <vector>
#include"Observer.h"

class Observable {
public:
    void addObservers(  Observer* observer);
    void removeObserver( Observer* observer);
    void notifyObservers();

private:

    std::vector<  Observer *> observers;
};
#endif // OBSERVABLE_H
