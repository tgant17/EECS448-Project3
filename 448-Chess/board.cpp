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

    //initializes a board of chessPiece pointers and sets them to nullptr
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            chessPieceInterface* temp = nullptr; 
            m_PiecesBoard[i][j] = temp;
        }
    }
}

void board::addToPieceBoard(chessPieceInterface* piecePtr, int row, int col) //good
{
    if(row < 0 || col < 0 || piecePtr == nullptr)
    {
        throw(std::runtime_error("Does not exist"));
    }
    else 
    {
        m_PiecesBoard[row][col] = piecePtr;
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
        for(int j = 0; j < 8; j++)
        {
            if(j == 0) 
            {
                cout << i+1 << '\t';
            }
            cout << m_board[i][j]  << '\t';
        }
        cout << endl; 
    }
}

void board::printPieceBoard() //good
{
    //sets up the column labels for the board
    cout << " " << '\t'; 
    for(char i = 'A'; i <= 'H'; i++) cout << i << "\t";
    cout << "\n\n";

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(j == 0) 
            {
                cout << i+1 << '\t';
            }
            if(m_PiecesBoard[i][j] == nullptr) cout << "-" <<'\t';
            else cout << m_PiecesBoard[i][j]->getSymbol() << '\t';   
        }
        cout << endl;
    }
}

void board::setInitialLocation() //good
{
    //creates a king object and sets it at 1,1
    king* king1 = new king(7,4,1); 
    m_board[7][4] = king1->getSymbol();
    addToPieceBoard(king1, 7, 4); 

    queen* queen1 = new queen(7,3,1);
    m_board[7][3] = queen1->getSymbol(); 
    addToPieceBoard(queen1, 7, 3);

    rook* player1rook0 = new rook(7,0,1);
    rook* player1rook1 = new rook(7,7,1); 
    m_board[7][0] = player1rook0->getSymbol();
    m_board[7][7] = player1rook1->getSymbol();
    addToPieceBoard(player1rook0,7,0);
    addToPieceBoard(player1rook1, 7,7); 

    knight* player1knight0 = new knight(7,1,1);
    knight* player1knight1 = new knight(7,6,1); 
    m_board[7][1] = player1knight0->getSymbol();
    m_board[7][6] = player1knight1->getSymbol();
    addToPieceBoard(player1knight0, 7,1); 
    addToPieceBoard(player1knight1,7,6); 

    bishop* player1bishop0 = new bishop(7,2,1);
    bishop* player1bishop1 = new bishop(7,5,1); 
    m_board[7][2] = player1bishop0->getSymbol(); 
    m_board[7][5] = player1bishop1->getSymbol();
    addToPieceBoard(player1bishop0,7,2);
    addToPieceBoard(player1bishop1,7,5); 

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
    addToPieceBoard(player1pawn0,6,0);
    addToPieceBoard(player1pawn1,6,1);
    addToPieceBoard(player1pawn2,6,2);
    addToPieceBoard(player1pawn3,6,3);
    addToPieceBoard(player1pawn4,6,4);
    addToPieceBoard(player1pawn5,6,5);
    addToPieceBoard(player1pawn6,6,6);
    addToPieceBoard(player1pawn7,6,7);




    //player 2 pieces being placed //

    king* king2 = new king(0,3,2);
    m_board[0][3] = king2->getSymbol(); 
    addToPieceBoard(king2,0,3); 

    queen* queen2 = new queen(0,4,2);
    m_board[0][4] = queen2->getSymbol();
    addToPieceBoard(queen2,0,4); 

    rook* player2rook0 = new rook(0,0,2);
    rook* player2rook1 = new rook(0,7,2); 
    m_board[0][0] = player2rook0->getSymbol();
    m_board[0][7] = player2rook1->getSymbol();
    addToPieceBoard(player2rook0,0,0); 
    addToPieceBoard(player2rook1,0,7); 

    knight* player2knight0 = new knight(0,1,2);
    knight* player2knight1 = new knight(0,6,2); 
    m_board[0][1] = player2knight0->getSymbol();
    m_board[0][6] = player2knight1->getSymbol();
    addToPieceBoard(player2knight0,0,1); 
    addToPieceBoard(player2knight1,0,6); 

    
    bishop* player2bishop0 = new bishop(0,2,2);
    bishop* player2bishop1 = new bishop(0,5,2); 
    m_board[0][2] = player2bishop0->getSymbol(); 
    m_board[0][5] = player2bishop1->getSymbol();
    addToPieceBoard(player2bishop0,0,2); 
    addToPieceBoard(player2bishop1,0,5); 

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
    addToPieceBoard(player2pawn0,1,0);
    addToPieceBoard(player2pawn1,1,1);
    addToPieceBoard(player2pawn2,1,2);
    addToPieceBoard(player2pawn3,1,3);
    addToPieceBoard(player2pawn4,1,4);
    addToPieceBoard(player2pawn5,1,5);
    addToPieceBoard(player2pawn6,1,6);
    addToPieceBoard(player2pawn7,1,7);


}

bool board::checkForPiece(int row, int col)
{
    if(m_board[row][col] == '-') return false; 
    else return true;
}


void board::move(int pickRow, int pickCol, int moveToRow, int moveToCol, int currentTurnPlayer)
{
    if(checkForPiece(pickRow, pickCol)) //if there is a piece on this spot 
    {
        try
        {
            m_PiecesBoard[pickRow][pickCol]->move(moveToRow,moveToCol);
            chessPieceInterface* temp = m_PiecesBoard[pickRow][pickCol]; 
            m_PiecesBoard[pickRow][pickCol] = nullptr; 
            m_PiecesBoard[moveToRow][moveToCol] = temp;
        }
        catch(const runtime_error& rte)
        {
            cout << rte.what() << endl;
        }
        
    }
}