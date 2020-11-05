/* -----------------------------------------------------------------------------
 *
 * File Name:  game.h
 * Author: Tristan Gant 
 * Assignment:   EECS-448 Project 3/4
 * Description:  Header file for the game class
 * Date: 10/29/2020
 *
 ---------------------------------------------------------------------------- */
#ifndef GAME_H
#define GAME_H

#include <string>
#include "board.h"
using namespace std;

class game 
{
    private:
        board gameBoard;
        int whichPlayer; 


    public:

        game();
        ~game(){}
        void run(); 

        bool checkMate();
        void changePlayer(int player); //changes from player 1 to player 2
        int getPlayer();
        bool isLetter(char letter); 
        bool isNumber(char num);

        void usersMoving();




};
#endif