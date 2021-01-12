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
class Icespell;	
class Firespell;	
class Lightingspell;

// living.cpp
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



// livings.cpp
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
        void buy(Weapon*);  // πρεπει να ελεγχουν και αν υπαρχει ήδη στο vector το αντικειμενο που παιρνουν ως ορισμα αρα πρεπει να επιστρεφουν και bool  
        void buy(Armor*);   // πρεπει να ελεγχουν και αν υπαρχει ήδη στο vector το αντικειμενο που παιρνουν ως ορισμα αρα πρεπει να επιστρεφουν και bool
        void buy(Potion*);  // πρεπει να ελεγχουν και αν υπαρχει ήδη στο vector το αντικειμενο που παιρνουν ως ορισμα αρα πρεπει να επιστρεφουν και bool
        void buy(Spell*);   // πρεπει να ελεγχουν και αν υπαρχει ήδη στο vector το αντικειμενο που παιρνουν ως ορισμα αρα πρεπει να επιστρεφουν και bool
        void sell(Weapon*); // πρεπει να ελεγχουν και αν υπαρχει ήδη στο vector το αντικειμενο που παιρνουν ως ορισμα αρα πρεπει να επιστρεφουν και bool
        void sell(Armor*);  // πρεπει να ελεγχουν και αν υπαρχει ήδη στο vector το αντικειμενο που παιρνουν ως ορισμα αρα πρεπει να επιστρεφουν και bool
        void sell(Potion*); // πρεπει να ελεγχουν και αν υπαρχει ήδη στο vector το αντικειμενο που παιρνουν ως ορισμα αρα πρεπει να επιστρεφουν και bool
        void sell(Spell*);  // πρεπει να ελεγχουν και αν υπαρχει ήδη στο vector το αντικειμενο που παιρνουν ως ορισμα αρα πρεπει να επιστρεφουν και bool
        void use(Potion*);  
        void equip(Weapon*, Weapon*, Armor*);  
        // void attack(Monster* a);
        //void defend(int damage);
        void regen();
        //void levelUp();
};


class Warrior : public Hero{ 
    public:
        Warrior(string);
        ~Warrior();
        void print();
};


class Sorcerer : public Hero{
    public:
        Sorcerer(string);
        ~Sorcerer();
        void print();
};


class Paladin : public Hero{
    public:
        Paladin(string);
        ~Paladin();
        void print();
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



class Team {        // Team with 1-3 heroes 
    private:
    Hero** heroes;
    int counter;
    // Square* location;   // θα δειχνει σε μια θεση προκαθορισμενη μεσα στον κόσμο

    public:
    Team(int);
    ~Team();

    void print();

    Hero** getHeroes()const;
    int getCounter()const;
    // Square* setLocation()const;
    // Square* getLocation()const;

    void joinTeam(Hero*);
    void displayStats()const;
};




// grid.cpp
class Grid{
    private:
        vector<Hero*> heroes;
        vector<Monster*> monsters;
        // Square* grid [8][8];   // ή κατι τετοιο

    public:
        Grid(vector<Hero*>, vector<Monster*>, vector<Weapon*>, vector<Armor*>, vector<Potion*>, vector<Spell*>);
        ~Grid();

        void displayMap();

        vector<Hero*> getHeroes()const;
        vector<Monster*> getMonsters()const;
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
        vector<Weapon*> weapons;
        vector<Armor*> armors;
        vector<Potion*> potions;
        vector<Spell*> spells;
        Team* team;
        int items;

    public:
        Market(vector<Weapon*>, vector<Armor*>, vector<Potion*>, vector<Spell*>);
        ~Market();

        void print();
        void menu();
        void buy(Hero*, int);
        void sell(Hero*, int);
        Hero* selectHero();
        void help();

        void enterTeam(Team*);
        void exitTeam();

        vector<Weapon*> getWeapons()const;
        vector<Armor*> getArmors()const;
        vector<Potion*> getPotions()const;
        vector<Spell*> getSpells()const;
        Team* getTeam()const;
        int getItems()const;
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
        void move();        // συνάρτηση κινησης 
        void buy();         // αγορα item & αοποθηκευση του στο vector του ηρωα
        void sell();        // πωληση αντικειμένου που εχει αγοράσει ήδη ο ηρωας 
        void help();        // συνάρτηση εκτυπωσης συντομη ςπεριγραφήςε καθε εντολής που μπορει να δωσει ο παικτης
        void startGame();
};
