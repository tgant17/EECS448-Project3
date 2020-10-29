/* -----------------------------------------------------------------------------
 *
 * File Name:  knight.h
 * Author: Tristan Gant 
 * Assignment:   EECS-448 Project 3
 * Description:  h file for the knight class
 * Date: 10/22/2020
 *
 ---------------------------------------------------------------------------- */

 #ifndef KNIGHT_H
 #define KNIGHT_H
 #include "chessPieceInterface.h"

 class knight : public chessPieceInterface
 {
    private:
        char symbol; 
        int currentRowPos;
        int currentColPos; 

    public: 

        knight(int row, int col, int player);
        ~knight(); 

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