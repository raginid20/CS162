/******************************************************
** Program: list.cpp
** Author: Ragini Dindukurthi
** Date: 6/2/21
** Description: creates a linked list, user can sort ascending or descending and
** finds number of prime numbers in the linked list
** Input: values for the nodes
** Output: sorted list, user info questions, number of prime numbers etc
******************************************************/

#include <iostream> 
#include <cstdlib> 
#include "list.h"

using namespace std; 

Linked_List::Linked_List(){

    length = 0; 
    head = nullptr; 
}

int Linked_List::get_length(){

    return length; 
}

void Linked_List::print(){

    Node* temp = head; 

    while(temp != nullptr){
        cout << temp->val << " "; 
        temp = temp->next; 
    }
    cout <<endl;
}

void Linked_List::printSplit(Node* h){

    Node* temp = h; 

    while(temp != nullptr){
        cout << temp->val << " "; 
        temp = temp->next; 
    }
    cout <<endl;
}

unsigned int Linked_List::push_front(int newVal){

    Node* n = new Node; 

    n->val = newVal; 
    n->next = head; 
    head = n; 

    return ++length; 
}

 unsigned int Linked_List::push_back(int newVal){

    Node* newNode = new Node; 
    newNode->val = newVal;

    if(head == nullptr){
        head = newNode; 
    }
    else{
        Node* temp = head; 

        while(temp->next != nullptr){
            temp = temp->next; 
        }
        
        temp->next = newNode; 
    }

    return ++length; 
}

unsigned int Linked_List::insert(int val, unsigned int index){

    Node* newNode = new Node; //creating a new node
    newNode->val = val; 

    if(head == nullptr){ // if empty linked list
      head = newNode; 

    }
    else if(index == 0){ // if want to insert in 0 index 
        newNode->next = head; 
        head = newNode; 
    }
    else{
        Node* prev = find(index-1); //finding the previous node to the position i want to insert 
        newNode->next = prev->next; //setting it to the next node's pointer (same as previous node currently)
        prev->next = newNode; //prev's next pointer is now equal to the new node
    }

    return ++length; 
    
}

Node* Linked_List::find(unsigned int index){

    int counter = 0; 
    Node* current = head; 

    while(counter < index){
        current = current->next; 
        counter++; 
    }

    return current; 
}

void Linked_List::prime(){

    int counter = 0; 
    bool p = true; 
    Node* temp = head; 
    
       
    while(temp != nullptr){
        p = true; 
        for(int j = 2; j <= (temp->val)/2; j++){
            if(temp->val % j == 0){
                p = false; 
                break; 
            }
        }
        if(p == true && temp->val > 0 && temp->val != 1){ //0, 1 and negative numbers are not prime numbers
            counter++; 
        }

        temp = temp->next; 
    }

    cout << "You have " << counter << " prime number(s) in your list." <<endl; 
}


void Linked_List::sort_ascending(){

    mergeSort(head, 1); 
}

void Linked_List::sort_descending(){

    mergeSort(head, 2); 
}

//https://gist.github.com/hnguyen091188/efa43431593f2370007e (used for merge function)
//https://www.geeksforgeeks.org/merge-sort-for-linked-list/ (used for mergesort)
//these sites were used as references to create the mergesort and merge functions 
void Linked_List::mergeSort(Node*& start, int order){

    Node* first = start; //these nodes will be equal to the head during the first call
    Node* second = start; 
    Node* middle = start; 
    int len = getSplitLength(start); //this function will return the number of nodes in the list using the head

    if(start == nullptr || start->next == nullptr){
        return; // BASE CASE: list of 0 or 1 node(s) is already sorted, so we just return to the function call
    }

    for(int i = 0; i < len/2; i++){ // using this to find the middle node of the linked list
        middle = second; 
        second = second->next; 
    }
    middle->next = nullptr; //by setting to null, we are effectively splitting the list

    mergeSort(first, order); //splitting the first half, through recursion
    mergeSort(second, order);//splitting the second half, through recursion

    start = merge(first, second, order);// this function will sort the nodes, and connect the sorted nodes together
    head = start;// after sorting, we set our head to the first node of our sorted list
}


int Linked_List::getSplitLength(Node* start){

    Node* temp = start; 
    int count = 0; 

    while(temp != nullptr){
        count++; 
        temp = temp->next; 
    }
    
    return count; 
}

Node* Linked_List::merge(Node* first, Node* second, int order){ // order = 1: ascending, order = 2: descending

    Node* temp = nullptr; //temporary head

    if (first == nullptr){ //BASE CASE: we return the other node (the one that's not null)
        return second;
    }
    else if (second == nullptr){
        return first;
    }

    if(order == 1){// sort ascending order
        
        if(first->val < second->val){ //comparing values, the val of the first node is smaller than val of second node
            temp = first;// then we set the smaller node as the temporary head
            temp->next = merge(first->next, second, order);//connecting the smaller node to the bigger node through recursion
        }
        else{// if val of first node is bigger, then we set the second node (smaller node) as the temp head
            temp = second; 
            temp->next = merge(first, second->next, order); 
        }
    }
    else if(order == 2){// sort descending order, same as ascending except with > 

        if(first->val > second->val){
            temp = first; 
            temp->next = merge(first->next, second, order); 
        }
        else{
            temp = second; 
            temp->next = merge(first, second->next, order); 
        }

    }

    return temp; //return our temporary head of our sorted linked list
}

void Linked_List::clear(){

    if(head != nullptr){
        delete head; 
        head = nullptr; 
    }

    length = 0; 

}

Linked_List::~Linked_List(){

    if(head != nullptr || length > 0){
        clear(); 
    }
}

void Linked_List::turn(){

    string input; 
    int end = 0; 

    while(end == 0){

        addNode(); 
        cout << "Sort Ascending or Descending? (a/d): "; 
        cin >> input; 

        if(input == "a"){
            sort_ascending(); 
        }
        else if(input == "d"){
            sort_descending(); 
        }

        cout << "Sorted List: "; 
        print(); 
        prime(); 

        cout << "Play again? (y/n): "; 
        cin >> input; 
        clear(); 

        if(input == "n"){
            break; 
        }
        
    }
    cout << "Goodbye!" <<endl; 

}

void Linked_List::addNode(){

    int check = 0; 
    int num = 0; 
    string input; 

    while(check == 0){
        
        cout << "Enter a number: "; 
        cin >> num; 
        push_back(num);

        cout << "Do you want another number? (y/n): "; 
        cin >> input; 

        if(input == "n"){
            break; 
        }

    }
}