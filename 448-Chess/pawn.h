/* -----------------------------------------------------------------------------
 *
 * File Name:  pawn.h
 * Author: Tristan Gant 
 * Assignment:   EECS-448 Project 3
 * Description:  h file for the pawn class
 * Date: 10/22/2020
 *
 ---------------------------------------------------------------------------- */

 #ifndef PAWN_H
 #define PAWN_H
 #include "chessPieceInterface.h"

 class pawn : public chessPieceInterface
 {
    private:
        char symbol; 
        int currentRowPos;
        int currentColPos;  //the pawn can move two spaces if it is the first move it makes
        bool isFirstMove;   //this determines if the pawn has moved yet or not

    public: 

        /**
        * @pre a board is created to put the pawn on
        * @post sets row and column to starting position
        * @post sets isFirstMove to true 
        * @post determines if it will be a 'P' or a 'p' based on which player it is 
        */
        pawn(int row, int col, int player);

        /**
        * @pre a pawn object is created 
        * @post a pawn object is destroyed 
        */
        ~pawn(); 




        void move(int row, int col);

        // void attack(int row, int col);

        // bool isAlive(); 

        bool validMove(int row, int col); 

        char getSymbol()const; //this is fine

        int getCurrentRowPos()const; //this is fine
 
        int getCurrentColPos()const; //this is fine
        
 };

 #endif