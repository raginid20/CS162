/******************************************************
** Program: pit.cpp
** Author: Ragini Dindukurthi
** Date: 5/20/21
** Description: Hunt the Wumpus Game
** Input: game functions
** Output: game statements and information
******************************************************/
#include <iostream> 
#include <cstdlib> 
#include <exception> 
#include <string>
#include "pit.h"

using namespace std; 

Pit::Pit(){
    precept = "You feel a breeze."; 
    letter = "P"; 
}

void Pit::encounter(){
    cout << "You unexpectedly fall to your death in a bottomless pit!" <<endl; 
    throw exception(); 
}