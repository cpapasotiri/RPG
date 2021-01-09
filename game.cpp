#include <iostream>
#include <fstream>
#include <cstring>

#include "living.hpp"

using namespace std;

Game::Game(vector<string> livingNames, vector<string> weaponNames, vector<string> armorNames, vector<string> potionNames, vector<string> spellNames){
    cout << "A New Game has been created!" << endl;

    vector<Weapon*> weapon;
    int i = 0;
    string name;
    int price = 5;
    int level = 0;
    int damage = 5;
    int hands = 1;
    vector<string> :: iterator j;
    for (j = weaponNames.begin(); j != weaponNames.end(); j++) {
        Weapon* w = new Weapon((*j), price, level, damage, hands);
        weapon.push_back(w);
        i++;
        if(i%2 == 0){
            hands = 2;
            level++;
        }
        else{
            hands = 1;
        }
        price += 6;
        damage += 5;
    }

    // vector<Armor*> armor;
    // int i = 0;
    // string name;
    // int price = 5;
    // int level = 0;
    // string ability;
    // int amount = 3;
    // vector<string> :: iterator j;
    // for (j = armorNames.begin(); j != armorNames.end(); j++) {
    //     Armor* w = new Armor((*j), price, level, abil, amount);
    //     armor.push_back(w);
    //     level++;
    //     price += 3;
    //     damage += 4;
    // }


}

Game::~Game(){
    cout << "A Grid to be destroyed!" << endl;

}
