/******************************************************
** Program: animal.h
** Author: Ragini Dindukurthi
** Date: 5/6/2021
** Description: Zoo Tycoon Game
** Input: N/A
** Output: game statements and information
******************************************************/

#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>


class Animal{
    protected: 
        int age; //measured in months   
        double cost; //initial cost of animal
        int babies; //number of babies species can have
        int foodMult; //foodCost*basecost = total food cost
        double revenue; //revenue ($) per month 
        double sickFee; //cost to pay if animal gets sick 
        
        

    public: 
        Animal();
        /**********************************************************
        ** Description: animal constructor, sets everything to 0
        ** Pre-conditions: Animal object is created w no arguments
        ** Post-conditions: default animal is created
        **********************************************************/
        void setAnimal(int, double, int, int, double, double); 
        /**********************************************************
        ** Description: initializes animal info (mutator) 
        ** Pre-conditions: Animal object is created
        ** Post-conditions: animal is initialized with correct values
        **********************************************************/
        void ageUp(); 
        /**********************************************************
        ** Description: increments age of animal by 1
        ** Pre-conditions: Animal object is created
        ** Post-conditions: animal is older by 1 month
        **********************************************************/
        int getAge() const; 
        /**********************************************************
        ** Description: returns animal age (accessor)
        ** Pre-conditions: Animal object is created
        ** Post-conditions: animal age is returned to function call
        **********************************************************/
        int getBabies() const;
        /**********************************************************
        ** Description: returns animal babies (accessor)
        ** Pre-conditions: Animal object is created
        ** Post-conditions: animal babies is returned to function call
        **********************************************************/
        double getCost() const; 
        /**********************************************************
        ** Description: returns animal cost (accessor)
        ** Pre-conditions: Animal object is created
        ** Post-conditions: animal cost is returned to function call
        **********************************************************/
        int checkAge(); 
        /**********************************************************
        ** Description: checks if animal is teen, adult, baby
        ** Pre-conditions: Animal object is created
        ** Post-conditions: returns 1, 2, 3
        **********************************************************/
        double getRevenue() const;  
        /**********************************************************
        ** Description: returns animal revenue (accessor)
        ** Pre-conditions: Animal object is created
        ** Post-conditions: animal revenue is returned to function call
        **********************************************************/
        int getFoodMult() const;
        /**********************************************************
        ** Description: returns animal food cost (accessor)
        ** Pre-conditions: Animal object is created
        ** Post-conditions: animal food cost is returned to function call
        **********************************************************/
        void updateRevenue();  
        /**********************************************************
        ** Description: updates revenue for baby animals when they become an adolescent
        ** Pre-conditions: Animal object is created
        ** Post-conditions: animal revenue is updated to adult
        **********************************************************/
        double getSickFee() const; 
        /**********************************************************
        ** Description: returns sick fee (accessor)
        ** Pre-conditions: Animal object is created
        ** Post-conditions: animal sick fee is returned to function call
        **********************************************************/
}; 

#endif