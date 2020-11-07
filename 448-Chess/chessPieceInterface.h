/* -----------------------------------------------------------------------------
 *
 * File Name:  chessPieceInterface.h
 * Author: Tristan Gant 
 * Assignment:   EECS-448 Project 3
 * Description:  h file for the chess piece class
 * Date: 10/29/2020
 *
 ---------------------------------------------------------------------------- */

 #ifndef CHESS_PIECE_INTERFACE_H
 #define CHESS_PIECE_INTERFACE_H

 class chessPieceInterface
 {
    public:

        /**
        * @pre empty constructor 
        */
        chessPieceInterface(){}

        /**
        * @pre empty destructor 
        */
        virtual ~chessPieceInterface(){}

        /**
        * @pre The chess piece has been created and the 2D array of chars
        * @param row - where to move on board 
        * @param col - where to move on board 
        * @param col - takes in a 2D array of chars to determine where other pieces are on the board
        * @post moves a chessPiece on the chessPiecePtr board and updates member variables 
        */
        virtual void move(int row, int col, char **b) = 0; 

        /**
        * @pre The chess piece has been created and validMove has to be defined
        * @param row - where to attack on board 
        * @param col - where to attack on board 
        * @param col - takes in a 2D array of chars to determine where other pieces are on the board
        * @post attacks a chessPiece on the chessPiecePtr board and updates member variables and removes attacked piece from the board
        */
        virtual void attack(int row, int col, char **b) = 0; 

        /**
        * @pre The chess piece has been created 
        * @post changes the symbol of a chessPiece to '-' which signifies an empty space 
        */
        virtual void isDead() = 0; 

        /**
        * @pre The chess piece has been created 
        * @param row - where to move on board 
        * @param col - where to move on board 
        * @param col - takes in a 2D array of chars to determine where other pieces are on the board
        * @post checks and makes sure the chessPiece can move that way
        */
        virtual bool validMove(int row, int col, char **b) = 0;

        /**
        * @pre The chess piece has been created 
        * @param row - where to attack on board 
        * @param col - where to attack on board 
        * @param col - takes in a 2D array of chars to determine where other pieces are on the board
        * @post checks and makes sure the chessPiece can attack that way
        */
        virtual bool validAttack(int row, int col, char **b) = 0;

        /**
        * @pre The chess piece can be created 
        * @post returns the symbol of the chess piece 
        */
        virtual char getSymbol()const = 0; 

    private: 

 };
 #endif
