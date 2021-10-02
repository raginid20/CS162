/******************************************************
** Program: wumpus.h
** Author: Ragini Dindukurthi
** Date: 5/20/21
** Description: Hunt the Wumpus Game
** Input: game functions
** Output: game statements and information
******************************************************/

#ifndef WUMPUS_H
#define WUMPUS_H

#include <iostream> 
#include <cstdlib> 
#include "event.h"

class Wumpus : public Event{
    public: 
        Wumpus(); 
        /**********************************************************
        ** Description: wumpus constructor
        ** Pre-conditions: a wumpus object is created
        ** Post-conditions: wumpus with initialized values is constructed
        **********************************************************/
        void encounter() override; 
        /**********************************************************
        ** Description: wumpus eats player
        ** Pre-conditions: player enters wumpus' room
        ** Post-conditions: throws exception to exit program since player is dead
        **********************************************************/
};




#endif