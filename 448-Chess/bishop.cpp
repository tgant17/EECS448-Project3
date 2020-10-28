/* -----------------------------------------------------------------------------
 *
 * File Name:  bishop.cpp
 * Author: Tristan Gant 
 * Assignment:   EECS-448 Project 3
 * Description:  cpp file for the bishop class
 * Date: 10/22/2020
 *
 ---------------------------------------------------------------------------- */
 #include "bishop.h"
 #include <iostream>
 #include <cmath>
 using namespace std;

 bishop::bishop(int row, int col, int player)
 {
    currentRowPos = row;
    currentColPos = col; 

    if(player == 1) symbol = 'B';
    else symbol = 'b';
 } 

 bishop::~bishop(){}

 void bishop::move(int row, int col, char **b)
 {
    if(!validMove(row, col, b))
    {
        throw(std::runtime_error("invalid move for BISHOP"));
    }
    else 
    {
        currentColPos = col; 
        currentRowPos = row; 
    }
 }

// void king::attack(int row, int col)
// {

// }

bool bishop::validMove(int row, int col, char **b)
{
    //if there is a piece at this space on the board
    if(!emptySpace(b[row][col])) return false; 

    // check if its NOT diagonal
    // if the difference between the startingRow and the destination row 
    // is equal to the difference between the startingCol and the destination col
    if(abs(currentRowPos - row) != abs(currentColPos - col)) return false; 
    else
    {
        //this is where the movement logic should go 
        //please test in main to make sure it works 
    }
}

char bishop::getSymbol()const
{
    return(symbol);
}

int bishop::getCurrentRowPos()const
{
    return(currentRowPos);
}

int bishop::getCurrentColPos()const
{
    return(currentColPos);
}

bool bishop::emptySpace(char space)
{
  if(space == '-') 
    return true; 
  else 
    return false; 
}