/******************************************************
** Program: game.cpp
** Author: Ragini Dindukurthi
** Date: 5/6/2021
** Description: Zoo Tycoon Game
** Input: N/A
** Output: game statements and information
******************************************************/

#include <iostream> 
#include <ctime> 
#include <cstdlib> 
#include "game.h"

using namespace std; 

Game::Game(){
    month = 1; 
    cout << "Welcome to Zoo Tycoon!" <<endl; 
}

int Game::foodChoice(int &first, int &second){

    int choice = 0; 

    cout << "Food Quality" <<endl; 
    cout <<endl; 
    cout << "1: Cheap" <<endl; 
    cout << "2: Regular" <<endl; 
    cout << "3: Premium" <<endl; 
    cout << "Enter your selection: ";  
    cin >> choice; 

    if(choice == 1){
        first = 59; 
        second = 74; 
    }
    else if(choice == 2){
        first = 29; 
        second = 59; 
    }
    else if(choice == 3){
        first = 14; 
        second = 52; 
    }
    return choice; 

}

void Game::specialEvent(int first, int second){

    int event = rand() % 90; 

    if(event <= first){
        myZoo.sickAnimal(); 
    }
    else if(event > first && event <= second){
        myZoo.birth(); 
    }
    else if(event > second){
        cout << "Nothing exciting happening: no special event this month!" <<endl; 
        cout <<endl; 
    }

}

void Game::playGame(){
    
    int end = 0; 
    int first = 0; 
    int second = 0; 

    int foodType = foodChoice(first, second); 
    do{
        cout << "**********" <<endl; 
        cout << "Month " << month <<endl; 
        cout << "**********" <<endl; 
        myZoo.addAge(); 
        myZoo.printAnimals(); 
        specialEvent(first, second); 
        if(myZoo.checkBank() == false){
            cout << "Game Over: Yikes, you ran out of money!" <<endl; 
            break; 
        }
        myZoo.calcRevenue();
        myZoo.buyAnimal(); 
        if(myZoo.checkBank() == false){
            cout << "Game Over: Yikes, you ran out of money!" <<endl; 
            break; 
        }
        myZoo.calcFoodCost(month, foodType); 
        month++; 
        
        if(myZoo.checkBank() == false){
            cout << "Game Over: Yikes, you ran out of money!" <<endl; 
            break; 
        }
        end = quit(); 

    }while(end == 0); 
    cout << "Goodbye!" <<endl; 

}

int Game::quit(){
    int quit = 0; 
    cout << "Quit? (1:Yes, 0:No): "; 
    cin >> quit; 
    return quit; 
}

