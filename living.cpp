#include <iostream>
#include <cstring>
#include <time.h>
#include <stdlib.h>
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
	a->defend(dmg);
	
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

int Hero::usePotion(){                  //epistrefei 0 an o iroas den exei kanena potion sto inventory tou
	if(potion.size()==0) {
		cout << "No available potions to use!" << endl;
		return 0;
	}
	for(int j=0; j<potion.size(); j++){
		cout << "Potion " << j+1 << " :" << endl;
		potion.at(j)->print();
	}
	cout << "Whice potion do you want to use?(give number)" << endl;
	int number;
	cin >> number;
	this->use(potion.at(number-1));
	return 1;
}

void Hero::defeat(){
	money=money/2;
}

void Hero::victory(int num){
	money=money + (10*level*num);
	experience=experience + (20*level*num);             //endeiktika noumera an thes allazoun
}

Warrior::Warrior(string n)
: Hero(n, 25, 12, 10){
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
	if(healthPower==0) healthPower=50;
}


Sorcerer::Sorcerer(string n)
: Hero(n, 15, 25, 10){
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
	if(healthPower==0) healthPower=50;
}


Paladin::Paladin(string n)
: Hero(n, 20, 18, 5){
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
	if(healthPower==0) healthPower=50;
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

void Monster::regen(){
	if(healthPower>0) healthPower=healthPower + 5;
	if(healthPower>100) healthPower=100;
	for(int j=0; j<i.size(); j++){
		if(i.at(j)->reduce()==0) {
			i.erase(i.begin() + j);
		}
	}
	for(int j=0; j<f.size(); j++){
		if(f.at(j)->reduce()==0) {
			f.erase(f.begin() + j);
		}
	}
	for(int j=0; j<l.size(); j++){
		if(l.at(j)->reduce()==0) {
			l.erase(l.begin() + j);
		}
	}
}

void Monster::print()
{
	cout <<"Printing monster...." << endl;
}

Dragon::Dragon(string n) 
: Monster(n, 24, 2, 8){
    // cout << "A New Dragon has been created! " << endl;
}

Dragon::~Dragon(){
    cout << "A Dragon to be destroyed! " << endl;
}

void Dragon::print(){
	cout << "Monster type: Dragon" << endl;
	cout << "Name: " << name << endl;
	cout << "Level: " << level << endl;
	cout << "Health: " << healthPower << endl;
	cout << "Damage: " << Monster::getDamage() << endl;
	cout << "Defense: " << Monster::getDefense() << endl;
	cout << "Agility: " << Monster::getAttack() << endl;
}

Exoskeleton::Exoskeleton(string n) 
: Monster(n, 16, 10, 4){
    // cout << "A New Exoskeleton has been created!" << endl;
}

Exoskeleton::~Exoskeleton(){
    cout << "A Exoskeleton to be destroyed!" << endl;
}

void Exoskeleton::print(){ 
	cout << "Monster type: Exoskeleton" << endl;
	cout << "Name: " << name<< endl;
	cout << "Level: " << level << endl;
	cout << "Health: " << healthPower << endl;
	cout << "Damage: " << Monster::getDamage() << endl;
	cout << "Defense: " << Monster::getDefense() << endl;
	cout << "Agility: " << Monster::getAttack() << endl;
}

Spirit::Spirit(string n) 
: Monster(n, 20, 6, 12){
    // cout << "A New Spirit has been created!" << endl;
}

Spirit::~Spirit(){
    cout << "A Spirit to be destroyed!" << endl;
}

void Spirit::print(){
	cout << "Monster type: Spirit" << endl;
	cout << "Name: " << name<< endl;
	cout << "Level: " << level << endl;
	cout << "Health: " << healthPower << endl;
	cout << "Damage: " << Monster::getDamage() << endl;
	cout << "Defense: " << Monster::getDefense() << endl;
	cout << "Agility: " << Monster::getAttack() << endl;
}


Team::Team(int num){
	// cout << "A New team has been created" << endl;
    heroes = new Hero*[num];
    counter = 0;
    location = NULL;
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

void Team::move(Square* square)const{
	location = square;
}

Square* Team::getLocation()const{
	return location;
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

void Hero::equip(){
	cout << "What do you want to equip?(weapon or armor)" << endl;
	string s;
	cin >> s;
	if(s=="weapon"){
		if(weapon.size()==0){
			cout << "No available weapons!" << endl;
			return;
		}
		cout << "Printing heros's weapons" << endl;
		for(int j=0; j<weapon.size(); j++){
			cout << "Weapon 1:" << endl;
			weapon.at(j)->print();
		}
		cout << "Which weapon do you want to equip?(Give its number)" << endl;
		int k;
		cin >> k;
		while(k>weapon.size()){
			cout << "Please give a correct number!" << endl;
			cin>> k;
		}
		cout << "Do you want to use it as a primary or secondary weapon?" << endl;
		cin >> s;
		if(s=="primary"){
			this->equipWeapon(weapon.at(k-1));
		}
		else {
			this->equipSecondaryWeapon(weapon.at(k-1));
		}
	}
	else if(s=="armor"){
		if(armor.size()==0){
			cout << "No available armors!" << endl;
			return;
		}
		cout << "Printing hero's armors" << endl;
		for(int j=0; j<armor.size(); j++){
			cout << "Armor 1:" << endl;
			armor.at(j)->print();
		}
		cout << "Which armor do you want to equip?(Give its number)" << endl;
		int k;
		cin >> k;
		while(k>armor.size()){
			cout << "Please give a correct number!" << endl;
			cin>> k;
		}
		this->equipArmor(armor.at(k-1));
	}
}

void Monster::put(Icespell* a){
	Icespell* w=new Icespell(*a);
	i.push_back(w);
}

void Monster::put(Firespell* a){
	Firespell* w=new Firespell(*a);
	f.push_back(w);
}

void Monster::put(Lightingspell* a){
	Lightingspell* w= new Lightingspell(*a);
	l.push_back(w);
}

void Monster::clear(){
	l.clear();
	f.clear();
	i.clear();
}

void Monster::destroy(Hero* a){
	int temp=damage;
	for(int j=0; j<i.size(); j++){
		temp=temp - (i.at(j)->getReduction());
	}
	if(temp<0) temp=0;                     // nomizo prepei na elegxoume kai ayto 
	a->defend(temp);
}

void Monster::defend(int damage){
	int temp1=attack;
	int temp2=defense;
	for(int j=0; j<f.size(); j++){
		temp2=temp2 - (f.at(j)->getReduction());
	}
	for(int j=0; j<l.size(); j++){
		temp1=temp1 - (l.at(j)->getReduction());
	}
	int v1;
	if(temp1<0) temp1=0;
	if(temp2<0) temp2=0;
	damage=damage - temp2;
	if(damage<0) damage=0;
	v1=rand() % 100;
	if(temp1>v1){
		cout << "The monster avoided the attack" << endl;
		return;
	}
	else{
		healthPower=healthPower - damage ;
	}
}

