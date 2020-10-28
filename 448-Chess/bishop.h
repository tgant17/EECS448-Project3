/* -----------------------------------------------------------------------------
 *
 * File Name:  bishop.h
 * Author: Tristan Gant 
 * Assignment:   EECS-448 Project 3
 * Description:  h file for the bishop class
 * Date: 10/22/2020
 *
 ---------------------------------------------------------------------------- */

 #ifndef BISHOP_H
 #define BISHOP_H
 #include "chessPieceInterface.h"

 class bishop : public chessPieceInterface
 {
    private:
        char symbol; 
        int currentRowPos;
        int currentColPos; 

    public: 

        bishop(int row, int col, int player);
        ~bishop(); 

        void move(int row, int col, char **b);

        // void attack(int row, int col);

        // bool isAlive(); 

        bool validMove(int row, int col, char **b); 

        char getSymbol()const; 

        int getCurrentRowPos()const; 

        int getCurrentColPos()const; 

        bool emptySpace(char space); 
        
 };

 #endif