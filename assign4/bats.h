/******************************************************
** Program: bats.h
** Author: Ragini Dindukurthi
** Date: 5/20/21
** Description: Hunt the Wumpus Game
** Input: game functions
** Output: game statements and information
******************************************************/
#ifndef BATS_H
#define BATS_H

#include <iostream> 
#include <cstdlib> 

class Bats : public Event{
    public: 
        Bats(); 
        /**********************************************************
        ** Description: bat constructor
        ** Pre-conditions: a bat object is created
        ** Post-conditions: bat members are initialized
        **********************************************************/
        void encounter() override; 
        /**********************************************************
        ** Description: executes bat event
        ** Pre-conditions: player enters room with bats
        ** Post-conditions: throw exception, game ends 
        **********************************************************/
};




#endif