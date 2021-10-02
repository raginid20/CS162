/******************************************************
** Program: event.cpp
** Author: Ragini Dindukurthi
** Date: 5/20/21
** Description: Hunt the Wumpus Game
** Input: game functions
** Output: game statements and information
******************************************************/
#include <iostream> 
#include <string> 
#include "event.h"

using namespace std; 

Event::Event(){
    precept = "Your average empty room, nothing to see here!"; 
    letter = "0"; 
}

string Event::getPrecept() const{
    return precept; 
}

string Event::getLetter() const{
    return letter; 
}
