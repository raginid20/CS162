#include <iostream> 
#include <exception> 
#include "event.h"
#include "bats.h"

using namespace std; 

Bats::Bats(){
    precept = "You hear wings flapping.";
    letter = "B"; 
}

void Bats::encounter(){
    cout << "Uh oh! These bats are super territorial about their real estate..." <<endl; 
    cout << "They grab you and drop you into another room!" <<endl; 
}