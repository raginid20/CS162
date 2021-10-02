/******************************************************
** Program: room.cpp
** Author: Ragini Dindukurthi
** Date: 5/20/21
** Description: Hunt the Wumpus Game
** Input: game functions
** Output: game statements and information
******************************************************/
#include <iostream> 
#include <string> 
#include "room.h"
#include "event.h"
#include "wumpus.h"
#include "gold.h"
#include "pit.h"
#include "rope.h"
#include "bats.h"

using namespace std; 

Room::Room(){
    event = nullptr; 
}

Room::~Room(){
    delete event; 
}

void Room::printPrecept(){
    if(event != nullptr){
        cout << event->getPrecept() <<endl; 
    }
}

void Room::printLetter(){
    cout << event->getLetter(); 
}

void Room::playEvent(){
    event->encounter(); 
}

string Room::letter(){
    return event->getLetter(); 
}

void Room::setEvent(Event* e){

    if(event != nullptr){
        delete event; 
    }
    event = e;
}

Event* Room::getEvent(){
    return event; 
}





