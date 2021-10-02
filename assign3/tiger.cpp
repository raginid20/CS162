/******************************************************
** Program: tiger.cpp
** Author: Ragini Dindukurthi
** Date: 5/6/2021
** Description: Zoo Tycoon Game
** Input: N/A
** Output: game statements and information
******************************************************/


#include <iostream> 
#include <string> 
#include "tiger.h"

using namespace std; 

Tiger::Tiger(string stage = "adult"){
    if(stage == "adult"){
        setAnimal(48, 15000, 3, 5, 1500, 7500); 
    }
    else if(stage == "baby"){
        setAnimal(0, 15000, 3, 5, 3000, 15000);
    }
}

Tiger::Tiger(){
    setAnimal(0,0,0,0,0,0); 
}