/******************************************************
** Program: catalog.cpp
** Author: Ragini Dindukurthi
** Date: 4/9/2021
** Description: sorts spellbooks according to pages, 
** spell effects, spell success rate
** Input: spellbook txt file
** Output: file/print of sorted catalog of spellbooks
******************************************************/

#include <iostream> 
#include <string> 
#include <cstring> 
#include <fstream>
#include "catalog.h"

using namespace std; 

//hello

int main(int argc, char* argv[]){
    ifstream file;
    int end = 0; 
    int numSpellbooks = commandCheck(argc, argv);
    int totalSpells = 0;

    if (numSpellbooks < 0){
        return 1; 
    }
    spellbook* catalog = create_spellbooks(numSpellbooks);
    file.open(argv[1]); 
    get_spellbook_data(catalog, numSpellbooks, file);
    spell* spellArray = createSpellArray(catalog, numSpellbooks, totalSpells); 
    do{
        end = options(catalog, spellArray, totalSpells, numSpellbooks); 
    }while(end != 1); 
    delete_spellbook_data(catalog, numSpellbooks);
    delete [] spellArray;
    file.close(); 

    cout << "Goodbye!" <<endl; 

    return 0; 
    
}

