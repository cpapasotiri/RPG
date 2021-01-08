#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

// classes definitions
// item_spell.cpp
class Item;
class Weapon;	
class Armor;	
class Potion;	 
class Spell;	
class IceSpell;	
class FireSpell;	
class LightSpell;

// livings.cpp
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

// grid.cpp
class Grid;
class Square;
class NonAccessible;
class Market;
class Common;

// game.cpp
class Game;


// item_spell.cpp
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
    string ability; //the ability of the hero that the potion increase
    int amount;     // the amount of the raise
    int flag;       //flag=0 not used , flag=1 used

    public:
    Potion(string,int,int,string,int);
    ~Potion();
    string getAbility()const;
    int getAmount()const;
    int getFlag()const;
    void Print();
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
    virtual void Print();
};


class Icespell: public Spell {
    public:
    Icespell(string,int,int,int,int,int,int,int);
    ~Icespell();
    void Print();
   
};


class Firespell: public Spell {
    public:
    Firespell(string,int,int,int,int,int,int,int);
    ~Firespell();
    void Print();
   
};


class Lightingspell: public Spell {
    public:
    Lightingspell(string,int,int,int,int,int,int,int);
    ~Lightingspell();
    void Print();
   
};



// livings.cpp
class Living{
    private:
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
        void changeHealth(int);
};


class Hero : public Living{
    private:
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

        void print()const;

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
        void equip(Weapon*, Weapon*, Armor*);  
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



class Team {                          //αν διαφωνείς με κατι πες
    private:
    Hero** heroes;
    int counter;

    public:
    Team(Hero*, Hero*, Hero*);
    ~Team();

    void print();

    Hero* getHero1()const;
    Hero* getHero2()const;
    Hero* getHero3()const;
    int getCounter()const;

    void joinTeam(Hero*);
    void displayStats()const;
};




// grid.cpp
class Grid{
    private:
        Square* grid [8][8];   // ή κατι τετοιο

    public:
        Grid();
        ~Grid();

        void displayMap();
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
        vector<Weapon> weapons;
        vector<Armor> armors;
        vector<Potion> potions;
        vector<Spell> spells;
        Team* team;

    public:
        Market(vector<Weapon>, vector<Armor>, vector<Potion>, vector<Spell>);
        ~Market();

        void print()const;
        void printMenu();

        void enterTeam(Team*);
        void exitTeam();

        vector<Weapon> getWeapons()const;
        vector<Armor> getArmors()const;
        vector<Potion> getPotions()const;
        vector<Spell> getSpells()const;
        Team* getTeam()const;
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



// game.cpp
class Game{
    private:


    protected:


    public:
        Game();
        ~Game();

};