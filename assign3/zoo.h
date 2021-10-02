/******************************************************
** Program: zoo.h
** Author: Ragini Dindukurthi
** Date: 5/6/2021
** Description: Zoo Tycoon Game
** Input: N/A
** Output: game statements and information
******************************************************/

#ifndef ZOO_H
#define ZOO_H
#include <iostream> 
#include "animal.h"
#include "lemur.h"
#include "tiger.h"
#include "blackbear.h"

class Zoo{
    private:
        int numLemurs; 
        int numTigers; 
        int numBears;
        double bank;  
        double base; 
        Lemur* lemurs; 
        Tiger* tigers; 
        Blackbear* bears; 


    public: 
        Zoo();
        /**********************************************************
        ** Description: zoo constructor, sets pointers to null, initializes data members
        ** Pre-conditions: Zoo object is created
        ** Post-conditions: data members initialized
        **********************************************************/
        ~Zoo(); 
        /**********************************************************
        ** Description: zoo destructor 
        ** Pre-conditions: Zoo object is created
        ** Post-conditions: dynamic memory freed
        **********************************************************/
        void buyAnimal(); 
        /**********************************************************
        ** Description: executes purchasing of animals 
        ** Pre-conditions: zoo object is initialized
        ** Post-conditions: desired number of animals are added to appropriate array
        **********************************************************/
        void addLemur(std::string); 
        /**********************************************************
        ** Description: adds baby/adult lemur to array
        ** Pre-conditions: user buys a lemur or baby is born
        ** Post-conditions: numLemurs is updated
        **********************************************************/
        void addTiger(std::string); 
        /**********************************************************
        ** Description: adds baby/adult tiger to array
        ** Pre-conditions: user buys a tiger or baby is born
        ** Post-conditions: numTigers is updated
        **********************************************************/
        void addBear(std::string); 
        /**********************************************************
        ** Description: adds baby/adult bear to array
        ** Pre-conditions: user buys a bear or baby is born
        ** Post-conditions: numBears is updated
        **********************************************************/
        void printAnimals(); 
        /**********************************************************
        ** Description: prints lemurs, tigers, bears
        ** Pre-conditions: arrays are initialized
        ** Post-conditions: lemur, tiger, bears printed on screen
        **********************************************************/
        void printLemurs(); 
        /**********************************************************
        ** Description: prints lemurs
        ** Pre-conditions: arrays are initialized
        ** Post-conditions: lemur info is printed on screen
        **********************************************************/
        void printTigers(); 
        /**********************************************************
        ** Description: prints tigers
        ** Pre-conditions: arrays are initialized
        ** Post-conditions: tiger info is printed on screen
        **********************************************************/
        void printBears(); 
        /**********************************************************
        ** Description: prints bears
        ** Pre-conditions: arrays are initialized
        ** Post-conditions: bear info is printed on screen
        **********************************************************/
        void addBaby(std::string); 
        /**********************************************************
        ** Description: baby is added to appropriate array
        ** Pre-conditions: birth special event is chosen
        ** Post-conditions: baby animal is in array, numAnimals updated
        **********************************************************/
        int bankCheck(std::string, int); 
        /**********************************************************
        ** Description: error checking for buying animals
        ** Pre-conditions: user selects species
        ** Post-conditions: valid input is returned
        **********************************************************/
        void addAge(); 
        /**********************************************************
        ** Description: increments age of animals by 1 month
        ** Pre-conditions: game starts 
        ** Post-conditions: animals are 1 month older
        **********************************************************/
        int pickSpecies(); 
        /**********************************************************
        ** Description: generates a random number 0-2
        ** Pre-conditions: special event is chosen 
        ** Post-conditions: random number is returned
        **********************************************************/
        void sickAnimal(); 
        /**********************************************************
        ** Description: executes sick animal event
        ** Pre-conditions: sick animal event is chosen
        ** Post-conditions: animal dies or is saved
        **********************************************************/
        void sickLemur(); 
        /**********************************************************
        ** Description: executes sick lemur
        ** Pre-conditions: lemur is chosen
        ** Post-conditions: lemur dies/is saved, sick fee subtracted from bank
        **********************************************************/
        void removeLemur(int); 
        /**********************************************************
        ** Description: removes lemur from array
        ** Pre-conditions: lemur dies
        ** Post-conditions: array and numLemurs is updated
        **********************************************************/
        void sickTiger();
        /**********************************************************
        ** Description: executes sick tiger
        ** Pre-conditions: tiger is chosen
        ** Post-conditions: tiger dies/is saved, sick fee subtracted from bank
        **********************************************************/
        void removeTiger(int); 
        /**********************************************************
        ** Description: removes tiger from array
        ** Pre-conditions: tiger dies
        ** Post-conditions: array and numTigers is updated
        **********************************************************/
        void sickBear(); 
        /**********************************************************
        ** Description: executes sick bear
        ** Pre-conditions: bear is chosen
        ** Post-conditions: bear dies/is saved, sick fee subtracted from bank
        **********************************************************/
        void removeBear(int); 
        /**********************************************************
        ** Description: removes bear from array
        ** Pre-conditions: bear dies
        ** Post-conditions: array and numBears is updated
        **********************************************************/
        void birth(); 
        /**********************************************************
        ** Description: executes birth special event
        ** Pre-conditions: birth event is chosen
        ** Post-conditions: baby animal is born, numAnimals updated
        **********************************************************/
        int checkBirth(std::string);  
        /**********************************************************
        ** Description: checks conditions for birth event
        ** Pre-conditions: birth event is chosen
        ** Post-conditions: returns if birth event can occur or not
        **********************************************************/
        void calcRevenue(); 
        /**********************************************************
        ** Description: calculates revenue 
        ** Pre-conditions: zoo object is created
        ** Post-conditions: revenue is added to bank 
        **********************************************************/
        bool checkBank(); 
        /**********************************************************
        ** Description: checks if bankrupt or not
        ** Pre-conditions: zoo object is created and initialized
        ** Post-conditions: returns true or false
        **********************************************************/
        void calcFoodCost(int, int); 
        /**********************************************************
        ** Description: calculates food costs
        ** Pre-conditions: revenue is calculated
        ** Post-conditions: food costs is subtracted from bank 
        **********************************************************/
       void foodQualMult(double&, int); 
       /**********************************************************
        ** Description: calculates food costs based on feed quality chosen
        ** Pre-conditions: regular food cost is calculated
        ** Post-conditions: food costs is updated
        **********************************************************/
}; 

#endif