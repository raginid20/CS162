/******************************************************
** Program: gold.cpp
** Author: Ragini Dindukurthi
** Date: 5/20/21
** Description: Hunt the Wumpus Game
** Input: game functions
** Output: game statements and information
******************************************************/
#include <iostream> 
#include <cstdlib> 
#include <exception> 
#include "gold.h"

using namespace std; 

Gold::Gold(){
    precept = "You see a glimmer nearby."; 
    letter = "G"; 
}

void Gold::encounter(){
    cout << "WOW! You have found the gold!! It’s 14K." <<endl; 
}