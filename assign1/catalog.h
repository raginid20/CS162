/******************************************************
** Program: catalog.cpp
** Author: Ragini Dindukurthi
** Date: 4/9/2021
** Description: sorts spellbooks according to pages, 
** spell effects, spell success rate
** Input: spellbook txt file
** Output: file/print of sorted catalog of spellbooks
******************************************************/

// Information used for C++ sort function was found here: https://www.geeksforgeeks.org/sort-c-stl/

#ifndef SPELLBOOK_H
#define SPELLBOOK_H

#include <iostream> 
#include <string>

using namespace std; 

struct spellbook {
  string title;
  string author;
  int num_pages;
  int edition;
  int num_spells;
  float avg_success_rate;
  struct spell* s;
};

struct spell {
  string name;
  float success_rate;
  string effect; 
};


spellbook* create_spellbooks(int);
/**********************************************************
 ** Function: create_spellbooks
 ** Description: creates dynamic array of struct spellbook   
 ** Parameters: numSpellbooks
 ** Pre-conditions: numSpellbooks is read in from txt file
 ** Post-conditions: dynamic array is returned to main
 **********************************************************/

void get_spellbook_data(spellbook*, int, ifstream &);
/**********************************************************
 ** Function: get_spellbook_data
 ** Description: reads spellbook data and populates 
 ** spellbook array with data
 ** Parameters: catalog, numSpellbooks, file
 ** Pre-conditions: numSpellbooks is read in from txt file
 ** Post-conditions: dynamic array is returned to main
 **********************************************************/

spell* create_spells(int);
/**********************************************************
 ** Function: create_spells
 ** Description: creates dynamic array of struct spell  
 ** Parameters: numSpells
 ** Pre-conditions: numSpells is read in from txt file
 ** Post-conditions: dynamic spell array is returned 
 **********************************************************/

void get_spell_data(spell*, int, ifstream &);
/**********************************************************
 ** Function: get_spell_data
 ** Description: reads spell data and populates 
 ** spell array with data
 ** Parameters: catalog, numSpellbooks, file
 ** Pre-conditions: numSpellbooks is read in from txt file
 ** Post-conditions: dynamic array is returned to main
 **********************************************************/

void delete_spellbook_data(spellbook*, int);
/**********************************************************
 ** Function: delete_spellbook_data
 ** Description: frees memory of spellbook array
 ** Parameters: catalog, numSpellbooks
 ** Pre-conditions: user selects quit
 ** Post-conditions: all memory allocated is freed 
 **********************************************************/

int commandCheck(int, char**);
/**********************************************************
 ** Function: commandCheck
 ** Description: checks command line for: two arguments, 
 ** existing file is provided
 ** Parameters: argc, argv
 ** Pre-conditions: program is executed 
 ** Post-conditions: numSpellbooks is returned 
 **********************************************************/

int options(spellbook*, spell*, int, int);
/**********************************************************
 ** Function: options
 ** Description: prints and executes sorting options
 ** Parameters: catalog, spellArray, numSpellbooks, totalSpells
 ** Pre-conditions: catalog has all spell info, 
 ** spellArray has copy of all spells
 ** Post-conditions: catalog is sorted
 **********************************************************/

void outputOptions(spellbook*, spell*, int, int, int); 
/**********************************************************
 ** Function: outputOptions
 ** Description: prints and executes output options
 ** Parameters: catalog, spellArray, numSpellbooks, totalSpells, selection
 ** Pre-conditions: user has selected sorting option
 ** Post-conditions: sorted catalog is printed/written to file
 **********************************************************/

void print(spellbook*, spell*, int, int, int);
/**********************************************************
 ** Function: print
 ** Description: prints sorted catalog to screen 
 ** Parameters: catalog, spellArray, numSpellbooks, totalSpells, selection 
 ** Pre-conditions: user selects option 1 for output
 ** Post-conditions: sorted catalog is printed to screen 
 **********************************************************/

void calcSuccessRate(spellbook*, int); 
/**********************************************************
 ** Function: calcSuccessRate
 ** Description: avg spell success rate is calculated, 
 ** assigned to spellbook array
 ** Parameters: catalog, numSpellbooks
 ** Pre-conditions: spellbook array is initialized
 ** Post-conditions: spellbook array is completely filled
 **********************************************************/

void fileOut(spellbook*, spell*, int, int, int);
/**********************************************************
 ** Function: fileOut
 ** Description: writes sorted catalog to desired file
 ** Parameters: catalog, spellArray, numSpellbooks, totalSpells, selection 
 ** Pre-conditions: selects option 2 for output, dest file is known
 ** Post-conditions: sorted catalog is written/appended to file
 **********************************************************/ 

string getFile(); 
/**********************************************************
 ** Function: getFile
 ** Description: gets destination file from user
 ** Parameters: none
 ** Pre-conditions: user selects option 2 for output
 ** Post-conditions: dest file is returned 
 **********************************************************/ 

void sortPages(spellbook*, int);
/**********************************************************
 ** Function: sortPages
 ** Description: sorts catalog by num of pages
 ** Parameters: catalog, numSpellbooks
 ** Pre-conditions: selects sort option 1 (by pages)
 ** Post-conditions: catalog is sorted by num of pages
 **********************************************************/ 

bool comparePages(spellbook, spellbook);
/**********************************************************
 ** Function: comparePages
 ** Description: custom sort function for C++ sort function
 ** Parameters: x, y
 ** Pre-conditions: selects sort option 1 (by pages)
 ** Post-conditions: returns if (x < y) is true/false
 **********************************************************/ 

void sortSuccessRate(spellbook*, int);
/**********************************************************
 ** Function: sortSuccessRate
 ** Description: sorts catalog by avg success rate
 ** Parameters: catalog, numSpellbooks
 ** Pre-conditions: selects sort option 3 (by success rate)
 ** Post-conditions: catalog is sorted by avg success rate
 **********************************************************/ 

bool compareSuccessRate(spellbook, spellbook);
/**********************************************************
 ** Function: compareSuccessRate
 ** Description: comparison sort function for C++ sort function
 ** Parameters: x, y
 ** Pre-conditions: selects sort option 3 (by success rate)
 ** Post-conditions: returns if (x > y) is true/false
 **********************************************************/ 

void sortSpells(spell*, int); 
/**********************************************************
 ** Function: sortSpells
 ** Description: sorts catalog by spell effect
 ** Parameters: catalog, numSpellbooks
 ** Pre-conditions: selects sort option 2 (by spell effect)
 ** Post-conditions: catalog is sorted by spell effect
 **********************************************************/ 

bool compareSpells(spell, spell);
/**********************************************************
 ** Function: compareSpells
 ** Description: comparison sort function for C++ sort function
 ** Parameters: x, y
 ** Pre-conditions: selects sort option 2 (by spell effect)
 ** Post-conditions: returns if (x > y) is true/false
 **********************************************************/ 

spell* createSpellArray(spellbook*, int, int&); 
/**********************************************************
 ** Function: createSpellArray
 ** Description: copies all spells from catalog into one array
 ** Parameters: catalog, numSpellbooks, totalSpells
 ** Pre-conditions: catalog has all info
 ** Post-conditions: returns spellArray
 **********************************************************/ 

void assign(spell, int&);
/**********************************************************
 ** Function: assign
 ** Description: additional sort function for compareSpells
 ** Parameters: comp, var
 ** Pre-conditions: user selects sort option 2 (by spell effect)
 ** Post-conditions: assigns comp variable an order
 **********************************************************/  

int printOptions();
/**********************************************************
 ** Function: printOptions
 ** Description: prints sorting options
 ** Parameters: none
 ** Pre-conditions: catalog has info
 ** Post-conditions: returns selection
 **********************************************************/  

int selectionCheck(string);
/**********************************************************
 ** Function: selectionCheck
 ** Description: error handling for sort selection
 ** Parameters: mssg
 ** Pre-conditions: catalog has info, spellArray created
 ** Post-conditions: returns valid input
 **********************************************************/  

int boolCheck(string); 
/**********************************************************
 ** Function: boolCheck
 ** Description: error handling for output selection
 ** Parameters: mssg
 ** Pre-conditions: catalog has info, spellArray created
 ** Post-conditions: returns valid input
 **********************************************************/  

#endif