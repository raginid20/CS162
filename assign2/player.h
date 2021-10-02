/******************************************************
** Program: assign2_app
** Author: Ragini Dindukurthi
** Date: 4/24/2021
** Description: A Crazy Eights game 
** Input: N/A
** Output: game statements, card selections
******************************************************/

#ifndef PLAYER_H
#define PLAYER_H 

#include <iostream> 
#include <string> 
#include <cstdlib>
#include "deck.h"

class Pile{
  private:
    Card p[52];
    int n_cards; //tells how many cards are filled in the pile (index) can use right away/ gives next empty card space
  public: 
    Pile(Deck&);
  /**********************************************************
  ** Function: Pile
  ** Description: draws 1 card from the deck 
  ** Parameters: Deck& stock
  ** Pre-conditions: none
  ** Post-conditions: Pile is initialized
  **********************************************************/
    void addCard(Card); 
  /**********************************************************
  ** Function: addCard
  ** Description: adds a card to the pile
  ** Parameters: Card match
  ** Pre-conditions: one turn is completed
  ** Post-conditions: card is added to pile
  **********************************************************/
    void printTop();
  /**********************************************************
  ** Function: printTop
  ** Description: prints top card
  ** Parameters: none
  ** Pre-conditions: pile has been initialized
  ** Post-conditions: top card is printed to the screen
  **********************************************************/
    Card getTop();
  /**********************************************************
  ** Function: getTop
  ** Description: returns copy of the top card in pile
  ** Parameters: none
  ** Pre-conditions: pile has been initialized
  ** Post-conditions: top card is returned to function call
  **********************************************************/
};

class Hand {
  private:
    Card* cards;
    int n_cards;  // Number of cards in the hand. (-1 for array index value)
  public:
    Hand(Deck&);
  /**********************************************************
  ** Function: Hand (constructor)
  ** Description: draws 7 cards from the deck
  ** Parameters: Deck& stock
  ** Pre-conditions: deck has been initialized and shuffled
  ** Post-conditions: seven cards added to the hand
  **********************************************************/
    ~Hand();
  /**********************************************************
  ** Function: Hand (destructor)
  ** Description: returns copy of the top card in pile
  ** Parameters: none
  ** Pre-conditions: Hand object is created
  ** Post-conditions: dynamic memory is freed
  **********************************************************/
    Hand(const Hand&);
  /**********************************************************
  ** Function: Hand (copy constructor)
  ** Description: initializes new Hand objects
  ** Parameters: const Hand& oldHand
  ** Pre-conditions: Hand object is created
  ** Post-conditions: new hand object is initialized with old hand object values
  **********************************************************/
    Hand& operator=(const Hand&);
  /**********************************************************
  ** Function: assignment operator 
  ** Description: assigns hand values to existing hand object
  ** Parameters: const Hand& oldHand
  ** Pre-conditions: Hand object is created 
  ** Post-conditions: hand object is initialized with old hand object values
  **********************************************************/
    Hand();
  /**********************************************************
  ** Function: Hand (constructor)
  ** Description: allocates 7 for card array
  ** Parameters: none
  ** Pre-conditions: Hand object is created
  ** Post-conditions: card array is allocated 7 spaces 
  **********************************************************/
    int getRemainCards();
  /**********************************************************
  ** Function: getRemainCards
  ** Description: returns n_cards
  ** Parameters: none
  ** Pre-conditions: Hand object is initialized
  ** Post-conditions: n_cards is returned to function call
  **********************************************************/
    void addCard(Card&);
  /**********************************************************
  ** Function: addCard
  ** Description: adds a card to hand
  ** Parameters: Card newCard
  ** Pre-conditions: Hand object is created and initialized with deck
  ** Post-conditions: new card is added to hand
  **********************************************************/
    void playCard(int);
  /**********************************************************
  ** Function: playCard
  ** Description: removes a card from the hand
  ** Parameters: int selection
  ** Pre-conditions: player must have selected a card
  ** Post-conditions: old card is added to hand
  **********************************************************/
    void printHand(Card&);
  /**********************************************************
  ** Function: printHand
  ** Description: prints hand's cards to screen 
  ** Parameters: Card& topCard
  ** Pre-conditions: Hand object is initialized
  ** Post-conditions: hand cards are printed to screen 
  **********************************************************/
    void printHand();
  /**********************************************************
  ** Function: printHand
  ** Description: prints hand's cards to screen (without indicating playable cards)
  ** Parameters: Card& topCard
  ** Pre-conditions: Hand object is initialized
  ** Post-conditions: hand cards are printed to screen 
  **********************************************************/
    Card selectCard(Card&);
  /**********************************************************
  ** Function: selectCard
  ** Description: executes selecting a card process
  ** Parameters: Card& topCard
  ** Pre-conditions: turn function executed
  ** Post-conditions: user's selected card is returned
  **********************************************************/
    int handCheck(Card, int);
  /**********************************************************
  ** Function: handCheck
  ** Description: checks hand cards for playable cards, zero cards in hand 
  ** Parameters: Card& topCard, int eightSuit
  ** Pre-conditions: at least one turn executed
  ** Post-conditions: next turn or game end determined
  **********************************************************/
    void draw(Deck&);
  /**********************************************************
  ** Function: draw
  ** Description: draws cards from deck and puts them in the hand
  ** Parameters: Deck& stock
  ** Pre-conditions: hand is checked for ending game
  ** Post-conditions: hand contains one playable card
  **********************************************************/
    Card matchCard(Card, int);
  /**********************************************************
  ** Function: matchCard
  ** Description: returns playable card
  ** Parameters: Card topCard, int eightSuit
  ** Pre-conditions: human player's turn is completed
  ** Post-conditions: playable card is returned
  **********************************************************/
    int search(Card);
  /**********************************************************
  ** Function: search
  ** Description: searches for a card in the hand
  ** Parameters: Card match
  ** Pre-conditions: human player's turn is completed
  ** Post-conditions: playable card is returned
  **********************************************************/
    int eight(Card);
  /**********************************************************
  ** Function: eight 
  ** Description: asks for suit of the eighth card
  ** Parameters: Card choice
  ** Pre-conditions: player selects wild card
  ** Post-conditions: suit of wild card is returned
  **********************************************************/
};

class Player {
  private:
    Hand hand;
    std::string name;
  public:
    void setPlayer(Deck&, std::string);
  /**********************************************************
  ** Function: setPlayer
  ** Description: initializes player name and hand
  ** Parameters: Deck& stock, string n
  ** Pre-conditions: player object is created
  ** Post-conditions: player object is ready for game
  **********************************************************/
    int turn(Deck&, Pile&);
  /**********************************************************
  ** Function: turn
  ** Description: executes player's turn 
  ** Parameters: Deck& stock, Pile& pile
  ** Pre-conditions: player is initialized 
  ** Post-conditions: player's turn is executed 
  **********************************************************/
    void compTurn(Deck&, Pile&, int);
  /**********************************************************
  ** Function: compTurn
  ** Description: executes computer's turn 
  ** Parameters: Deck& stock, Pile& pile, int eightSuit
  ** Pre-conditions: player is initialized 
  ** Post-conditions: computer's turn is executed 
  **********************************************************/
    void printPlayer();
  /**********************************************************
  ** Function: printPlayer
  ** Description: prints player's information 
  ** Parameters: none
  ** Pre-conditions: player has to be initialized
  ** Post-conditions: player's info is printed to screen 
  **********************************************************/
    int check(Card, int);
  /**********************************************************
  ** Function: check
  ** Description: calls handCheck
  ** Parameters: Deck& stock, int eightSuit 
  ** Pre-conditions: a turn is executed 
  ** Post-conditions: player's end is checked
  **********************************************************/
    int getCardCount();
  /**********************************************************
  ** Function: getCardCount
  ** Description: returns n_cards 
  ** Parameters: none
  ** Pre-conditions: player is initialized 
  ** Post-conditions: n_cards is returned 
  **********************************************************/
    std::string getName();
  /**********************************************************
  ** Function: getName
  ** Description: returns name 
  ** Parameters: none
  ** Pre-conditions: player is initialized 
  ** Post-conditions: name is returned 
  **********************************************************/
};

class Game {
  private:
    Deck cards;
    Player players[2];
  public:
    Game();
  /**********************************************************
  ** Function: Game (constructor)
  ** Description: sets up the game, initializes players
  ** Parameters: none
  ** Pre-conditions: game is created 
  ** Post-conditions: game is set up 
  **********************************************************/
    int endCheck(Pile&, int);
  /**********************************************************
  ** Function: endCheck
  ** Description: game is checked for ending 
  ** Parameters: Card topCard, int playerNum, int eightSuit
  ** Pre-conditions: one turn is completed 
  ** Post-conditions: determination of game ending or not 
  **********************************************************/
    void playGame();
  /**********************************************************
  ** Function: playGame
  ** Description: game body 
  ** Parameters: none
  ** Pre-conditions: game is initialized and set up 
  ** Post-conditions: winner is known, one game is completed 
  **********************************************************/
    void winner(int);
  /**********************************************************
  ** Function: winner
  ** Description: prints winner/ending statements to the screen 
  ** Parameters: int playerNum 
  ** Pre-conditions: one game is completed  
  ** Post-conditions: winner is printed
  **********************************************************/
  };
#endif