#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

#include "game.hpp"

using namespace std;


int main(int argc, char* argv[]){
    string name;

    vector<string> livingNames;
    ifstream file1 ("names.txt");
    if (file1.is_open()){
        while(getline(file1, name)){
            livingNames.push_back(name);
        }
    }

    vector<string> weaponNames;
    ifstream file2 ("weapons.txt");
    if (file2.is_open()){
        while(getline(file2, name)){
            weaponNames.push_back(name);
        }
    }
            
    vector<string> armorNames;
    ifstream file3 ("armors.txt");
    if (file3.is_open()){
        while(getline(file3, name)){
            armorNames.push_back(name);
        }
    }
    
    vector<string> potionNames;
    ifstream file4 ("potions.txt");
    if (file4.is_open()){
        while(getline(file4, name)){
            potionNames.push_back(name);
        }
    }

    vector<string> spellNames;
    ifstream file5 ("spells.txt");
    if (file5.is_open()){
        while(getline(file5, name)){
            spellNames.push_back(name);
        }
    }

    Game* game = new Game(livingNames, weaponNames, armorNames, potionNames, spellNames);




    livingNames.clear();
    weaponNames.clear();
    armorNames.clear();
    potionNames.clear();
    spellNames.clear();
    return 0;
}