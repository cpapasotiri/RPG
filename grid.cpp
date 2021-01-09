#include <iostream>
#include <cstring>
#include <vector> 

#include "living.hpp"

using namespace std;

Grid::Grid(){
    cout << "A New Grid has been created!" << endl;
}

Grid::~Grid(){
    cout << "A Grid to be destroyed!" << endl;
}

void Grid::displayMap(){
    cout << "A Grid to be destroyed!" << endl;
}


Square::Square(int t){
    cout << "A New Square has been created!" << endl;
    type = t;
}

Square::~Square(){
    cout << "A Square to be destroyed!" << endl;
}

int Square::getType()const{
    return type;
}


NonAccessible::NonAccessible()
: Square(0){
    cout << "A New NonAccessible has been created!" << endl;
}

NonAccessible::~NonAccessible(){
    cout << "A NonAccessible to be destroyed!" << endl;
}

void NonAccessible::print()const{
    cout << "A Non Accessible square!" << endl;
}


Market::Market(vector<Weapon*> w, vector<Armor*> a, vector<Potion*> p, vector<Spell*> s)
: Square(1){
    cout << "A New Market has been created!" << endl;
    weapons = w;
    armors = a;
    potions = p;
    spells = s;
    team = NULL;
}

Market::~Market(){
    cout << "A Market to be destroyed!" << endl;
    weapons.clear();
    armors.clear();
    potions.clear();
    spells.clear();
}

void Market::print(){
    cout << "A Market square!" << endl;
    cout << "To select an item, please give the number that corresponding to this object." << endl;
    printMenu();
}

void Market::printMenu(){
    // πρεπει να προσθεσω και πως θα διαλεγει για ποιο μελος της ομαδας επιλεγει καθε φορα
    int item = 0;
    cout << endl <<"Weapons are: " << endl;
    vector <Weapon*> :: iterator w;
    for (w = weapons.begin(); w != weapons.end(); w++) {
        item++;
        cout << "Press " << item << " to select: ";
        (*w)->Print();
    }
    cout << "To select an item a weapon, please give his number" << endl;
    int select = 0;
    while(select > 0){
        cin >> select;
        if(select > 0){     // αν εχει επιλεξει καποιο αντικειμενο πρεπει να ελεγξω αν μπορει να το αγορασει ή πρεπει να μου πει αν θελει να το πουλησω κλπ
            
        }
    }
     
    
    item = 0;
    cout << endl << "Armors are: " << endl;
    vector <Armor*> :: iterator a;
    for (a = armors.begin(); a != armors.end(); a++) {
        item++;
        cout << "Press " << item << " to select: ";
        (*a)->Print();
    }
    item = 0;
    cout << endl << "Potions are: " << endl;
    vector <Potion*> :: iterator p;
    for (p = potions.begin(); p != potions.end(); p++) {
        item++;
        cout << "Press " << item << " to select: ";
        (*p)->Print();
    }
    item = 0;
    cout << endl << "Spells are: " << endl;
    vector <Spell*> :: iterator s;
    for (s = spells.begin(); s != spells.end(); s++) {
        item++;
        cout << "Press " << item << " to select: ";
        (*s)->Print();
    }
}

void Market::enterTeam(Team* t){
    team = t;
}

void Market::exitTeam(){
    team = NULL;
}

vector<Weapon*> Market::getWeapons()const{
    return weapons;
}

vector<Armor*> Market::getArmors()const{
    return armors;
}

vector<Potion*> Market::getPotions()const{
    return potions;
}

vector<Spell*> Market::getSpells()const{
    return spells;
}

Team* Market::getTeam()const{
    return team;
}


Common::Common()
: Square(2){
    cout << "A New Common has been created!" << endl;
}

Common::~Common(){
    cout << "A Common to be destroyed!" << endl;
}

void Common::print()const{
    cout << "A Common square!" << endl;
    if(team != NULL){
        team->print();
    }
}

void Common::enterTeam(Team* t){
    team = t;
}

void Common::exitTeam(){
    team = NULL;
}

Team* Common::getTeam()const{
    return team;
}