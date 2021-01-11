#include <iostream>
#include <fstream>
#include <cstring>
#include <time.h>

#include "living.hpp"

using namespace std;

Game::Game(vector<string> livingNames, vector<string> weaponNames, vector<string> armorNames, vector<string> potionNames, vector<string> spellNames){
    cout << "A New Game has been created!" << endl;

    // create livings(heroes & monsters)
    int j = 0;
    vector<string> :: iterator i;
    for(i = livingNames.begin(); i != livingNames.end(); i++){
        j++;
        if(j <= 3){
            Warrior* warrior = new Warrior(*i);
            heroes.push_back(warrior);
        }
        else if(j <= 6){
            Sorcerer* sorcerer = new Sorcerer(*i);
            heroes.push_back(sorcerer);
        }
        else if(j <= 9){
            Paladin* paladin = new Paladin(*i);
            heroes.push_back(paladin);
        }
        else if(j <= 15){
            Dragon* dragon = new Dragon(*i);
            monsters.push_back(dragon);
        }
        else if(j <= 21){
            Exoskeleton* exoskeleton = new Exoskeleton(*i);
            monsters.push_back(exoskeleton);
        }
        else if(j <= 27){
            Spirit* spirit = new Spirit(*i);
            monsters.push_back(spirit);
        }
    }

    // create items & spells
    j = 0;
    int price = 5;
    int level = 1;
    int damage = 4;
    int hands = 1;
    // create weapons
    for(i = weaponNames.begin(); i != weaponNames.end(); i++){
        Weapon* weapon = new Weapon((*i), price, level, damage, hands);
        weapons.push_back(weapon);
        j++;
        if(j%2 == 0){
            hands = 2;
            level++;
            damage += 4;
        }
        else{
            hands = 1;
            damage += 2;
        }
        price += 6;
    }
    // create armors
    price = 10;
    level = 1;
    int defence = 4;
    for(i = armorNames.begin(); i != armorNames.end(); i++){
        Armor* armor = new Armor((*i), price, level, defence);
        armors.push_back(armor);
        price += 20;
        level++;
        defence += 11;
    }
    // create potions
    j = 0;
    price = 5;
    level = 1;
    vector<string> ability;
    ability.push_back("strenght");
    ability.push_back("dexterity");
    ability.push_back("agility");
    srand(time(NULL));
    int amount = 7;
    for(i = potionNames.begin(); i != potionNames.end(); i++){
        j++;
        int a = rand() % 3;     // 0-2
        Potion* potion = new Potion((*i), price, level, ability[a], amount);
        potions.push_back(potion);
        price += 20;
        if(j%3 == 0){
            level++;
            amount += 2;
        }
    }
    ability.clear();
    // create spells
    j = 0;
    price = 5;
    level = 1;
    int energy = 6;
    int min = 0;     // ??? τι να βαλω εδω ???
    int max = 0;     // ??? τι να βαλω εδω ???
    int a = 0;       // ??? τι να βαλω εδω ???
    int b = 0;       // ??? τι να βαλω εδω ???
    for(i = spellNames.begin(); i != spellNames.end(); i++){
        j++;
        if(j <= 10){
            Icespell* ispell = new Icespell((*i), price, level, energy, min, max, a, b);
            spells.push_back(ispell);    
        }
        else if(j <= 20){
            Firespell* fspell = new Firespell((*i), price, level, energy, min, max, a, b);
            spells.push_back(fspell);
        }
        else{
            Lightingspell* lspell = new Lightingspell((*i), price, level, energy, min, max, a, b);
            spells.push_back(lspell); 
        }
        level++;
        energy += 6;
        min++;          // ??? ??? 
        max++;          // ??? ??? 
        a++;            // ??? ??? 
        b++;            // ??? ??? 
        if(j%10 == 0){
            level = 1;
            energy = 6;
            min = 0;    // ??? ???          
            max = 0;    // ??? ???          
            a = 0;      // ??? ???      
            b = 0;      // ??? ???      
        }
    }
}

Game::~Game(){
    cout << "A Grid to be destroyed!" << endl;
    heroes.clear();
    monsters.clear();
    weapons.clear();
    armors.clear();
    potions.clear();
    spells.clear(); 
}

vector<Hero*> Game::getHeroes()const{
    return heroes;
}

vector<Monster*> Game::getMonsters()const{
    return monsters;
}

vector<Weapon*> Game::getWeapons()const{
    return weapons;
}

vector<Armor*>Game:: getArmors()const{
    return armors;
}

vector<Potion*> Game::getPotions()const{
    return potions;
}

vector<Spell*>Game:: getSpells()const{
    return spells;
}

void Game::play(){

}

void Game::move(){

}

void Game::buy(){

}

void Game::sell(){

}

void Game::help(){

}
void Game::startGame(){
	cout<< "How many heroes do you want ? (1-3)" << endl;
	int num;
	cin >> num ;
	team=new Team(num);
	int k;
	this->printHeroes();
	for(int j=0; j<(num-1); j++){
		cout << "Choose Hero number" << j+1 << endl;
		cin >> k;
		team->joinTeam(heroes.at(k-1));
	}
	cout <<"Your team is ready" << endl;
	team->displayStats();
}

