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
        throw(std::runtime_error("invalid move for QUEEN"));
    }
    else 
    {
        currentColPos = col; 
        currentRowPos = row; 
    }
 }

void queen::attack(int row, int col, char **b)
{
    if(!validMove(row, col, b))
    {
        throw(std::runtime_error("invalid attack for QUEEN"));
    }
    else 
    {
        currentColPos = col; 
        currentRowPos = row; 
    }
}

bool queen::validMove(int row, int col, char **b)
{
    return false;
    //  if((row - currentRowPos == col - currentColPos || row - currentRowPos == currentColPos - col) && row - currentRowPos != 0)
    // {
    //     int rowpace = row -currentRowPos;
    //     int colpace = col -currentColPos;
    //     if (rowpace > 0)
    //         rowpace = 1;
    //     else
    //         rowpace = -1;
    //     if (colpace > 0)
    //         colpace = 1;
    //     else
    //         colpace = -1;
    //     int i = currentRowPos+rowpace;
    //     int j = currentColPos+colpace;
    //     for (; i!=row; i +=rowpace)
    //     {
    //         if (!emptySpace(b[i][j]))
    //             return false;
    //         else
    //             j += colpace;
    //     }
    //     return true;
    // }
    // if (row == currentRowPos && col != currentColPos)
    // {
    //     int pace = col - currentColPos;
    //     if (pace > 0)
    //         pace = 1;
    //     else
    //         pace = -1;
    //     for (int i =currentColPos + pace; i != col; i+=pace)
    //         if (!emptySpace(b[row][i]))
    //             return false;
    //     return true;
    // }
    // else if (col == currentColPos && row != currentRowPos)
    // {
    //     int pace = row - currentRowPos;
    //     if (pace > 0)
    //         pace = 1;
    //     else
    //         pace = -1;
    //     for (int i =currentRowPos + pace; i != row; i+=pace)
    //         if (!emptySpace(b[i][col]))
    //             return false;
    //     return true;
    // }
    // else
    //     return false;
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

void queen::isDead()
{
    symbol = '-';
}

bool queen::isOpposingPlayer(char s)
{
    if(symbol == 'Q') //if player1 
    {
        if(s == 'p' || s == 'r' || s == 'n' || s == 'b' || s == 'q' || s == 'k') 
            return true; 
        else 
            return false; 
    }
    else 
    {
        if(s == 'P' || s == 'R' || s == 'N' || s == 'B' || s == 'Q' || s == 'K') 
            return true; 
        else 
            return false;       
    }
}

bool queen::validAttack(int row, int col, char **b)
{
    return false; 
}
