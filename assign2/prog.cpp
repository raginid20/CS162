/******************************************************
** Program: assign2_app
** Author: Ragini Dindukurthi
** Date: 4/24/2021
** Description: A Crazy Eights game 
** Input: N/A
** Output: game statements, card selections
******************************************************/

#include <iostream> 
#include "deck.h"
#include "player.h"

using namespace std; 

int main(){
    int over = 1;

    do{
        Game game1; 
        game1.playGame();

        cout << "Do you want to play again? (1-Play Again, 0-Quit): "; 
        cin >> over; 

    }while(over == 1);
    
    cout << "Goodbye!" <<endl; 

    return 0; 
}