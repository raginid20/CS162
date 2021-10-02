/******************************************************
** Program: pit.h
** Author: Ragini Dindukurthi
** Date: 5/20/21
** Description: Hunt the Wumpus Game
** Input: game functions
** Output: game statements and information
******************************************************/
#ifndef PIT_H
#define PIT_H

#include <iostream> 
#include <cstdlib> 
#include "event.h"

class Pit : public Event{
    public: 
        Pit(); 
        /**********************************************************
        ** Description: pit constructor
        ** Pre-conditions: pit object is created
        ** Post-conditions: pit members are initialized
        **********************************************************/
        void encounter() override; 
        /**********************************************************
        ** Description: executes pit event
        ** Pre-conditions: player is in a room with pit event
        ** Post-conditions: player dies, program ends 
        **********************************************************/
};


#endif