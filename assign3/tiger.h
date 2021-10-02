/******************************************************
** Program: tiger.h
** Author: Ragini Dindukurthi
** Date: 5/6/2021
** Description: Zoo Tycoon Game
** Input: N/A
** Output: game statements and information
******************************************************/

#ifndef TIGER_H
#define TIGER_H

#include <iostream> 
#include "animal.h"


class Tiger : public Animal{
    public:
    Tiger(std::string); 
    /**********************************************************
    ** Description: initializes tiger info 
    ** Pre-conditions: tiger object is created
    ** Post-conditions: tiger is ready for game
    **********************************************************/
    Tiger(); 
    /**********************************************************
    ** Description: default constructor 
    ** Pre-conditions: tiger object is created with no arguments
    ** Post-conditions: blank tiger is initialized
    **********************************************************/
        

}; 

#endif