/* -----------------------------------------------------------------------------
 *
 * File Name:  rook.cpp
 * Author: Tristan Gant 
 * Assignment:   EECS-448 Project 3
 * Description:  cpp file for the rook class
 * Date: 10/22/2020
 *
 ---------------------------------------------------------------------------- */
 #include "rook.h"
 #include <iostream>
 using namespace std;

 rook::rook(int row, int col, int player)
 {
    currentRowPos = row;
    currentColPos = col; 

    if(player == 1) symbol = 'R';
    else symbol = 'r';
 } 

 rook::~rook(){}

 void rook::move(int row, int col)
 {
    if(validMove(row, col))
    {
        throw(std::runtime_error("invalid move for KING"));
    }
    else 
    {
        currentColPos = col; 
        currentRowPos = row; 
    }
 }
 void rook::attack(int row, int col)

{
  if (pieceAt(row, col) != EMPTY) return false;
  else if (currentRowPos == row) 
  {
    // horizontal move
    if (currentColPos == col) return false; // same position
    int dx, x;
    if (currentColPos < col) 
      dx = 1;
    else 
      dx = -1; 

    for (x = currentColPos + dx; x != col; x += dx) 
    {
      if (pieceAt(row, x) != EMPTY) return false; // occupied
    }
  }
  else if (currentColPos == col) 
  {
    // vertical move
    int dy, y;
    if (currentRowPos < row) 
      dy = 1;
    else 
      dy = -1; 

    for (y = currentRowPos + dy; y != row; y += dy) 
    {
      if (pieceAt(y, col) != EMPTY) return false; // occupied

      return true; // free path
    }


bool rook::validMove(int row, int col)
{
    if(row > currentRowPos+1 || col > currentColPos+1 || row < currentRowPos-1 || col < currentColPos-1)
    {
        return(false); 
    }
    else return(true);
}

char rook::getSymbol()const
{
    return(symbol);
}

int rook::getCurrentRowPos()const
{
    return(currentRowPos);
}

int rook::getCurrentColPos()const
{
    return(currentColPos);
}
