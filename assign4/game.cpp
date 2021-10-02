/******************************************************
** Program: game.cpp
** Author: Ragini Dindukurthi
** Date: 5/20/21
** Description: Hunt the Wumpus Game
** Input: game functions
** Output: game statements and information
******************************************************/

#include <iostream> 
#include <cstdlib> 
#include <vector>
#include <cstring> 
#include <ctime> 
#include "game.h"
#include "room.h"
#include "bats.h"
#include "gold.h"
#include "pit.h"
#include "wumpus.h"
#include "rope.h"

using namespace std; 

Game::Game(int n, bool m){
    mode = m; 
    wumpusStatus = 0; 
    goldStatus = 0; 
    arrow = 3; 
    size = n; 
    cave.resize(size); 
    
    for(int i = 0; i < size; i++){
        vector<Room> row(size); 
        cave[i] = row; 
    }
}

void Game::assign(){ 
    int row = 0; 
    int col = 0; 

    Pit* pit1 = new Pit; 
    Pit* pit2 = new Pit; 

    genIndex(row, col); 
    cave[row][col].setEvent(pit1); 
   
    genIndex(row, col); 
    cave[row][col].setEvent(pit2);  

    Bats* bat1 = new Bats; 
    Bats* bat2 = new Bats;

    genIndex(row, col); 
    cave[row][col].setEvent(bat1); 

    genIndex(row, col); 
    cave[row][col].setEvent(bat2);

    Gold* gold = new Gold; 

    genIndex(row, col);
    cave[row][col].setEvent(gold); 
    
    Wumpus* wumpus = new Wumpus; 
    
    genIndex(row, col); 
    cave[row][col].setEvent(wumpus); 
    wumpusLoc[0] = row; 
    wumpusLoc[1] = col; 

    Rope* rope = new Rope; 

    genIndex(row, col); 
    cave[row][col].setEvent(rope); 
    playerLoc[0] = row; 
    playerLoc[1] = col; 

    ropeLoc[0] = row; 
    ropeLoc[1] = col; 
    

}

void Game::genIndex(int& row, int& col){
    do{
        row = rand() % size; 
        col = rand() % size; 
    }while(cave[row][col].getEvent() != nullptr); 
}

void Game::printBoard(){

    if(mode == false){
        printNorm(); 
    }
    else if(mode == true){
        printDebug(); 
    }
}

void Game::printDebug(){

    for(int x = 0; x < size; x++){
        for(int i = 0; i < size; i++){
            cout << "+---";
            if(i == size - 1){
                cout << "+" <<endl; 
            }
        }
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < size; k++){
                if(cave[x][k].getEvent() != nullptr && j == 0){
                    cout << "| " << cave[x][k].letter() << " "; 
                }
                else if(j == 1 && (playerLoc[0] == x && playerLoc[1] == k)){
                    cout << "| * "; 
                }
                else{
                    cout << "|   ";
                }
            }
            cout << "|" <<endl; 
        }
    }
    for(int i = 0; i < size; i++){
        cout << "+---";
        if(i == size - 1){
            cout << "+" <<endl; 
        }
    }
     
}

void Game::printNorm(){

    for(int x = 0; x < size; x++ ){
        for(int i = 0; i < size; i++){
            cout << "+---";
            if(i == size - 1){
                cout << "+" <<endl; 
            }
        }
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < size+1; k++){

                if(j == 1 && (playerLoc[0] == x && playerLoc[1] == k)){
                    cout << "| * "; 
                }
                else{
                    cout << "|   ";
                }

            }
            cout <<endl; 
        }
    }
    for(int i = 0; i < size; i++){
        cout << "+---";
        if(i == size - 1){
            cout << "+" <<endl; 
        }
    }

}

void Game::navigate(){

    string nav; 

    cout << endl; 
    playPrecept(); 
    cout << endl; 
    cout << "To Navigate: " <<endl; 
    cout << "Arrows: " << arrow <<endl; 
    cout << "Enter letter to move, or space then letter to shoot arrow" <<endl; 
    cout << "w: North" <<endl; 
    cout << "a: West" <<endl; 
    cout << "s: South" <<endl; 
    cout << "d: East" <<endl; 
    cout << "Selection: "; 
    getline(cin, nav); 
    
    if(nav[0] == 32){
        if(arrow == 0){
            cout << "Sorry, you have no more arrows to shoot!" <<endl;  
        }
        else{
            fireArrow(nav);
        }
    }
    else if(nav[0] != 32 ){
        move(nav); 
    }
    
}

void Game::move(string nav){

    if(nav == "w"){
        playerLoc[0] = playerLoc[0] - 1; 
    }
    else if(nav == "a"){
        playerLoc[1] = playerLoc[1] - 1;
    }
    else if(nav == "s"){
        playerLoc[0] = playerLoc[0] + 1; 
    }
    else if(nav == "d"){
        playerLoc[1] = playerLoc[1] + 1; 
    }
    printBoard(); 
    event(); 
        
}

void Game::playPrecept(){
   
    if(playerLoc[0] - 1 >= 0){ // if in 0 row 
        cave[playerLoc[0]-1][playerLoc[1]].printPrecept(); 
    }

    if(playerLoc[1] - 1 >= 0){ // if in 0 col
       
        cave[playerLoc[0]][playerLoc[1]-1].printPrecept(); 
    }

    if(playerLoc[0] + 1 <= size - 1){ // if in last row
        cave[playerLoc[0] + 1][playerLoc[1]].printPrecept(); 
    }

    if(playerLoc[1] + 1 <= size - 1){ //if in last col
        cave[playerLoc[0]][playerLoc[1]+1].printPrecept(); 
    }
    
}

void Game::event(){

    if(cave[playerLoc[0]][playerLoc[1]].getEvent() != nullptr){
        
        cave[playerLoc[0]][playerLoc[1]].playEvent(); 

        if(cave[playerLoc[0]][playerLoc[1]].letter() == "B"){
            playerLoc[0] = rand() % size; 
            playerLoc[1] = rand() % size; 
            cout << "New Location: " <<endl; 
            printBoard(); 
            event(); //play the event of the new location you end up 
        }
        else if(cave[playerLoc[0]][playerLoc[1]].letter() == "G"){
            cave[playerLoc[0]][playerLoc[1]].setEvent(nullptr); 
            goldStatus = 1; 
        }
    }
}

void Game::fireArrow(string nav){

    int row = playerLoc[0]; 
    int col = playerLoc[1]; 
    int temp = 0; 

    arrow--; 

    if(nav == " w"){// up
        temp = row - 3; 
        while(row > temp){
            row--; 
            checkWumpus(row, col); 
        }
        checkArrow(row); 
    }
    else if(nav == " a"){// left
        temp = col - 3; 
        while(col > temp){
            col--; 
            checkWumpus(row, col); 
        }
        checkArrow(col); 
    }
    else if(nav == " d"){// right
        temp = col + 3; 
        while(col < temp){
            col++; 
            checkWumpus(row, col); 
        }
        checkArrow(col); 
    }
    else if(nav == " s"){// down
        temp = row + 3; 
        while(row < temp){
            row++; 
            checkWumpus(row, col); 
        }
        checkArrow(row); 
    }
   
    if(wumpusStatus != 1){
        cout << "Arrow Location: " << row << " " << col <<endl; 
        cout << "No offense to your shooting skills, but your arrow missed!" <<endl; 
        moveWumpus();
    }
    printBoard(); 
         
}

void Game::checkArrow(int& num){
    if(num < 0){
        num = 0; 
    }
    else if(num > size - 1){
        num = size - 1; 
    }
}

void Game::moveWumpus(){

    int x = rand() % 100; 
    int row = 0; 
    int col = 0; 
    
    if(x <= 75){

        Wumpus* w = new Wumpus; 
        cout << endl; 
        cout << "Wumpus moved to a new location!" <<endl; 
        cout << "It's a surprisingly cautious creature..." <<endl; 
        cout << endl; 
        genIndex(row, col); 
        cave[wumpusLoc[0]][wumpusLoc[1]].setEvent(nullptr);
        cave[row][col].setEvent(w); 
        wumpusLoc[0] = row; 
        wumpusLoc[1] = col; 
    }
}

void Game::checkWumpus(int row, int col){

    if(wumpusLoc[0] == row && wumpusLoc[1] == col){
        cout << "Wumpus was killed by your arrow!" <<endl; 
        cave[wumpusLoc[0]][wumpusLoc[1]].setEvent(nullptr); 
        wumpusStatus = 1; 
    }

}

void Game::endCheck(){

    if((wumpusStatus == 1 && goldStatus == 1 && ropeLoc[0] == playerLoc[0] && ropeLoc[1] == playerLoc[1]) || 
        (goldStatus == 1 && ropeLoc[0] == playerLoc[0] && ropeLoc[1] == playerLoc[1])){
        cout << "You have made a smooth escape!" <<endl; 
        throw 0; 
    }
    
}

bool commandCheck(char** argv, int argc, bool& mode){

    if(strcmp(argv[2], "true") == 0){
        mode = true; 
    }
    else if(strcmp(argv[2], "false") == 0){
        mode = false; 
    }
    
}

