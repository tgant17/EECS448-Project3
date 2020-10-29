/* -----------------------------------------------------------------------------
 *
 * File Name:  board.h
 * Author: Tristan Gant 
 * Assignment:   EECS-448 Project 3
 * Description:  Header file for the board class
 * Date: 10/22/2020
 *
 ---------------------------------------------------------------------------- */
#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string>
using namespace std; 
#include "chessPieceInterface.h"
#include "king.h"
#include "pawn.h"
#include "queen.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"



class board
{
    private:
        // this board keeps track of the symbols of each chess piece 
        // that way we can pass this board into the move function of 
        // every chess piece so it can determine where other pieces are at 
        char **m_board; 

        //this is a 2D array of chessPieceInterface* pointers 
        //this allows for the ability to assign any chess piece to the board 
        //that we need and then call on its methods no matter what class it is 
        //it wont matter if its a pawn, king, rook, etc 
        //it will only be able to call on the pure virtual functions that were 
        //declared in the chessPieceinterface class 
        chessPieceInterface* m_PiecesBoard[8][8]; //[0-63]
        int m_rows; 
        int m_cols; 

        bool checkForPiece(int row, int col); //checks the board to see if its occupied
        // int checkPlayer(char piece, int player); //checks if its lowercase or uppercase

    public:

        /**
        * @pre m_board is a 2D array of chars
        * @post fills an 8x8 board of chars and fills them with '-'s 
        * @post 
        */
        board();

        /**
        * @pre the board had been created
        * @post deletes the 2D array and frees memory to prevent memory leaks
        */
        ~board();

        /**
        * @pre The index is valid
        * @post creates an object for every piece for each player sets all the pieces on the game board
        */
        void setInitialLocation(); 

        /**
        * @pre The board was created and filled
        * @post prints out the board with all the correct elements 
        */
        void printBoard();

        /**
        * @pre The piece board is created 
        * @param takes in a chessPiece poiner, pawn, queen, etc.. 
        * @param row - where to place on board 
        * @param col - where to place on board 
        * @post adds an object to the chessPieceBoard
        */
        void addToPieceBoard(chessPieceInterface* piecePtr, int row, int col); 

        /**
        * @pre The board was created and filled with nullptr to start
        * @post prints out the board with all the correct elements 
        * @post mostly just used for debugging
        */
        void printPieceBoard();


        void move(int pickRow, int pickCol, int moveToRow, int moveToCol, int player);
        string getLocation();
        bool isOffBoard(int x, int y); 
        int convertCharToInt(char letter); 
        void attack(int pickRow, int pickCol, int moveToRow, int moveToCol, int player);

    
};
#endif