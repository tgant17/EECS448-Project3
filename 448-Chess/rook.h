/* -----------------------------------------------------------------------------
 *
 * File Name:  rook.h
 * Author: Tristan Gant 
 * Assignment:   EECS-448 Project 3
 * Description:  h file for the rook class
 * Date: 10/22/2020
 *
 ---------------------------------------------------------------------------- */

 #ifndef ROOK_H
 #define ROOK_H
 #include "chessPieceInterface.h"

 class rook : public chessPieceInterface
 {
    private:
        char symbol; 
        int currentRowPos;
        int currentColPos; 


    public: 

        rook(int row, int col, int player);
        ~rook(); 

        void move(int row, int col, char** b);

        void attack(int row, int col, char** b);

        void isDead(); 

        bool validMove(int row, int col, char** b); 

        char getSymbol()const; 

        int getCurrentRowPos()const; 

        int getCurrentColPos()const; 

        bool emptySpace(char space); //takes in a char and if its '-' then return true
        
 };

 #endif