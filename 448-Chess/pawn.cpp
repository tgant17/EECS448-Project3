/* -----------------------------------------------------------------------------
 *
 * File Name:  pawn.cpp
 * Authors: Tristan Gant, Alec McGlynn
 * Assignment:   EECS-448 Project 3
 * Description:  cpp file for the pawn class
 * Date: 10/23/2020
 *
 ---------------------------------------------------------------------------- */
#include "pawn.h"
#include <iostream>
using namespace std;

pawn::pawn(int row, int col, int player)
{
    currentRowPos = row;
    currentColPos = col;
    isFirstMove = true;

    if (player == 1)
        symbol = 'P';
    else
        symbol = 'p';
}

pawn::~pawn() {}

void pawn::move(int row, int col)
{
    if (!validMove(row, col))
    {
        throw(std::runtime_error("invalid move for PAWN"));
    }
    else
    {
        currentColPos = col;
        currentRowPos = row;
    }
}

bool pawn::validMove(int row, int col)
{
    if(isFirstMove == true)
    {
        //this check is put in place because 
        //player 1 pawns only move up
        //player 2 pawns only move down
        if(symbol == 'P')
        {
            if(row < currentRowPos-2 || col != currentColPos) return false; 
            else return true; 
        }
        else // this is for player 2 
        {
            if(row > currentRowPos+2 || col != currentColPos) return false;
            else return true;
        }
    }
    
}

char pawn::getSymbol() const
{
    return (symbol);
}

int pawn::getCurrentRowPos() const
{
    return (currentRowPos);
}

int pawn::getCurrentColPos() const
{
    return (currentColPos);
}