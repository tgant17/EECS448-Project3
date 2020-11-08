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
        throw(std::runtime_error("invalid move for Queen"));
    }
    else
    {
        currentColPos = col;
        currentRowPos = row;
    }
 }

void queen::attack(int row, int col, char **b)//good
{
    if(!validAttack(row, col, b))
    {
      throw(std::runtime_error("invalid ATTACK for QUEEN"));
    }
    else
    {
      currentColPos = col;
      currentRowPos = row;
    }
}

bool queen::validAttack(int row, int col, char **b)
{
    if(!isOpposingPlayer(b[row][col])) return false;

    else
    {
        if(currentRowPos == row && currentColPos == col) return false;

        if(row == currentRowPos+1 && col == currentColPos+1) return true;

        else if(row == currentRowPos+1 && col == currentColPos-1) return true;

        else if(row == currentRowPos-1 && col == currentColPos+1) return true;

        else if(row == currentRowPos-1 && col == currentColPos-1) return true;

        else if(row == currentRowPos-1 && col == currentColPos) return true;

        else if(row == currentRowPos+1 && col == currentColPos) return true;

        else if(row == currentRowPos && col == currentColPos-1) return true;

        else if(row == currentRowPos && col == currentColPos+1) return true;

        else if(abs(row - currentRowPos) == abs(col - currentColPos)){ return true; }
        else if(
            (currentRowPos != row && currentColPos == col) ||
            (currentColPos != col && currentRowPos == row)
        ) return true;

        else return false;
    }
}

bool queen::validMove(int row, int col, char **b)//good
{

    if (!emptySpace(b[row][col])) return false;

    else if(currentRowPos == row && currentColPos == col) return false;

    else if(
         abs(currentRowPos - row) != abs(currentColPos - col)  &&
         currentRowPos != row && currentColPos != col
       ) return false;
    else return true;
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
