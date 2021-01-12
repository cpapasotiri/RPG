#include <iostream>
#include <cstring>
#include <vector>

#include "living.hpp"

using namespace std;

class Grid;
class Square;
class NonAccessible;
class Market;
class Common;

class Grid{
    private:
        vector<Hero*> heroes;
        vector<Monster*> monsters;
        // Square* grid [8][8];   // ή κατι τετοιο

    public:
        Grid(vector<Hero*>, vector<Monster*>, vector<Weapon*>, vector<Armor*>, vector<Potion*>, vector<Spell*>);
        ~Grid();

        void displayMap();

        vector<Hero*> getHeroes()const;
        vector<Monster*> getMonsters()const;
};


class Square{
    private:
        int type;

    public:
        Square(int);
        ~Square();

        virtual void print()const=0;

        int getType()const;
};


class NonAccessible : public Square{
    public:
        NonAccessible();
        ~NonAccessible();

        void print()const;
};


class Market : public Square{
    private:
        vector<Weapon*> weapons;
        vector<Armor*> armors;
        vector<Potion*> potions;
        vector<Spell*> spells;
        Team* team;
        int items;

    public:
        Market(vector<Weapon*>, vector<Armor*>, vector<Potion*>, vector<Spell*>);
        ~Market();

        void print();
        void menu();
        void buy(Hero*, int);
        void sell(Hero*, int);
        Hero* selectHero();
        void help();

        void enterTeam(Team*);
        void exitTeam();

        vector<Weapon*> getWeapons()const;
        vector<Armor*> getArmors()const;
        vector<Potion*> getPotions()const;
        vector<Spell*> getSpells()const;
        Team* getTeam()const;
        int getItems()const;
};


class Common : public Square{
    private:
        Team* team;

    public:
        Common();
        ~Common();

        void print()const;

        void enterTeam(Team*);
        void exitTeam();

        Team* getTeam()const;
};