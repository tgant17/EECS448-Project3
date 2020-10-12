/* -----------------------------------------------------------------------------
 *
 * File Name:  king.cpp
 * Author: Tristan Gant 
 * Assignment:   EECS-448 Project 3
 * Description:  cpp file for the king class
 * Date: 10/12/2020
 *
 ---------------------------------------------------------------------------- */
 #include "king.h"

 king::king(){} 
 king::~king(){}

 void king::move(int row, int col)
 {
    if(validMove(row, col))
    {
        throw("invalid move for KING");
    }
    else 
    {
        updatePosition(row, col);
    }
 }

void king::updatePosition(int row, int col)
{
    currentRowPos = row; 
    currentColPos = col;
}

// void king::attack(int row, int col)
// {

// }

bool king::validMove(int row, int col)
{
    if(row > currentRowPos+1 || col > currentColPos+1 || row < currentRowPos-1 || col < currentColPos-1)
    {
        return(false); 
    }
    else return(true);
}

char king::getSymbol()const
{
    return(symbol);
}

int king::getCurrentRowPos()const
{
    return(currentRowPos);
}

int king::getCurrentColPos()const
{
    return(currentColPos);
}