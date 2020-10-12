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
    test.printBoard(); 

    char answer = 'y';
    int row; 
    int col; 

    while(answer != 'n')
    {
        cout << "would you like to move(y/n): ";
        cin >> answer; 
        if(answer == 'n') break;
        cout << "row: ";
        cin >> row; 
        cout << "col: ";
        cin >> col; 
        test.setLocation(row, col);
        test.printBoard();
        
    }



    return(0); 
}