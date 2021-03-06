/* -----------------------------------------------------------------------------
 *
 * File Name:  rook.h
 * Author: Tristan Gant 
 * Assignment:   EECS-448 Project 3
 * Description:  h file for the rook class
 * Date: 10/29/2020
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

        /**
        * @pre a board is created to put the rook on
        * @post sets row and column to starting position
        * @post determines if it will be a 'R' or a 'r' based on which player it is 
        */
        rook(int row, int col, int player);

        /**
        * @pre a rook object is created 
        * @post a rook object is destroyed 
        */
        ~rook(); 

        /**
        * @pre The chess piece has been created and the 2d array of chars
        * @param row - where to move on board 
        * @param col - where to move on board 
        * @param col - takes in a 2D array of chars to determine where other pieces are on the board
        * @post moves a chessPiece on the chessPiecePtr board and updates member variables 
        */
        void move(int row, int col, char** b);

        /**
        * @pre The chess piece has been created and validMove has to be defined
        * @param row - where to attack on board 
        * @param col - where to attack on board 
        * @param col - takes in a 2D array of chars to determine where other pieces are on the board
        * @post attacks a chessPiece on the chessPiecePtr board and updates member variables and removes attacked piece from the board
        */
        void attack(int row, int col, char** b);

        /**
        * @pre The chess piece has been created 
        * @post changes the symbol of a chessPiece to '-' which signifies an empty space 
        */
        void isDead(); 

        /**
        * @pre The chess piece has been created 
        * @param row - where to move on board 
        * @param col - where to move on board 
        * @param col - takes in a 2D array of chars to determine where other pieces are on the board
        * @post checks and makes sure the chessPiece can move that way
        */
        bool validMove(int row, int col, char** b); 

        /**
        * @pre The chess piece can be created 
        * @post returns the symbol of the chess piece 
        */
        char getSymbol()const; 

        /**
        * @pre The chess piece can be created 
        * @post returns the currentRowPos of the chess piece 
        */
        int getCurrentRowPos()const; 

        /**
        * @pre The chess piece can be created 
        * @post returns the currentColPos of the chess piece 
        */
        int getCurrentColPos()const; 

        /**
        * @pre The 2D array of chars must be created for the param
        * @post returns true if the index is empty 
        */
        bool emptySpace(char space); //takes in a char and if its '-' then return true

        /**
        * @pre The chess piece has been created and the 2d array of chars has been created
        * @param row - where to attack on board 
        * @param col - where to attack on board 
        * @param col - takes in a 2D array of chars to determine where other pieces are on the board
        * @post checks and makes sure the chessPiece can attack that space
        */
        bool validAttack(int row, int col, char **b);

        /**
        * @pre The 2D array of chars must be created for the param
        * @post returns true if the index is an opposing player  
        */
        bool isOpposingPlayer(char s);
        
 };

 #endif