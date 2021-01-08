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
    if(team != NULL){
        team->print();
    }
}

void Market::printMenu(){

}

void Market::print()const{
    cout << "A Market square!" << endl;
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