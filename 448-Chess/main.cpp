/**
* Author: Tristan Gant 
* File: main.cpp
* Description: This file is the main, and is empty right now
* Date: Last changed on 10/7/20 by Tristan Gant 
*/
#include <iostream> 
#include "board.h"

int main()
{

    board test; 

    test.setInitialLocation();
    test.printPieceBoard();

cout << "WELCOME TO CHESS" << endl;
char n = 'y'; 
char n2;
int startRow, startCol, endRow, endCol; 
char inpCol, inpEndCol;

    while(1)
    {
        cout << "\n\twould u like to move a piece: ";
        cin >> n; 


        if(n == 'y')
        {
            cout << "what row is your piece at: ";
            cin >> startRow;
            cout << "what col is your piece at: ";
            cin >> inpCol; 
            cout << "what row do u want to move to: ";
            cin >> endRow;
            cout << "what col do u want to move to: ";
            cin >> inpEndCol; 

            startCol = test.convertCharToInt(inpCol); 
            endCol = test.convertCharToInt(inpEndCol); 

            system("clear");
            test.move(startRow-1, startCol, endRow-1, endCol, 1); 
            test.printPieceBoard();
        }
        else
        {
            cout << "Would you like to attack: "; 
            cin >> n2;

            if(n2 == 'y') 
            {
                cout << "what row is your piece at: ";
                cin >> startRow;
                cout << "what col is your piece at: ";
                cin >> inpCol; 
                cout << "what row do u want to attack: ";
                cin >> endRow;
                cout << "what col do u want to attack: ";
                cin >> inpEndCol; 

                startCol = test.convertCharToInt(inpCol); 
                endCol = test.convertCharToInt(inpEndCol); 

                system("clear"); 
                test.attack(startRow-1, startCol, endRow-1, endCol, 1);
                test.printPieceBoard();
            }
        }

    }

    //  BISHOPS can move diagonally in every direction but sometimes that cant move so far (?)
    //  PAWN attack works 5/6 times. it didnt work one time, not sure why 
    //      just something to watch for in bug checking 

    // WISH LIST 
    // TAKE IN A STRING FOR INPUTS and parse the string and convert to int / char
    //      input - A2 
    //      input - A4 

    //RUNTIME STUFF 
    //  CHECK AND MAKE SURE THE INPUTS ARE 1-8 and A-H
    //  INPUT ERROR CHECKING WILL BE A BIG THING OTHERWISE IT WILL RESULT IN A SEGFAULT
    //  ALSO WHEN ASKING FOR A PIECE LOCATION AT RUNTIME
    //      CHECK AND MAKE SURE THERE IS A PIECE AT THAT LOCATION
    //      CHECK AND MAKE SURE IT IS THE CORRECT PLAYERS PIECE



    return(0); 
}