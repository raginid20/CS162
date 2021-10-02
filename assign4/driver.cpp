/******************************************************
** Program: driver.cpp
** Author: Ragini Dindukurthi
** Date: 5/20/21
** Description: Hunt the Wumpus Game
** Input: game functions
** Output: game statements and information
******************************************************/
#include <iostream> 
#include <cstring> 
#include <string.h> // for the strcmp function: https://www.cplusplus.com/reference/cstring/strcmp/
#include <exception> 
#include <vector>
#include <cstdlib> 
#include <ctime> 
#include "event.h"
#include "room.h"
#include "bats.h"
#include "gold.h"
#include "pit.h"
#include "wumpus.h"
#include "rope.h"
#include "game.h"

using namespace std; 

int main(int argc, char* argv[]){

    if(argc != 3){
        cout << "Missing/Invalid number of command line arguments!" <<endl; 
        return 0; 
    }

    bool mode; 
    srand(time(0)); 
    
    commandCheck(argv, argc, mode); 

    cout << "Welcome to Hunt the Wumpus!" <<endl; 
    Game game(atoi(argv[1]), mode);  
    game.assign(); 
    game.printBoard();
     
    int i = 1;  
    while(i == 1){
        try{
            game.navigate(); 
            game.endCheck(); 
        }catch(exception& dead){
            cout << "Game Over: You have died!" <<endl; 
            break; 
        }catch(int){
            cout << "You have won the game!" <<endl; 
            break; 
        }
    }
    
    return 0; 
}