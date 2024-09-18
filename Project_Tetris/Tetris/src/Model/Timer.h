#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
public:
    Timer() {}

    void start() {
        startTime = std::chrono::steady_clock::now();
    }

    double getTimeInSeconds() const {
        std::chrono::duration<double> elapsed = std::chrono::steady_clock::now() - startTime;
        return elapsed.count();
    }

private:
    std::chrono::time_point<std::chrono::steady_clock> startTime;
};

#endif //TIMER_H
