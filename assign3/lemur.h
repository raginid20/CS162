/******************************************************
** Program: lemur.h
** Author: Ragini Dindukurthi
** Date: 5/6/2021
** Description: Zoo Tycoon Game
** Input: N/A
** Output: game statements and information
******************************************************/

#ifndef LEMUR_H
#define LEMUR_H

#include <iostream>
#include "animal.h" 


class Lemur: public Animal{
    public: 
    Lemur(std::string); 
    /**********************************************************
    ** Description: initializes lemur info 
    ** Pre-conditions: lemur object is created
    ** Post-conditions: lemur is ready for game
    **********************************************************/
    Lemur(); 
    /**********************************************************
    ** Description: default constructor 
    ** Pre-conditions: lemur object is created with no arguments
    ** Post-conditions: blank lemur is initialized
    **********************************************************/
}; 

#endif