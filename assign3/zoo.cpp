/******************************************************
** Program: zoo.cpp
** Author: Ragini Dindukurthi
** Date: 5/6/2021
** Description: Zoo Tycoon Game
** Input: N/A
** Output: game statements and information
******************************************************/

#include <iostream> 
#include <cstdlib> 
#include <ctime> 
#include "zoo.h"


using namespace std; 

Zoo::Zoo(){

    numLemurs = 0; 
    numTigers = 0; 
    numBears = 0;
    bank = 100000; 
    base = 80;  
    lemurs = nullptr; 
    tigers = nullptr; 
    bears = nullptr; 
}

Zoo::~Zoo(){

    delete [] lemurs; 
    delete [] tigers; 
    delete [] bears; 

    lemurs = NULL; 
    tigers = NULL; 
    bears = NULL; 
}

//this function is over 20 lines due to print statements 
void Zoo::buyAnimal(){

    int species = 0; 
    int count = 0; 
    cout <<endl; 
    cout << "Purchasing Animals" <<endl; 
    cout <<endl; 
    cout << "You may purchase up to two adult animals of one species." <<endl; 
    cout << "Enter 0, if you do not have enough money to buy the animal." <<endl;  
    cout << "Select the species you want to buy." <<endl; 
    cout << endl; 
    cout << "1: Lemur" <<endl; 
    cout << "2: Tiger" <<endl;
    cout << "3: Blackbear" <<endl;
    cout << "4: No Purchase" <<endl; 
    cout << "Enter your selection: "; 

    cin >> species; 
    
    if(species == 1){

        Lemur lemur("adult"); 
        count = bankCheck("lemurs", lemur.getCost());

        for(int i = 0; i < count; i++){
            addLemur("adult");
            
        }
        bank = bank - (count*lemur.getCost()); 
    }
    else if(species == 2){

        Tiger tiger("adult"); 
        count = bankCheck("tigers", tiger.getCost());

        for(int i = 0; i < count; i++){
            addTiger("adult"); 
        }
        bank = bank - (count*tiger.getCost()); 
    }
    else if(species == 3){

        Blackbear bear("adult"); 
        count = bankCheck("bears", bear.getCost());
    
        for(int i = 0; i < count; i++){
            addBear("adult"); 
        }
        bank = bank - (count*bear.getCost()); 
    }

}

int Zoo::bankCheck(string mssg, int cost){

    bool valid = 0;
    string input;
   
    do{
        cout << "Enter the number of " << mssg << " you want to buy (0, 1, 2): "; 
        cin >> input;
        if(stoi(input) != 0 && stoi(input) != 1 && stoi(input) != 2){
           valid = false;
           cout << "Error! You can only buy 0, 1, or 2 animals." <<endl; 
        }
        else{
            valid = true; 
        }

    }while(valid == false);
    return stoi(input.c_str());
}



void Zoo::addLemur(string stage){
    
    Lemur newLemur(stage); 
    Lemur* temp = new Lemur[numLemurs + 1];

    for(int i = 0; i < numLemurs; i++){
        temp[i] = lemurs[i];
    }
    
    delete [] lemurs; 

    temp[numLemurs] = newLemur; 

    lemurs = temp; 
    numLemurs++; 

}

void Zoo::addTiger(string stage){

    Tiger newTiger(stage); 
    Tiger* temp = new Tiger[numTigers + 1];

    for(int i = 0; i < numTigers; i++){
        temp[i] = tigers[i]; 
    }
    
    delete [] tigers; 

    temp[numTigers] = newTiger; 

    tigers = temp; 
    numTigers++; 
    
}

void Zoo::addBear(string stage){

    Blackbear newBear(stage); 
    Blackbear* temp = new Blackbear[numBears + 1];

    for(int i = 0; i < numBears; i++){
        temp[i] = bears[i];
    }
    
    delete [] bears; 

    temp[numBears] = newBear; 

    bears = temp; 
    numBears++; 
    
}

void Zoo::addBaby(string species){

    Lemur lemur("adult"); 
    Blackbear bear("adult"); 
    Tiger tiger("adult"); 

    if(species == "lemur"){

        for(int i = 0; i < lemur.getBabies(); i++){
            addLemur("baby"); 
        }
    }
    else if(species == "bear"){

        for(int i = 0; i < bear.getBabies(); i++){
            addBear("baby"); 
        }
    }
    else if(species == "tiger"){

        for(int i = 0; i < tiger.getBabies(); i++){
            addTiger("baby"); 
        }
    }
}

void Zoo::printAnimals(){

    cout << "Bank($): " << bank <<endl; 
    printLemurs(); 
    printTigers(); 
    printBears(); 

}

void Zoo::printLemurs(){

    int numAdult = 0; 
    int numBaby = 0; 
    int numAdol = 0; 

    cout << "Lemurs" <<endl; 
    for(int i = 0; i < numLemurs; i++){
        if(lemurs[i].checkAge() == 1){
            numAdult++; 
        }
        else if(lemurs[i].checkAge() == 2){
            numAdol++; 
        } 
        else if(lemurs[i].checkAge() == 3){
            numBaby++; 
        }
    }

    cout << "Babies: " << numBaby <<endl; 
    cout << "Adolescents: " << numAdol <<endl; 
    cout << "Adults: " << numAdult <<endl; 
    cout <<endl; 

}

void Zoo::printTigers(){

    int numAdult = 0; 
    int numBaby = 0; 
    int numAdol = 0; 

    cout << "Tigers" <<endl; 
    for(int i = 0; i < numTigers; i++){
        if(tigers[i].checkAge() == 1){
            numAdult++; 
        }
        else if(tigers[i].checkAge() == 2){
            numAdol++; 
        } 
        else if(tigers[i].checkAge() == 3){
            numBaby++; 
        }
    }

    cout << "Babies: " << numBaby <<endl; 
    cout << "Adolescents: " << numAdol <<endl; 
    cout << "Adults: " << numAdult <<endl; 
    cout <<endl; 

}

void Zoo::printBears(){

    int numAdult = 0; 
    int numBaby = 0; 
    int numAdol = 0; 

    cout << "Bears" <<endl; 
    for(int i = 0; i < numBears; i++){
        if(bears[i].checkAge() == 1){
            numAdult++; 
        }
        else if(bears[i].checkAge() == 2){
            numAdol++; 
        } 
        else if(bears[i].checkAge() == 3){
            numBaby++; 
        }
    }

    cout << "Babies: " << numBaby <<endl; 
    cout << "Adolescents: " << numAdol <<endl; 
    cout << "Adults: " << numAdult <<endl; 
    cout <<endl; 

}

void Zoo::addAge(){

    for(int i = 0; i < numLemurs; i++){
        lemurs[i].ageUp(); 
    }

    for(int i = 0; i < numTigers; i++){
        tigers[i].ageUp(); 
    }

    for(int i = 0; i < numBears; i++){
        bears[i].ageUp(); 
    }
}

int Zoo::pickSpecies(){

    return rand() % 3; 
}

void Zoo::sickAnimal(){
    
    int selection = pickSpecies(); 

    cout << endl; 
    cout << "Special Event: Sick Animal" <<endl; 
    cout << endl; 

    if(selection == 0){
        if(numLemurs == 0){
            cout << "Unfortunately, lemurs were selected and you don't have any lemurs!" <<endl; 
            cout << "You can't participate in this event. Event will be skipped this month." <<endl; 
        }
        else{
            sickLemur(); 
        }
    }
    else if(selection == 1){
        if(numTigers == 0){
            cout << "Unfortunately, tigers were selected and you currently do not have any tigers to get sick!" <<endl; 
            cout << "You can't participate in this event. Event will be skipped this month." <<endl; 
        }
        else{
           sickTiger(); 
        }
    }
    else if(selection == 2){
        if(numBears == 0){
            cout << "Unfortunately, bears were selected and you currently do not have any bears to get sick!" <<endl; 
            cout << "You can't participate in this event. Event will be skipped this month." <<endl; 
        }
        else{
            sickBear(); 
        }

    }
    
}

void Zoo::sickLemur(){

    int index = 0; 

    if(numLemurs != 1){
       index = rand() % numLemurs;
    }
    
    double sickFee = lemurs[index].getSickFee(); 

    cout << "One of your lemurs is sick! She has insomnia :(" <<endl; 
    cout << "You must pay $" << sickFee << " to save her!" <<endl;  
    cout <<endl; 

    if(bank >= sickFee){
        bank = bank - sickFee; 
        cout << "You now have $" << bank << " in your bank." <<endl; 
        cout << "Medicine worked fast...the lemur has recovered!" <<endl; 
    }
    else{
        cout << "American Healthcare is expensive, you don't have enough money to take care of the sick lemur!" <<endl; 
        cout << "Unfortunately, the lemur has died :(" <<endl; 
        removeLemur(index); 
    }
}

void Zoo::removeLemur(int index){

    int x = 0; 
    Lemur* temp = new Lemur[numLemurs - 1]; 
    

    for(int i = 0; i < numLemurs; i++){
        if(i != index){
            temp[x] = lemurs[i]; 
            x++; 
        }
    }
    delete [] lemurs; 

    lemurs = temp; 
    numLemurs--; 
}

void Zoo::sickTiger(){

    int index = 0; 

    if(numTigers != 1){
       index = rand() % numTigers;
    }
    
    double sickFee = tigers[index].getSickFee(); 

    cout << "One of your tigers is sick! He has mild indigestion :(" <<endl; 
    cout << "You must pay $" << sickFee << " to save him!" <<endl;  
    cout <<endl; 

    if(bank >= sickFee){
        bank = bank - sickFee; 
        cout << "You now have $" << bank << " in your bank." <<endl; 
        cout << "Medicine worked fast...The tiger has recovered!" <<endl; 
    }
    else{
        cout << "American Healthcare is expensive, you don't have enough money to take care of the sick tiger!" <<endl; 
        cout << "Unfortunately, the tiger has died :(" <<endl; 
        removeTiger(index); 
    }

}

void Zoo::removeTiger(int index){

    int x = 0; 
    Tiger* temp = new Tiger[numTigers - 1]; 
    

    for(int i = 0; i < numTigers; i++){
        if(i != index){
            temp[x] = tigers[i]; 
            x++; 
        }
    }
    delete [] tigers; 

    tigers = temp; 
    numTigers--; 
}

void Zoo::sickBear(){

    int index = 0; 

    if(numBears != 1){
       index = rand() % numBears;
    }
    
    double sickFee = bears[index].getSickFee(); 
    
    cout << "One of your bears is sick! She has food poisoning :(" <<endl; 
    cout << "You must pay $" << sickFee << " to save her!" <<endl;  
    cout <<endl; 

    if(bank >= sickFee){
        bank = bank - sickFee; 
        cout << "You now have $" << bank << " in your bank." <<endl; 
        cout << "Medicine worked fast...The bear has recovered!" <<endl; 
    }
    else{
        cout << "American Healthcare is expensive, you don't have enough money to take care of the sick bear!" <<endl; 
        cout << "Unfortunately, the bear has died :(" <<endl; 
        removeBear(index); 
    }

}

void Zoo::removeBear(int index){

    int x = 0; 
    Blackbear* temp = new Blackbear[numBears - 1]; 
    

    for(int i = 0; i < numBears; i++){
        if(i != index){
            temp[x] = bears[i]; 
            x++; 
        }
    }
    delete [] bears; 

    bears = temp; 
    numBears--; 
}

void Zoo::birth(){

    int selection = pickSpecies();  
    cout << "Special Event: Birth!!" <<endl; 
    cout <<endl; 

    if(selection == 0){
        if(numLemurs < 2 && checkBirth("lemur") < 2){
            cout << "Unfortunately, you don't have enough lemurs to participate in this event!" <<endl; 
            cout << "Event will be skipped this month." <<endl; 
        }
        else{
            cout << "One of your lemurs had a surprise pregnancy! She gave birth to one baby lemur." <<endl; 
            addBaby("lemur"); 
        }
    }
    else if(selection == 1){
        if(numTigers < 2 && checkBirth("tiger") < 2){
            cout << "Unfortunately, you don't have enough tigers to participate in this event!" <<endl; 
            cout << "Event will be skipped this month." <<endl; 
        }
        else{
            cout << "One of your tigers had a surprise (but happy) pregnancy! She had triplets!" <<endl; 
            addBaby("tiger"); 
        }
    }
    else if(selection == 2){
        if(numBears < 2 && checkBirth("bear") < 2){
            cout << "Unfortunately, you don't have enough bears to participate in this event!" <<endl; 
            cout << "Event will be skipped this month." <<endl; 
        }
        else{
            cout << "One of your bears had a surprise (but happy) pregnancy! She had twins!" <<endl; 
            addBaby("bear"); 
        }
    }

}

int Zoo::checkBirth(string species){
    int check = 0; 

    if(species == "lemur"){
        for(int i = 0; i < numLemurs; i++){
            if(lemurs[i].checkAge() == 1){
                check++; 
            }
        }
    }
    else if(species == "tiger"){
        for(int i = 0; i < numTigers; i++){
            if(tigers[i].checkAge() == 1){
                check++; 
            }
        }
    }
    else if(species == "bear"){
        for(int i = 0; i < numBears; i++){
            if(bears[i].checkAge() == 1){
                check++; 
            }
        }
    }

    return check; 
        
}

void Zoo::calcRevenue(){

    double revenue = 0; 

    for(int i = 0; i < numLemurs; i++){
        revenue = revenue + lemurs[i].getRevenue(); 
    }
    for(int i = 0; i < numTigers; i++){
        revenue = revenue + tigers[i].getRevenue(); 
    }
    for(int i = 0; i < numBears; i++){
        revenue = revenue + bears[i].getRevenue(); 
    }

    cout <<endl; 
    cout <<"Revenue Earned ($): " << revenue <<endl;  
    bank = bank + revenue; 
    cout << "Bank ($): " << bank <<endl; 

}

bool Zoo::checkBank(){

    if(bank <= 0){
        return false; 
    }
    else{
        return true; 
    }
}

void Zoo::calcFoodCost(int month, int foodChoice){

    float mult = 1; 
    double foodCost = 0; 
    cout <<endl; 
    cout << "Food Costs" <<endl; 
    cout <<endl; 

    if(month > 1){
        mult = ((rand() % 41) + 80);   
        foodCost = 0; 
        base = base * (mult/100.00); 
    }

    for(int i = 0; i < numLemurs; i++){
        foodCost = foodCost + (base * lemurs[i].getFoodMult()); 
    }
    for(int i = 0; i < numTigers; i++){
        foodCost = foodCost + (base * tigers[i].getFoodMult()); 
    }
    for(int i = 0; i < numBears; i++){
        foodCost = foodCost + (base * bears[i].getFoodMult()); 
    }

    foodQualMult(foodCost, foodChoice); 

    cout << "Base Food Cost: " << base <<endl; 
    cout << "Your total food cost is $" << foodCost <<endl; 
    bank = bank - foodCost; 
    cout << "Bank ($): " << bank <<endl;  
}

void Zoo::foodQualMult(double& foodCost, int foodChoice){

    if(foodChoice == 1){
        foodCost = foodCost/2.00; 
    }
    else if(foodChoice == 3){
        foodCost = foodCost*2.00; 
    }

}
