#include <iostream>
#include <fstream>
#include <cstring>
#include <time.h>
#include "game.hpp"

using namespace std;

Game::Game(vector<string> livingNames, vector<string> weaponNames, vector<string> armorNames, vector<string> spellNames){
    // Create livings(heroes & monsters)
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

    // Create items & spells
    j = 0;
    int price = 10;
    int level = 1;
    int damage = 10;
    int hands = 1;
    int dmg=3;
    int prc=8;
    int w;
    // create weapons
    for(i = weaponNames.begin(); i != weaponNames.end(); i++){
        Weapon* weapon = new Weapon((*i), prc, level, dmg, hands);
        weapons.push_back(weapon);
        j++;
        if(j==11){
        	level++;
        	if(level>10) 
                level--;
        	j=0;
        	price=level*10;
        	
		}
		hands= 1 + rand() % 2;
		if(hands==2){
		    dmg= (level*5) + rand() % (level*5);
		    prc=price + rand() % 10;
		}
		else {
		    dmg= (level*5)/2 + rand() % (level*3);
		    prc=price + rand() % 10;
		}
		
    }
    // create armors
    price = 10;
    level = 1;
    int defence = 8;
    int mindef=2;
    int def=3;
    prc=7;
    j=0;
    for(i = armorNames.begin(); i != armorNames.end(); i++){
        Armor* armor = new Armor((*i), prc, level, def);
        armors.push_back(armor);
        j++;
        if(j==7) {
        	level++;
        	if(level>10) level--;
        	j=0;
        	price=level*10;
        	mindef=defence;
        	defence=defence+4;
		}
		def=mindef + rand() % 5;
		prc= price + rand() % 10;  	
    }
    // create potions
    Potion* potion=new Potion("Health Potion",20,2,"healthPower",10);
    potions.push_back(potion);
    potion=new Potion("Mana Potion",40,3,"magicPower",10);
    potions.push_back(potion);
    potion=new Potion("Mega Mana Potion",40,6,"magicPower",50);
    potions.push_back(potion);
    potion=new Potion("Mega Health Potion",40,6,"healthPower",100);
    potions.push_back(potion);
    potion=new Potion("Dexterity Potion",140,8,"dexterity",1);
    potions.push_back(potion);
    potion=new Potion("Strength Potion",140,8,"strength",1);
    potions.push_back(potion);
    // create spells
    j = 0;
    price = 5;
    level = 1;
    int energy = 5;
    int min = 20;     
    int max = 50;     
    int a = 1;       
    int b = 1;       
    for(i = spellNames.begin(); i != spellNames.end(); i++){
        j++;
        if(j <= 10){
        	a=1+level + rand() % 5;
            Icespell* ispell = new Icespell((*i), price, level, energy, min, max, a, b);
            spells.push_back(ispell);    
            
        }
        else if(j <= 20){
        	a= 1+level/2 + rand() % 5;
            Firespell* fspell = new Firespell((*i), price, level, energy, min, max, a, b);
            spells.push_back(fspell);
        }
        else{
        	a= 1+level/2 + rand() % 5;
            Lightingspell* lspell = new Lightingspell((*i), price, level, energy, min, max, a, b);
            spells.push_back(lspell); 
        }
       
        level= 1 +rand() % 10;
        min=20 + (10*(level-1));
        max=50 + (21*(level-1));
        energy=5*level;
        b= 1 + rand() %3;
        a=2;        
    }

    grid = new Grid(heroes, monsters, weapons, armors, potions, spells);
    grid->displayMap();
}

Game::~Game(){
    Monster* ptr1;
    Item* ptr;
    for(int j=0; j<heroes.size(); j++){
   	    delete heroes[j];
    }
    heroes.clear();

    for(int j=0; j<monsters.size(); j++){
    	ptr1=monsters[j];
        delete ptr1;
	}
    monsters.clear();

    for(int j=0; j<weapons.size(); j++){
   	    ptr=weapons[j];
        delete ptr;
	}
    weapons.clear();

    for(int j=0; j<armors.size(); j++){
    	ptr=armors[j];
        delete ptr;
	}
    armors.clear();

    for(int j=0; j<potions.size(); j++){
   	    ptr=potions[j];
        delete ptr;
	}
    potions.clear();

    for(int j=0; j<spells.size(); j++){
    	ptr=spells[j];
        delete ptr;
	}
    spells.clear();

    delete grid;
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

vector<Armor*>Game::getArmors()const{
    return armors;
}

vector<Potion*> Game::getPotions()const{
    return potions;
}

vector<Spell*>Game:: getSpells()const{
    return spells;
}


Grid* Game::getGrid()const{
    return grid;
}

Team* Game::getTeam()const{
    return team;
}

void Game::move(string m){
    grid->move(team, m);
}

void Game::start(){
	int flag=0;
	vector<Monster* > mon;
	cout<< "How many heroes do you want ? (1-3)" << endl;
	int num = 0;
	cin >> num;
	team = new Team(num);
	int k;
	this->printHeroes();
	for(int j=0; j<num; j++){
		cout << "Choose Hero number" << j+1 << endl;
		cin >> k;
		team->joinTeam(heroes.at(k-1));
	}
	cout <<"Your team is ready:" << endl;
	team->displayStats();
    grid->setTeam(team);
    grid->displayMap(); 

    string m;
    cout << "Please select where you want to move between up/down/right/left/quitGame" << endl;
    cin >> m;
    cout << "You selected:" << m << endl;
    while(true){
        if((m.compare("up") == 0) || (m.compare("down") == 0) || (m.compare("right") == 0) || (m.compare("left") == 0)){
            move(m);
        }
        else if(m.compare("quitGame") == 0){
            bool s = quitGame();
            if (s == true){
                break;
            }
        }
        else{
            help();
        }
        grid->displayMap();
        cout << "Please select where you want to move between up/down/right/left/quitGame" << endl;
        cin >> m;
        cout << "You selected: " << m << endl;
    }
    delete team;
}

bool Game::quitGame(){
    cout << "If you are sure you want to stop playing write OK else CANCEL.";
    string s;
    cin >> s;
    if(s.compare("OK") == 0){
        return true;
    }
    return false;
}

void Game::help(){
    cout << "HELP" << endl;
    cout << "If you want to move up, please give: up" << endl;
    cout << "If you want to move down, please give: down" << endl;
    cout << "If you want to move right, please give: right" << endl;
    cout << "If you want to move left, please give: left" << endl;
    cout << "If you want to stop playing the game, please give: quitGame" << endl;
}

void Game::printHeroes(){
	for(int j=0; j<heroes.size(); j++){
		cout << "Hero " << j+1 << ":" << endl;
		heroes.at(j)->print();
	}
}
