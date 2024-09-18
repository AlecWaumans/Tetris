#include "Model/Board.h"
#include "Model/Game.h"
#include "Controller/Controller.h"
#include "View/View.h"
#include <iostream>
#include <limits>
#include <QApplication>
#include"View/ViewGui/mainwindow.h"




#define Gui 0

#if Gui

  int getValidInput(const std::string& prompt, int minVal, int maxVal) {
    int  input;
    bool validInput = false;

    do {
        std::cout << prompt;
        std::cin >> input;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            std::cin.clear(); // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the input buffer
        } else if (input < minVal || input > maxVal) {
            std::cout << "Invalid input. Please enter a number between " << minVal << " and " << maxVal << "." << std::endl;
        } else {
            validInput = true;
        }
    } while (!validInput);

    return input;
}

int main() {
    std::cout << "Welcome to Tetris" << std::endl;

    int height, width;
    height = getValidInput("Insert the height of the board: ", 20, 100);
    width = getValidInput("Insert the width of the board: ", 10, 100);

    Board board(height, width);
    std::string answer;
    do{
    std::cout << "Do you want to partially fill the board? Press yes or no: ";
    std::cin >> answer;

    if (answer == "yes") {
            int n = getValidInput("Insert the number of cells to fill: ", 0, (height * width)/2);
        board.fillRandomlyBoard(n);
    }
    }while(answer!="yes"&&answer!="no");

    Game game(board);

    View view(game);
    Controller controller(game, view);

    controller.run();

    return 0;
}
#else
int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    MainWindow w;

    w.show();



    return a.exec();
}
#endif
