#include <iostream>
#include <cstring>
#include <vector>

#include "item_spell.hpp"

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
        void attack(Monster* a);
        void defend(int damage);
        void regen();
        void levelUp();
        void equipArmor(Armor* a);
        void equipWeapon(Weapon* a);
        void equipSecondaryWeapon(Weapon* a);
        virtual void levelUp()=0;
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
        void setMonster();
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
