// #pragma once

#include <iostream>
#include <cstring>
#include <vector>

#include "living.hpp"
#include "grid.hpp"

using namespace std;

// classes definitions
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

        void play();        // κυρια συναρτηση λειτουργιας του παιχνιδιου
        void move(string);  // συνάρτηση κινησης 
        void buy();         // αγορα item & αοποθηκευση του στο vector του ηρωα
        void sell();        // πωληση αντικειμένου που εχει αγοράσει ήδη ο ηρωας 
        void help();        // συνάρτηση εκτυπωσης συντομη ςπεριγραφήςε καθε εντολής που μπορει να δωσει ο παικτης
        void startGame();
        void stopGame();
        void printHeroes();
};
