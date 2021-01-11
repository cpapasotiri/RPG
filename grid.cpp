#include <iostream>
#include <cstring>
#include <vector> 

#include "living.hpp"

using namespace std;

Grid::Grid(vector<Hero*> h, vector<Monster*> m, vector<Weapon*> w, vector<Armor*> a, vector<Potion*> p, vector<Spell*> s){
    cout << "A New Grid has been created!" << endl;
    heroes = h;
    monsters = m;
    weapons = w;
    armors = a;
    potions = p;
    spells = s;
}

Grid::~Grid(){
    cout << "A Grid to be destroyed!" << endl;
    heroes.clear();
    monsters.clear();
    weapons.clear();
    armors.clear();
    potions.clear();
    spells.clear(); 
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


Market::Market(vector<Item*> i)
: Square(1){
    cout << "A New Market has been created!" << endl;
    items = i;
    team = NULL;
}

Market::~Market(){
    cout << "A Market to be destroyed!" << endl;
    items.clear();
}

void Market::print(){
    cout << "A Market square!" << endl;
    if(team != NULL){
        team->print();
    }
}

void Market::menu(){
    cout << endl <<"Menu: " << endl << endl;
    cout << "To select an item, please give the number that corresponding to this object." << endl;
    // πρεπει να προσθεσω και πως θα διαλεγει για ποιο μελος της ομαδας επιλεγει καθε φορα
    int item = 0;
    vector <Item*> :: iterator i;
    for (i = items.begin(); i != items.end(); i++) {
        item++;
        cout << "Press " << item << " to select: ";
        (*i)->Print();
    }
    cout << "To select an item a weapon, please give his number" << endl;
    // int select = 0;
    // while(select > 0){
    //     cin >> select;
    //     if(select > 0){     // αν εχει επιλεξει καποιο αντικειμενο πρεπει να ελεγξω αν μπορει να το αγορασει ή πρεπει να μου πει αν θελει να το πουλησω κλπ
            
    //     }
    // }
     
    
    
}

void Market::enterTeam(Team* t){
    team = t;
}

void Market::exitTeam(){
    team = NULL;
}

vector<Item*> Market::getItem()const{
    return items;
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