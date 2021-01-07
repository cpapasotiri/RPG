#include <iostream>
#include <cstring>

#include "living.hpp"

using namespace std;

Living::Living(string n){
    cout << "A New Living has been created! " << endl;
    name = n;
    level = 0;
    healthPower = 10;
}

Living::~Living(){
    cout << "A Living to be destroyed! " << endl;
    cout << "name: " << name << " level: " << level << " healthPower: " << healthPower << endl; 
}

// faint
// void Living::changeHelthPower(int number){
//     if(healthPower == 0)
// }

string Living::getName()const{
    return name;
}

int Living::getLevel()const{
    return level;
}

int Living::getHelthPower()const{
    return healthPower;
}


Hero::Hero(string n, int s, int d, int a)
: Living(n){
    cout << "A New Hero has been created! " << endl;
    magicPower = 10;
    strenght = s;
    dexterity = d;
    agility = a;
    money = 50;
    experience = 0;
}

Hero::~Hero(){
    cout << "A Hero to be destroyed! " << endl;
}


void Hero::print()const{
    cout << "Hero " << Living::getName() << endl
         << "level = " << Living::getLevel() << endl
         << "healthPower = " << Living::getHelthPower() << endl
         << "magicPower = " << magicPower << endl 
         << "strenght = " << strenght << endl
         << "dexterity = " << dexterity << endl
         << "agility = " << agility << endl
         << "money = " << money << endl
         << "experience = " << experience << endl;
}

int Hero::getMagicPower()const{
    return magicPower;
}

int Hero::getStrenght()const{
    return strenght;
}

int Hero::getDexterity()const{
    return dexterity;
}

int Hero::getAgility()const{
    return agility;
}

int Hero::getMoney()const{
    return money;
}

int Hero::getExperience()const{
    return experience;
}


Warrior::Warrior(string n)
: Hero(n, 8, 5, 7){
    cout << "A New Warrior has been created! " << endl;
}

Warrior::~Warrior(){
    cout << "A Warrior to be destroyed! " << endl;
}


Sorcerer::Sorcerer(string n)
: Hero(n, 4, 7, 8){
    cout << "A New Sorcerer has been created! " << endl;
}

Sorcerer::~Sorcerer(){
    cout << "A Sorcerer to be destroyed! " << endl;
}


Paladin::Paladin(string n)
: Hero(n, 7, 9, 3){
    cout << "A New Paladin has been created! " << endl;
}

Paladin::~Paladin(){
    cout << "A Paladin to be destroyed! " << endl;
}



Monster::Monster(string n, int da, int de, int a)
: Living(n){
    cout << "A New Monster has been created! " << endl;
    damage = da;
    defense = de;
    attack = a;
}

Monster::~Monster(){
    cout << "A Monster to be destroyed! " << endl;
}

int Monster::getDamage()const{
    return damage;
}

int Monster::getDefense()const{
    return defense;
}

int Monster::getAttack()const{
    return attack;
}


Dragon::Dragon(string n) 
: Monster(n, 9, 5, 5){
    cout << "A New Dragon has been created! " << endl;
}

Dragon::~Dragon(){
    cout << "A Dragon to be destroyed! " << endl;
}


Exoskeleton::Exoskeleton(string n) 
: Monster(n, 5, 9, 5){
    cout << "A New Exoskeleton has been created!" << endl;
}

Exoskeleton::~Exoskeleton(){
    cout << "A Exoskeleton to be destroyed!" << endl;
}


Spirit::Spirit(string n) 
: Monster(n, 5, 5, 9){
    cout << "A New Spirit has been created!" << endl;
}

Spirit::~Spirit(){
    cout << "A Spirit to be destroyed!" << endl;
}



Team::Team(Hero* h1, Hero* h2, Hero* h3){
    cout << "A New Team has been created!" << endl;
    hero1 = h1;
    hero2 = h2;
    hero3 = h3;
}

Team::~Team(){
    cout << "A Team to be destroyed!" << endl;
}

void Team::print(){
    hero1->print();
    hero2->print();
    hero3->print();
}

Hero* Team::getHero1()const{
    return hero1;
}

Hero* Team::getHero2()const{
    return hero2;
}

Hero* Team::getHero3()const{
    return hero3;
}