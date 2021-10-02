/******************************************************
** Program: room.h
** Author: Ragini Dindukurthi
** Date: 5/20/21
** Description: Hunt the Wumpus Game
** Input: game functions
** Output: game statements and information
******************************************************/
#ifndef ROOM_H
#define ROOM_H

#include <iostream> 
#include <cstdlib> 
#include "event.h"

class Room{
    private: 
        Event* event; 
    public: 
        Room();
        /**********************************************************
        ** Description: room constructor
        ** Pre-conditions: a room object is created
        ** Post-conditions: event pointer initialized with nullptr
        **********************************************************/
        ~Room();  
        /**********************************************************
        ** Description: room destructor
        ** Pre-conditions: a room object is created
        ** Post-conditions: dynamic memory is freed
        **********************************************************/
        void printPrecept(); 
        /**********************************************************
        ** Description: prints precept of room event pointer is pointing to
        ** Pre-conditions: event* is pointing to an event
        ** Post-conditions: event's precept is printed
        **********************************************************/
        void printLetter(); 
        /**********************************************************
        ** Description: prints letter of room event pointer is pointing to
        ** Pre-conditions: event* is pointing to an event
        ** Post-conditions: event's letter is printed
        **********************************************************/
        void playEvent(); 
        /**********************************************************
        ** Description: executes event of event*
        ** Pre-conditions: event* is pointing to an event
        ** Post-conditions: event is completed
        **********************************************************/
        std::string letter(); 
        /**********************************************************
        ** Description: returns letter of event*'s event
        ** Pre-conditions: event* is pointing to an event
        ** Post-conditions: event's letter is returned
        **********************************************************/
        void setEvent(Event*);
        /**********************************************************
        ** Description: sets event of argument
        ** Pre-conditions: room object is created
        ** Post-conditions: event* is initialized
        **********************************************************/
        Event* getEvent(); 
        /**********************************************************
        ** Description: returns event*
        ** Pre-conditions: room object is created
        ** Post-conditions: event* is returned to function call
        **********************************************************/
};




#endif