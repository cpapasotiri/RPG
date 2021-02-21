#include <iostream>
#include <cstring>
#include <vector> 

#include "grid.hpp"

using namespace std;

Grid::Grid(vector<Hero*> h, vector<Monster*> m, vector<Weapon*> w, vector<Armor*> a, vector<Potion*> p, vector<Spell*> s){
    world = new Square**[8];             
    for(int i = 0; i < 8; i++){
        world[i] = new Square*[8];       
        for(int j = 0; j < 8; j++){
            if(i == 0 || i == 7){
                world[i][j] = new NonAccessible(i, j);    
            }
            else if(j == 0 || j == 7){
                world[i][j] = new NonAccessible(i, j);
            }
            else if((i == 2 && j == 2) || (i == 2 && j == 5)){
                world[i][j] = new Market(w, a, p, s, i, j);
            }
            else if((i == 3 && j == 3) || (i == 4 && j == 4)){
                world[i][j] = new Market(w, a, p, s, i, j);
            }
            else if((i == 5 && j == 2) || (i == 5 && j == 5)){
                world[i][j] = new Market(w, a, p, s, i, j);
            }
            else{
                world[i][j] = new Common(i, j); 
            }
        }
    }
    heroes = h;
    monsters = m;
}

Grid::~Grid(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            delete world[i][j];
        }
        delete[] world[i];
    }
    delete[] world;
    heroes.clear();
    monsters.clear();
}

void Grid::displayMap(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(world[i][j]->getTeam() == NULL){
                world[i][j]->print();
            }
            else{
                cout << "*";
            }
            cout << " ";
        }
        cout << endl;
    }
}

void Grid::move(Team* team, string m){
    Square* curr = team->getLocation();
    int i = curr->getI();
    int j = curr->getJ();
	vector<Monster*> mon;
    Square* move;
    int move_type;
    if(m.compare("up") == 0){
        move = world[i-1][j];
        move_type = move->getType();
    }
    else if(m.compare("down") == 0){
        move = world[i+1][j];
        move_type = move->getType();
    }
    else if(m.compare("right") == 0){
        move = world[i][j+1];
        move_type = move->getType();
    }
    else if(m.compare("left") == 0){
        move = world[i][j-1];
        move_type = move->getType();
    }

    if(move_type == 1){                
        curr->exitTeam();
        team->setLocation(move);
        move->enterTeam(team);
        move->start(mon);
        
    }
    else if(move_type==2){
    	curr->exitTeam();
        team->setLocation(move);
        move->enterTeam(team);
        mon=prepare(team->getLevel(),team->getCounter());
        move->start(mon);
	}
    else{
        cout << "You can't move into a Non Accessible Square" << endl; 
    }
    mon.clear();
}

void Grid::setTeam(Team* t){
    world[6][5]->enterTeam(t);
    t->setLocation(world[6][5]);
}

Square*** Grid::getWorld()const{
    return world;
}

vector<Hero*> Grid::getHeroes()const{
    return heroes;
}

vector<Monster*> Grid::getMonsters()const{
    return monsters;
}

vector<Monster*> Grid::prepare(int lvl,int ctr){
	int amount;
	int v3;
	amount= 1+ rand() % (ctr+1);

	vector<Monster*> k;
	for(int j=0; j<amount; j++){
		v3=rand() % monsters.size();
		if(v3<=5){
		    Monster* m=new Dragon(monsters.at(v3)->getName());
		    k.push_back(m);
		}
		else if(v3<=10){
			Monster* m=new Exoskeleton(monsters.at(v3)->getName());
			k.push_back(m);
		}
		else{
			Monster* m=new Spirit(monsters.at(v3)->getName());
			k.push_back(m);
		}
	
    }
	for(int j=1; j<lvl; j++){
		for(int i=0; i<k.size(); i++){
			k.at(i)->levelUp();
		}
	}
	return k;
}


Square::Square(int t, int x, int y){
    type = t;
    i = x;
    j = y;
    team = NULL;
}

Square::~Square(){
    // delete team;
}

void Square::enterTeam(Team* t){
    team = t;
}

void Square::exitTeam(){
    team = NULL;
}

int Square::getType()const{
    return type;
}

int Square::getI()const{
    return i;
}

int Square::getJ()const{
    return j;
}

Team* Square::getTeam()const{
    return team;
}


NonAccessible::NonAccessible(int x, int y)
: Square(0, x, y){
}

NonAccessible::~NonAccessible(){
}

void NonAccessible::print()const{
    cout << 0;
}

void NonAccessible::start(vector <Monster*> k){}

void NonAccessible::operate(vector <Monster*> k){}


Market::Market(vector<Weapon*> w, vector<Armor*> a, vector<Potion*> p, vector<Spell*> s, int x, int y)
: Square(1, x, y){
    weapons = w;
    armors = a;
    potions = p;
    spells = s;
    items = weapons.size() + armors.size() + potions.size() + spells.size();
}

Market::~Market(){
    weapons.clear();
    armors.clear();
    potions.clear();
    spells.clear();
}

void Market::print()const{
    cout << 1;
    if(Square::getTeam() != NULL){
        Square::getTeam()->print();
    }
}

int Market::printMenu(string s){
    cout << endl <<"MENU: " << endl << endl;
    int index = 0;
    if(s.compare("weapon") == 0){
        vector<Weapon*> :: iterator w;
        for(w = weapons.begin(); w != weapons.end(); w++){
            index++;
            cout << "Press " << index << " to select: ";
            (*w)->print();
        }
    }
    else if(s.compare("armor") == 0){
        vector<Armor*> :: iterator a;
        for(a = armors.begin(); a != armors.end(); a++){
            index++;
            cout << "Press " << index << " to select: ";
            (*a)->print();
        } 
    }
    else if(s.compare("potion") == 0){
        vector<Potion*> :: iterator p;
        for(p = potions.begin(); p != potions.end(); p++){
            index++;
            cout << "Press " << index << " to select: ";
            (*p)->print();
        }
    }
    else{
        vector<Spell*> :: iterator s;
        for(s = spells.begin(); s != spells.end(); s++){
            index++;
            cout << "Press " << index << " to select: ";
            (*s)->print();
        }
    }
    
    return index;
}

void Market::menu(){
    // select to buy/sell items or exit/help of menu
    string item;
    cout << "Please select: buy, sell, exit or help:" << endl;
    cin >> item;
    cout << "You selected:" << item << endl;
    while(item.compare("exit") != 0){
        Hero* hero;
        if(item.compare("buy") == 0){
            string category = selectCategory();
            int index = printMenu(category);
            hero = selectHero();
            buy(hero, category, index);
        }
        else if(item.compare("sell") == 0){
            hero = selectHero();
            sell(hero);
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

void Market::buy(Hero* hero, string s, int i){
    int x;
    cout << "Please select an item to buy between 1-" << i << endl;
    cout << "If you want to stop buying select 0" << endl;
    cin >> x;
    cout << "You selected:" << x << endl;
    while(x >= 0 && x <= i){
        if(x == 0){                             // exit
            break;
        }
        else if(s.compare("weapon") == 0){      // weapon
            hero->buy(weapons[x-1]);
        }
        else if(s.compare("armor") == 0){       // armor
            hero->buy(armors[x-1]);
        }
        else if(s.compare("potion") == 0){      // potion
            hero->buy(potions[x-1]);
        }
        else{                                   // spell
            hero->buy(spells[x-1]);
        }
        cout << "Please select an item to buy between 1-" << i << endl;
        cout << "If you want to stop buying select 0" << endl;
        cin >> x;
        cout << "You selected:" << x << endl;
    }
}

void Market::sell(Hero* hero){
    hero->sellItem();
}

Hero* Market::selectHero(){
    Hero* hero = NULL;
    Hero** heroes = Square::getTeam()->getHeroes();
    int counter = Square::getTeam()->getCounter();
    cout << "Heroes:" << endl;
    for(int j = 0; j < counter; j++){
        cout << "Hero " << j+1 << ":" << endl;
        cout << heroes[j]->getName() << endl;
    }  
    int temp;
    while(hero == NULL){
    	cout << "Please select a hero: (by giving its number)" << endl;
    	cin >> temp;
    	while(temp<=0 || temp>counter){
    		cout << "Wrong input" << endl;
    		cout << "Please select a hero: (by giving its number)" << endl;
    		cin >> temp;
		}
    	string name=heroes[temp-1]->getName();
    	cout << "You selected: " << name << endl;
       	hero=heroes[temp-1];
    }
    return hero;
}

string Market::selectCategory(){
    string type;
    cout << "Please select item type: weapon/armor/potion/spell." << endl;
    cin >> type;
    cout << "You selected:" << type << endl;
    while(type.compare("weapon") != 0 && type.compare("armor") != 0 && type.compare("potion") != 0 && type.compare("spell") != 0){
        cout << "Please select item type: weapon/armor/potion/spell." << endl;
        cin >> type;
        cout << "You selected:" << type << endl;
    }
    return type;
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

void Market::start(vector <Monster*> k){
    menu();
}

void Market::operate(vector <Monster*> k){}

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


Common::Common(int x, int y)
: Square(2, x, y){}

Common::~Common(){}

void Common::print()const{
    cout << 2;
    if(Square::getTeam() != NULL){
        Square::getTeam()->print();
    }
}


void Common::start(vector <Monster*> k){
    this->Battle(k);
}

void Common::operate(vector <Monster*> k){
	this->Battle(k);	
}

void Common::afterBattle(int num,vector<Monster*>monsters,int flag){              //flag=1 kerdisan oi iroes           //sto vector ipotithetai oti exo ta terata opou itan sth maxi
	Hero** b=Square::getTeam()->getHeroes();
	for(int j=0; j<Square::getTeam()->getCounter(); j++){
		if(flag==1){ 
			b[j]->victory(num);
		}
		else{
			b[j]->defeat();
		}
		b[j]->levelUp();                                  //osoi exoun arketa exp anevenoun level , tsekarei gia aftous me 0 health na paei 50
	}
}

int Common::Battle(vector<Monster*> monsters){
	int num=monsters.size();
	cout << endl << endl << "A Battle has begun" << endl;
	cout << "The enemy monsters are: " << endl;
	for(int j=0; j<monsters.size(); j++){
		cout << "Monster " << j+1 << endl;
		monsters.at(j)->print();
		cout << endl;
	}

	Hero** heroes=Square::getTeam()->getHeroes();
	vector<Hero*> h;
	for(int j=0; j<Square::getTeam()->getCounter(); j++){
		h.push_back(heroes[j]);
	}

	string move;
	int m;
	int v1;
	Monster* ptr;
	while(h.size()!=0 && monsters.size()!=0){
	    for(int j=0; j<h.size(); j++){
	    	if(monsters.size()==0) 
                break;
		    cout << "Choose hero's " << j+1 << " next move" << endl;
            cout << "Please give: attack/castspell/use/inventory/equip/displayStats" << endl;
    		cin >> move;
	    	if(move=="attack"){
		    	cout << "Which monster you want to attack?(Give its number)" << endl;
			    for(int i=0; i<monsters.size(); i++){
			    	cout << endl;
				    cout << "Monster " << i+1 <<": " << endl;
				    monsters.at(i)->print();
				    cout << endl;
    			}
	    		cin >> m;
		    	while((m-1)>monsters.size() || (m-1)<0){
			    	cout << "Give a correct number!" << endl;
				    cin >> m;
			    }
			    h.at(j)->attack(monsters.at(m-1));
    			if(monsters.at(m-1)->getHelthPower()<=0){                   //tsekaroume an pethane to teras 
		    		ptr=monsters[m-1];
			    	monsters.erase(monsters.begin()+(m-1)); 
					delete ptr;
    			}
	    	}
	    	else if(move=="castspell"){
		    	cout << "Which monster you want to attack?" << endl;
			    for(int i=0; i<monsters.size(); i++){
			    	cout << endl;
				    cout << "Monster " << i+1 <<": " << endl;
				    monsters.at(i)->print();
    			}
	    		cin >> m;
		    	while((m-1)>monsters.size()){
			    	cout << "Give a correct number!" << endl;
				    cin >> m;
			    }
			    h.at(j)->castSpell(monsters.at(m-1));
    			if(monsters.at(m-1)->getHelthPower()<=0){                   //tsekaroume an pethane to teras 
		    		ptr=monsters[m-1];
			    	monsters.erase(monsters.begin()+(m-1));             // to diagrafoume apo to vector ton teraton
			    	delete ptr;
			    }		
    		}
		    else if(move=="use"){
		    	if(h.at(j)->usePotion()==0){
				    j--;
				}
		    }
            else if(move=="inventory"){
	    		h.at(j)->checkInventory();
    			j--;
		    }
		    else if(move=="equip"){
		    	h.at(j)->equip();
		    	j--;
			}
			else if(move=="displayStats"){
				cout << "View heroes' and monsters' stats..." << endl;
				for(int i=0; i<this->getTeam()->getCounter(); i++){
					cout << endl << "Hero " << i+1 << ":" << endl;
					heroes[i]->print();
					cout << endl;
				}
				
			    for(int i=0; i<monsters.size(); i++){
			    	cout << endl;
			    	cout << "Monster " << i+1 << ":" << endl;
			    	monsters.at(i)->print();
			    	cout << endl;
			    }
			    j--;
			}
		    else{
		    	cout << "Please give a correct instruction!" << endl;
                cout << "Please give: attack/castspell/use/inventory/equip/displayStats" << endl;
	    		j--;
    	    }
	    }
		for(int j=0; j<monsters.size(); j++){
			if(h.size()==0) 
                break;
			v1=rand() % h.size();
			monsters.at(j)->destroy(h.at(v1));
			if(h.at(v1)->getHelthPower()<=0){
				h.erase(h.begin()+v1);
			}
		}
	
		cout << "View heroes' and monsters' stats..." << endl << endl;
		for(int i=0; i<h.size(); i++){
			h.at(i)->regen();
			cout << "Hero " << i+1 << ":" << endl;
			h.at(i)->print();
		}

		cout << endl;
		for(int i=0; i<monsters.size(); i++){
			monsters.at(i)->regen();
			cout << "Monster " << i+1 << ":" << endl;
			monsters.at(i)->print();
		}
		// End of round
    }	
	if(h.size()==0){
		for(int j=0; j<monsters.size(); j++){
			ptr=monsters[j];
			delete ptr;
		}
		monsters.clear();
		cout << "Monsters won!" << endl << endl;
		this->afterBattle(num,monsters,0);
		return 0;
	}
	else{
		cout << "Heroes won" << endl << endl;
	 	this->afterBattle(num,monsters,1);
		return 1;
	}
}