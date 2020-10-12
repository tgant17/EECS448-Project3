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
        char symbol = 'K'; 
        int currentRowPos;
        int currentColPos; 

    public: 

        king(int row, int col);
        ~king(); 

        void move(int row, int col);

        // void attack(int row, int col);

        // bool isAlive(); 

        bool validMove(int row, int col); 

        char getSymbol()const; 

        int getCurrentRowPos()const; 

        int getCurrentColPos()const; 
        
 };

 #endif