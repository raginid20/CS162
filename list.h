/******************************************************
** Program: list.h
** Author: Ragini Dindukurthi
** Date: 6/2/21
** Description: creates a linked list, user can sort ascending or descending and
** finds number of prime numbers in the linked list
** Input: values for the nodes
** Output: sorted list, user info questions, number of prime numbers etc
******************************************************/

#ifndef LIST_H
#define LIST_H

#include <iostream> 
#include <cstdlib> 
#include "node.h"

class Linked_List {
    private:
        unsigned int length; // the number of nodes in the list
        Node *head; // a pointer to the first node in the list
    public:
        int get_length();
        /**********************************************************
        ** Description: returns length of linked list (number of nodes)
        ** Pre-conditions: a linked list object is created
        ** Post-conditions: returns length to function call
        **********************************************************/
        void print(); 
        /**********************************************************
        ** Description: prints a list of the values of each node in the list in order
        ** Pre-conditions: a linked list object is created
        ** Post-conditions: list is printed to screen
        **********************************************************/
        void clear(); 
        /**********************************************************
        ** Description: delete the entire list (remove all nodes and reset length to 0)
        ** Pre-conditions: at least one node is in the list
        ** Post-conditions: list is cleared, memory is freed, length is reset
        **********************************************************/
        unsigned int push_front(int); 
        /**********************************************************
        ** Description: insert a new value at the front of the list (returns the new length of the list)
        ** Pre-conditions: a linked list object is created
        ** Post-conditions: node with given int is added to the front of the list (new head)
        **********************************************************/
        unsigned int push_back(int); 
        /**********************************************************
        ** Description: insert a new value at the back of the list (returns the new length of the list)
        ** Pre-conditions: a linked list object is created
        ** Post-conditions: node with given int is added to the back of the list (last node)
        **********************************************************/
        unsigned int insert(int val, unsigned int index); 
        /**********************************************************
        ** Description: insert a new value in the list at the specified index (returns the new length of the list))
        ** Pre-conditions: a linked list object is created
        ** Post-conditions: new node is inserted at desired index with specified value
        **********************************************************/
        void sort_ascending(); 
        /**********************************************************
        ** Description: sorts list in ascending order, using merge sort
        ** Pre-conditions: linked list contains more than 1 node
        ** Post-conditions: linked list is sorted in ascending order
        **********************************************************/
        void sort_descending();
        /**********************************************************
        ** Description: sorts list in descending order, using merge sort
        ** Pre-conditions: linked list contains more than 1 node
        ** Post-conditions: linked list is sorted in descending order
        **********************************************************/
        Linked_List(); 
        /**********************************************************
        ** Description: constructor, sets head to null, length to zero
        ** Pre-conditions: linked list object is created
        ** Post-conditions: linked list is constructed
        **********************************************************/
        Node* find(unsigned int); 
        /**********************************************************
        ** Description: finds a node at the specified index, and then returns a pointer to the node
        ** Pre-conditions: must call insert function
        ** Post-conditions: pointer to node at specified index is returned
        **********************************************************/
        void prime(); 
        /**********************************************************
        ** Description: counts number of prime numbers in list
        ** Pre-conditions: linked list contains at least one node
        ** Post-conditions: number of prime numbers is printed to screen
        **********************************************************/
        void printSplit(Node*);
        /**********************************************************
        ** Description: prints the values of nodes connected to the node* passed in (used for testing merge sort)
        ** Pre-conditions: linked list object is created
        ** Post-conditions: list is printed to screen
        **********************************************************/
        void mergeSort(Node*&, int); 
        /**********************************************************
        ** Description: sorts list using merge sort in specified order (ascending or descending)
        ** Pre-conditions: list contains more than one node 
        ** Post-conditions: list is sorted
        **********************************************************/
        int getSplitLength(Node*); 
        /**********************************************************
        ** Description: counts the number of nodes in the linked list (head is passed in)
        ** Pre-conditions: merge sort function is called
        ** Post-conditions: number of nodes is returned to function call
        **********************************************************/
        Node* merge(Node*, Node*, int); 
        /**********************************************************
        ** Description: sorts the nodes and connects them together
        ** Pre-conditions: nodes are split into 1
        ** Post-conditions: head of sorted list is returned to function call
        **********************************************************/
        void turn(); 
        /**********************************************************
        ** Description: user application function
        ** Pre-conditions: linked list object is created
        ** Post-conditions: user did not want to continue 
        **********************************************************/
        void addNode(); 
        /**********************************************************
        ** Description: adds nodes of user-specified values to the linked list
        ** Pre-conditions: user wanted to keep adding nodes
        ** Post-conditions: user did not want to continue adding nodes 
        **********************************************************/
        ~Linked_List();
        /**********************************************************
        ** Description: destructor 
        ** Pre-conditions: linked list object is out of scope, clear function hasn't been called
        ** Post-conditions: dynamic memory is freed, length reset to 0
        **********************************************************/
};

#endif