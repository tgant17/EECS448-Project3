/* -----------------------------------------------------------------------------
 *
 * File Name:  queen.h
 * Author: Tristan Gant 
 * Assignment:   EECS-448 Project 3
 * Description:  h file for the queen class
 * Date: 10/22/2020
 *
 ---------------------------------------------------------------------------- */

 #ifndef QUEEN_H
 #define QUEEN_H
 #include "chessPieceInterface.h"

 class queen : public chessPieceInterface
 {
    private:
        char symbol; 
        int currentRowPos;
        int currentColPos; 

    public: 

        queen(int row, int col, int player);
        ~queen(); 

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