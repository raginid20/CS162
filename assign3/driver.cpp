/******************************************************
** Program: driver.cpp
** Author: Ragini Dindukurthi
** Date: 5/6/2021
** Description: Zoo Tycoon Game
** Input: N/A
** Output: game statements and information
******************************************************/

#include <iostream> 
#include "zoo.h"
#include "animal.h"
#include "lemur.h"
#include "tiger.h"
#include "blackbear.h"
#include "game.h"

using namespace std; 


int main(){
    srand(time(0));
 
    Game game; 
    game.playGame(); 

    return 0; 
}