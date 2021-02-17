#ifndef GRID_HPP
#define GRID_HPP
#include "living.hpp"
#include "item_spell.hpp"
#include <vector>

using namespace std;

class Living;
class Hero;
class Warrior;
class Sorcerer;
class Paladin;
class Monster;
class Dragon;
class Exoskeleton;
class Spirit;
class Team;

class Item;
class Weapon;	
class Armor;	
class Potion;	 
class Spell;	
class Icespell;	
class Firespell;	
class Lightingspell;


class Grid;
class Square;
class NonAccessible;
class Market;
class Common;

class Grid{
    private:
        Square*** world;     // Square* world[8][8];
        vector<Hero*> heroes;
        vector<Monster*> monsters;

    public:
        Grid(vector<Hero*>, vector<Monster*>, vector<Weapon*>, vector<Armor*>, vector<Potion*>, vector<Spell*>);
        ~Grid();
        void displayMap();
        void move(Team*, string);
        void setTeam(Team*);
        Square*** getWorld()const;
        vector<Hero*> getHeroes()const;
        vector<Monster*> getMonsters()const;
};


class Square{
    private:
        int type;
        int i;
        int j;
        Team* team;

    public:
        Square(int, int, int);
        ~Square();
        virtual void print()const=0;
        virtual void start()=0;
        void enterTeam(Team*);
        void exitTeam();
        int getType()const;
        int getI()const;
        int getJ()const;
        Team* getTeam()const;
        virtual void operate(vector <Monster*> k)=0;
};


class NonAccessible : public Square{
    public:
        NonAccessible(int, int);
        ~NonAccessible();
        void print()const;
        void start();
        void operate(vector <Monster*> k);
};


class Market : public Square{
    private:
        vector<Weapon*> weapons;
        vector<Armor*> armors;
        vector<Potion*> potions;
        vector<Spell*> spells;
        int items;

    public:
        Market(vector<Weapon*>, vector<Armor*>, vector<Potion*>, vector<Spell*>, int, int);
        ~Market();

        void print()const;
        int printMenu(string);
        void menu();
        void buy(Hero*, string, int);
        void sell(Hero*);
        Hero* selectHero();
        string selectCategory();
        void help();
        void start();
        void operate(vector <Monster*> k);
        vector<Weapon*> getWeapons()const;
        vector<Armor*> getArmors()const;
        vector<Potion*> getPotions()const;
        vector<Spell*> getSpells()const;
        int getItems()const;
};


class Common : public Square{
    public:
        Common(int, int);
        ~Common();
        void print()const;
        void start();
        void operate(vector <Monster*> k);
        void afterBattle(int num,vector<Monster*> monsters,int flag);
        int Battle(vector<Monster*> monsters);             // return 1 for victory and return 0 for defeat 
};


#endif