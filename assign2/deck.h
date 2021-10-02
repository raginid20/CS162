/******************************************************
** Program: assign2_app
** Author: Ragini Dindukurthi
** Date: 4/24/2021
** Description: A Crazy Eights game 
** Input: N/A
** Output: game statements, card selections
******************************************************/

#ifndef CARD_H
#define CARD_H 

#include <iostream> 
#include <string> 
#include <cstdlib>
#include <ctime> 

//1: Diamonds 
//2: Clubs 
//3: Hearts
//4: Spades

class Card{
  private:
    int rank;  // Should be in the range 1-13.
    int suit;  // Should be in the range 1-4.
  public:
    Card();
  /**********************************************************
  ** Function: Card (constructor)
  ** Description: initializes rank and suit with zero
  ** Parameters: none
  ** Pre-conditions: card object is created 
  ** Post-conditions: suit and rank = 0 
  **********************************************************/
    Card(const Card&);
  /**********************************************************
  ** Function: Card (copy constructor)
  ** Description: copies a card 
  ** Parameters: const Card& oldCard  
  ** Pre-conditions: new Card is created 
  ** Post-conditions: new card has all of old card's values  
  **********************************************************/
    void setCard(int, int);
  /**********************************************************
  ** Function: setCard 
  ** Description: initializes rank and suit with zero
  ** Parameters: suit, rank
  ** Pre-conditions: card object is created
  ** Post-conditions: suit and rank equal argument values 
  **********************************************************/
    std::string getSuit();
  /**********************************************************
  ** Function: getSuit
  ** Description: returns string version of suit 
  ** Parameters: none 
  ** Pre-conditions: suit and rank are intialized with non zero values 
  ** Post-conditions: returns string suit to function call
  **********************************************************/
    std::string getRank();
  /**********************************************************
  ** Function: getRank
  ** Description: returns string version of rank
  ** Parameters: none 
  ** Pre-conditions: suit and rank are intialized with non zero values 
  ** Post-conditions: returns string rank to function call
  **********************************************************/
    int getIntSuit();
  /**********************************************************
  ** Function: getIntSuit
  ** Description: returns int version of suit 
  ** Parameters: none 
  ** Pre-conditions: suit and rank are intialized with non zero values 
  ** Post-conditions: returns int suit to function call
  **********************************************************/
    int getIntRank();
  /**********************************************************
  ** Function: getIntRank
  ** Description: returns int version of rank
  ** Parameters: none 
  ** Pre-conditions: suit and rank are intialized with non zero values 
  ** Post-conditions: returns int rank to function call
  **********************************************************/
    void printCard();
  /**********************************************************
  ** Function: printCard
  ** Description: prints a card (ex. 5 of Diamonds)
  ** Parameters: none 
  ** Pre-conditions: suit and rank are intialized with non zero values 
  ** Post-conditions: card is printed to screen 
  **********************************************************/
};

class Deck{
  private:
    Card cards[52];
    int n_cards; 
      
  public:
    Deck();
  /**********************************************************
  ** Function: Deck (constructor)
  ** Description: initializes deck with standard 52 cards
  ** Parameters: none 
  ** Pre-conditions: deck object is created
  ** Post-conditions: card array is filled with standard 52 cards 
  **********************************************************/
    void createDeck(int, int, int);
  /**********************************************************
  ** Function: createDeck
  ** Description: for loop for constructing the deck and initializing the cards 
  ** Parameters: int a, int b, int suitType
  ** Pre-conditions: deck object is created
  ** Post-conditions: deck is initialized 
  **********************************************************/
    void printDeck();
  /**********************************************************
  ** Function: printDeck
  ** Description: prints deck 
  ** Parameters: none
  ** Pre-conditions: deck object is created
  ** Post-conditions: deck is printed to screen 
  **********************************************************/
    void shuffle();
  /**********************************************************
  ** Function: shuffle
  ** Description: shuffles cards in deck
  ** Parameters: none
  ** Pre-conditions: deck object is created
  ** Post-conditions: deck is randomly shuffled
  **********************************************************/
    Card drawCard();
  /**********************************************************
  ** Function: drawCard
  ** Description: returns a card on the top of the deck
  ** Parameters: none
  ** Pre-conditions: deck object is created
  ** Post-conditions: returns a card from the deck to the function call
  **********************************************************/
    Card getDeck();
  /**********************************************************
  ** Function: getDeck
  ** Description: returns card array 
  ** Parameters: none
  ** Pre-conditions: deck object is created
  ** Post-conditions: returns deck to the function call
  **********************************************************/
    int getCardCount();
  /**********************************************************
  ** Function: getCardCount
  ** Description: returns n_cards
  ** Parameters: none
  ** Pre-conditions: deck object is created and initialized 
  ** Post-conditions: returns n_cards to the function call
  **********************************************************/
};
#endif