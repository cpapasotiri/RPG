#include <iostream>
#include <cstring>

#include "item_spell.hpp"

using namespace std;


Item::Item(string name,int price,int leastlevel){
    this->name=name;
    this->price=price;
    this->leastlevel=leastlevel;
    cout << "A new Item has been created " << endl;
}

Item::~Item(){
    cout << "An Item to be destroyed " << endl;
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
Item(name,price,leastlevel)
{
    damage=dmg;
    hands=i;
    cout<< "A new Weapon has been created" << endl;
}

Weapon::~Weapon(){
    cout << "A Weapon to be destroyed" << endl;
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
    cout << "Hands: " << hands << endl;
}


Armor::Armor(string name,int price, int leastlevel,int defence):
Item(name,price,leastlevel)
{   
    this->defence=defence;
    cout << "A new armor has been created" << endl;
}

Armor::~Armor(){
    cout <<"An armor to be destroyed" << endl;
}

int Armor::getDefence()const{
    return defence;
}

void Armor::print(){
    cout << "Armor: " << name <<endl;
    cout << "Price: " << price << endl;
    cout << "Minimum level: " << leastlevel << endl;
    cout << "Defemce: " << defence << endl;
}


Potion::Potion(string name,int price,int leastlevel,string abil,int amount):
Item(name,price,leastlevel)
{
    ability=abil;
    this->amount=amount;
    flag=0;
    cout << "A new Potion has been created" << endl ;
}

Potion::~Potion(){
    cout << "A potion to be destroyed" << endl;
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
Item(name,price,leastlevel)
{
    energy=en;
    maxdamage=max;
    mindamage=min;
    reduction=a;
    rounds=b;
    cout << "A new Spell has been created" << endl;
}

Spell::~Spell(){
    cout << "A spell to be destroyed" << endl;
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

void Spell::print(){
    cout << "Spell: " << name <<endl;
    cout << "Price: " << price << endl;
    cout << "Minimum level: " << leastlevel << endl;
    cout << "Energy needed: " << energy << endl;
    cout << "Range of damage: " << mindamage << "-" << maxdamage << endl;
    
}


Icespell::Icespell(string name,int price,int leastlevel,int energy,int min,int max, int a, int b):
Spell(name,price,leastlevel,energy,min,max,a,b)
{
    cout << "A new icespell has been created" << endl;
}

Icespell::~Icespell(){
    cout << "An icespell to be destroyed" << endl;
}

void Icespell::print(){
    Spell::print();
    cout << "Category: Ice spell "<< endl;
    cout << "Spell effect: " << "It reduces enemy's damage by " << reduction << " for " << rounds << " rounds" << endl;
}


Firespell::Firespell(string name,int price,int leastlevel,int energy,int min,int max, int a, int b):
Spell(name,price,leastlevel,energy,min,max,a,b)
{
    cout << "A new icespell has been created" << endl;
}

Firespell::~Firespell(){
    cout << "An icespell to be destroyed" << endl;
}

void Firespell::print(){
    Spell::print();
    cout << "Category: Fire spell "<< endl;
    cout << "Spell effect: " << "It reduces enemy's defence by " << reduction << " for " << rounds << " rounds" << endl;
}


Lightingspell::Lightingspell(string name,int price,int leastlevel,int energy,int min,int max, int a, int b):
Spell(name,price,leastlevel,energy,min,max,a,b)
{
    cout << "A new Lightingspell has been created" << endl;
}

Lightingspell::~Lightingspell(){
    cout << "An Lightingspell to be destroyed" << endl;
}

void Lightingspell::print(){
    Spell::print();
    cout << "Category: Lighting spell "<< endl;
    cout << "Spell effect: " << "It reduces the chance of the opponent avoiding an attack by " << reduction << "% for " << rounds << " rounds" << endl;
}

void Spell::cast(int dexterity,Monster* a){
	int dmg=dexterity + mindamage;
	if(dmg>maxdamage) dmg=maxdamage;
	a->changeHealth(-dmg);
}

void Icespell::cast(int dexterity,Monster* a){
	Spell::cast(dexterity,a);
//	a->setMonster(a->getDamage()-amount,a->getDefense(),a->getAttack());       //borei kai na ginei allios to skeftomai akoma
}

void Firespell::cast(int dexterity,Monster* a){
	Spell::cast(dexterity,a);
//	a->setMonster(a->getDamage(),(a->getDefense()-amount),a->getAttack());		//borei kai na ginei allios to skeftomai akoma
}

void Lightingspell::cast(int dexterity,Monster* a){
		Spell::cast(dexterity,a);
		//a->setMonster(a->getDamage(),a->getDefense(),(a->getAttack()-amount));		//borei kai na ginei allios to skeftomai akoma
}
