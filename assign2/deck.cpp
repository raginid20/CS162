#include <iostream> 
#include <string> 
#include <cstdlib>
#include <ctime>
#include "deck.h"

using namespace std; 

void Card::setCard(int s, int r){

    suit = s; 
    rank = r; 
}

Card::Card(){

    suit = 0; 
    rank = 0;
}

string Card::getSuit(){

    if(suit == 1){
        return " of Diamonds"; 
    }
    else if(suit == 2){
        return " of Clubs"; 
    }
    else if(suit == 3){
        return " of Hearts"; 
    }
    else if(suit == 4){
        return " of Spades"; 
    }
}

string Card::getRank(){

    if(rank >= 2 && rank <= 10){
        return to_string(rank);
    }
    else if(rank == 1){
        return "Ace"; 
    }
    else if(rank == 11){
        return "Jack";
    }
    else if(rank == 12){
        return "Queen";
    }
    else if(rank == 13){
        return "King"; 
    }
}

void Card::printCard(){

    cout << getRank() << getSuit() <<endl; 
}

Card::Card(const Card& oldCard){
    
    this->suit = oldCard.suit; 
    this->rank = oldCard.rank; 
}

int Card::getIntSuit(){

    return suit; 
}

int Card:: getIntRank(){

    return rank; 
}

Deck::Deck(){

    n_cards = 52; 
    createDeck(0, 13, 1);
    createDeck(13, 26, 2);
    createDeck(26, 39, 3); 
    createDeck(39, 52, 4);
}

void Deck::createDeck(int a, int b, int suitType){

    int rankNum = 1; 
    for(int i = a; i < b; i++){
        cards[i].setCard(suitType, rankNum);
        rankNum++; 
    }

}

void Deck::printDeck(){

    for(int i = 0; i < n_cards; i++){
        cards[i].printCard(); 
    }
}

void Deck::shuffle(){

    srand(time(0));
    int a = 0;
    int b = 0;
    Card temp;

    for(int i = 0; i < 55; i++){  
        do{
            a = rand() % 52; 
            b = rand() % 52; 
        }while(a == b); 

        temp = cards[a]; 
        cards[a] = cards[b]; 
        cards[b] = temp;  
    }

}

Card Deck::drawCard(){ 
    
    if(n_cards > 0){
        Card newCard = cards[n_cards - 1];
        cards[n_cards - 1].setCard(0, 0);
        n_cards--; 
        return newCard; 
    }
    else{
        Card newCard;
        return newCard; 
    }
      
}

int Deck::getCardCount(){
    return n_cards; 
}