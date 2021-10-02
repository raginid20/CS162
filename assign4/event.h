/******************************************************
** Program: event.h
** Author: Ragini Dindukurthi
** Date: 5/20/21
** Description: Hunt the Wumpus Game
** Input: game functions
** Output: game statements and information
******************************************************/
#ifndef EVENT_H
#define EVENT_H

#include <iostream> 
#include <cstdlib> 

class Event{
    protected:
        std::string precept; 
        std::string letter; 
    public: 
        Event(); 
        /**********************************************************
        ** Description: event constructor
        ** Pre-conditions: an event object is created
        ** Post-conditions: event members initialized with nothing
        **********************************************************/
        virtual void encounter() = 0; 
        /**********************************************************
        ** Description: encounter function, executes the event
        ** Pre-conditions: player is in a room that contains an event
        ** Post-conditions: event is executed
        **********************************************************/
        std::string getPrecept() const; 
        /**********************************************************
        ** Description: returns precept of event
        ** Pre-conditions: event object is initialized
        ** Post-conditions: precept is returned to function call
        **********************************************************/
        std::string getLetter() const; 
        /**********************************************************
        ** Description: returns letter of event
        ** Pre-conditions: event object is initialized
        ** Post-conditions: letter is returned to function call
        **********************************************************/
};




#endif