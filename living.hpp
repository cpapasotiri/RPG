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
class Team;

class Item;
class Weapon;	
class Armor;	
class Potion;	 
class Spell;	
class Icespell;	
class Firespell;	
class Lightingspell;




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
        void attack(Monster* a);
        void defend(int damage);
        void regen();
        void equipArmor(Armor* a);
        void equipWeapon(Weapon* a);
        void equipSecondaryWeapon(Weapon* a);
        virtual void levelUp()=0;
        void castSpell(Monster* a);
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
        void setMonster(int, int, int);
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
    virtual void cast(int,Monster*);
};


class Icespell: public Spell {
    public:
    Icespell(string,int,int,int,int,int,int,int);
    ~Icespell();
    void print();
    void cast(int,Monster*);
   
};


class Firespell: public Spell {
    public:
    Firespell(string,int,int,int,int,int,int,int);
    ~Firespell();
    void print();
    void cast(int,Monster*);
   
};


class Lightingspell: public Spell {
    public:
    Lightingspell(string,int,int,int,int,int,int,int);
    ~Lightingspell();
    void print();
    void cast(int,Monster*);
};
