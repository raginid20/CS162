/******************************************************
** Program: blackbear.h
** Author: Ragini Dindukurthi
** Date: 5/6/2021
** Description: Zoo Tycoon Game
** Input: N/A
** Output: game statements and information
******************************************************/

#ifndef BLACKBEAR_H
#define BLACKBEAR_H

#include <iostream>
#include "animal.h" 

class Blackbear: public Animal{
    public:
        Blackbear(std::string);  
        /**********************************************************
        ** Description: initializes bear info 
        ** Pre-conditions: bear object is created
        ** Post-conditions: bear is ready for game
        **********************************************************/
        Blackbear(); 
        /**********************************************************
        ** Description: default constructor 
        ** Pre-conditions: bear object is created with no arguments
        ** Post-conditions: blank bear is initialized
        **********************************************************/
}; 

#endif