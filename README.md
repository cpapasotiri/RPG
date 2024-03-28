<p align="center"><img src="logo_en.png" alt="Logo NKUA DiT" width=35%/></p>

# <center>Object Oriented Programming - Role Playing Game - Winter Semester 2020-2021</center>
<center>Professor: Izambo Karali</center><br>

## Team Personal Data:
- [George Mouratos](https://github.com/mouratos41)
- [Christina Papasotiri](https://github.com/cpapasotiri)

## Role Playing Game
### World
The game contains items, spells, heroes and monsters. <br>
The heroes and monsters live in a world that represented by a grid. <br> 
The heroes can engage in battles with monsters, where they can fight against the monsters, and the heroes can fight against each other. <br>
Heroes can use items and spells to defeat the monsters, or they can buy items to help them on their adventure. <br>
Every time the heroes defeat a monster, they collect some money and gain experience. When they gain enough experience, the heroes "level up" one level, which means they become stronger in their individual abilities.

### Game Creation
The approach we followed to create this game was to start with the living beings, objects and grid squares in order to connect them in such a way that the player, using simple words and numbers, could play this game.

### Objects and Living Beings in this world
27 livings: (9 Hero => 3 Warrior, 3 Sorcerer, 3 Paladin, 18 Monster => 6 Dragon, 6 Exoskeleton, 6 Spirit) <br>
120 weapons => 2/level <br>
80 armors => 1/level <br>
30 spells => Ice, Fire, Light => 1/level <br>
6 potions => 2 health, 2 magicPower, dexterity, strength <br> 

### We emphasize that
- When the world appears the team is represented graphically as * . 
- The graphical representation of the world which is also displayed on the command line is also availiable in Grid.pdf file.
- For the game to work properly the player must not choose the same hero more than once at the beginning.
- Each level of player interface gives appropriate instructions on how to handle the game. Help is also provided for each level. 
- Every heroe can hold up to 2 guns (primary,secondary) provided that both of these 2 weapons require a hand to be used.

### Battle  
Before the battle begins, some monsters are randomly selected for the heroes to face. The number of monsters takes value in the interval [1, counter+1] where counter is the number of heroes. <br>
For the battle to start the monsters must be of the same level as the heroes, once this is done the battle starts. <br>
Initially we place heroes and monsters in two diferrent vectors. <br>
When the life counter of a monster or a heroe becomes 0 we remove it from the vector and the battle ends when one of the two vectors is empty i.e. when all monsters or all heroes die. <br>
The battle takes place in rounds in each round the heroes plays first. <br>
The user chooses the move of each hero and if he chooses to attack a monster with or without the a spell he is also asked to choose witch monster he wants to hit. <br>
When its the monsters round each monster hits a heroe chosen at random. After the battle and the heroes get their rewards i.e. ther experience and money increases if they won, if they lost the lose half of their money.  

## Implementation Details
### Living
We defined the class Living as superclass which represents the entities Heroes and Monsters in our implementation. The class Living contains the name, level, life, and whether the current object is fainted or not. 
The class Living has the following subclasses:
1. Hero, whitch represents the types of Heroes.
2. Monster, whitch represents the types of Monsters.
 
#### Hero
We defined the class Hero as a superclass, which has the following subclasses: (Warrior, Sorcerer, Paladin).
These classes inherit all characteristics from Hero and essentially differentiate between them because they describe different types of Heroes based on the statistics that initialize them.

Each Hero can buy, sell, and use items purchased from the Market squares of the grid. Also, each hero can attack monsters with or without spells each round, or use a potion, or change armor.

#### Team
We defined the class Team, which represents a team consisting of 1 to 3 Heroes, created by the player at the beginning of the game.

#### Monster
We defined the class Monster as a subclass of Living and it inherits all its elements. In addition, each monster has a damage amount, a defense amount, an attack amount, and 3 vectors for the spells affecting it, reducing some statistic for a certain number of rounds (there is one vector for each type of spell and when the required rounds pass, the spell stops affecting the monster and is removed from the vector).
    
We also defined 3 subclasses of the Monster class to distinguish the 3 different types of monsters that exist (Spirit, Dragon, Exoskeleton).

### Items & Spells
#### Item
We defined the class Item as a superclass, which represents the items and spells used by the heroes in our game. 
The class Item contains the name of the item, its value, and the minimum level required for the hero to use it. The class Item has 4 subclasses: Weapon, Armor, Potion, Spell 

#### Weapon
The class Weapon, which represents weapons and contains the damage of each weapon and an integer variable hands which takes values 1 or 2 depending on how many hands the hero needs to use it.

#### Armor
The class Armor, which represents armor and contains the defense amount of the armor.

#### Potion
The class Potion, which represents potions that the hero can use to increase a specific statistic (life, magic power, dexterity, strength). It contains the statistic of the hero to be increased (string ability) and the amount of increase (int amount).

#### Spell
The class Spell, which represents spells and contains the energy amount required by the hero to perform the specific spell (int energy), the maximum and minimum damage it can cause (maxdamage, mindamage). That is, depending on the hero's dexterity, casting a spell causes different damage, which, however, belongs to the interval [mindamage, maxdamage]. Also, depending on their category, spells reduce a statistic of the opponent monster by a certain amount (int reduction) for some rounds of the battle (int rounds). 
The class Spell also has 3 subclasses: (Firespell, Lightingspell, Icespell)

### Grid
We defined the class Grid as the world of the game with dimensions 8*8 (chessboard - for graphical representation see Grid.pdf), which is represented by 3 types of Squares. The team can move on the grid from square to square. Additionally, it can be printed graphically as a matrix with 0, 1, 2, depending on the type of square that each square represents.

#### Square
The class Square represents the squares of the grid and contains the type, the coordinates (as an array [i][j]), and the Hero Team. In a square - depending on its type - the team can enter and exit.
We defined the class Square as a superclass, which has the following subclasses: NonAccessible, Common, Market

#### Non Accessible
NonAccessible, which is printed as 0, are the squares of the Grid where no Hero can go.

#### Common 
We defined the class Common as the square type 2, where the team can enter, and when it enters, a battle begins.

Common, which is printed as 2, are the squares of the grid where the Battles take place.


#### Market
We defined the class Market as the square type 1 where the team can enter, and when it enters, it starts by asking which items it wants to display: those it has already purchased or those available in the store. Then, if it chooses to print the items available to buy or sell, it should also select which category of items it wants to display to see the offered items for each of its choices. Generally, through the Market, items for sale or purchase are printed by selecting separately for each Hero which actions we want to take.

Market, which is printed as 1, are the squares of the Grid where each Hero can buy or sell items.

Market Functionality Description:
When the team enters squares of this type, the player must choose what they want to do: buy/sell or seek help if they need clarification, or exit if they want to stop viewing things related to the Market to continue with their next move.

### Game
We define the Game class as the game interface between player, main and Grid. From the main of Game gets the names to build the creatures and objects, while from user it gets the information needed to build the world team. <br>
The game starts automatically by printing to the player which are the offered Heroes and he can choose 1-3. The player writes down the number of Heroes he wants in his team and is then asked to choose exactly who they will be. After the creation of the world team the player is asked to choose each time he wants the team to move through the world by giving up/down/right/left or help if he wants some clarification or quitGame if he wants to stop the game and if he really wants to end the game he has to choose OK.

### main.cpp 
It stores in separate vectors the names that will be discussed below and passes them to the Game by creating it.

### Name files
The following files contain the names which are read in the main of the program and passed as vectors to the Game to create entities or objects of the world.<br>
    names.txt -> names of living beings<br>
    weapons.txt -> names of weapons<br>
    armors.txt -> names of armors<br>
    spells.txt -> names of spells<br>

## How to Use:
inside of programs/

    make run

or

    g++ -c living.cpp
    g++ -c item_spell.cpp
    g++ -c grid.cpp
    g++ -c main.cpp
    g++ -c game.cpp
    g++ -o game living.o item_spell.o grid.o game.o main.o
    ./game 

