/******************************************************
** Program: blackbear.cpp
** Author: Ragini Dindukurthi
** Date: 5/6/2021
** Description: Zoo Tycoon Game
** Input: N/A
** Output: game statements and information
******************************************************/

#include <iostream> 
#include <string> 
#include "blackbear.h"

using namespace std; 

Blackbear::Blackbear(string stage = "adult"){
    if(stage == "adult"){// consider changing to char A= adult B= baby
        setAnimal(48, 6000, 2, 3, 600, 3000); 
    }
    else if(stage == "baby"){
        setAnimal(0, 6000, 2, 3, 1200, 6000);
    }
}

Blackbear::Blackbear(){
    setAnimal(0,0,0,0,0,0); 
}

