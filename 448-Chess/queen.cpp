/* -----------------------------------------------------------------------------
 *
 * File Name:  queen.cpp
 * Author: Tristan Gant 
 * Assignment:   EECS-448 Project 3
 * Description:  cpp file for the queen class
 * Date: 10/22/2020
 *
 ---------------------------------------------------------------------------- */
 #include "queen.h"
 #include <iostream>
 using namespace std;

 queen::queen(int row, int col, int player)
 {
    currentRowPos = row;
    currentColPos = col; 

    if(player == 1) symbol = 'Q';
    else symbol = 'q';
 } 

 queen::~queen(){}

 void queen::move(int row, int col, char **b)
 {
    if(!validMove(row, col, b))
    {
        throw(std::runtime_error("invalid move for KING"));
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

bool queen::validMove(int row, int col, char **b)
{
    if(row > currentRowPos+1 || col > currentColPos+1 || row < currentRowPos-1 || col < currentColPos-1)
    {
        return(false); 
    }
    else return(true);
}

char queen::getSymbol()const
{
    return(symbol);
}

int queen::getCurrentRowPos()const
{
    return(currentRowPos);
}

int queen::getCurrentColPos()const
{
    return(currentColPos);
}

bool queen::emptySpace(char space)
{
  if(space == '-') 
    return true; 
  else 
    return false; 
}