### Tetris game 
This is a simple implementation of our Tetris. The game is built using object-oriented programming principles and consists of several classes, including Game, Board, Bag, Brick, Observable, and View.

### Features
- Random generation of tetromino shapes.
- Ability to move tetrominoes left, right, down, and rotate them.
- Scoring system based on the number of lines cleared simultaneously,current level and the height of the drop of tetromino.
- Pause and resume functionality.

### Gameplay
In order to set up the game properly, the game starts by asking the user to enter :

- the size of the board (minimum 20x10; maximum 100x100)
- whether or not they want to partially fill the board
- the winning score (minumum 5000)
- the victory level (minimum 2; maximum 20)
- the number of cleared lines needed to win (minimum 10).

Then, the game will ask the user to press 'h' to view the help guide and see the possible commands, or to directly start the game and give a command. The possible commands are:

q : move the tetronimo left
d : move the tetronimo right
s : move the tetronimo down
e : rotate the tetronimo clockwise
p : pause
x : to instantly drop the tetronimo
h : view the help guide
r : continue game
u : level up
a : rotate the tetronimo anticlockwise
l : to quit the game

After entering every command, the user has to press 'enter' in order to execute it.
The individual parts of the tetronimo will be  initially displayed as an 'a'. Once the user places the tetronimo in its desired final position, he/she should give the command 's' to confirm it. At this point the tetramino will change to its proper letter. 
The game ends when the stack of tetrominoes reaches the top of the playing field (GAME OVER), or if one of the winning parameters has been reached (VICTORY).

### Bugs
So far, we did not find any bugs.

### Programmers

Giuliano Taurone 59333
Alec Waumans 58399


