#include <iostream> 
#include "animal.h"

using namespace std; 

Animal::Animal(){
    age = 0; 
    cost = 0; 
    babies = 0; 
    foodMult = 0; 
    revenue = 0; 
}

void Animal::setAnimal(int age, double cost, int babies, int foodMult, double revenue, double sickFee){
    this->age = age;
    this->cost = cost;
    this->babies = babies;
    this->foodMult = foodMult;
    this->revenue = revenue;
    this->sickFee = sickFee; 
       
}

void Animal::ageUp(){
    age = age + 1; 
    updateRevenue(); 
}

int Animal::getAge() const{
    return age; 
}

int Animal::getBabies() const{
    return babies; 
}

double Animal::getCost() const{
    return cost; 
}

int Animal::checkAge(){
    if(age >= 48){
        return 1; //adult 
    }
    else if(age >= 5 && age < 48){
        return 2; //adolescent
    }
    else if(age < 5){
        return 3; //baby
    }
}

double Animal::getRevenue() const{
    return revenue; 
}

int Animal::getFoodMult() const{
    return foodMult; 
}

void Animal::updateRevenue(){
    if(age == 6){
        revenue = revenue/2; 
        sickFee = sickFee/2;
    }
}

double Animal::getSickFee() const{
    return sickFee; 
}

