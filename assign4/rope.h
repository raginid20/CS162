/******************************************************
** Program: rope.h
** Author: Ragini Dindukurthi
** Date: 5/20/21
** Description: Hunt the Wumpus Game
** Input: game functions
** Output: game statements and information
******************************************************/
#ifndef ROPE_H
#define ROPE_H

#include <iostream> 
#include <cstdlib> 
#include "event.h"

class Rope : public Event{
    public: 
        Rope(); 
        /**********************************************************
        ** Description: rope constructor
        ** Pre-conditions: a rope object is created
        ** Post-conditions: rope with initialized values is constructed
        **********************************************************/
        void encounter() override; 
        /**********************************************************
        ** Description: does nothing!
        ** Pre-conditions: player enters room with rope
        ** Post-conditions: rope with initialized values is constructed
        **********************************************************/
};




#endif