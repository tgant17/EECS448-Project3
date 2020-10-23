/* -----------------------------------------------------------------------------
 *
 * File Name:  rook.cpp
 * Author: Tristan Gant 
 * Assignment:   EECS-448 Project 3
 * Description:  cpp file for the rook class
 * Date: 10/22/2020
 *
 ---------------------------------------------------------------------------- */
 #include "rook.h"
 #include <iostream>
 using namespace std;

 rook::rook(int row, int col, int player)
 {
    currentRowPos = row;
    currentColPos = col; 

    if(player == 1) symbol = 'R';
    else symbol = 'r';
 } 

 rook::~rook(){}

 void rook::move(int row, int col)
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

bool rook::validMove(int row, int col)
{
    if(row > currentRowPos+1 || col > currentColPos+1 || row < currentRowPos-1 || col < currentColPos-1)
    {
        return(false); 
    }
    else return(true);
}

char rook::getSymbol()const
{
    return(symbol);
}

int rook::getCurrentRowPos()const
{
    return(currentRowPos);
}

int rook::getCurrentColPos()const
{
    return(currentColPos);
}