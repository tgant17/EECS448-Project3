/* -----------------------------------------------------------------------------
 *
 * File Name:  pawn.cpp
 * Author: Alec McGlynn
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
    if (validMove(row, col))
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
    if (currentColPos == col && ((isFirstMove && (symbol == 'P' && row == currentRowPos + 2) || symbol == 'p' && row == currentRowPos - 2) || ((symbol == 'P' && row == currentRowPos + 1) || (symbol == 'p' && row == currentRowPos - 1))))
    {
        return (false);
    }
    else
        return (true);
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