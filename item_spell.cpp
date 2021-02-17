#include <iostream>
#include <cstring>

#include "item_spell.hpp"

using namespace std;


Item::Item(string name,int price,int leastlevel){
    this->name=name;
    this->price=price;
    this->leastlevel=leastlevel;
}

Item::~Item(){
}

string Item::getName()const{
    return name;
}

int Item::getPrice()const{
    return price;
}

int Item::getLeastlevel()const{
    return leastlevel;
}


Weapon::Weapon(string name,int price,int leastlevel,int dmg,int i):
Item(name,price,leastlevel){
    damage=dmg;
    hands=i;
}

Weapon::~Weapon(){
}

int Weapon::getDamage()const{
    return damage;
}

int Weapon::getHands()const{
    return hands;
}

void Weapon::print(){
    cout << "Weapon: " << name <<endl;
    cout << "Price: " << price << endl;
    cout << "Minimum level: " << leastlevel << endl;
    cout << "Damage: " << damage << endl;
    cout << "Hands: " << hands << endl << endl;
}


Armor::Armor(string name,int price, int leastlevel,int defence):
Item(name,price,leastlevel){   
    this->defence=defence;
}

Armor::~Armor(){
}

int Armor::getDefence()const{
    return defence;
}

void Armor::print(){
    cout << "Armor: " << name <<endl;
    cout << "Price: " << price << endl;
    cout << "Minimum level: " << leastlevel << endl;
    cout << "Defemce: " << defence << endl << endl;
}


Potion::Potion(string name,int price,int leastlevel,string abil,int amount):
Item(name,price,leastlevel){
    ability=abil;
    this->amount=amount;
    flag=0; //
}

Potion::~Potion(){
}

string Potion::getAbility()const{
    return ability;
}

int Potion::getAmount()const{
    return amount;
}

int Potion::getFlag()const{
    return flag;
}

void Potion::print(){
    cout << "Potion: " << name <<endl;
    cout << "Price: " << price << endl;
    cout << "Minimum level: " << leastlevel << endl;
    cout << "Ability: The " << ability << " is increased by " << amount << endl;
}


Spell::Spell(string name,int price,int leastlevel,int en,int min,int max,int a,int b):
Item(name,price,leastlevel){
    energy=en;
    maxdamage=max;
    mindamage=min;
    reduction=a;
    rounds=b;
}

Spell::~Spell(){
} 

int Spell::getEnergy()const{
    return energy;
}

int Spell::getMax()const{
    return maxdamage;
}

int Spell::getMin()const{
    return mindamage;
}

int Spell::getReduction()const{
    return reduction;
}

int Spell::getRounds()const{
    return rounds;
}

int Spell::reduce(){
	rounds--;
	return rounds;
}

void Spell::print(){
    cout << "Spell: " << name <<endl;
    cout << "Price: " << price << endl;
    cout << "Minimum level: " << leastlevel << endl;
    cout << "Energy needed: " << energy << endl;
    cout << "Range of damage: " << mindamage << "-" << maxdamage << endl << endl;
    
}

void Spell::cast(int dexterity,Monster* a){
	int dmg=(dexterity*maxdamage)/(40 +((a->getLevel()-1)*4));
	if(dmg<mindamage){ 
        dmg=mindamage;
    }
	if(dmg>maxdamage){ 
        dmg=maxdamage;
    }
	a->defend(dmg);
}

Icespell::Icespell(string name,int price,int leastlevel,int energy,int min,int max, int a, int b):
Spell(name,price,leastlevel,energy,min,max,a,b){
}

Icespell::Icespell(const Icespell &p2):
Spell(p2.name,p2.price,p2.leastlevel,p2.energy,p2.mindamage,p2.maxdamage,p2.reduction,p2.rounds+1){
}

Icespell::~Icespell(){
}

void Icespell::print(){
    Spell::print();
    cout << "Category: Ice spell "<< endl;
    cout << "Spell effect: " << "It reduces enemy's damage by " << reduction << " for " << rounds << " rounds" << endl << endl;
}

void Icespell::cast(int dexterity,Monster* a){
	Spell::cast(dexterity,a);
	a->put(this);
}

Firespell::Firespell(string name,int price,int leastlevel,int energy,int min,int max, int a, int b):
Spell(name,price,leastlevel,energy,min,max,a,b){
}

Firespell::Firespell(const Firespell &p2):
Spell(p2.name,p2.price,p2.leastlevel,p2.energy,p2.mindamage,p2.maxdamage,p2.reduction,p2.rounds+1){
}

Firespell::~Firespell(){
}

void Firespell::print(){
    Spell::print();
    cout << "Category: Fire spell "<< endl;
    cout << "Spell effect: " << "It reduces enemy's defence by " << reduction << " for " << rounds << " rounds" << endl << endl;
}

void Firespell::cast(int dexterity,Monster* a){
	Spell::cast(dexterity,a);
	a->put(this);
}

Lightingspell::Lightingspell(string name,int price,int leastlevel,int energy,int min,int max, int a, int b):
Spell(name,price,leastlevel,energy,min,max,a,b){
}

Lightingspell::Lightingspell(const Lightingspell &p2):
Spell(p2.name,p2.price,p2.leastlevel,p2.energy,p2.mindamage,p2.maxdamage,p2.reduction,p2.rounds+1){
}

Lightingspell::~Lightingspell(){
}

void Lightingspell::print(){
    Spell::print();
    cout << "Category: Lighting spell "<< endl;
    cout << "Spell effect: " << "It reduces the chance of the opponent avoiding an attack by " << reduction << "% for " << rounds << " rounds" << endl;
}

void Lightingspell::cast(int dexterity,Monster* a){
	Spell::cast(dexterity,a);
	a->put(this);
}