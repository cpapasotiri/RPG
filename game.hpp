#include <iostream>
#include <cstring>
#include <vector>
#include "living.hpp"
#include "item_spell.hpp"
#include "grid.hpp"

using namespace std;

// class definition
class Game;

class Game{
    private:
        vector<Hero*> heroes;
        vector<Monster*> monsters;
        vector<Weapon*> weapons;
        vector<Armor*> armors;
        vector<Potion*> potions;
        vector<Spell*> spells; 
        Grid* grid;
        Team* team;

    public:
        Game(vector<string>, vector<string>, vector<string>, vector<string>, vector<string>);
        ~Game();

        vector<Hero*> getHeroes()const;
        vector<Monster*> getMonsters()const;
        vector<Weapon*> getWeapons()const;
        vector<Armor*> getArmors()const;
        vector<Potion*> getPotions()const;
        vector<Spell*> getSpells()const;
        Grid* getGrid()const;
        Team* getTeam()const;
        void setTeam();
        void start();
        bool stop();
        void move(string);
        void help();
        void printHeroes();
};
