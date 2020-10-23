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

        void move(int row, int col);

        // void attack(int row, int col);

        // bool isAlive(); 

        bool validMove(int row, int col); 

        char getSymbol()const; 

        int getCurrentRowPos()const; 

        int getCurrentColPos()const; 
        
 };

 #endif