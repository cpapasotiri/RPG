#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

// classes definitions
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
        Living(string);
        ~Living();

        // void helthCheck(); // void changeHelthPower(int);

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
        // vector<Weapon> weapon;
        // vector<Armor> armor;
        // vector<Potion> potion;
        
    public:
        Hero(string, int, int, int);
        ~Hero();

        int getMagicPower()const;
        int getStrenght()const;
        int getDexterity()const;
        int getAgility()const;
        int getMoney()const;
        int getExperience()const;
};


class Warrior : public Hero{ 
    public:
        Warrior(string);
        ~Warrior();
};


class Sorcerer : public Hero{
    public:
        Sorcerer(string);
        ~Sorcerer();
};


class Paladin : public Hero{
    public:
        Paladin(string);
        ~Paladin();
};


class Monster : public Living{
    private:
     
        int damage;     // damage it causes
        int defense;    // defense it has
        int attack;     // avoid attack

    public:
        Monster(string, int, int, int);
        ~Monster();

        int getDamage()const;
        int getDefense()const;
        int getAttack()const;
};


class Dragon : public Monster{
    public:
        Dragon(string);
        ~Dragon();
};


class Exoskeleton : public Monster{
    public:
        Exoskeleton(string);
        ~Exoskeleton();
};


class Spirit : public Monster{
    public:
        Spirit(string);
        ~Spirit();
};