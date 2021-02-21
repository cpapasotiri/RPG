#ifndef ITEM_SPELL_HPP
#define ITEM_SPELL_HPP
#include "grid.hpp"
#include <cstring>

using namespace std;

// classes definitions
// item.hpp
class Item;
class Weapon;	
class Armor;	
class Potion;	 
class Spell;	
class Icespell;	
class Firespell;	
class Lightingspell;

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

// grid.hpp
class Grid;
class Square;
class NonAccessible;
class Market;
class Common;

class Item{
    protected:
        string name;
        int price;
        int leastlevel;

    public:
        Item(string name,int price, int leastlevel);
        virtual ~Item();
        string getName()const;
        int getPrice()const;
        int getLeastlevel()const;
        virtual void print()=0;
};


class Weapon: public Item{
    private:
        int damage;
        int hands;          //when hands=1 one hand is needed , when hands=2 two hands are needed to use the weapon

    public:
        Weapon(string,int,int,int,int);
        ~Weapon();
        int getDamage()const;
        int getHands()const;
        void print();
};  


class Armor: public Item{
    private:
        int defence;             //number of enemy's damage that the armor reduce
    
    public:
        Armor(string,int,int,int);
        ~Armor();
        int getDefence()const;
        void print();
};


class Potion: public Item {
    private:
        string ability; //the ability of the hero that the potion increase
        int amount;     // the amount of the raise
       

    public:
        Potion(string,int,int,string,int);
        ~Potion();
        string getAbility()const;
        int getAmount()const;
        int getFlag()const;
        void print();
};


class Spell: public Item {
    protected:
        int energy;      // energy needed to use the spell
        int maxdamage;
        int mindamage;
        int reduction;  //reduction of enemy's skill
        int rounds;     // the reduction last several rounds

    public:
        Spell(string,int,int,int,int,int,int,int);
        virtual ~Spell();
        int getEnergy()const;
        int getMax()const;
        int getMin()const;
        int getReduction()const;
        int getRounds()const;
        int reduce();
        virtual void print();
        virtual void cast(int,Monster*);
};


class Icespell: public Spell {
    public:
        Icespell(string,int,int,int,int,int,int,int);
        Icespell(const Icespell &p2);
        ~Icespell();
        void print();
        void cast(int,Monster*);
};


class Firespell: public Spell {
    public:
        Firespell(string,int,int,int,int,int,int,int);
        Firespell(const Firespell &p2);    
        ~Firespell();
        void print();
        void cast(int,Monster*);   
};


class Lightingspell: public Spell {
    public:
        Lightingspell(string,int,int,int,int,int,int,int);
        Lightingspell(const Lightingspell &p2);
        ~Lightingspell();
        void print();
        void cast(int,Monster*);
};


#endif
