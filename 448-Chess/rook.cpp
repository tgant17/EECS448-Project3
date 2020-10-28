/* -----------------------------------------------------------------------------
 *
 * File Name:  rook.cpp
 * Author: Tristan Gant, Chenyu Hao
 * Assignment:   EECS-448 Project 3
 * Description:  cpp file for the rook class
 * Date: 10/22/2020
 *
 ---------------------------------------------------------------------------- */
 #include "rook.h"
 #include <iostream>
 using namespace std;

 rook::rook(int row, int col, int player) //good
 {
    currentRowPos = row;
    currentColPos = col; 

    if(player == 1) symbol = 'R';
    else symbol = 'r';
 } 

 rook::~rook(){} //good

 void rook::move(int row, int col, char** b)
 {
    if(!validMove(row, col, b))
    {
        throw(std::runtime_error("invalid move for ROOK"));
    }
    else 
    {
        currentColPos = col; 
        currentRowPos = row; 
    }
 }

bool rook::validMove(int row, int col, char** b)
{
  //if there is a piece in the space you are moving to
  if (!emptySpace(b[row][col])) return false; 

  //if the position doesnt change 
  else if(currentRowPos == row && currentColPos == col) return false; 

  //if the row and the column change it is not moving in a straight line
  else if(currentRowPos != row && currentColPos != col) return false; 

  else if (currentRowPos == row) //row doesnt change  
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
      if (!emptySpace(b[row][x])) return false; // occupied
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
      if (!emptySpace(b[y][col])) return false; // occupied
    }
  }
  return true; // free path
}

char rook::getSymbol()const //good
{
    return(symbol);
}

int rook::getCurrentRowPos()const //good
{
    return(currentRowPos);
}

int rook::getCurrentColPos()const //good
{
    return(currentColPos);
}

bool rook::emptySpace(char space)
{
  if(space == '-') 
    return true; 
  else 
    return false; 
}
