#include <iostream>
#include <cstring>
#include <time.h>
#include <stdlib.h>
#include "living.hpp"


using namespace std;

Living::Living(string n){
    name = n;
    level = 1;
    healthPower = 100;
    faint = false;
}

Living::~Living(){}

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
	if(healthPower<0){ 
		healthPower=0;
	}
	if(healthPower>100){ 
		healthPower=100;
	}	
}


Hero::Hero(string n, int s, int d, int a)
: Living(n){
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
    for(int j=0; j<potion.size(); j++){
    	potion[j];
	}
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
		cout << endl;
    }
    for(int j=0; j<armor.size(); j++){
        counter++;
        cout << "Item " << counter << ":" << endl;
        armor.at(j)->print();
		cout << endl;
    }
    for(int j=0; j<potion.size(); j++){
        counter++;
        cout << "Item " << counter << ":" << endl;
        potion.at(j)->print();
		cout << endl;
    }
    for(int j=0; j<spell.size(); j++){
        counter++;
        cout << "Item " << counter << ":" << endl ;
        spell.at(j)->print();
		cout << endl;
    }
	cout << "The Hero is wearing: " << endl << endl;
    cout << "Armor: ";
	if(arm!=NULL){
		cout << arm->getName() << endl;
	}
	else{
		cout << "None" << endl;
	}
    cout  << endl << "Primary Weapon: ";
	if(w1!=NULL){
		cout << w1->getName() << endl;
	}
	else{
		cout << "None" << endl;
	}
    cout << endl << "Secondary Weapon: ";
	if(w2!=NULL){
		cout << w2->getName() << endl;
	}
	else{
		cout << "None" << endl;
	}
}

void Hero::buy(Weapon* a){
    if(searchWeapon(a)==1){
		cout << "Already bought" << endl;
		return;
	}
    if(money<(a->getPrice())){
    	cout << this->name << " cannot afford this item" << endl;
		return;
	}
	if(this->level< a->getLeastlevel()){
		cout << "Not enough experience to buy this item" << endl;
		return;
	}
    weapon.push_back(a);
    money=money - (a->getPrice());
}

void Hero::buy(Armor* a){
	cout << money << "--" << a->getPrice() << endl;
    if(searchArmor(a)==1){
		cout << "Already bought" << endl;
		return;
	}
    if(money<(a->getPrice())){
    	cout << this->name << " cannot afford this item" << endl;
		return;
	}
		if(this->level< a->getLeastlevel()){
		cout << "Not enough experience to buy this item" << endl;
		return;
	}
    armor.push_back(a);
    money=money - (a->getPrice());
}

void Hero::buy(Potion* a){
    if(this->level< a->getLeastlevel()){
		cout << "Not enough experience to buy this item" << endl;
		return;
	}
    if(money<(a->getPrice())){ 
    	cout << this->name << " cannot afford this item" << endl;
		return;
	}
	Potion* ptr= new Potion(a->getName(),a->getPrice(),a->getLeastlevel(),a->getAbility(),a->getAmount());
	potion.push_back(ptr);
    money=money - (a->getPrice());
}

void Hero::buy(Spell* a){
    if(this->level< a->getLeastlevel()){
		cout << "Not enough experience to buy this spell" << endl;
		return;
	}
    if(money<(a->getPrice())){
    		cout << this->name << " cannot afford this spell" << endl;
		return;
	}
    spell.push_back(a);
    money=money - (a->getPrice());
}

void Hero::sell(Weapon* a){
    for(int j=0; j<weapon.size(); j++){
		if(weapon.at(j)==a) {
			weapon.erase(weapon.begin()+j);
   			money=money + (a->getPrice()/2);        //poleite sti misi timi
			break;
	    }
    }
}

void Hero::sell(Armor* a){
    for(int j=0; j<armor.size(); j++){
        if(armor.at(j)==a) {
			armor.erase(armor.begin()+j);
    		money=money + (a->getPrice()/2);        //poleite sti misi timi
			break;
	    }
    }
}

void Hero::sell(Potion* a){
    int j=0;
    Potion* ptr;
    for(j=0; j<potion.size(); j++){
        if(potion.at(j)==a){
        	ptr=potion.at(j);
			potion.erase(potion.begin()+j);
    		money=money + (a->getPrice()/2);        //poleite sti misi timi
			break;
	    }
	}
	delete ptr;
}
   

void Hero::sell(Spell* a){
    for(int j=0; j<spell.size(); j++){
		if(spell.at(j)==a){
			spell.erase(spell.begin()+j);
   			money=money + (a->getPrice()/2);        //poleite sti misi timi
			break;
	    }
    }
}

void Hero::sellItem(){
	cout << "What do you want to sell? (weapon/armor/potion/spell)" << endl;
	string item;
	cin>>item;
	int k;
	if(item=="weapon"){
		if(weapon.size()==0){
			cout << "No available weapons for sale!!" << endl;
			return;
		}
		for(int j=0; j<weapon.size(); j++){
			cout << endl << "Weapon " << j+1 << " :" << endl;
			weapon.at(j)->print();
			cout << endl;
		}
		cout << "Choose by giving its number(give 0 if you want to exit)" << endl;
		cin >> k;
		if(k<=0) 
			return;
		if(w1==weapon.at(k-1)){
			w1=NULL;
		}
		if(w2==weapon.at(k-1)){
			w2=NULL;
		}
		sell(weapon.at(k-1));
	}
	else if(item=="armor"){
		if(armor.size()==0){
			cout << "No available armors for sale!!" << endl;
			return;
		}
		for(int j=0; j<armor.size(); j++){
			cout << endl << "Armor " << j+1 << " :" << endl;
			armor.at(j)->print();
			cout << endl;
		}
		cout << "Choose by giving its number(give 0 if you want to exit)" << endl;
		cin >> k;
		if(k<=0) 
			return;
		if(arm==armor.at(k-1)){
			arm=NULL;
		}
		sell(armor.at(k-1));
	}
	else if(item=="potion"){
		if(potion.size()==0){
			cout << "No available potions for sale!!" << endl;
			return;
		}
		for(int j=0; j<potion.size(); j++){
			cout << endl << "Potion " << j+1 << " :" << endl;
			potion.at(j)->print();
			cout << endl;
		}
		cout << "Choose by giving its number(give 0 if you want to exit)" << endl;
		cin >> k;
		if(k<=0) 
			return;
		sell(potion.at(k-1));
	}
	else if(item=="spell"){
		if(spell.size()==0){
			cout << "No available spells for sale!!" << endl;
			return;
		}
		for(int j=0; j<spell.size(); j++){
			cout << endl << "Spell " << j+1 << " :" << endl;
			spell.at(j)->print();
			cout << endl;
		}
		cout << "Choose by giving its number(give 0 if you want to exit)" << endl;
		cin >> k;
		if(k<=0) 
			return;
		sell(spell.at(k-1));
	}
	else {
		cout << "Wrong instruction!" << endl;
	}
}

void Hero::use(Potion* a){
    if(a->getAbility()=="healthPower"){
		this->healthPower=healthPower + a->getAmount();
		if(healthPower>100) 
			healthPower=100;
	}
    else if(a->getAbility()=="magicPower"){
        magicPower=magicPower + (a->getAmount());
        if(magicPower>50) 
			magicPower=50;
    }
    else if(a->getAbility()=="strength"){
        strenght=strenght + (a->getAmount());
    }
    else {
        dexterity=dexterity + (a->getAmount());
    }
    int j=0;
    for(j=0; j<potion.size(); j++){
        if(potion.at(j)==a){
			break;
		}
    }
    Potion* ptr=potion.at(j);	// giati xreiazetai ayth h grammi??
    potion.erase(potion.begin()+j);
	delete ptr;
}


void Hero::regen(){
	if(healthPower>0){
		healthPower=healthPower + 4;
		magicPower=magicPower + 2;
		if(magicPower>50){
			magicPower=50;
		}        
		if(healthPower>100){
			healthPower=100;
		}
	}
}

void Hero::equipArmor(Armor* a){
	arm=a;
}

void Hero::equipWeapon(Weapon* a){
	if(w1==a){
		cout << "Already equipped" << endl << endl;
		return;
	}
	if(w2==a){
		w2=NULL;
		w1=a;
		return;
	}
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
	if(w2==a){
		cout <<"Already equipped" << endl << endl;
		return;
	}
	if(w1==a){
		w1=NULL;
		w2=a;
	}
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

void Hero::equip(){
	cout << "Do you want to equip a weapon or an armor?" << endl;
	string temp;
	cin >> temp;
	if(temp=="weapon") {
		if(weapon.size()==0) {
			cout << "No available weapons" << endl;
			return;
		}
		cout << "Printing hero's weapons..." << endl << endl;
		Weapon* ptr=this->printWeapons();
		if(ptr->getHands()==2){
			this->equipWeapon(ptr);
		}
		else {
			cout << "Do you want to use it as a primary or secondary weapon?" << endl;
			string temp2;
			cin >> temp2;
			if(temp2=="primary"){
				equipWeapon(ptr);
			}
			else if(temp2=="secondary"){
				this->equipSecondaryWeapon(ptr);
			}
			else {
				cout << "Wrong instruction" << endl;
			}
		}
		
	}
	else if(temp=="armor"){
		if(armor.size()==0){
			cout << "No available armors" << endl;
			return;
		}
		cout << "Printing hero's armors..." << endl << endl;
		Armor* ptr=this->printArmor();
		this->equipArmor(ptr);
	}
}

void Hero::defend(int damage){                 //otan dexetai epithsei apo teras
	int v1;
	v1=rand() % 100  ;   // 0-99
	if(v1<agility){                              //analoga me to agility borei na apofigei kapoia epithesi
		cout << "Hero " << name << " avoided the attack" << endl;
	}
	else{
		int temp=0;
		if(arm!=NULL){
			temp=arm->getDefence();
		}
		healthPower= healthPower - (damage - temp);
	}
}

void Hero::attack(Monster* a){              //kanoniki epithesi se teras
	int dmg=strenght;
	if(w1!=NULL){
		dmg=dmg + w1->getDamage();
	}
	if(w2!=NULL){
		dmg=dmg + w2 ->getDamage();
	}
	a->defend(dmg);
}

void Hero::castSpell(Monster* a){
	if(spell.size()==0) {
		cout << "No spells to use!" << endl;
		this->attack(a);
		return;
	}
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
		magicPower=magicPower - ptr->getEnergy();
		ptr->cast(dexterity,a);
	}
	else {
		cout << "Not enough magic power" << endl;    
		this->attack(a);      // kanoume kanoniki epithesi sto monster
		return;
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
	while(number<=0 || number>potion.size()){
		cout << "Give a correct number!" << endl;
		cin>> number;
	}
	this->use(potion.at(number-1));
	return 1;
}

void Hero::victory(int num){
	money=money + (20*level*num);
	experience=experience + (40*level*num);             //endeiktika noumera an thes allazoun
}

void Hero::defeat(){
	money=money/2;
}

Armor* Hero::printArmor(){
	for(int j=0; j<armor.size(); j++){
		cout << "Armor " <<j+1 << ":" <<  endl;
		armor.at(j)->print();
	}
	cout << endl << "Choose an armor!(by giving its number)" << endl;
	int temp;
	cin >> temp;
	while(temp<=0 || temp>armor.size()){
		cout << "Give a correct number!" << endl;
		cin >>temp;
	}
	
	return armor.at(temp-1);
}

Weapon* Hero::printWeapons(){
	for(int j=0; j<weapon.size(); j++){
		cout << "Weapon " <<j+1 << ":" <<  endl;
		weapon.at(j)->print();
	}
	cout << endl << "Choose a weapon!(by giving its number)" << endl;
	int temp;
	cin >> temp;
	while(temp<=0 || temp>weapon.size()){
		cout << "Give a correct number!" << endl;
		cin >>temp;
	}
	
	return weapon.at(temp-1);
}

int Hero::searchWeapon(Weapon* a){       //return 1 an iparxei sto inventory
	for(int j=0; j<weapon.size(); j++){
		if(weapon.at(j)==a) 
			return 1;
	}
	return 0;
}

int Hero::searchArmor(Armor* a){        //return 1 an iparxei sto inventory
	for(int j=0; j<armor.size(); j++){
		if(armor.at(j)==a) 
			return 1;
	}
	return 0;
}


Warrior::Warrior(string n)
: Hero(n, 50, 20, 10){}

Warrior::~Warrior(){}

void Warrior::print(){
	cout << "Category: Warrior" << endl;
	cout << "Name: " << Living::name << endl;
    cout << "level: " << Living::level << endl;
    cout << "healthPower: " << Living::getHelthPower() << endl;
    cout << "magicPower: " << magicPower << endl ;
    cout << "strenght: " << strenght << endl;
    cout << "dexterity: " << dexterity << endl;
    cout << "agility: " << agility << endl;
    cout << "money: " << money << endl;
    cout << "experience: " << experience << endl << endl;
} 

void Warrior::levelUp(){
	if(level<10){
		int temp=level*100;
		while(experience>temp){
			level++;
			strenght=strenght + 4;
			agility=agility + 2;
			dexterity++;
			experience=experience - temp;
			healthPower=100;                     
			magicPower=50;
			temp=level*100;
		}
		
	}
	else {
		cout << "Hero " << name << " is at max level" << endl;
	}
	if(healthPower<=0){
		healthPower=50;
	}
}


Sorcerer::Sorcerer(string n)
: Hero(n, 30, 40, 10){}

Sorcerer::~Sorcerer(){}

void Sorcerer::print(){
	cout << "Category: Sorcerer" << endl;
	cout << "Name: " << Living::getName() << endl;
	cout << "level: " << Living::getLevel() << endl;
	cout << "healthPower: " << Living::getHelthPower() << endl;
	cout << "magicPower: " << magicPower << endl ;
	cout << "strenght: " << strenght << endl;
	cout << "dexterity: " << dexterity << endl;
	cout << "agility: " << agility << endl;
	cout << "money: " << money << endl;
	cout << "experience: " << experience << endl << endl;
}

void Sorcerer::levelUp(){
	if(level<10){
		int temp=level*100;
		while(experience>temp){
			level++;
			strenght=strenght + 2;
			agility=agility + 2;
			dexterity=dexterity + 4;
			experience=experience - temp;
			healthPower=100;                     
			magicPower=50;
			temp=level*100;
		}
	}
	else {
		cout << "Hero " << name << " is at max level" << endl;
	}
	if(healthPower<=0){
		healthPower=50;
	}
}


Paladin::Paladin(string n)
: Hero(n, 42, 38, 5){}

Paladin::~Paladin(){}

void Paladin::print(){
	cout << "Category: Paladin" << endl;
	cout << "Name: " << Living::getName() << endl;
    cout << "level: " << Living::getLevel() << endl;
    cout << "healthPower: " << Living::getHelthPower() << endl;
	cout << "magicPower: " << magicPower << endl ;
	cout << "strenght: " << strenght << endl;
	cout << "dexterity: " << dexterity << endl;
	cout << "agility: " << agility << endl;
	cout << "money: " << money << endl;
	cout << "experience: " << experience << endl << endl;
}

void Paladin::levelUp(){
	if(level<10){
		int temp=level*100;
		while(experience>temp){
			level++;
			strenght=strenght + 3;
			agility=agility + 1;
			dexterity=dexterity +3;
			experience=experience - temp;
			healthPower=100;                     
			magicPower=50;
			temp=100*level;
		}
	}
	else {
		cout << "Hero " << name << " is at max level" << endl;
	}
	if(healthPower<=0){
		healthPower=50;
	}
}


Monster::Monster(string n, int da, int de, int a)
: Living(n){
    damage = da;
    defense = de;
    attack = a;
}

Monster::~Monster(){
    for(int j=0; j<i.size(); j++){
    	delete i[j];
	}
	for(int j=0; j<l.size(); j++){
    	delete l[j];
	}
	for(int j=0; j<f.size(); j++){
    	delete f[j];
	}
    i.clear();
    l.clear();
    f.clear();
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
	Spell* ptr;
	if(healthPower>0){
		healthPower=healthPower + 1;
	}
	if(healthPower>100){
		healthPower=100;
	}
	for(int j=0; j<i.size(); j++){
		if(i.at(j)->reduce()==0) {
			ptr=i[j];
			i.erase(i.begin() + j);
			delete ptr;
		}
	}
	for(int j=0; j<f.size(); j++){
		if(f.at(j)->reduce()==0) {
			ptr=i[j];
			f.erase(f.begin() + j);
			delete ptr;
		}
	}
	for(int j=0; j<l.size(); j++){
		if(l.at(j)->reduce()==0) {
			ptr=i[j];
			l.erase(l.begin() + j);
			delete ptr;
		}
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
	if(temp<0){
		temp=0;
	}
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
	if(temp1<0){
		temp1=0;
	}
	if(temp2<0){
		temp2=0;
	}
	damage=damage - temp2;
	if(damage<0){
		damage=0;
	}
	v1=rand() % 100;
	if(temp1>v1){
		cout << "The monster avoided the attack" << endl;
		return;
	}
	else{
		healthPower=healthPower - damage ;
	}
}

void Monster::print(){
	cout <<"Printing monster...." << endl;
}


Dragon::Dragon(string n) 
: Monster(n, 32, 3, 6){}

Dragon::~Dragon(){}

void Dragon::print(){
	cout << "Monster type: Dragon" << endl;
	cout << "Name: " << name << endl;
	cout << "Level: " << level << endl;
	cout << "Health: " << healthPower << endl;
	cout << "Damage: " << Monster::getDamage() << endl;
	cout << "Defense: " << Monster::getDefense() << endl;
	cout << "Agility: " << Monster::getAttack() << endl << endl;
}

void Dragon::levelUp(){
	damage=damage+8;
	defense=defense+3;
	attack=attack+1;
	level++;
}

Exoskeleton::Exoskeleton(string n) 
: Monster(n, 20, 12, 5){}

Exoskeleton::~Exoskeleton(){}

void Exoskeleton::print(){ 
	cout << "Monster type: Exoskeleton" << endl;
	cout << "Name: " << name<< endl;
	cout << "Level: " << level << endl;
	cout << "Health: " << healthPower << endl;
	cout << "Damage: " << Monster::getDamage() << endl;
	cout << "Defense: " << Monster::getDefense() << endl;
	cout << "Agility: " << Monster::getAttack() << endl << endl;
}

void Exoskeleton::levelUp(){
	damage=damage+6;
	defense=defense+5;
	attack=attack+1;
	level++;
}

Spirit::Spirit(string n) 
: Monster(n, 25, 5, 12){}

Spirit::~Spirit(){}

void Spirit::print(){
	cout << "Monster type: Spirit" << endl;
	cout << "Name: " << name<< endl;
	cout << "Level: " << level << endl;
	cout << "Health: " << healthPower << endl;
	cout << "Damage: " << Monster::getDamage() << endl;
	cout << "Defense: " << Monster::getDefense() << endl;
	cout << "Agility: " << Monster::getAttack() << endl << endl;
}

void Spirit::levelUp(){
	damage=damage+7;
	defense=defense+3;
	attack=attack+2;
	level++;
}


Team::Team(int num){
    heroes = new Hero*[num];
    counter = 0;
    location = NULL;
}

Team::~Team(){
	Hero* ptr;
    delete[] heroes;
}

void Team::print(){
    cout << "Team:" << endl;
    for(int i = 0; i < counter; i++){
        cout << "Hero " << i+1 << ":" << endl;
        heroes[i]->print();
    }
}

void Team::setLocation(Square* square){
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

int Team::getLevel()const{
	int w=this->heroes[0]->getLevel();
	return w;
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