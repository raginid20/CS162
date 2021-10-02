/******************************************************
** Program: wumpus.cpp
** Author: Ragini Dindukurthi
** Date: 5/20/21
** Description: Hunt the Wumpus Game
** Input: game functions
** Output: game statements and information
******************************************************/
#include <iostream> 
#include <cstdlib> 
#include <string>
#include "wumpus.h"

using namespace std; 

Wumpus::Wumpus(){
    precept = "You smell a terrible stench.";
    letter = "W"; 
}

void Wumpus::encounter(){
    cout << "Oh no! The Wumpus has gobbled you up because you interrupted his beauty sleep!" <<endl; 
    throw exception(); 
}