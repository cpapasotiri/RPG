#include <iostream>
#include <cstring>
#include <vector> 

#include "grid.hpp"

using namespace std;

Grid::Grid(vector<Hero*> h, vector<Monster*> m, vector<Weapon*> w, vector<Armor*> a, vector<Potion*> p, vector<Spell*> s){
    cout << "A New Grid has been created!" << endl;
    world = new Square**[8];            // 
    for(int i = 0; i < 8; i++){
        world[i] = new Square*[8];      // 
        for(int j = 0; j < 8; j++){
            if(i == 0 || i == 7){
                world[i][j] = new NonAccessible();    
            }
            else if(j == 0 || j == 7){
                world[i][j] = new NonAccessible();
            }
            else if((i == 2 && j == 2) || (i == 2 && j == 5)){
                world[i][j] = new Market(w, a, p, s);
            }
            else if((i == 3 && j == 3) || (i == 4 && j == 4)){
                world[i][j] = new Market(w, a, p, s);
            }
            else if((i == 5 && j == 2) || (i == 5 && j == 5)){
                world[i][j] = new Market(w, a, p, s);
            }
            else{
                world[i][j] = new Common(); 
            }
        }
    }
    heroes = h;
    monsters = m;
}

Grid::~Grid(){
    cout << "A Grid to be destroyed!" << endl;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            delete world[i][j];
        }
        delete world[i];
    }
    delete world;
    heroes.clear();
    monsters.clear();
}

void Grid::displayMap(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            world[i][j]->print();
            cout << " ";
        }
        cout << endl;
    }
}

vector<Hero*> Grid::getHeroes()const{
    return heroes;
}

vector<Monster*> Grid::getMonsters()const{
    return monsters;
}

Square*** Grid::getWorld()const{
    return world;
}

Square::Square(int t){
    // cout << "A New Square has been created!" << endl;
    type = t;
}

Square::~Square(){
    cout << "A Square to be destroyed!" << endl;
}

int Square::getType()const{
    return type;
}


NonAccessible::NonAccessible()
: Square(0){
    // cout << "A New NonAccessible has been created!" << endl;
}

NonAccessible::~NonAccessible(){
    cout << "A NonAccessible to be destroyed!" << endl;
}

void NonAccessible::print()const{
    // cout << "A Non Accessible square!" << endl;
    cout << 0;
}


Market::Market(vector<Weapon*> w, vector<Armor*> a, vector<Potion*> p, vector<Spell*> s)
: Square(1){
    // cout << "A New Market has been created!" << endl;
    weapons = w;
    armors = a;
    potions = p;
    spells = s;
    team = NULL;
    items = weapons.size() + armors.size() + potions.size() + spells.size();
}

Market::~Market(){
    cout << "A Market to be destroyed!" << endl;
    weapons.clear();
    armors.clear();
    potions.clear();
    spells.clear();
}

void Market::print()const{
    // cout << "A Market square!" << endl;
    cout << 1;
    if(team != NULL){
        team->print();
    }
}

void Market::menu(){
    // print Menu
    cout << endl <<"Menu: " << endl << endl;
    int index = 0;
    vector<Weapon*> :: iterator w;
    for(w = weapons.begin(); w != weapons.end(); w++){
        index++;
        cout << "Press " << index << " to select: ";
        (*w)->print();
    }
    vector<Armor*> :: iterator a;
    for(a = armors.begin(); a != armors.end(); a++){
        index++;
        cout << "Press " << index << " to select: ";
        (*a)->print();
    } 
    vector<Potion*> :: iterator p;
    for(p = potions.begin(); p != potions.end(); p++){
        index++;
        cout << "Press " << index << " to select: ";
        (*p)->print();
    }
    vector<Spell*> :: iterator s;
    for(s = spells.begin(); s != spells.end(); s++){
        index++;
        cout << "Press " << index << " to select: ";
        (*s)->print();
    }

    // select to buy/sell items or exit/help of menu
    string item;
    cout << "Please select: buy, sell, exit or help:" << endl;
    cin >> item;
    cout << "You selected:" << item << endl;
    while(item.compare("exit") != 0){
        Hero* hero;
        if(item.compare("buy") == 0){
            hero = selectHero();
            buy(hero, index);
        }
        else if(item.compare("sell") == 0){
            hero = selectHero();
            sell(hero, index);
        }
        else if(item.compare("help") == 0){
            help();
        }
        else{
            cout << "Wrong input! Please: select buy, sell, exit or help:" << endl;
        }
        cout << "Please select: buy, sell, exit or help:" << endl;
        cin >> item;
        cout << "You selected:" << item << endl;
    }    
}

void Market::buy(Hero* hero, int i){
    int x;
    cout << "Please select an item to buy between 0-" << i << endl;
    cin >> x;
    cout << "You selected:" << x << endl;
    while(x >= 0){
        if(x == 0){                         // exit
            break;
        }
        else if(x >= 1 || x <= 120){        // weapon
            x -= 1;
            hero->buy(weapons[x]);
        }
        else if(x >= 121 || x <= 200){      // armor
            x -= 121;
            hero->buy(armors[x]);
        }
        else if(x >= 201 || x <= 266){      // potion
            x -= 201;
            hero->buy(potions[x]);
        }
        else{                               // spell
            x -= 267;
            hero->buy(spells[x]);
        }
        cout << "Please select an item to buy between 0-" << i << endl;
        cin >> x;
        cout << "You selected:" << x << endl;
    }
}

void Market::sell(Hero* hero, int i){
    int x;
    cout << "Please select an item to sell between 0-" << i << endl;
    cin >> x;
    cout << "You selected:" << x << endl;
    while(x >= 0){
        if(x == 0){                         // exit
            break;
        }
        else if(x >= 1 || x <= 120){        // weapon
            x -= 1;
            hero->sell(weapons[x]);
        }
        else if(x >= 121 || x <= 200){      // armor
            x -= 121;
            hero->sell(armors[x]);
        }
        else if(x >= 201 || x <= 266){      // potion
            x -= 201;
            hero->sell(potions[x]);
        }
        else{                               // spell
            x -= 267;
            hero->sell(spells[x]);
        }
        cout << "Please select an item to sell between 0-" << i << endl;
        cin >> x;
        cout << "You selected:" << x << endl;
    }
}

Hero* Market::selectHero(){
    Hero* hero = NULL;
    Hero** heroes = team->getHeroes();
    int counter = team->getCounter();
    cout << "Heroes:" << endl;
    for(int j = 0; j < counter; j++){
        cout << "Hero " << j+1 << ":" << endl;
        heroes[j]->getName();
    }  
    string name;
    cout << "Please select a hero:" << endl;
    cin >> name;
    cout << "You selected: " << name << endl;
    while(hero == NULL){
        for(int j = 0; j < counter; j++){
            if(heroes[j]->getName().compare(name) == 0){
                hero = heroes[j];
            }
        }
        cout << "Please select a hero:" << endl;
        cin >> name;
        cout << "You selected: " << name << endl;
    }
    return hero;
}

void Market::help(){
    cout << "If you want to buy an item, please give: buy" << endl;
    cout << "To buy an item, please give its number" << endl;
    cout << "If you want to stop buying items, please give: 0" << endl;
    cout << "If you want to sell an item, please give: sell" << endl;
    cout << "To sell an item, please give its number" << endl;
    cout << "If you want to stop selling items, please give: 0" << endl;
    cout << "If you want to exit from menu, please give: exit" << endl;
}

void Market::enterTeam(Team* t){
    team = t;
}

void Market::exitTeam(){
    team = NULL;
}

vector<Weapon*> Market::getWeapons()const{
    return weapons;
}

vector<Armor*> Market::getArmors()const{
    return armors;
}

vector<Potion*> Market::getPotions()const{
    return potions;
}

vector<Spell*> Market::getSpells()const{
    return spells;
}

int Market::getItems()const{
    return items;
}

Team* Market::getTeam()const{
    return team;
}


Common::Common()
: Square(2){
    // cout << "A New Common has been created!" << endl;
    team = NULL;
}

Common::~Common(){
    cout << "A Common to be destroyed!" << endl;
}

void Common::print()const{
    // cout << "A Common square!" << endl;
    cout << 2;
    if(team != NULL){
        team->print();
    }
}

void Common::enterTeam(Team* t){
    team = t;
}

void Common::exitTeam(){
    team = NULL;
}

Team* Common::getTeam()const{
    return team;
}

void Common::afterBattle(int num,vector<Monster*>monsters,int flag){              //flag=1 kerdisan oi iroes           //sto vector ipotithetai oti exo ta terata opou itan sth maxi
	Hero** b=team->getHeroes();
	
		for(int j=0; j<team->getCounter(); j++){
			if(flag==1){ 
				b[j]->victory(num);
			}
			else{
				b[j]->defeat();
			}
			b[j]->levelUp();                                  //osoi exoun arketa exp anevenoun level , tsekaroi gia aftous me 0 health na paei 50
		}
		for(int j=0; j<monsters.size(); j++){
			monsters.at(j)->changeHealth(100);
		}
	
	
}

int Common::Battle(vector<Monster*>monsters){
	int num=monsters.size();
	cout << "A Battle has begun" << endl;
	cout << "The enemy monsters are: " << endl;
	for(int j=0; j<monsters.size(); j++){
		cout << "Monster " << j+1 << endl;
		monsters.at(j)->print();
	}
	Hero** heroes=team->getHeroes();
	vector<Hero*> h;
	for(int j=0; j<team->getCounter(); j++){
		h.push_back(heroes[j]);
		
	}
	string move;
	int m;
	int v1;
	while(h.size()!=0 && monsters.size()!=0){
	for(int j=0; j<h.size(); j++){
		cout << "Choose hero's " << j+1 << " next move" << endl;
		cin >> move ;
		if(move=="attack"){
			cout << "Which monster you want to attack?" << endl;
			for(int j=0; j<monsters.size(); j++){
				cout << "Monster " << j+1 << endl;
				monsters.at(j)->print();
			}
			cin >> m;
			while((m-1)>monsters.size()){
				cout << "Give a correct number!" << endl;
				cin >> m;
			}
			h.at(j)->attack(monsters.at(m-1));
			if(monsters.at(m-1)->getHelthPower()<=0){                   //tsekaroume an pethane to teras 
				monsters.at(m-1)->changeHealth(100);      // xanagemizei i zoi tou gia epomenes maxes
				monsters.at(m-1)->clear();
				monsters.erase(monsters.begin()+(m-1));             // to diagrafoume apo to vector ton teraton
			}
			
		}
		else if(move=="castspell"){
			cout << "Which monster you want to attack?" << endl;
			for(int j=0; j<monsters.size(); j++){
				cout << "Monster " << j+1 << endl;
				monsters.at(j)->print();
			}
			cin >> m;
			while((m-1)>monsters.size()){
				cout << "Give a correct number!" << endl;
				cin >> m;
			}
			h.at(j)->castSpell(monsters.at(m-1));
			if(monsters.at(m-1)->getHelthPower()<=0){                   //tsekaroume an pethane to teras 
				monsters.at(m-1)->changeHealth(100);      // xanagemizei i zoi tou gia epomenes maxes
				monsters.at(m-1)->clear();
				monsters.erase(monsters.begin()+(m-1));             // to diagrafoume apo to vector ton teraton
			}
			
		}
		else if(move=="use"){
			h.at(j)->usePotion();
			
		}
		else if(move=="inventory"){
			h.at(j)->checkInventory();
			j--;
		}
		else{
			cout << "Please give a correct instruction!" << endl;
			j--;
		}
	}
		for(int j=0; j<monsters.size(); j++){
			v1=rand() % h.size();
			monsters.at(j)->destroy(h.at(v1));
			if(h.at(v1)->getHelthPower()<=0){
				h.erase(h.begin()+v1);
			}
		}
		cout << "View heroes' and monsters' stats" << endl << endl;
		for(int j=0; j<h.size(); j++){
			h.at(j)->regen();
			h.at(j)->print();
		}
		for(int j=0; j<monsters.size(); j++){
			monsters.at(j)->regen();
			monsters.at(j)->print();
		}
		// End of round
		
	
}	
	if(h.size()==0){
		this->afterBattle(num,monsters,0);
		return 0;
	}
	else
	 {
	 	this->afterBattle(num,monsters,1);
		return 1;
	}
	
}
