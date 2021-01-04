#include <iostream>
#include <cstring>

using namespace std;

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

Item::Item(string name,int price,int leastlevel){
    this->name=name;
    this->price=price;
    this->leastlevel=leastlevel;
    cout << "A new Item has been created " << endl;
}

Item::~Item(){
    cout << "An Item to be destroyed " << endl;
}

string Item::getName()const{
    return name;
}

int Item::getPrice()const{
    return price;
}

int Item::getLeastlevel()const{
    return leastlevel;
}

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

Weapon::Weapon(string name,int price,int leastlevel,int dmg,int i):
Item(name,price,leastlevel)
{
    damage=dmg;
    hands=i;
    cout<< "A new Weapon has been created" << endl;
}

Weapon::~Weapon(){
    cout << "A Weapon to be destroyed" << endl;
}

int Weapon::getDamage()const{
    return damage;
}

int Weapon::getHands()const{
    return hands;
}

void Weapon::Print(){
    cout << "Name: " << name <<endl;
    cout << "Price: " << price << endl;
    cout << "Minimum level: " << leastlevel << endl;
    cout << "Damage: " << damage << endl;
    cout << "Hands: " << hands << endl;
}

class Armor: public Item{
    int defence;             //number of enemy's damage that the armor reduce
    public:
    Armor(string,int,int,int);
    ~Armor();
    int getDefence()const;
    void Print();

};

Armor::Armor(string name,int price, int leastlevel,int defence):
Item(name,price,leastlevel)
{   
    this->defence=defence;
    cout << "A new armor has been created" << endl;
}

Armor::~Armor(){
    cout <<"An armor to be destroyed" << endl;
}

int Armor::getDefence()const{
    return defence;
}

void Armor::Print(){
    cout << "Name: " << name <<endl;
    cout << "Price: " << price << endl;
    cout << "Minimum level: " << leastlevel << endl;
    cout << "Defemce: " << defence << endl;
}

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

Potion::Potion(string name,int price,int leastlevel,string abil,int amount):
Item(name,price,leastlevel)
{
    ability=abil;
    this->amount=amount;
    cout << "A new Potion has been created" << endl ;
}

Potion::~Potion(){
    cout << "A potion to be destroyed" << endl;
}

string Potion::getAbility()const{
    return ability;
}

int Potion::getAmount()const{
    return amount;
}

void Potion::Print(){
    cout << "Name: " << name <<endl;
    cout << "Price: " << price << endl;
    cout << "Minimum level: " << leastlevel << endl;
    cout << "Ability: The " << ability << " is increased by " << amount << endl;
}

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

Spell::Spell(string name,int price,int leastlevel,int en,int min,int max,int a,int b):
Item(name,price,leastlevel)
{
    energy=en;
    maxdamage=max;
    mindamage=min;
    reduction=a;
    rounds=b;
    cout << "A new Spell has been created" << endl;
}

Spell::~Spell(){
    cout << "A spell to be destroyed" << endl;
} 

int Spell::getEnergy()const{
    return energy;
}

int Spell::getMax()const{
    return maxdamage;
}

int Spell::getMin()const{
    return mindamage;
}

int Spell::getReduction()const{
    return reduction;
}

int Spell::getRounds()const{
    return rounds;
}

void Spell::Print(){
     cout << "Name: " << name <<endl;
    cout << "Price: " << price << endl;
    cout << "Minimum level: " << leastlevel << endl;
    cout << "Energy needed: " << energy << endl;
    cout << "Range of damage: " << mindamage << "-" << maxdamage << endl;
    
}

class Icespell: public Spell {
  

    public:
    Icespell(string,int,int,int,int,int,int,int);
    ~Icespell();
    void Print();
   
};

Icespell::Icespell(string name,int price,int leastlevel,int energy,int min,int max, int a, int b):
Spell(name,price,leastlevel,energy,min,max,a,b)
{
   
    cout << "A new icespell has been created" << endl;
}

Icespell::~Icespell(){
    cout << "An icespell to be destroyed" << endl;
}

void Icespell::Print(){
    Spell::Print();
    cout << "Category: Ice spell "<< endl;
    cout << "Spell effect: " << "It reduces enemy's damage by " << reduction << " for " << rounds << " rounds" << endl;
}

class Lightingspell: public Spell {
  

    public:
    Lightingspell(string,int,int,int,int,int,int,int);
    ~Lightingspell();
    void Print();
   
};

Lightingspell::Lightingspell(string name,int price,int leastlevel,int energy,int min,int max, int a, int b):
Spell(name,price,leastlevel,energy,min,max,a,b)
{
   
    cout << "A new Lightingspell has been created" << endl;
}

Lightingspell::~Lightingspell(){
    cout << "An Lightingspell to be destroyed" << endl;
}

void Lightingspell::Print(){
    Spell::Print();
    cout << "Category: Lighting spell "<< endl;
    cout << "Spell effect: " << "It reduces the chance of the opponent avoiding an attack by " << reduction << "% for " << rounds << " rounds" << endl;
}


class Firespell: public Spell {
  

    public:
    Firespell(string,int,int,int,int,int,int,int);
    ~Firespell();
    void Print();
   
};

Firespell::Firespell(string name,int price,int leastlevel,int energy,int min,int max, int a, int b):
Spell(name,price,leastlevel,energy,min,max,a,b)
{
   
    cout << "A new icespell has been created" << endl;
}

Firespell::~Firespell(){
    cout << "An icespell to be destroyed" << endl;
}

void Firespell::Print(){
    Spell::Print();
    cout << "Category: Fire spell "<< endl;
    cout << "Spell effect: " << "It reduces enemy's defence by " << reduction << " for " << rounds << " rounds" << endl;
}
