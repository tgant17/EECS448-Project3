# EECS 448 - PROJECT 3 / 4
 For this project we created a game of Chess
 * Coding implementation was in C++
 * Board / Game class controls bulk of program operation.
 * Class list
   * game 
   * board 
   * chessPieceInterface
   * pawn
   * rook
   * knight
   * bishop
   * king
   * queen 
 * Board Size: 8x8
   * Columns denoted A-H
   * Rows denoted 1-8
 * Number of chess Pieces per player:
   * 8 pawns 
   * 2 rooks
   * 2 knights 
   * 2 bishops
   * 1 king 
   * 1 queen
 * Two players can play the game 
   * player 1 chess pieces denoted by upper case letters 
   * player 2 chess pieces denoted by lower case letters 
## Input:
Interaction with program occurs at runtime

## Installing

Clone this repository into a directory
```
~: cd Downloads
~/Downloads: git clone https://github.com/tgant17/EECS448-Project3
```

Compilation needs to be ran on the machine afterwords. Makefile included. Use 'make' and 'make clean' commands

## Run:
* executable name: chess
* Run in terminal using: ./chess

## Built With
* [GNU Compiler Collection - GCC](https://gcc.gnu.org/) - C++ compiler used. 
* [Valgrind](https://valgrind.org/) - Used for memory leak detection
* [GNU Debugger - gdb](https://www.gnu.org/savannah-checkouts/gnu/gdb/index.html) - For quick debugging done in terminal. 
* [DDD Debugger](https://www.gnu.org/software/ddd/) - For occasional debugging with graphical tool.

## Authors

* **Chenyu Hao** - *initial work* - [CHENYU HAO](https://github.com/c082h002)
* **Fengming Yang** - *initial work* - [f436y923](https://github.com/f436y923)
* **Mohammed Atif Siddiqui** - *initial work* - [atifsiddiqui10](https://github.com/atifsiddiqui10)
* **Tristan Gant** - *initial work* - [tgant17](https://github.com/tgant17)

## Contributors

* **University of Kansas School of Engineering** 

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Professor David Johnson
