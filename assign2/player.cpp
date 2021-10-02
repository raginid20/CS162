#include <iostream> 
#include <string> 
#include <cstdlib>
#include "player.h"

using namespace std; 

//need testing

Pile::Pile(Deck& stock){

    n_cards = 0;
    p[0] = stock.drawCard(); 
    n_cards++;
}

void Pile::addCard(Card match){

    p[n_cards] = match; 
    n_cards++;
}

void Pile::printTop(){ 

    cout << "Top Card: "; 
    p[n_cards - 1].printCard();  
}

Card Pile::getTop(){

    return p[n_cards - 1]; 
}

Hand::Hand(Deck& stock){

    n_cards = 7;
    cards = new Card[n_cards];
    for(int i = 0; i < n_cards; i++){
        cards[i] = stock.drawCard(); 
    }

}

int Hand::getRemainCards(){

    return n_cards; 
}

void Hand::printHand(Card& topCard){

    cout << "Possible Cards to Play (*)" <<endl; 
    for(int i = 0; i < n_cards; i++){
        cout << (i+1) << ": " ;
        if(cards[i].getIntRank() == topCard.getIntRank() || cards[i].getIntSuit() == topCard.getIntSuit() || cards[i].getIntRank() == 8){
            cout << "*"; 
        }
        cards[i].printCard(); 
    }
}

void Hand::printHand(){

    for(int i = 0; i < n_cards; i++){
        cout << (i+1) << ": " ;
        cards[i].printCard(); 
    }
}

Card Hand::selectCard(Card& topCard){

    int selection = 0; 
    printHand(topCard);
    cout << "Enter your selection: ";
    cin >> selection;
    Card choice = cards[selection - 1];
    playCard(selection - 1);
    return choice; 
}

int Hand::eight(Card choice){

    int eightSuit = 0; 

    if(choice.getIntRank() == 8){
        cout << "1: Diamonds" <<endl;
        cout << "2: Clubs" <<endl; 
        cout << "3: Hearts" <<endl; 
        cout << "4: Spades" <<endl; 
        cout << "Enter a suit (1-4) for wild card: ";
        cin >> eightSuit; 
        return eightSuit; 
    }
    else{
        return 0; 
    }
}


Hand::~Hand(){

    delete [] cards; 
    cards = nullptr; 
}

void Hand::addCard(Card& newCard){

    Card* temp = new Card[n_cards + 1];
    for(int i = 0; i < n_cards; i++){
        temp[i] = cards[i];
    }
    delete [] cards; 
    temp[n_cards] = newCard; 
    n_cards++;
    cards = temp;  

}

void Hand::draw(Deck& stock){
    
    Card newCard = stock.drawCard();
    if(newCard.getIntRank() != 0){
        addCard(newCard);
    }
}

Card Hand::matchCard(Card topCard, int eightSuit){//returns a playable card

    if(eightSuit != 0){
        for(int i = 0; i < n_cards; i++){

            if(cards[i].getIntSuit() == eightSuit || cards[i].getIntRank() == 8){ 
                return cards[i];
            }
        }
    }
    else{
        for(int i = 0; i < n_cards; i++){

            if(cards[i].getIntRank() == topCard.getIntRank() || cards[i].getIntSuit() == topCard.getIntSuit() || cards[i].getIntRank() == 8){ 
                return cards[i];
            }
        }
    }
}

void Hand::playCard(int selection){ 

    Card* temp = new Card[n_cards - 1];
    
    int x = 0; 
    for(int i = 0; i < n_cards; i++){
        if(i != selection){
            temp[x] = cards[i];
            x++; 
        }
    }
    delete [] cards;
    n_cards--;
    cards = temp;  
    
}

Hand::Hand(const Hand& oldHand){

    Card* temp = new Card[oldHand.n_cards];
    for(int i = 0; i < oldHand.n_cards; i++){
        temp[i] = oldHand.cards[i];
    }
    this->cards = temp;
    this->n_cards = oldHand.n_cards;  

}



int Hand::search(Card match){

    for(int i = 0; i < n_cards; i++){
        if(match.getIntRank() == cards[i].getIntRank() && match.getIntSuit() == cards[i].getIntSuit()){
            cout << "Computer plays: "; 
            cards[i].printCard(); 
            return i; 
        }
    }
}

Hand& Hand::operator=(const Hand& oldHand){

    this->n_cards = oldHand.n_cards;
    if(cards){
        delete [] cards;
    }
    cards = new Card[n_cards];
    for(int i = 0; i < this->n_cards; i++){
        this->cards[i] = oldHand.cards[i];
    }

    return *this; 

}

Hand::Hand(){

    cards = new Card[7]; 
    n_cards = 7; 
}

int Hand::handCheck(Card topCard, int eightSuit){
     
    if(n_cards == 0){
        return 0;//zero cards in the hand, means someone has won 
    }
    else if(eightSuit != 0){

        for(int i = 0; i < n_cards; i++){

            if(cards[i].getIntSuit() == eightSuit || cards[i].getIntRank() == 8){ 
                return 1;
            }
        }
        return 2;//no playable cards, need to draw from deck
    }
    else if(eightSuit == 0){

        for(int i = 0; i < n_cards; i++){
            if(cards[i].getIntRank() == topCard.getIntRank() || cards[i].getIntSuit() == topCard.getIntSuit() || cards[i].getIntRank() == 8){ 
                return 1;//there are playable cards 
            }
        }   
        return 2;//no playable cards, need to draw from deck 

    }
   
}

void Player::setPlayer(Deck& stock, string n){

    Hand temp(stock); 
    hand = temp; 
    name = n;
}

void Player::printPlayer(){

    cout << name <<endl; 
}


//over 20 lines due to print statements
int Player::turn(Deck& stock, Pile& pile){

    cout << "The deck has " << stock.getCardCount() << " cards." <<endl; 
    Card topCard = pile.getTop();
    int draw = hand.handCheck(topCard, 0);
    int eightSuit = 0; 

    cout << name << "'s Turn:" <<endl; 
    pile.printTop();


    if(draw == 1){
        Card choice = hand.selectCard(topCard);
        pile.addCard(choice);
        cout << "Your card is added to the pile." <<endl;
        eightSuit = hand.eight(choice);
        return eightSuit;
    }
    else if(draw == 2){
        hand.printHand(topCard); 
        cout << "You have no matching cards to play. Drawing cards from the deck..." <<endl; 
        while(hand.handCheck(topCard, 0) == 2 && stock.getCardCount() != 0){
            hand.draw(stock);
        }
        
        if(stock.getCardCount() == 0 && hand.handCheck(topCard, 0) == 2){
            return eightSuit; 
        }
        else{
            Card choice = hand.selectCard(topCard);
            pile.addCard(choice);
            cout << "Your card is added to the pile." <<endl;
            eightSuit = hand.eight(choice);
            return eightSuit;

        }
        
    }

}

int Player::check(Card topCard, int eightSuit){

    return hand.handCheck(topCard, eightSuit);

}

//over 20 lines due to print statements and logic flow
void Player::compTurn(Deck& stock, Pile& pile, int eightSuit){

    cout << "The deck has " << stock.getCardCount() << " cards." <<endl; 
    Card topCard = pile.getTop();
    int draw = hand.handCheck(topCard, eightSuit);

    cout << name << "'s Turn:" <<endl;
    pile.printTop();

    if(draw == 1){
        Card match = hand.matchCard(topCard, eightSuit); 
        int index = hand.search(match);
        hand.playCard(index);
        pile.addCard(match);
        
    }
    else if(draw == 2){ 
        cout << "Computer has no matching cards to play. Drawing cards from the deck..." <<endl;
        while(hand.handCheck(topCard, eightSuit) == 2 && stock.getCardCount() != 0){ 
            hand.draw(stock);

        }
         
        if(stock.getCardCount() != 0 || hand.handCheck(topCard, eightSuit) != 2){ 
            Card match = hand.matchCard(topCard, eightSuit); 
            int index = hand.search(match);
            hand.playCard(index);
            pile.addCard(match);

        }
        
    }

}

int Player::getCardCount(){

    return hand.getRemainCards();
}

string Player::getName(){
    
    return name; 
}

Game::Game(){

    string n; 

    cout << "Welcome to Crazy Eight!" <<endl;
    cout << "Note: Since 8s are wild, when the computer plays an 8, consider the suit to be the same as the suit of the 8 played." <<endl; 
    cout << "Enter your name: "; 
    cin >> n; 
    
    cards.shuffle();
    players[0].setPlayer(cards, n); 
    players[1].setPlayer(cards, "Computer");

    cout << "Player 1: "; 
    players[0].printPlayer();
    cout << "Player 2: "; 
    players[1].printPlayer();
}

int Game::endCheck(Pile& pile, int eightSuit){

    Card topCard = pile.getTop();

    int check0 = players[0].check(topCard, eightSuit);
    int check1 = players[1].check(topCard, eightSuit);
 
    if(check0 == 0 || check1 == 0){//hand has zero cards left
        if(check0 == 0)
            return 0; //Human is the winner
        else if(check1 == 0){
            return 1; //computer is winner
        }
    }
    else if(check0 == 2 && check1 == 2 && cards.getCardCount() == 0){ 
        
        cout << players[0].getName() << " has " << players[0].getCardCount() << " cards." <<endl; 
        cout << players[1].getName() << " has " << players[1].getCardCount() << " cards." <<endl; 
        if(players[0].getCardCount() < players[1].getCardCount()){

            return 2; //human is winner 
        }
        else if(players[0].getCardCount() == players[1].getCardCount()){

            return 5;// tie
        }
        else{
            
            return 3; //computer is winner 
        }
    }
    else{
        return 4; //no winner, continue loop 
    }

}

void Game::playGame(){

    Pile pile(cards);
    Card topCard = pile.getTop();
    int end = 4;
    int eightSuit = 0; 

    do{
        eightSuit = players[0].turn(cards, pile);
        end = endCheck(pile, eightSuit); 
        
        if(end != 4){
            break; 
        }
        players[1].compTurn(cards, pile, eightSuit); 
        end = endCheck(pile, eightSuit);

    }while(end == 4);

    winner(end);

}

void Game::winner(int end){

    if(end == 0){
        cout << players[0].getName() << " has zero cards in their hand!" <<endl; 
        cout << "Game Over: " << players[0].getName() << " wins!" <<endl; 
    }
    else if(end == 1){
        cout << players[1].getName() << " has zero cards in their hand!" <<endl; 
        cout << "Game Over: " << players[1].getName() << " wins!" <<endl; 
    }
    else if(end == 2){
        cout << "The deck has zero cards!" <<endl; 
        cout << "Game Over: " << players[0].getName() << " wins!" <<endl; 
    }
    else if(end == 3){
        cout << "The deck has zero cards!" <<endl; 
        cout << "Game Over: " << players[1].getName() << " wins!" <<endl; 
    }
    else if(end == 5){
        cout << "Game Over: Tie!" <<endl; 
    }
}



