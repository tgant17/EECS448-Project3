/* -----------------------------------------------------------------------------
 *
 * File Name:  chessPieceInterface.h
 * Author: Tristan Gant 
 * Assignment:   EECS-448 Project 3
 * Description:  h file for the chess piece class
 * Date: 10/12/2020
 *
 ---------------------------------------------------------------------------- */

 #ifndef CHESS_PIECE_INTERFACE_H
 #define CHESS_PIECE_INTERFACE_H

 class chessPieceInterface
 {
    public:

        chessPieceInterface(){}
        virtual ~chessPieceInterface(){}

        virtual void move(int row, int col, char **b) = 0; 

        virtual void attack(int row, int col, char **b) = 0; 

        virtual void isDead() = 0; 

        virtual bool validMove(int row, int col, char **b) = 0;

        virtual char getSymbol()const = 0; 

    private: 

 };
 #endif
