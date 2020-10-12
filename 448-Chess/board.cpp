/* -----------------------------------------------------------------------------
 *
 * File Name:  board.h
 * Author: Tristan Gant 
 * Assignment:   EECS-448 Project 3
 * Description:  cpp file for the board class
 * Date: 10/12/2020
 *
 ---------------------------------------------------------------------------- */
#include "board.h"

board::board()
{
    m_cols = 8; 
    m_rows = 8; 

    m_board = new char*[8]; 
    for(int i = 0; i < 8; i++)
    {
        m_board[i] = new char[8]; 
    }

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            m_board[i][j] = '-'; 
        }
    }
}

board::~board()
{
    for(int i = 0; i < m_rows; i++)
    {
        delete m_board[i];
    }
    delete[] m_board;
}

void board::printBoard()
{
    for(int i = 0; i < m_rows; i++)
    {
        for(int j = 0; j < m_cols; j++)
        {
            cout << m_board[i][j];
        }
        cout << endl;
    }
}

void board::setLocation(int row, int col)
{
    king test; 
    test.updatePosition(row,col); 
    m_board[test.getCurrentRowPos()][test.getCurrentColPos()] = test.getSymbol(); 
}