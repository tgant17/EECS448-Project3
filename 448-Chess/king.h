/* -----------------------------------------------------------------------------
 *
 * File Name:  king.h
 * Author: Tristan Gant 
 * Assignment:   EECS-448 Project 3
 * Description:  h file for the king class
 * Date: 10/12/2020
 *
 ---------------------------------------------------------------------------- */

 #ifndef KING_H
 #define KING_H
 #include "chessPieceInterface.h"

 class king : public chessPieceInterface
 {
    private:
        char symbol; 
        int currentRowPos;
        int currentColPos; 

    public: 

        king(int row, int col, int player);
        ~king(); 

        void move(int row, int col, char **b);

        void attack(int row, int col, char **b);

        void isDead();

        bool validMove(int row, int col, char **b); 

        char getSymbol()const; 

        int getCurrentRowPos()const; 

        int getCurrentColPos()const; 

        bool emptySpace(char space); 
        
 };

 #endif