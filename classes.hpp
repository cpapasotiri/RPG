#include <iostream>
#include <cstring>

using namespace std;

// classes definitions
class Item;
class Weapons;
class Armor;
class Potion;

class Spell;
class IceSpell;
class FireSpell;
class LightSpell;

class Living;
class Hero;
class Warrior;
class Sorcerer;
class Paladin;
class Monster;
class Dragon;
class Exoskeleton;
class Spirit;



class Living{
    private:
        string name;
        int level;
        int healthPower;
        
    public:
        Living(string, int, int);
        ~Living();

        void helthCheck();
        // void changeHelthPower(int);

        string getName()const;
        int getLevel()const;
        int getHelthPower()const;


};


class Hero : public Living{
    private:
        int magicPower;
        int strenght;
        int dexterity;
        int agility;
        int money;
        int experience;
        
    public:
        Hero(string, int, int, int, int, int, int, int, int);
        ~Hero();

        int getMagicPower()const;
        int getStrenght()const;
        int getDexterity()const;
        int getAgility()const;

};


class Warrior : public Hero{
    private:
        
        
    public:
        Warrior(int, int, int, int);
        ~Warrior();
};


class Sorcerer : public Hero{
    private:
        
        
    public:
        Sorcerer(int, int, int, int);
        ~Sorcerer();
};


class Paladin : public Hero{
    private:
        
        
    public:
        Paladin(int, int, int, int);
        ~Paladin();

};


class Monster : public Living{
    private:
        int damage;
        int defence;

    public:
        Monster(string, int, int, int, int);
        ~Monster();

        int getDamage()const;
        int getDefence()const;
};


class Dragon : public Monster{
    private:
        

    public:
        Dragon(string, int, int, int, int);
        ~Dragon();
};


class Exoskeleton : public Monster{
    private:


    public:
        Exoskeleton(string, int, int, int, int);
        ~Exoskeleton();
};


class Spirit : public Monster{
    private:


    public:
        Spirit(string, int, int, int, int);
        ~Spirit();
};