#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

// classes definitions
class Item;
class Weapon;	
class Armor;	
class Potion;	 
class Spell;	
class Icespell;	
class Firespell;	
class Lightingspell;



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
    virtual void print()=0;
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
    void print();
};


class Armor: public Item{
    int defence;             //number of enemy's damage that the armor reduce
    
    public:
    Armor(string,int,int,int);
    ~Armor();
    int getDefence()const;
    void print();
};


class Potion: public Item {
    string ability; //the ability of the hero that the potion increase
    int amount;     // the amount of the raise
    int flag;       //flag=0 not used , flag=1 used

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
    ~Spell();
    int getEnergy()const;
    int getMax()const;
    int getMin()const;
    int getReduction()const;
    int getRounds()const;
    virtual void print();
};


class Icespell: public Spell {
    public:
    Icespell(string,int,int,int,int,int,int,int);
    ~Icespell();
    void print();
   
};


class Firespell: public Spell {
    public:
    Firespell(string,int,int,int,int,int,int,int);
    ~Firespell();
    void print();
   
};


class Lightingspell: public Spell {
    public:
    Lightingspell(string,int,int,int,int,int,int,int);
    ~Lightingspell();
    void print();
};
