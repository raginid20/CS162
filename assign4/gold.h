/******************************************************
** Program: gold.h
** Author: Ragini Dindukurthi
** Date: 5/20/21
** Description: Hunt the Wumpus Game
** Input: game functions
** Output: game statements and information
******************************************************/
#ifndef GOLD_H
#define GOLD_H

#include <iostream> 
#include <cstdlib> 
#include "event.h"

class Gold : public Event{
    public: 
        Gold(); 
        /**********************************************************
        ** Description: gold constructor
        ** Pre-conditions: a gold object is created
        ** Post-conditions: gold members are initialized
        **********************************************************/
        void encounter() override; 
        /**********************************************************
        ** Description: executes gold event
        ** Pre-conditions: player is in room w gold event
        ** Post-conditions: player has picked up gold
        **********************************************************/
};  




#endif