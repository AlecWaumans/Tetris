#include"Observable.h"
#include"Observer.h"
#include <vector>

void Observable::addObservers(  Observer* observer) {
    observers.push_back(observer);
}

void Observable::removeObserver(  Observer * observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}
void Observable::notifyObservers() {
    for (auto observer : observers) {
        observer->update( const_cast<Observable *>(this));
    }
}
