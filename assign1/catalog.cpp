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
#include <fstream> 
#include <stdlib.h> 
#include <algorithm> 
#include "catalog.h"

using namespace std; 

spellbook* create_spellbooks(int numSpellbooks){
    spellbook* catalog = new spellbook[numSpellbooks]; 
    return catalog; 
}

void delete_spellbook_data(spellbook* catalog, int numSpellbooks){
    for(int i = 0; i < numSpellbooks; i++){
        delete [] catalog[i].s; 
        catalog[i].s = NULL; 
    }
    
    delete [] catalog;
    catalog = NULL;  
}


spell* create_spells(int numSpells){
    spell* spellCatalog = new spell[numSpells]; 
    return spellCatalog; 
}

void get_spell_data(spell* spellCatalog, int numSpells, ifstream &file){

    string temp; 

        for(int i = 0; i < numSpells; i++){
            getline(file, spellCatalog[i].name, ' ');
            getline(file, temp, ' '); 
            spellCatalog[i].success_rate = stof(temp);
            getline(file, spellCatalog[i].effect, '\n');
        }
    
}

int commandCheck(int argc, char** argv){
    ifstream file;
    int numSpellbooks = 0; 

    if(argc != 2){ //checking if file is provided
        cout << "Error! No file provided. Please run program with file." <<endl; 
        return -1; 
    }
    else{
        file.open(argv[1]); 
        if(!file.is_open()){//checking if file exists and we are able to open it
            cout << "Error! Unable to open file. Exiting program." <<endl; 
            return -1; 
        }
        else{
            cout << "Processing file..." <<endl; 
            file >> numSpellbooks; //getting number of spellbooks in file
            file.close(); 
            return numSpellbooks; 
        }
        
    }

}

void get_spellbook_data(spellbook* catalog, int numSpellbooks, ifstream &file){
    
    string temp;
    file >> numSpellbooks; 
    getline(file, temp, '\n');
    
    for(int i = 0; i < numSpellbooks; i++){
        getline(file, catalog[i].title, ' ');
        getline(file, catalog[i].author, ' '); 
        getline(file, temp, ' ');
        catalog[i].num_pages = stoi(temp); 
        getline(file, temp, ' ');
        catalog[i].edition = stoi(temp); 
        getline(file, temp, '\n');
        catalog[i].num_spells = stoi(temp);
        catalog[i].s = create_spells(catalog[i].num_spells);
        get_spell_data(catalog[i].s, catalog[i].num_spells, file);
    }

    calcSuccessRate(catalog, numSpellbooks); 
}

void calcSuccessRate(spellbook* catalog, int numSpellbooks){
    double total = 0;  

     for(int i = 0; i < numSpellbooks; i++){
        for(int j = 0; j < catalog[i].num_spells; j++){
            total = total + catalog[i].s[j].success_rate;
        }
        catalog[i].avg_success_rate = total/catalog[i].num_spells; //calculating avg success rate
        total = 0; 
    }

}

int options(spellbook* catalog, spell* spellArray, int totalSpells, int numSpellbooks){

    int selection = printOptions(); 

    if(selection == 1){//executing specific sort function
        sortPages(catalog, numSpellbooks); 
    } 
    else if(selection == 2){
        sortSpells(spellArray, totalSpells);
    }
    else if(selection == 3){
        sortSuccessRate(catalog, numSpellbooks); 
    }
    else if(selection == 4){
        return 1; 
    }

    outputOptions(catalog, spellArray, numSpellbooks, totalSpells, selection);  

}

void outputOptions(spellbook* catalog, spell* spellArray, int numSpellbooks, int totalSpells, int selection){

    cout << "Print to screen (Press 1)" <<endl; 
    cout << "Print to file (Press 2)" <<endl; 

    int choice = boolCheck("your selection"); 

    if(choice == 1){
        print(catalog, spellArray, numSpellbooks, selection, totalSpells); 
    } 
    else if(choice == 2){
        fileOut(catalog, spellArray, numSpellbooks, selection, totalSpells); 
    }

}

void print(spellbook* catalog, spell* spellArray, int numSpellbooks, int selection, int totalSpells){

    for(int i = 0; i < numSpellbooks; i++){//printing information to screen based on user's selection 
        if(selection == 1){
            cout << catalog[i].title << " " <<  catalog[i].num_pages <<endl; 
        }
        else if(selection == 3){
            cout << catalog[i].title << " " << catalog[i].avg_success_rate <<endl;
        }
    }
    if(selection == 2){
        for(int j = 0; j < totalSpells; j++){
            cout << spellArray[j].effect << " "; 
            cout << spellArray[j].name <<endl; 
        }
    }
}

string getFile(){

    string fileName; //getting a filename from the user
    cout << "Enter a filename (.txt): ";
    cin >> fileName; 
    cin.clear(); 
    cin.ignore(10000, '\n'); 
    return fileName; 

}

void fileOut(spellbook* catalog, spell* spellArray, int numSpellbooks, int selection, int totalSpells){

    ofstream fout; 
    string fileName = getFile(); //getting the file name from user 
    fout.open(fileName, ios:: out | ios:: app); 

    for(int i = 0; i < numSpellbooks; i++){//writing/appending to file based on user's selection 
        if(selection == 1){
            fout << catalog[i].title << " " << catalog[i].num_pages <<endl; 
        }
        else if(selection == 3){
            fout << catalog[i].title << " " << catalog[i].avg_success_rate <<endl; 
        }
    }
    if(selection == 2){
        for(int j = 0; j < totalSpells; j++){
            fout << spellArray[j].effect << " "; 
            fout << spellArray[j].name <<endl;  
        }
    }

    cout << "Information appended to file." <<endl;
    fout.close(); 
}

void sortPages(spellbook* catalog, int numSpellbooks){
    sort(catalog, catalog + numSpellbooks, comparePages); 
}

bool comparePages(spellbook x, spellbook y){
    return (x.num_pages < y.num_pages); 
}

void sortSuccessRate(spellbook* catalog, int numSpellbooks){
    sort(catalog, catalog + numSpellbooks, compareSuccessRate);
}

bool compareSuccessRate(spellbook x, spellbook y){
    return (x.avg_success_rate > y.avg_success_rate); 
}

void sortSpells(spell* catalog, int numSpells){
    sort(catalog, catalog + numSpells, compareSpells); 
}

bool compareSpells(spell x, spell y){
    int a = 0; 
    int b = 0; 

    assign(x, a); 
    assign(y, b); 

    return (a < b); 
}

spell* createSpellArray(spellbook* catalog, int numSpellbooks, int& totalSpells){
    totalSpells = 0;
    int x = 0;

    for(int i = 0; i < numSpellbooks; i++){
        totalSpells = totalSpells + catalog[i].num_spells; //counting total number of spells
    }
    spell* spellArray = new spell[totalSpells];//creating dynamic spell array

    for(int j = 0; j < numSpellbooks; j++){// copy spells into array
        for(int k = 0; k < catalog[j].num_spells; k++){
            spellArray[x] = catalog[j].s[k];
            x++; 
        }
    }
    return spellArray; 

}

void assign(spell comp, int& var){

    if(comp.effect == "bubble"){//assigning order to two spells being compared
        var = 1; 
    }
    else if(comp.effect == "memory_loss"){
        var = 2; 
    }
    else if(comp.effect == "fire"){
        var = 3; 
    }
    else if(comp.effect == "poison"){
        var = 4; 
    }
    else if(comp.effect == "death"){
        var = 5; 
    }

}

int printOptions(){
   

    cout << "Which option would you like to choose?" <<endl; 
    cout << "Sort spellbooks by number of pages (Press 1)" <<endl; 
    cout << "Group spells by their effect (Press 2)" <<endl; //causing seg fault 
    cout << "Sort spellbooks by average success rate (Press 3)" <<endl; 
    cout << "Quit (Press 4)" <<endl; 
    int selection = selectionCheck("your selection"); 
    
    return selection; 

}

int selectionCheck(string mssg){
    bool valid = false;
    string input;
    do{
        cout << "Enter " << mssg << ": "; 
        getline(cin, input); 

        if(input.length() > 1){ //the valid input should be 1 character
            valid = false;
        }
        else if(!(input[0] == '1' || input[0] == '2' || input[0] == '3' || input[0] == '4' )){  
            valid = false;
        }
        else{
            valid = true;
        }
    }while(valid == false);
    return atoi(input.c_str());
}

int boolCheck(string mssg){
    bool valid = false;
    string input;
    do{
        cout << "Enter " << mssg << ": "; 
        getline(cin, input); 

        if(input.length() > 1){ //the valid input should be 1 character
            valid = false;
        }
        else if(!(input[0] == '1' || input[0] == '2')){  
            valid = false;
        }
        else{
            valid = true;
        }
        
    }while(valid == false);

    return atoi(input.c_str());
}