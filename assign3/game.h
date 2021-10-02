/******************************************************
** Program: game.h
** Author: Ragini Dindukurthi
** Date: 5/6/2021
** Description: Zoo Tycoon Game
** Input: N/A
** Output: game statements and information
******************************************************/

#include <iostream> 
#include "zoo.h"

class Game{
    private: 
        Zoo myZoo; 
        int month; 
    public: 
        Game(); 
        /**********************************************************
        ** Description: default constructor 
        ** Pre-conditions: game object is created
        ** Post-conditions: game is initialized
        **********************************************************/
        void playGame();  
        /**********************************************************
        ** Description: turn structure 
        ** Pre-conditions: game is initialized
        ** Post-conditions: game is over, or user wants to quit
        **********************************************************/
        void specialEvent(int, int); 
        /**********************************************************
        ** Description: executes special event 
        ** Pre-conditions: animal info is printed 
        ** Post-conditions: special event is chosen and completed
        **********************************************************/
        int quit(); 
        /**********************************************************
        ** Description: asks user if they want to quit
        ** Pre-conditions: a turn is completed
        ** Post-conditions: game continues or ends
        **********************************************************/
        int foodChoice(int&, int&); 
        /**********************************************************
        ** Description: asks user to pick food quality
        ** Pre-conditions: game has just started
        ** Post-conditions: food costs calculated accordingly, probability of events calculated accordingly
        **********************************************************/

};