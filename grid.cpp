#include <iostream>
#include <cstring>

#include "living.hpp"

using namespace std;

Grid::Grid(){

}

Grid::~Grid(){

}

void Grid::displayMap(){

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


Market::Market(vector<Weapon> w, vector<Armor> a, vector<Potion> p, vector<Spell> s)
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
}

void Market::printMenu(){

}

void Market::print()const{

}

void Market::enterTeam(Team* t){
    team = t;
}

void Market::exitTeam(){
    team = NULL;
}

vector<Weapon> Market::getWeapons()const{
    return weapons;
}

vector<Armor> Market::getArmors()const{
    return armors;
}

vector<Potion> Market::getPotions()const{
    return potions;
}

vector<Spell> Market::getSpells()const{
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