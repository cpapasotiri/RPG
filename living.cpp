#include <iostream>
#include <cstring>

#include "living.hpp"

using namespace std;

Living::Living(string n){
    // cout << "A New Living has been created! " << endl;
    name = n;
    level = 1;
    healthPower = 100;
    faint = false;
}

Living::~Living(){
    cout << "A Living to be destroyed! " << endl;
    cout << "name: " << name << " level: " << level << " healthPower: " << healthPower << endl; 
}

string Living::getName()const{
    return name;
}

int Living::getLevel()const{
    return level;
}

int Living::getHelthPower()const{
    return healthPower;
}

bool Living::getFaint()const{
    return faint;
}

bool Living::checkHealth(){
    if(healthPower == 0){
        faint = true;
    }
    else{
        faint = false;
    }
    return faint;
}

void Living::changeHealth(int x){
    healthPower += x;
	if(healthPower<0) healthPower=0;    //nomizo prepei na tsekaroume kai afto edo
	if(healthPower>100) healthPower=100;  // kai afto
}


Hero::Hero(string n, int s, int d, int a)
: Living(n){
    // cout << "A New Hero has been created! " << endl;
    magicPower = 50;
    strenght = s;
    dexterity = d;
    agility = a;
    money = 50;
    experience = 0;  
    w1=NULL;
    w2=NULL;
    arm=NULL;
}

Hero::~Hero(){
    cout << "A Hero to be destroyed! " << endl;
    weapon.clear();
    armor.clear();
    potion.clear();
    spell.clear();
}

int Hero::getMagicPower()const{
    return magicPower;
}

int Hero::getStrenght()const{
    return strenght;
}

int Hero::getDexterity()const{
    return dexterity;
}

int Hero::getAgility()const{
    return agility;
}

int Hero::getMoney()const{
    return money;
}

int Hero::getExperience()const{
    return experience;
}

vector<Weapon*> Hero::getWeapons()const{
    return weapon;
}

vector<Armor*>Hero:: getArmors()const{
    return armor;
}

vector<Potion*> Hero::getPotions()const{
    return potion;
}

vector<Spell*>Hero:: getSpells()const{
    return spell;
}

Weapon* Hero::getWeapon1()const{
    return w1;
}

Weapon* Hero::getWeapon2()const{
    return w2;
}

Armor* Hero::getArmor()const{
    return arm;
}

void Hero::checkInventory()const{
    int counter=0;
    cout << Living::getName() << "'s Items are: " << endl;
    for(int j=0; j<weapon.size(); j++){
        counter++;
        cout << "Item " << counter << ":" << endl;
        weapon.at(j)->print();
    }
    for(int j=0; j<armor.size(); j++){
         counter++;
        cout << "Item " << counter << ":" << endl;
        armor.at(j)->print();
    }
    for(int j=0; j<potion.size(); j++){
         counter++;
        cout << "Item " << counter << ":" << endl;
        potion.at(j)->print();
    }
    for(int j=0; j<spell.size(); j++){
        counter++;
        cout << "Item " << counter << ":" << endl ;
        spell.at(j)->print();
    }
	cout << "The Hero is wearing: " << endl;
    cout << "Armor: " ;
	if(arm!=NULL){
		cout << arm->getName() << endl;
	}
	else{
		cout << "None" << endl;
	}
    cout << "Primary Weapon: " ;
	if(w1!=NULL){
		cout << w1->getName() << endl;
	}
	else{
		cout << "None" << endl;
	}
    cout << "Secondary Weapon: " ;
	if(w2!=NULL){
		cout << w2->getName() << endl;
	}
	else{
		cout << "None" << endl;
	}


}

void Hero::buy(Weapon* a){
    if(money<(a->getPrice())) return;
     weapon.push_back(a);
     money=money - (a->getPrice());
}

void Hero::buy(Armor* a){
    if(money<(a->getPrice())) return;
    armor.push_back(a);
     money=money - (a->getPrice());
}

void Hero::buy(Potion* a){
     if(money<(a->getPrice())) return;
    potion.push_back(a);
     money=money - (a->getPrice());
}

void Hero::buy(Spell* a){
    if(money<(a->getPrice())) return;
    spell.push_back(a);
    money=money - (a->getPrice());
}

void Hero::sell(Weapon* a){
    int j=0;
    for(j=0; j<weapon.size(); j++){
            if(weapon.at(j)==a) {
		 weapon.erase(weapon.begin()+j);
   		 money=money + (a->getPrice()/2);        //poleite sti misi timi
		 break;
	    }
    }
   
}

void Hero::sell(Armor* a){
    int j=0;
    for(j=0; j<armor.size(); j++){
            if(armor.at(j)==a) {
		armor.erase(armor.begin()+j);
    		money=money + (a->getPrice()/2);        //poleite sti misi timi
		break;
	    }
		 
    }
   
}

void Hero::sell(Potion* a){
    int j=0;
    for(j=0; j<potion.size(); j++){
            if(potion.at(j)==a) {
		potion.erase(potion.begin()+j);
    		money=money + (a->getPrice()/2);        //poleite sti misi timi
		break;
	    }
	}
    }
   

void Hero::sell(Spell* a){
    int j=0;
    for(j=0; j<spell.size(); j++){
            if(spell.at(j)==a){
		 spell.erase(spell.begin()+j);
   		 money=money + (a->getPrice()/2);        //poleite sti misi timi
		 break;
	    }
    }
   
}

void Hero::use(Potion* a){
    if(a->getAbility()=="magicPower"){
        magicPower=magicPower + (a->getAmount());
    }
    if(a->getAbility()=="strength"){
        strenght=strenght + (a->getAmount());
    }
    if(a->getAbility()=="dexterity"){
        dexterity=dexterity + (a->getAmount());
    }
    if(a->getAbility()=="agility"){
        agility=agility + (a->getAmount());
    }
    int j=0;
    for(j=0; j<potion.size(); j++){
            if(potion.at(j)==a) break;
    }
    potion.erase(potion.begin()+j);

}


void Hero::regen(){
	if(healthPower>0){
	healthPower=healthPower + 5;
	magicPower=magicPower + 5;
	if(magicPower>50) magicPower=50;        
	if(healthPower>100) healthPower=100;
}
}

void Hero::equipArmor(Armor* a){
	arm=a;
}

void Hero::equipWeapon(Weapon* a){
	if(w2!=NULL){
		if(a->getHands()==2){
			w2=NULL;
			w1=a;
		}
		else {
			w1=a;
		}
	}
	else {
		w1=a;
	}
}

void Hero::equipSecondaryWeapon(Weapon* a){
	if(a->getHands()==1 ){
		if(w1!=NULL){
			if(w1->getHands()==2) {
				cout << "Cannot equip this weapon" << endl;
			}
			else{
				w2=a;
			}
		}
	}
	else {
		cout << "Cannot equip this weapon" << endl;
	}
}

void Hero::defend(int damage){                 //otan dexetai epithsei apo teras
	int v1;
	v1=rand() % 100  ;   // 0-99
	if(v1<agility){                              //analoga me to agility borei na apofigei kapoia epithesi
		cout << "Hero " << name << " avoided the attack" << endl;
	}
	else {
		int temp=0;
		if(arm!=NULL) temp=arm->getDefence();
		healthPower= healthPower - (damage - temp);
	}
}

void Hero::attack(Monster* a){              //kanoniki epithesi se teras
	int dmg=strenght;
	if(w1!=NULL) dmg=dmg + w1->getDamage();
	if(w2!=NULL) dmg=dmg + w2 ->getDamage();
	a->changeHealth(-(dmg-a->getDefense()));
	
}

void Hero::castSpell(Monster* a){
	cout << "Printing hero's spells.." << endl;
	for(int j=0; j<spell.size(); j++){
		cout << "Spell " << j+1 <<": " <<  endl;
		spell.at(j)->print();
	}
	cout << "Which spell do you want to use?(give its number)" << endl;
	int w;
	cin >> w;
	Spell* ptr=spell[w-1];
	if(ptr->getEnergy()<magicPower){
		ptr->cast(dexterity,a);
		
	}
	else {
		cout << "Not enough magic power" << endl;    //prepei na doume ti tha kanoume se afti ti periptosi
	}
}

Warrior::Warrior(string n)
: Hero(n, 8, 5, 7){
    // cout << "A New Warrior has been created! " << endl;
}

Warrior::~Warrior(){
    cout << "A Warrior to be destroyed! " << endl;
}

void Warrior::print(){
	cout << "Category: Warrior" << endl;
	cout << "Name= " << Living::name << endl
         << "level = " << Living::level << endl
         << "healthPower = " << Living::getHelthPower() << endl
         << "magicPower = " << magicPower << endl 
         << "strenght = " << strenght << endl
         << "dexterity = " << dexterity << endl
         << "agility = " << agility << endl
         << "money = " << money << endl
         << "experience = " << experience << endl;
} 

void Warrior::levelUp(){
	if(level<10){
		int temp=level*100;
		if(experience>temp){
			level++;
			strenght=strenght + 3;
			agility=agility + 2;
			dexterity++;
			experience=experience - temp;
			healthPower=100;                     
			magicPower=50;
		}
		else {
			return;
		}
	}
	else {
		cout << "Hero " << name << " is at max level" << endl;
	}
}


Sorcerer::Sorcerer(string n)
: Hero(n, 4, 7, 8){
    // cout << "A New Sorcerer has been created! " << endl;
}

Sorcerer::~Sorcerer(){
    cout << "A Sorcerer to be destroyed! " << endl;
}

void Sorcerer::print(){
	cout << "Category: Sorcerer" << endl;
	cout << "Name= " << Living::getName() << endl
         << "level = " << Living::getLevel() << endl
         << "healthPower = " << Living::getHelthPower() << endl
         << "magicPower = " << magicPower << endl 
         << "strenght = " << strenght << endl
         << "dexterity = " << dexterity << endl
         << "agility = " << agility << endl
         << "money = " << money << endl
         << "experience = " << experience << endl;
}

void Sorcerer::levelUp(){
	if(level<10){
		int temp=level*100;
		if(experience>temp){
			level++;
			strenght=strenght + 1;
			agility=agility + 2;
			dexterity=dexterity + 3;
			experience=experience - temp;
			healthPower=100;                     
			magicPower=50;
		}
		else {
			return;
		}
	}
	else {
		cout << "Hero " << name << " is at max level" << endl;
	}
}


Paladin::Paladin(string n)
: Hero(n, 7, 9, 3){
    // cout << "A New Paladin has been created! " << endl;
}

Paladin::~Paladin(){
    cout << "A Paladin to be destroyed! " << endl;
}

void Paladin::print(){
	cout << "Category: Paladin" << endl;
	cout << "Name= " << Living::getName() << endl
         << "level = " << Living::getLevel() << endl
         << "healthPower = " << Living::getHelthPower() << endl
         << "magicPower = " << magicPower << endl 
         << "strenght = " << strenght << endl
         << "dexterity = " << dexterity << endl
         << "agility = " << agility << endl
         << "money = " << money << endl
         << "experience = " << experience << endl;
}

void Paladin::levelUp(){
	if(level<10){
		int temp=level*100;
		if(experience>temp){
			level++;
			strenght=strenght + 2;
			agility=agility + 1;
			dexterity=dexterity +3;
			experience=experience - temp;
			healthPower=100;                     
			magicPower=50;
		}
		else {
			return;
		}
	}
	else {
		cout << "Hero " << name << " is at max level" << endl;
	}
}


Monster::Monster(string n, int da, int de, int a)
: Living(n){
    // cout << "A New Monster has been created! " << endl;
    damage = da;
    defense = de;
    attack = a;
}

Monster::~Monster(){
    cout << "A Monster to be destroyed! " << endl;
}

int Monster::getDamage()const{
    return damage;
}

int Monster::getDefense()const{
    return defense;
}

int Monster::getAttack()const{
    return attack;
}

void Monster::setMonster(int a,int b,int c){
	damage=a;
	defense=b;
	attack=c;
}

Dragon::Dragon(string n) 
: Monster(n, 9, 5, 5){
    // cout << "A New Dragon has been created! " << endl;
}

Dragon::~Dragon(){
    cout << "A Dragon to be destroyed! " << endl;
}


Exoskeleton::Exoskeleton(string n) 
: Monster(n, 5, 9, 5){
    // cout << "A New Exoskeleton has been created!" << endl;
}

Exoskeleton::~Exoskeleton(){
    cout << "A Exoskeleton to be destroyed!" << endl;
}


Spirit::Spirit(string n) 
: Monster(n, 5, 5, 9){
    // cout << "A New Spirit has been created!" << endl;
}

Spirit::~Spirit(){
    cout << "A Spirit to be destroyed!" << endl;
}



Team::Team(int num){
    heroes=new Hero*[num];
    counter=0;
    // cout << "A New team has been created" << endl;
}

Team::~Team(){
    delete[] heroes;
    cout << "A Team to be destroyed" << endl;
}

void Team::print(){
    cout << "Team:" << endl;
    for(int i = 0; i < counter; i++){
        cout << "Hero " << i+1 << ":" << endl;
        heroes[i]->print();
    }
}

Hero** Team::getHeroes()const{
    return heroes;
}

int Team::getCounter()const{
    return counter;
}

void Team::joinTeam(Hero* a){
    heroes[counter++]=a;
}

void Team::displayStats()const{
    for(int j=0; j<counter; j++){
        cout << "Hero " << j+1 << ":" << endl;
        heroes[j]->print();
    }
}
