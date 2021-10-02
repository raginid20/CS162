/******************************************************
** Program: node.h
** Author: Ragini Dindukurthi
** Date: 6/2/21
** Description: creates a linked list, user can sort ascending or descending and
** finds number of prime numbers in the linked list
** Input: values for the nodes
** Output: sorted list, user info questions, number of prime numbers etc
******************************************************/

#ifndef NODE_H
#define NODE_H

#include <iostream> 
#include <cstdlib> 

class Node {
    public:
        int val;    // the value that this node stores
        Node *next; // a pointer to the next node in the list
        Node();
        /**********************************************************
        ** Description: node constructor
        ** Pre-conditions: node object is created
        ** Post-conditions: node object is constructed
        **********************************************************/
        ~Node(); 
        /**********************************************************
        ** Description: node destructor
        ** Pre-conditions: node object is created
        ** Post-conditions: dynamic memory is freed
        **********************************************************/

}; 

#endif