#include <iostream>
#include <cstring>
#include <vector>

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


class Item {
    protected:
    string name;
    int price;
    int leastlevel;

    public:
    Item(string name,int price, int leastlevel);
    ~Item();
    string getName()const;
    int getPrice()const;
    int getLeastlevel()const;
    virtual void Print()=0;
};


class Weapon: public Item{
    private:
    int damage;
    int hands;                       //when hands=1 one hand is needed , when hands=2 two hands are needed to use the weapon

    public:
    Weapon(string,int,int,int,int);
    ~Weapon();
    int getDamage()const;
    int getHands()const;
    void Print();
};


class Armor: public Item{
    int defence;             //number of enemy's damage that the armor reduce
    public:
    Armor(string,int,int,int);
    ~Armor();
    int getDefence()const;
    void Print();

};


class Potion: public Item {
    string ability;        //the ability of the hero that the potion increase
    int amount;            // the amount of the raise

    public:
    Potion(string,int,int,string,int);
    ~Potion();
    string getAbility()const;
    int getAmount()const;
    void Print();
};


class Spell: public Item {
    protected:
    int energy;                // energy needed to use the spell
    int maxdamage;
    int mindamage;
    int reduction;            //reduction of enemy's skill
    int rounds;                // the reduction last several rounds

    public:
    Spell(string,int,int,int,int,int,int,int);
    ~Spell();
    int getEnergy()const;
    int getMax()const;
    int getMin()const;
    int getReduction()const;
    int getRounds()const;
    virtual void Print();
};


class Icespell: public Spell {
    public:
    Icespell(string,int,int,int,int,int,int,int);
    ~Icespell();
    void Print();
   
};


class Lightingspell: public Spell {
    public:
    Lightingspell(string,int,int,int,int,int,int,int);
    ~Lightingspell();
    void Print();
   
};


class Firespell: public Spell {
    public:
    Firespell(string,int,int,int,int,int,int,int);
    ~Firespell();
    void Print();
   
};



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