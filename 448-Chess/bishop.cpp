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
 using namespace std;

 bishop::bishop(int row, int col, int player)
 {
    currentRowPos = row;
    currentColPos = col; 

    if(player == 1) symbol = 'B';
    else symbol = 'b';
 } 

 bishop::~bishop(){}

 void bishop::move(int row, int col)
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

bool bishop::validMove(int row, int col)
{
    if(row > currentRowPos+1 || col > currentColPos+1 || row < currentRowPos-1 || col < currentColPos-1)
    {
        return(false); 
    }
    else return(true);
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