/* -----------------------------------------------------------------------------
 *
 * File Name:  king.cpp
 * Author: Tristan Gant 
 * Assignment:   EECS-448 Project 3
 * Description:  cpp file for the king class
 * Date: 10/29/2020
 *
 ---------------------------------------------------------------------------- */
 #include "king.h"
 #include <iostream>
 using namespace std;

 king::king(int row, int col, int player)
 {
    currentRowPos = row;
    currentColPos = col; 

    if(player == 1) symbol = 'K';
    else symbol = 'k';
 } 

 king::~king(){}

 void king::move(int row, int col, char **b)
 {
    if(!validMove(row, col,b))
    {
        throw(std::runtime_error("invalid move for KING"));
    }
    else 
    {
        currentColPos = col; 
        currentRowPos = row; 
    }
 }

void king::attack(int row, int col, char **b)
{
    if(!validAttack(row, col, b))
    {
        throw(std::runtime_error("invalid ATTACK for KING"));
    }
    else
    {
        currentColPos = col;
        currentRowPos = row;
    }
}

bool king::validMove(int row, int col, char **b)
{
    //if there is a piece in the space already 
    if(!emptySpace(b[row][col])) return false;

    //if the position doesnt change
    if(currentRowPos == row && currentColPos == col) return false; 

    //diagonal up right 
    if(row == currentRowPos+1 && col == currentColPos+1) return true; 

    // down right
    else if(row == currentRowPos-1 && col == currentColPos+1) return true; 

    //down left 
    else if(row == currentRowPos-1 && col == currentColPos-1) return true; 

    //up left 
    else if(row == currentRowPos+1 && col == currentColPos-1) return true; 

    //right 
    else if(row == currentRowPos && col == currentColPos+1) return true; 

    //left 
    else if(row == currentRowPos && col == currentColPos-1) return true; 

    //up
    else if(row == currentRowPos+1 && col == currentColPos) return true; 

    //down 
    else if(row == currentRowPos-1 && col == currentColPos) return true; 

    else return false; 

    
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

bool king::emptySpace(char space)
{
  if(space == '-') 
    return true; 
  else 
    return false; 
}

void king::isDead()
{
    symbol = '-';
}

bool king::isOpposingPlayer(char s)
{
    if(symbol == 'K') //if player1 
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

bool king::validAttack(int row, int col, char **b)
{
    //if the space you are attacking is not an opposing player
    if(!isOpposingPlayer(b[row][col])) return false; 
    else 
    {
        //if the position doesnt change
        if(currentRowPos == row && currentColPos == col) return false; 

        //diagonal up right 
        if(row == currentRowPos+1 && col == currentColPos+1) return true; 

        // down right
        else if(row == currentRowPos-1 && col == currentColPos+1) return true; 

        //down left 
        else if(row == currentRowPos-1 && col == currentColPos-1) return true; 

        //up left 
        else if(row == currentRowPos+1 && col == currentColPos-1) return true; 

        //right 
        else if(row == currentRowPos && col == currentColPos+1) return true; 

        //left 
        else if(row == currentRowPos && col == currentColPos-1) return true; 

        //up
        else if(row == currentRowPos+1 && col == currentColPos) return true; 

        //down 
        else if(row == currentRowPos-1 && col == currentColPos) return true; 

        else return false; 
    }
}