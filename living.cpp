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
	if(healthPower<0){ 
		healthPower=0;    //nomizo prepei na tsekaroume kai afto edo
	}
	if(healthPower>100){ 
		healthPower=100;  // kai afto
	}	
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
    int j=0;
    for(j=0; j<weapon.size(); j++){
		if(weapon.at(j)==a) {
			weapon.erase(weapon.begin()+j);
   			money=money + (a->getPrice()/2);        //poleite sti misi timi
			break;
	    }
    }
}

void Hero::sellItem(){
	cout << "What do you want to sell?" << endl;
	string item;
	cin>>item;
	int k;
	if(item=="weapon"){
		if(weapon.size()==0){
			cout << "No available weapons for sale!!" << endl;
			return;
		}
		for(int j=0; j<weapon.size(); j++){
			cout << endl;
			cout << "Weapon " << j+1 << " :" << endl;
			weapon.at(j)->print();
			cout << endl;
		}
		cout << "Choose by giving its number(give 0 if you want to exit)" << endl;
		cin >> k;
		if(k<=0) return;
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
			cout << endl;
			cout << "Armor " << j+1 << " :" << endl;
			armor.at(j)->print();
			cout << endl;
		}
		cout << "Choose by giving its number(give 0 if you want to exit)" << endl;
		cin >> k;
		if(k<=0) return;
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
			cout << endl;
			cout << "Potion " << j+1 << " :" << endl;
			potion.at(j)->print();
			cout << endl;
		}
		cout << "Choose by giving its number(give 0 if you want to exit)" << endl;
		cin >> k;
		if(k<=0) return;
		sell(potion.at(k-1));
	}
	else if(item=="spell"){
		if(spell.size()==0){
			cout << "No available spells for sale!!" << endl;
			return;
		}
	for(int j=0; j<spell.size(); j++){
			cout << endl;
			cout << "Spell " << j+1 << " :" << endl;
			spell.at(j)->print();
			cout << endl;
		}
		cout << "Choose by giving its number(give 0 if you want to exit)" << endl;
		cin >> k;
		if(k<=0) return;
		sell(spell.at(k-1));
	}
	else {
		cout << "Wrong instruction!" << endl;
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
    Potion* ptr;
    for(j=0; j<potion.size(); j++){
        if(potion.at(j)==a) {
        	ptr=potion.at(j);
			potion.erase(potion.begin()+j);
    		money=money + (a->getPrice()/2);        //poleite sti misi timi
			break;
	    }
	}
	delete ptr;
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
	if(a->getAbility()=="healthPower"){
		this->healthPower=healthPower + a->getAmount();
		if(healthPower>100) healthPower=100;
	}
    else if(a->getAbility()=="magicPower"){
        magicPower=magicPower + (a->getAmount());
        if(magicPower>50) magicPower=50;
    }
    else if(a->getAbility()=="strength"){
        strenght=strenght + (a->getAmount());
    }
    else {
        dexterity=dexterity + (a->getAmount());
    }
   // else(a->getAbility()=="agility"){
    //    agility=agility + (a->getAmount());
   // }
    int j=0;
    for(j=0; j<potion.size(); j++){
        if(potion.at(j)==a){
			break;
		}
    }
    Potion* ptr=potion.at(j);
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
	if(w1==a ) {
		cout <<"Already equipped" << endl << endl;
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
//reerreererererererer
Armor* Hero::printArmor(){
	for(int j=0; j<armor.size(); j++){
		cout << "Armor " <<j+1 << ":" <<  endl;
		armor.at(j)->print();
	}
	cout << endl << "Choose an armor!(by giving its number)" << endl;
	int temp;
	cin >> temp;
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
	return weapon.at(temp-1);
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


//rererererreererer

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

void Hero::victory(int num){
	money=money + (10*level*num*2);
	experience=experience + (20*level*num);             //endeiktika noumera an thes allazoun
}

void Hero::defeat(){
	money=money/2;
}

int Hero::searchWeapon(Weapon* a){       //return 1 an iparxei sto inventory
	for(int j=0; j<weapon.size(); j++){
		if(weapon.at(j)==a) return 1;
	}
	return 0;
}

int Hero::searchArmor(Armor* a){        //return 1 an iparxei sto inventory
	for(int j=0; j<armor.size(); j++){
		if(armor.at(j)==a) return 1;
	}
	return 0;
}




Warrior::Warrior(string n)
: Hero(n, 47, 30, 15){
    // cout << "A New Warrior has been created! " << endl;
}

Warrior::~Warrior(){
    cout << "A Warrior to be destroyed! " << endl;
}

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
		if(experience>temp){
			level++;
			strenght=strenght + 5;
			agility=agility + 2;
			dexterity++;
			experience=experience - temp;
			healthPower=100;                     
			magicPower=50;
		}
		else {
			if(healthPower<=0) healthPower=50;
			return;
		}
	}
	else {
		cout << "Hero " << name << " is at max level" << endl;
	}
	if(healthPower==0){
		healthPower=50;
	}
}


Sorcerer::Sorcerer(string n)
: Hero(n, 40, 38, 15){
    // cout << "A New Sorcerer has been created! " << endl;
}

Sorcerer::~Sorcerer(){
    cout << "A Sorcerer to be destroyed! " << endl;
}

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
		if(experience>temp){
			level++;
			strenght=strenght + 3;
			agility=agility + 2;
			dexterity=dexterity + 3;
			experience=experience - temp;
			healthPower=100;                     
			magicPower=50;
		}
			else {
			if(healthPower<=0) healthPower=50;
			return;
		}
	}
	else {
		cout << "Hero " << name << " is at max level" << endl;
	}
	if(healthPower==0){
		healthPower=50;
	}
}


Paladin::Paladin(string n)
: Hero(n, 45, 35, 8){
    // cout << "A New Paladin has been created! " << endl;
}

Paladin::~Paladin(){
    cout << "A Paladin to be destroyed! " << endl;
}

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
		if(experience>temp){
			level++;
			strenght=strenght + 4;
			agility=agility + 1;
			dexterity=dexterity +3;
			experience=experience - temp;
			healthPower=100;                     
			magicPower=50;
		}
		else {
			if(healthPower<=0) healthPower=50;
			return;
		}
	}
	else {
		cout << "Hero " << name << " is at max level" << endl;
	}
	if(healthPower==0){
		healthPower=50;
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

void Monster::regen(){
	if(healthPower>0){
		healthPower=healthPower + 1;
	}
	if(healthPower>100){
		healthPower=100;
	}
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
		temp=0;                     // nomizo prepei na elegxoume kai ayto 
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
: Monster(n, 43, 3, 6){
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
	cout << "Agility: " << Monster::getAttack() << endl << endl;
}

Exoskeleton::Exoskeleton(string n) 
: Monster(n, 36, 10, 5){
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
	cout << "Agility: " << Monster::getAttack() << endl << endl;
}

Spirit::Spirit(string n) 
: Monster(n, 38, 5, 12){
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
	cout << "Agility: " << Monster::getAttack() << endl << endl;
}


Team::Team(int num){
	// cout << "A New team has been created" << endl;
    heroes = new Hero*[num];
    counter = 0;
    // location = NULL;
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

void Team::joinTeam(Hero* a){
    heroes[counter++]=a;
}

void Team::displayStats()const{
    for(int j=0; j<counter; j++){
        cout << "Hero " << j+1 << ":" << endl;
        heroes[j]->print();
    }
}

//erererererrerererer



void Dragon::levelUp(){
	damage=damage+9;
	defense=defense+3;
	attack=attack+1;
}

void Exoskeleton::levelUp(){
	damage=damage+7;
	defense=defense+5;
	attack=attack+1;
}

void Spirit::levelUp(){
	damage=damage+8;
	defense=defense+4;
	attack=attack+2;
}

int Team::getLevel(){
	int w=this->heroes[0]->getLevel();
	return w;
}



