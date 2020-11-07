/* -----------------------------------------------------------------------------
 *
 * File Name:  game.cpp
 * Author: Tristan Gant 
 * Assignment:   EECS-448 Project 3/4
 * Description:  cpp file for the game class
 * Date: 10/29/2020
 *
 ---------------------------------------------------------------------------- */
 #include "game.h"

game::game()
{
    gameBoard.setInitialLocation(); //sets all the pieces on the board 
    whichPlayer = 1; //player 1 starts
    m_checkMate = false;
}

void game::run()
{
    //GAME INTRO 
    cout << "WELCOME TO CHESS\n" << endl;

    /**
    * game loop starts
    * checks which player is playing 
    * asks if they would like to attack or move 
    */
    while(checkMate() == false)
    {
        //if the game goes into checkMate then end the game
        if(checkHandling()) continue;
        usersMoving();
        changePlayer(getPlayer());
    }
    cout << "Game Over" << endl;
}

bool game::checkMate()
{
    return(m_checkMate);
}

void game::changePlayer(int player)
{
    if(whichPlayer == 1) 
        whichPlayer = 2;
    else 
        whichPlayer = 1;
}

int game::getPlayer()
{
    return(whichPlayer);
}

bool game::isLetter(char letter)
{
    if(letter == 'a' || letter == 'A' || letter == 'b' || letter == 'B') return true; 
    else if(letter == 'c' || letter == 'C' || letter == 'd' || letter == 'D') return true; 
    else if(letter == 'e' || letter == 'E' || letter == 'f' || letter == 'F') return true; 
    else if(letter == 'g' || letter == 'G' || letter == 'h' || letter == 'H') return true;
    else return false; 
}

bool game::isNumber(char num)
{
    if(num == '1' || num == '2' || num == '3' || num == '4' || num == '5')
        return true; 
    else if(num == '6' || num == '7' || num == '8' || num == '9' || num == '0')
        return true; 
    else 
        return false; 
}

void game::usersMoving()
{
    char attackOrMove; 
    // char n2;
    int startRow, startCol, endRow, endCol; 
    char inpCol, inpEndCol;
    string initialLocation; 
    string destination;
    bool validateInputLoop; 


    do
    {
        gameBoard.printPieceBoard(); //prints out the initial board 
        cout << "It is Player " << getPlayer() << "\'s turn\n" << endl;

        cout << "\n\t(move: 'm' || attack: 'a')";
        cout << "\n\twould u like to move a piece or attack: ";
        cin >> attackOrMove; 

        if(attackOrMove == 'a' || attackOrMove == 'A')
        {
            cout << "\n\t(e.g. A1 - H8)";
            cout << "\n\tWhere is your piece at: ";
            cin >> initialLocation;
            if(initialLocation.length() != 2) //if length is not two 
            {
                validateInputLoop = false;
                system("clear");
                cout << "invalid input" << endl;
                continue;
            }
            if(!isLetter(initialLocation[0])) //if col is not the right char
            {
                validateInputLoop = false;
                system("clear");
                cout << "invalid input" << endl;
                continue;
            }
            if(!isNumber(initialLocation[1])) //if the row is not a num 
            {
                validateInputLoop = false;
                system("clear");
                cout << "invalid input" << endl;
                continue;
            }

            //Converts the input to a single char and a int to pass as params
            inpCol = initialLocation[0]; 
            startRow = initialLocation[1] - 48;

            cout << "\n\t(e.g. A1 - H8)";
            cout << "\n\tWhere do you want to attack: ";
            cin >> destination;
            if(destination.length() != 2) //if length is not two 
            {
                validateInputLoop = false;
                system("clear");
                cout << "invalid input" << endl;
                continue;
            }
            if(!isLetter(destination[0])) //if col is not the right char
            {
                validateInputLoop = false;
                system("clear");
                cout << "invalid input" << endl;
                continue;
            }
            if(!isNumber(destination[1])) //if the row is not a num 
            {
                validateInputLoop = false;
                system("clear");
                cout << "invalid input" << endl;
                continue;
            }

            //convert the input to a single char and int
            inpEndCol = destination[0]; 
            endRow = destination[1] - 48; 

            //converts the COL chars to ints to pass in
            startCol = gameBoard.convertCharToInt(inpCol); 
            endCol = gameBoard.convertCharToInt(inpEndCol); 

            system("clear"); 
            try 
            {
                gameBoard.attack(startRow-1, startCol, endRow-1, endCol, getPlayer(), validateInputLoop);            
            }
            catch(std::runtime_error& rte)
            {
                cout << rte.what() << endl;
                validateInputLoop = false;
            }
        }
            //MOVE conditions
            /**
            * input from user is move
            * checks which player is playing 
            * asks if they would like to attack or move 
            */
        else if(attackOrMove == 'm' || attackOrMove == 'M')
        {
            cout << "\n\t(e.g. A1 - H8)";
            cout << "\n\tWhere is your piece at: ";
            cin >> initialLocation;
            if(initialLocation.length() != 2) //if length is not two 
            {
                validateInputLoop = false;
                system("clear");
                cout << "invalid input" << endl;
                continue;
            }
            if(!isLetter(initialLocation[0])) //if col is not the right char
            {
                validateInputLoop = false;
                system("clear");
                cout << "invalid input" << endl;
                continue; 
            }
            if(!isNumber(initialLocation[1])) //if the row is not a num 
            {
                validateInputLoop = false;
                system("clear");
                cout << "invalid input" << endl;
                continue; 
            }

            //Converts the input to a single char and a int to pass as params
            inpCol = initialLocation[0]; 
            startRow = initialLocation[1] - 48;

            cout << "\n\t(e.g. A1 - H8)";
            cout << "\n\tWhere do you want to move to: ";
            cin >> destination;
            if(destination.length() != 2) //if length is not two 
            {
                validateInputLoop = false;
                system("clear");                    
                cout << "invalid input" << endl;
                continue;
            }
            if(!isLetter(destination[0])) //if col is not the right char
            {
                validateInputLoop = false;
                system("clear");
                cout << "invalid input" << endl;
                continue;
            }
            if(!isNumber(destination[1])) //if the row is not a num 
            {
                validateInputLoop = false;
                system("clear");
                cout << "invalid input" << endl;
                continue;
            }

            //convert the input to a single char and int
            inpEndCol = destination[0]; 
            endRow = destination[1] - 48; 

            //converts the COL chars to ints to pass in
            startCol = gameBoard.convertCharToInt(inpCol); 
            endCol = gameBoard.convertCharToInt(inpEndCol); 

            system("clear"); 
            try
            {
                gameBoard.move(startRow-1, startCol, endRow-1, endCol, getPlayer(), validateInputLoop);
            }
            catch(const runtime_error& rte)
            {
                cout << rte.what() << endl;
                validateInputLoop = false;
            }
        }
        else 
        {
            validateInputLoop = false;
            system("clear");
            cout << "invalid input try again\n" << endl;
        }
    }while(validateInputLoop == false);
}

bool game::checkHandling()
{
    //if either player is in check
    if(gameBoard.inCheck(1))
    {
        cout << "Player 1 is in check" << endl;
        if(gameBoard.checkKingMoves(1)) 
        {
            m_checkMate = true; 
            return(true); 
        }

    }
    //player 2
    if(gameBoard.inCheck(2))
    {
        cout << "Player 2 is in check" << endl;
        if(gameBoard.checkKingMoves(2)) 
        {
            m_checkMate = true; 
            return(true); 
        }
    }
}