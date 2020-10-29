/* -----------------------------------------------------------------------------
 *
 * File Name:  knight.cpp
 * Author: Tristan Gant 
 * Assignment:   EECS-448 Project 3
 * Description:  cpp file for the knight class
 * Date: 10/22/2020
 *
 ---------------------------------------------------------------------------- */
 #include "knight.h"
 #include <iostream>
 using namespace std;

 knight::knight(int row, int col, int player)
 {
    currentRowPos = row;
    currentColPos = col; 

    if(player == 1) symbol = 'N';
    else symbol = 'n';
 } 

 knight::~knight(){}

 void knight::move(int row, int col, char **b)
 {
    if(!validMove(row, col, b))
    {
        throw(std::runtime_error("invalid move for KNIGHT"));
    }
    else 
    {
        currentColPos = col; 
        currentRowPos = row; 
    }
 }

void knight::attack(int row, int col, char **b)
{

}

bool knight::validMove(int row, int col, char **b)
{
    //if there is a piece there already 
    if(!emptySpace(b[row][col])) return false; 

    //if the position doesnt change
    if(currentRowPos == row && currentColPos == col) return false; 

    //up one and right two 
    if(row == currentRowPos+1 && col == currentColPos+2) return true;  
    
    //up one and left two 
    else if(row == currentRowPos+1 && col == currentColPos-2) return true; 

    //up two and right one 
    else if(row == currentRowPos+2 && col == currentColPos+1) return true; 

    //up two and left one
    else if(row == currentRowPos+2 && col == currentColPos-1) return true; 

    //down one and left two 
    else if(row == currentRowPos-1 && col == currentColPos-2) return true; 

    //down one and right two
    else if(row == currentRowPos-1 && col == currentColPos+2) return true; 

    //down two and left one
    else if(row == currentRowPos-2 && col == currentColPos-1) return true; 

    //down two and right one
    else if(row == currentRowPos-2 && col == currentColPos+1) return true; 

    //if not an L
    else return false;


}

char knight::getSymbol()const
{
    return(symbol);
}

int knight::getCurrentRowPos()const
{
    return(currentRowPos);
}

int knight::getCurrentColPos()const
{
    return(currentColPos);
}

bool knight::emptySpace(char space)
{
  if(space == '-') 
    return true; 
  else 
    return false; 
}

void knight::isDead()
{
    symbol = '-';
}
