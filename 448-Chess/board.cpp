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

board::board() //good
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

    m_PiecesBoard = new chessPieceInterface*[64]; 
}

void board::addToPieceBoard(chessPieceInterface* piecePtr, int index)
{
    if(index < 0 || piecePtr == nullptr)
    {
        throw(std::runtime_error("Does not exist"));
    }
    else 
    {
        m_PiecesBoard[index] = piecePtr; 
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

void board::printBoard() //good
{
    //sets up the column labels for the board
    cout << " " << '\t'; 
    for(char i = 'A'; i <= 'H'; i++) cout << i << "\t";
    cout << "\n\n";


    //prints out the board with the row labels
    for(int i = 0; i < m_rows; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(j == 0) 
            {
                cout << i+1 << '\t';
            }
            cout << m_board[i][j] << '\t';
        }
        cout << endl; 
    }
}

void board::setInitialLocation() //good
{
    //creates a king object and sets it at 1,1
    king* king1 = new king(7,4,1); 
    m_board[7][4] = king1->getSymbol();

    queen* queen1 = new queen(7,3,1);
    m_board[7][3] = queen1->getSymbol(); 

    rook* player1rook0 = new rook(7,0,1);
    rook* player1rook1 = new rook(7,7,1); 
    m_board[7][0] = player1rook0->getSymbol();
    m_board[7][7] = player1rook1->getSymbol();

    knight* player1knight0 = new knight(7,1,1);
    knight* player1knight1 = new knight(7,6,1); 
    m_board[7][1] = player1knight0->getSymbol();
    m_board[7][6] = player1knight1->getSymbol();

    bishop* player1bishop0 = new bishop(7,2,1);
    bishop* player1bishop1 = new bishop(7,5,1); 
    m_board[7][2] = player1bishop0->getSymbol(); 
    m_board[7][5] = player1bishop1->getSymbol();

    pawn* player1pawn0 = new pawn(6,0,1); 
    pawn* player1pawn1 = new pawn(6,1,1); 
    pawn* player1pawn2 = new pawn(6,2,1); 
    pawn* player1pawn3 = new pawn(6,3,1); 
    pawn* player1pawn4 = new pawn(6,4,1); 
    pawn* player1pawn5 = new pawn(6,5,1); 
    pawn* player1pawn6 = new pawn(6,6,1); 
    pawn* player1pawn7 = new pawn(6,7,1); 
    m_board[6][0] = player1pawn0->getSymbol(); 
    m_board[6][1] = player1pawn1->getSymbol(); 
    m_board[6][2] = player1pawn2->getSymbol(); 
    m_board[6][3] = player1pawn3->getSymbol(); 
    m_board[6][4] = player1pawn4->getSymbol(); 
    m_board[6][5] = player1pawn5->getSymbol(); 
    m_board[6][6] = player1pawn6->getSymbol(); 
    m_board[6][7] = player1pawn7->getSymbol(); 



    //player 2 pieces being placed //

    king* king2 = new king(0,3,2);
    m_board[0][3] = king2->getSymbol(); 

    queen* queen2 = new queen(0,4,2);
    m_board[0][4] = queen2->getSymbol();

    rook* player2rook0 = new rook(0,0,2);
    rook* player2rook1 = new rook(0,7,2); 
    m_board[0][0] = player2rook0->getSymbol();
    m_board[0][7] = player2rook1->getSymbol();

    knight* player2knight0 = new knight(0,1,2);
    knight* player2knight1 = new knight(0,6,2); 
    m_board[0][1] = player2knight0->getSymbol();
    m_board[0][6] = player2knight1->getSymbol();

    
    bishop* player2bishop0 = new bishop(0,2,2);
    bishop* player2bishop1 = new bishop(0,5,2); 
    m_board[0][2] = player2bishop0->getSymbol(); 
    m_board[0][5] = player2bishop1->getSymbol();

    pawn* player2pawn0 = new pawn(1,0,2); 
    pawn* player2pawn1 = new pawn(1,1,2); 
    pawn* player2pawn2 = new pawn(1,2,2); 
    pawn* player2pawn3 = new pawn(1,3,2); 
    pawn* player2pawn4 = new pawn(1,4,2); 
    pawn* player2pawn5 = new pawn(1,5,2); 
    pawn* player2pawn6 = new pawn(1,6,2); 
    pawn* player2pawn7 = new pawn(1,7,2); 
    m_board[1][0] = player2pawn0->getSymbol(); 
    m_board[1][1] = player2pawn1->getSymbol(); 
    m_board[1][2] = player2pawn2->getSymbol(); 
    m_board[1][3] = player2pawn3->getSymbol(); 
    m_board[1][4] = player2pawn4->getSymbol(); 
    m_board[1][5] = player2pawn5->getSymbol(); 
    m_board[1][6] = player2pawn6->getSymbol(); 
    m_board[1][7] = player2pawn7->getSymbol(); 

}

bool board::checkForPiece(int row, int col)
{
    if(m_board[row][col] == '-') return false; 
    else return true;
}

void board::move(int pickRow, int pickCol, int moveToRow, int moveToCol, int player)
{
    if(checkForPiece(pickRow, pickCol)) //if there is a piece on this spot 
    {
        int index = (pickRow+1) * (pickCol+1); 

        // m_PiecesBoard[]
    }
}