#include <iostream>
#include <fstream>
#include <cstring>
#include <time.h>

#include "game.hpp"
using namespace std;

Game::Game(vector<string> livingNames, vector<string> weaponNames, vector<string> armorNames, vector<string> potionNames, vector<string> spellNames){
    // cout << "A New Game has been created!" << endl;

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
        	if(level>10) level--;
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
    potion=new Potion("Dexterity Potion",40,8,"dexterity",1);
    potions.push_back(potion);
    potion=new Potion("Strength Potion",40,8,"strength",1);
    potions.push_back(potion);
    // create spells
    j = 0;
    price = 5;
    level = 1;
    int energy = 6;
    int min = 0;     // ??? t? ?a ßa?? ed? ???
    int max = 0;     // ??? t? ?a ßa?? ed? ???
    int a = 0;       // ??? t? ?a ßa?? ed? ???
    int b = 0;       // ??? t? ?a ßa?? ed? ???
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

    grid = new Grid(heroes, monsters, weapons, armors, potions, spells);
    grid->displayMap();
}

Game::~Game(){
    cout << "A Grid to be destroyed!" << endl;
    heroes.clear();
    monsters.clear();
    weapons.clear();
    armors.clear();
    potions.clear();
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
	for(int j=0; j<num; j++){       // j<num p?epe? ?a e??a? ???
		cout << "Choose Hero number" << j+1 << endl;
		cin >> k;
		team->joinTeam(heroes.at(k-1));
	}
	cout <<"Your team is ready:" << endl;
	team->displayStats();
    grid->setTeam(team);
    grid->displayMap(); // 
    string m;
    cout << "Please select where you want to move between up/down/right/left" << endl;
    cin >> m;
    cout << "You selected:" << m << endl;
    while(true){
        if((m.compare("up") == 0) || (m.compare("down") == 0) || (m.compare("right") == 0) || (m.compare("left") == 0)){
            move(m);
        }
        else if(m.compare("stop") == 0){
            bool s = stop();
            if (s == true){
                break;
            }
        }
        else{
            help();
            flag=1;
        }
        if(flag!=1){
        if(team->getLocation()->getType()==2){
        mon=this->prepare();
		team->getLocation()->operate(mon);
		}
	}
		flag=0;
        grid->displayMap();
        cout << "Please select where you want to move" << endl;
        cin >> m;
        cout << "You selected:" << m << endl;
        mon.clear();
    }
}

bool Game::stop(){
    cout << "You selected: stop." << endl;
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
    // cout << "WARNING: You can't move out of world" << endl;
    cout << "If you want to stop playing the game, please give: stop" << endl;
}

void Game::printHeroes(){
	for(int j=0; j<heroes.size(); j++){
		cout << "Hero " << j+1 << ":" << endl;
		heroes.at(j)->print();
	}
}

vector<Monster*> Game::prepare(){
	int amount;
	int v3;
	amount= rand() % (team->getCounter()+3);
	while(amount<team->getCounter()){
		amount=rand() % (team->getCounter()+2);
	}
	vector<Monster*> k;
	for(int j=0; j<amount; j++){
		v3=rand() % monsters.size();
		if(v3<=5){
		Monster* m=new Dragon(monsters.at(v3)->getName());
		k.push_back(m);
		}
		else if(v3<=10){
			Monster* m=new Exoskeleton(monsters.at(v3)->getName());
			k.push_back(m);
		}
		else{
			Monster* m=new Spirit(monsters.at(v3)->getName());
			k.push_back(m);
		}
	
}
	for(int j=1; j<team->getLevel(); j++){
		for(int i=0; i<k.size(); i++){
			k.at(i)->levelUp();
		}
	}
	return k;
}
