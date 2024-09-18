cmake_minimum_required(VERSION 3.5)
set (CMAKE_AUTOUIC ON)
set (CMAKE_AUTOMOC ON)
set (CMAKE_AUTORCC ON)

add_executable(Tetris


    ../src/Model/Bricks/Brick.cpp
    ../src/Model/Bricks/Brick.h
    ../src/Model/Bricks/BrickC.cpp
    ../src/Model/Bricks/BrickC.h
    ../src/Model/Bricks/BrickI.cpp
    ../src/Model/Bricks/BrickI.h
    ../src/Model/Bricks/BrickJ.cpp
    ../src/Model/Bricks/BrickJ.h
    ../src/Model/Bricks/BrickL.cpp
    ../src/Model/Bricks/BrickL.h
    ../src/Model/Bricks/BrickS.cpp
    ../src/Model/Bricks/BrickS.h
    ../src/Model/Bricks/BrickT.cpp
    ../src/Model/Bricks/BrickT.h
    ../src/Model/Bricks/BrickZ.cpp
    ../src/Model/Bricks/BrickZ.h
    ../src/Model/Bricks/BrickCustom.cpp
    ../src/Model/Bricks/BrickCustom.h
    ../src/Model/Board.cpp
    ../src/Model/Board.h
    ../src/Model/Bag.h
    ../src/Model/Bag.cpp
    ../src/Model/Position.cpp
    ../src/Model/Position.h
    ../src/Model/Game.cpp
    ../src/Model/Game.h
    ../src/Model/RotationClock.h
    ../src/Model/Shapes.h
    ../src/Model/Level.cpp
    ../src/Model/Level.h
    ../src/Model/State.h
    main.cpp
    Controller/Controller.h
    Controller/Controller.cpp
    View/View.h
    View/View.cpp
    Model/Observable.cpp
    Model/Observer.h
    Model/Observable.h
    View/ViewGui/mainwindow.h
    View/ViewGui/mainwindow.cpp
    View/ViewGui/mainwindow.ui


)



find_package (QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets )
find_package ( Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets )
target_link_libraries (Tetris PRIVATE
 Qt${QT_VERSION_MAJOR}::Widgets )


install(TARGETS Tetris
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
