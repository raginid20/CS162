/******************************************************
** Program: lemur.cpp
** Author: Ragini Dindukurthi
** Date: 5/6/2021
** Description: Zoo Tycoon Game
** Input: N/A
** Output: game statements and information
******************************************************/

#include <iostream> 
#include <string> 
#include "lemur.h"

using namespace std; 

Lemur::Lemur(string stage){
    if(stage == "adult"){
        setAnimal(48, 700, 1, 1, 140, 350); 
    }
    else if(stage == "baby"){
        setAnimal(0, 700, 1, 1, 280, 700);
    }
}


Lemur::Lemur(){
    setAnimal(0,0,0,0,0,0); 
}