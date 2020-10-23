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

 void knight::move(int row, int col)
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

// void king::attack(int row, int col)
// {

// }

bool knight::validMove(int row, int col)
{
    if(row > currentRowPos+1 || col > currentColPos+1 || row < currentRowPos-1 || col < currentColPos-1)
    {
        return(false); 
    }
    else return(true);
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