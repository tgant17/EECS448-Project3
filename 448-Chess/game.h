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

#include "board.h"

class game 
{
    private:
        board gameBoard;


    public:

        game();
        ~game(){}
        void run(); 



};
#endif