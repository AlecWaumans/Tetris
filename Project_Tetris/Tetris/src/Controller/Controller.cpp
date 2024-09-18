#include "Controller.h"
#include <iostream>
#include <unistd.h>
#include <limits>

Controller::Controller(Game &game, View &view) : game{game}, view{view} {

    game.addObservers(&view);
}

bool is_input_av() {
    return std::cin.peek() != EOF;
}
void flush_input_buffer() {
    // Clear the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Controller::run() {

    int score=this->view.getValidInput("Insert the winning  score: ", 5000, std::numeric_limits<int>::max());
    int level=this->view.getValidInput("Insert the victory level: ", 2, 20);
    int clearedLines=this->view.getValidInput("How many lines  you want to delete to win the game: ", 10, std::numeric_limits<int>::max());
    std::cout<<"Insert h for help guide  or a command  "<<std::endl;
    while (!game.isGameOver()&&!game.getVictorie()) {
    game.setVictorie(score,level,clearedLines);
        usleep(1000);
        // Check if there's input available
        if (is_input_av()) {
            char input;
            std::cin.get(input);
            // Check if input was successful
            if (std::cin.good()) {
                game.handleInput(input);
                if(input=='h'){
                    view.commandHelp();
                }
            }
            else {
                // Handle input error
                std::cerr << "Input error!" << std::endl;
                // Clear error state and flush the input buffer
                std::cin.clear();
                flush_input_buffer();
            }
        }
    }
}
