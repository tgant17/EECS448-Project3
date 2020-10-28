/* -----------------------------------------------------------------------------
 *
 * File Name:  pawn.cpp
 * Authors: Tristan Gant, Alec McGlynn
 * Assignment:   EECS-448 Project 3
 * Description:  cpp file for the pawn class
 * Date: 10/23/2020
 *
 ---------------------------------------------------------------------------- */
#include "pawn.h"
#include <iostream>
using namespace std;

pawn::pawn(int row, int col, int player)
{
    currentRowPos = row;
    currentColPos = col;
    isFirstMove = true;

    if (player == 1)
        symbol = 'P';
    else
        symbol = 'p';
}

pawn::~pawn() {}

void pawn::move(int row, int col, char **b)
{
    if (!validMove(row, col, b))
    {
        throw(std::runtime_error("invalid move for PAWN"));
    }
    else
    {
        isFirstMove = false;
        currentColPos = col;
        currentRowPos = row;
    }
}

bool pawn::validMove(int row, int col, char **b)
{
    
    //if the position doesnt change
    if(currentRowPos == row && currentColPos == col) return false; 
    
    if(isFirstMove == true)
    {
        //this check is put in place because 
        //player 1 pawns only move up
        //player 2 pawns only move down
        if(symbol == 'P')
        {
            //if there is a piece in front of the pawn it can not move
            if(!emptySpace(b[row][col])) return false; 

            if(row < currentRowPos-2 || col != currentColPos || row > currentRowPos) return false; 
            else return true; 
        }
        else // this is for player 2 
        {
            //if there is a piece in front of the pawn it can not move
            if(!emptySpace(b[row][col])) return false; 
            
            if(row > currentRowPos+2 || col != currentColPos || row < currentRowPos) return false;
            else return true;
        }
    }
    else //the pawn can move one space forward
    {
        if(symbol == 'P')
        {
            //if there is a piece in front of the pawn it can not move
            if(!emptySpace(b[row][col])) return false; 

            if(row < currentRowPos-1 || col != currentColPos || row > currentRowPos) return false; 
            else return true; 
        }
        else // this is for player 2 
        {
            //if there is a piece in front of the pawn it can not move
            if(!emptySpace(b[row][col])) return false; 

            if(row > currentRowPos+1 || col != currentColPos || row < currentRowPos) return false;
            else return true;
        }
    }
    
}

char pawn::getSymbol() const
{
    return (symbol);
}

int pawn::getCurrentRowPos() const
{
    return (currentRowPos);
}

int pawn::getCurrentColPos() const
{
    return (currentColPos);
}

bool pawn::emptySpace(char space)
{
  if(space == '-') 
    return true; 
  else 
    return false; 
}
