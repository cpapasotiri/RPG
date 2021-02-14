#ifndef LIVING_HPP
#define LIVING_HPP
#include "grid.hpp"
#include "item_spell.hpp"
#include <cstring>
#include <vector>

using namespace std;

// classes definitions
// living.hpp
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

// item.cpp
class Item;
class Weapon;	
class Armor;	
class Potion;	 
class Spell;	
class Icespell;	
class Firespell;	
class Lightingspell;

// grid.hpp
class Grid;
class Square;
class NonAccessible;
class Market;
class Common;


class Living{
    protected:
        string name;
        int level;
        int healthPower;
        bool faint;     // if health=0: true, else: false
        
    public:
        Living(string);
        ~Living();
        string getName()const;
        int getLevel()const;
        int getHelthPower()const;
        bool getFaint()const;
        bool checkHealth();     // if health=0: true, else: false  
        void changeHealth(int); // give positive or negative number    
};


class Hero : public Living{
    protected:
        int magicPower;
        int strenght;
        int dexterity;
        int agility;
        int money;
        int experience;
        vector<Weapon*> weapon;
        vector<Armor*> armor;
        vector<Potion*> potion;
        vector<Spell*> spell;
        Weapon* w1;
        Weapon* w2;
        Armor* arm;
        
    public:
        Hero(string, int, int, int);
        ~Hero();
        virtual void print()=0;
        int getMagicPower()const;
        int getStrenght()const;
        int getDexterity()const;
        int getAgility()const;
        int getMoney()const;
        int getExperience()const;
        vector<Weapon*> getWeapons()const;
        vector<Armor*> getArmors()const;
        vector<Potion*> getPotions()const;
        vector<Spell*> getSpells()const;
        Weapon* getWeapon1()const;
        Weapon* getWeapon2()const;
        Armor* getArmor()const;
        void checkInventory()const;
        void buy(Weapon*); 
        void buy(Armor*); 
        void buy(Potion*);
        void buy(Spell*);
        void sell(Weapon*);
        void sell(Armor*);
        void sell(Potion*);
        void sell(Spell*);
        void use(Potion*);
        void attack(Monster* a);
        void defend(int damage);
        void regen();
        void equipArmor(Armor* a);
        void equipWeapon(Weapon* a);
        void equipSecondaryWeapon(Weapon* a);
        virtual void levelUp()=0;
        void castSpell(Monster* a);
        int usePotion();
        void victory(int num);
        void defeat();
        void equip();
        Weapon* printWeapons();
        Armor* printArmor();
        int searchWeapon(Weapon* a);
        int searchArmor(Armor* a);
        void sellItem();
};


class Warrior : public Hero{ 
    public:
        Warrior(string);
        ~Warrior();
        void print();
        void levelUp();
};


class Sorcerer : public Hero{
    public:
        Sorcerer(string);
        ~Sorcerer();
        void print();
        void levelUp();
};


class Paladin : public Hero{
    public:
        Paladin(string);
        ~Paladin();
        void print();
        void levelUp();
};


class Monster : public Living{
    protected:
        int damage;     // damage it causes
        int defense;    // defense it has
        int attack;     // avoid attack
        vector<Firespell*> f;
        vector<Icespell*> i;
        vector<Lightingspell*> l;

    public:
        Monster(string, int, int, int);
        ~Monster();
        int getDamage()const;
        int getDefense()const;
        int getAttack()const;
        void setMonster(int, int, int);
        void regen();
        void put(Icespell*);
        void put(Firespell*);
        void put(Lightingspell*);
        void clear();
        void destroy(Hero*);
        void defend(int);
        virtual void print();
        virtual void levelUp()=0;
};


class Dragon : public Monster{
    public:
        Dragon(string);
        ~Dragon();
        void print();
        void levelUp();
};


class Exoskeleton : public Monster{
    public:
        Exoskeleton(string);
        ~Exoskeleton();
        void print();
        void levelUp();
};


class Spirit : public Monster{
    public:
        Spirit(string);
        ~Spirit();
        void print();
        void levelUp();
};



class Team {        // Team with 1-3 heroes 
    private:
    Hero** heroes;
    int counter;
    Square* location;   // ?a de???e? se µ?a ?es? p???a????sµe?? µesa st?? ??sµ?

    public:
    Team(int);
    ~Team();
    void print();
    void setLocation(Square*);
    Square* getLocation()const;
    Hero** getHeroes()const;
    int getCounter()const;
    void joinTeam(Hero*);
    void displayStats()const;
    int getLevel();
};


#endif





