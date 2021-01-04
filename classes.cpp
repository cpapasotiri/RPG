#include <iostream>
#include <cstring>

#include "classes.hpp"

using namespace std;

Living::Living(string n, int l, int h){
    cout << "A New Living has been created! " << endl;
    name = n;
    level = l;
    healthPower = h;
}

Living::~Living(){
    cout << "A Living to be destroyed! " << endl;
    cout << "name: " << name << " level: " << level << " healthPower: " << healthPower << endl; 
}

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


Hero::Hero(string n, int l, int h, int mp, int s, int d, int a, int mo, int e)
: Living(n, l, h){
    cout << "A New Hero has been created! " << endl;
    magicPower = mp;
    strenght = s;
    dexterity = d;
    agility = a;
    money = mo;
    experience = e;
}

Hero::~Hero(){
    cout << "A Hero to be destroyed! " << endl;
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


Warrior::Warrior(string n, int l, int h, int m, int s, int d, int a)
: Hero(mn, l, h, m, s, d, a){
    cout << "A New Warrior has been created! " << endl;
}

Warrior::~Warrior(){
    cout << "A Warrior to be destroyed! " << endl;
}


Sorcerer::Sorcerer(int m, int s, int d, int a)
: Hero(mn, l, h, m, s, d, a){
    cout << "A New Sorcerer has been created! " << endl;
}

Sorcerer::~Sorcerer(){
    cout << "A Sorcerer to be destroyed! " << endl;
}


Paladin::Paladin(int m, int s, int d, int a)
: Hero(mn, l, h, m, s, d, a){
    cout << "A New Paladin has been created! " << endl;
}

Paladin::~Paladin(){
    cout << "A Paladin to be destroyed! " << endl;
}



Monster::Monster(string n, int l, int h, int da, int de)
: Living(n, h, l){
    cout << "A New Monster has been created! " << endl;
    damage = da;
    defence = de;
}

Monster::~Monster(){
    cout << "A Monster to be destroyed! " << endl;
}

int Monster::getDamage()const{
    return damage;
}

int Monster::getDefence()const{
    return defence;
}


Dragon::Dragon(string n, int l, int h, int da, int de) 
: Monster(n, l, h, da, de){
    cout << "A New Dragon has been created! " << endl;
}

Dragon::~Dragon(){
    cout << "A Dragon to be destroyed! " << endl;
}


Exoskeleton::Exoskeleton(string n, int l, int h, int da, int de) 
: Monster(n, l, h, da, de){
    cout << "A New Exoskeleton has been created! " << endl;
}

Exoskeleton::~Exoskeleton(){
    cout << "A Exoskeleton to be destroyed! " << endl;
}


Spirit::Spirit(string n, int l, int h, int da, int de) 
: Monster(n, l, h, da, de){
    cout << "A New Spirit has been created! " << endl;
}

Spirit::~Spirit(){
    cout << "A Spirit to be destroyed! " << endl;
}