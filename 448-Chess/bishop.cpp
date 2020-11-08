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

 void bishop::move(int row, int col, char **b)//good
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

 bool bishop::validMove(int row, int col, char **b)//good
 {
     bool result = true;
     //if there is a piece at this space on the board
     if(!emptySpace(b[row][col]))
     {
         return(false);
     }
     // check if its NOT diagonal
     // if the difference between the startingRow and the destination row
     // is equal to the difference between the startingCol and the destination col
     if(abs(currentRowPos - row) != abs(currentColPos - col))
     {
         return(false);
     }

     while (true)
     {
         if(row == currentRowPos && col == currentColPos)
         {
             break;
         }
         else
         {
             if( emptySpace(b[row][col]) )
             {
                 if(row > currentRowPos && col > currentColPos)
                 {
                     row--;
                     col--;
                 }
                 else if(row > currentRowPos && col < currentColPos)
                 {
                     row--;
                     col++;
                 }
                 else if( row < currentRowPos && col < currentColPos)
                 {
                     row++;
                     col++;
                 }
                 else if(row < currentRowPos && col > currentColPos)
                 {
                     row++;
                     col--;
                 }
             }
             else
             {
                 result = false;
                 break;
             }
         }
     }

     return result;
 }

void bishop::attack(int row, int col, char **b)//good
{
    if(!validAttack(row, col, b))
    {
      throw(std::runtime_error("invalid ATTACK for BISHOP"));
    }
    else
    {
      currentColPos = col;
      currentRowPos = row;
    }
}

bool bishop::validAttack(int row, int col, char **b)//good
{
    if(!isOpposingPlayer(b[row][col])) return false;
    else
    {
        if(currentRowPos == row && currentColPos == col) return false;

        if(row == currentRowPos+1 && col == currentColPos+1) return true;

        else if(row == currentRowPos+1 && col == currentColPos-1) return true;

        else if(row == currentRowPos-1 && col == currentColPos+1) return true;

        else if(row == currentRowPos-1 && col == currentColPos-1) return true;

        else if( row < currentRowPos && col < currentColPos)
        {
            while (row != currentRowPos && col != currentColPos)
            {
                row++;
                col++;
                if(emptySpace(b[row][col])){return true;}
                else return false;
            }
        }

        else if( row < currentRowPos && col > currentColPos)
        {
            while (row != currentRowPos && col != currentColPos)
            {
                row++;
                col--;
                if(emptySpace(b[row][col])){return true;}
                else return false;
            }
        }

        else if( row > currentRowPos && col > currentColPos)
        {
            while (row != currentRowPos && col != currentColPos)
            {
                row--;
                col--;
                if(emptySpace(b[row][col])){return true;}
                else return false;
            }
        }

        else if( row > currentRowPos && col < currentColPos)
        {
            while (row != currentRowPos && col != currentColPos)
            {
                row--;
                col++;
                if(emptySpace(b[row][col])){return true;}
                else return false;
            }
        }

        else return false;


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

void bishop::isDead()
{
    symbol = '-';
}



bool bishop::isOpposingPlayer(char s)
{
    if(symbol == 'B') //if player1
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
