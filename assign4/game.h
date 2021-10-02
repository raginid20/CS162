/******************************************************
** Program: game.h
** Author: Ragini Dindukurthi
** Date: 5/20/21
** Description: Hunt the Wumpus Game
** Input: game functions
** Output: game statements and information
******************************************************/
#ifndef GAME_H
#define GAME_H

#include <iostream> 
#include <cstdlib> 
#include <vector>
#include "room.h"

class Game{
    private: 
        bool mode;// true for debug mode, false for normal mode
        int goldStatus;//= 0: gold not found, = 1: gold is found 
        int wumpusStatus; //= 1: wumpus is dead, = 0: wumpus alive
        int arrow; //number of arrows player has left
        int size; //size of one side of room 
        std::vector<std::vector<Room>> cave;//vector of rooms 
        std::vector<int> playerLoc = std::vector<int>(2, 0);//vector of player location 
        std::vector<int> wumpusLoc = std::vector<int>(2, 0); //vector of wumpus location
        std::vector<int> ropeLoc = std::vector<int>(2, 0); 
    public: 
        Game(int, bool); 
        /**********************************************************
        ** Description: Game constructor
        ** Pre-conditions: a game object is created, must pass in size and mode
        ** Post-conditions: game is created according to parameters given
        **********************************************************/
        void assign(); 
        /**********************************************************
        ** Description: assigns each room in the cave an event
        ** Pre-conditions: cave vector is initialized
        ** Post-conditions: cave's room are assigned correct # of events
        **********************************************************/
        void genIndex(int&, int&);
        /**********************************************************
        ** Description: generates row and col of an empty room in cave
        ** Pre-conditions: cave vector is initialized 
        ** Post-conditions: updates row and col thru ref
        **********************************************************/
        void printBoard();
        /**********************************************************
        ** Description: prints game board (based on mode)
        ** Pre-conditions: cave vector is initialized 
        ** Post-conditions: game board is printed on screen
        **********************************************************/
        void printNorm(); 
        /**********************************************************
        ** Description: prints board in normal mode
        ** Pre-conditions: cave vector is initialized 
        ** Post-conditions: board without locations of event is printed on screen
        **********************************************************/
        void printDebug();
        /**********************************************************
        ** Description: prints board in debug mode
        ** Pre-conditions: cave vector is initialized 
        ** Post-conditions: board with locations of event is printed on screen
        **********************************************************/
        void navigate();
        /**********************************************************
        ** Description: asks player if they want to move/shoot arrow
        ** Pre-conditions: cave vector is initialized 
        ** Post-conditions: player either moves or shoots arrow in desired direction
        **********************************************************/
        void move(std::string); 
        /**********************************************************
        ** Description: executes player moving in desired direction
        ** Pre-conditions: cave vector is initialized, board is printed on screen
        ** Post-conditions: player's marker moves on the board
        **********************************************************/
        void playPrecept(); 
        /**********************************************************
        ** Description: prints precepts of rooms arounds the player's location
        ** Pre-conditions: board is printed
        ** Post-conditions: precept is printed on screen
        **********************************************************/
        void event(); 
        /**********************************************************
        ** Description: executes event of the room that player is currently in
        ** Pre-conditions: precept is printed, player was allowed to move
        ** Post-conditions: event is complete
        **********************************************************/
        void fireArrow(std::string); 
        /**********************************************************
        ** Description: fires an arrow in desired direction
        ** Pre-conditions: board is printed
        ** Post-conditions: arrow either missed or killed wumpus
        **********************************************************/
        void checkArrow(int&); 
        /**********************************************************
        ** Description: make sure arrow is within bounds of board
        ** Pre-conditions: player decides to fire an arrow
        ** Post-conditions: updates location of arrow
        **********************************************************/
        void moveWumpus(); 
        /**********************************************************
        ** Description: moves wumpus to random empty room 
        ** Pre-conditions: arrow missed 
        ** Post-conditions: board is printed with wumpus' new location
        **********************************************************/
        void checkWumpus(int, int); 
        /**********************************************************
        ** Description: checks if arrow killed wumpus
        ** Pre-conditions: player shoots arrow
        ** Post-conditions: wumpus is either killed or not
        **********************************************************/
        void endCheck(); 
        /**********************************************************
        ** Description: checks ending conditions of game
        ** Pre-conditions: player played one turn
        ** Post-conditions: if end, throws exception, if not does nothing
        **********************************************************/
};

bool commandCheck(char**, int, bool&); 
/**********************************************************
** Description: converts command line arg into bool
** Pre-conditions: player provided correct number of command line args
** Post-conditions: valid bool mode is updated thru ref
**********************************************************/

#endif