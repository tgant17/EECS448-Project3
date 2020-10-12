/* -----------------------------------------------------------------------------
 *
 * File Name:  board.h
 * Author: Tristan Gant 
 * Assignment:   EECS-448 Project 3
 * Description:  Header file for the board class
 * Date: 10/7/2020
 *
 ---------------------------------------------------------------------------- */
#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
using namespace std; 
#include "king.h"

class board
{
    private:
        char **m_board; 
        int m_rows; 
        int m_cols; 

    public:

        board();

        ~board();

        void printBoard();

        string getLocation();
        void setLocation(int row, int col); 
        bool isOffBoard(int x, int y); 
    
};
#endif