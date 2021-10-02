/******************************************************
** Program: node.cpp
** Author: Ragini Dindukurthi
** Date: 6/2/21
** Description: creates a linked list, user can sort ascending or descending and
** finds number of prime numbers in the linked list
** Input: values for the nodes
** Output: sorted list, user info questions, number of prime numbers etc
******************************************************/

#include <iostream> 
#include <cstdlib> 
#include "node.h"

using namespace std; 

Node::Node(){

    val = 0; 
    next = nullptr; 
}

Node::~Node(){
    
    if(next != nullptr){
        delete next; 
    }
}