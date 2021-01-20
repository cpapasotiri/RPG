## ΠΡΟΣΩΠΙΚΑ ΣΤΟΙΧΕΙΑ:
-   Χριστίνα Παπασωτήρη, AM: 1115201900151
-   Γιώργος Μουράτος, ΑΜ: 1115201900118

## HOW TO COMPILE:
g++ -c living.cpp
g++ -c item_spell.cpp
g++ -c grid.cpp
g++ -c main.cpp
g++ -c game.cpp
g++ -o game living.o item_spell.o grid.o game.o main.o
./game 

ή

γράφοντας στο terminal: make
 
## ΠΕΡΙΓΡΑΦΗ ΥΛΟΠΟΙΗΣΕΩΝ: (Role Playing Game)
- Χριστίνα: Έστω ότι το πρόγραμμα κάνει compile. Φτιάχνω τα move και μετα θα βρω λύση για το πως θα διορθωθεί το πρόβλημα με τα includes.

- Γιώργος:


## .txts
names.txt -> 27 livings 
    9 -> (3*3) -> Hero(Warrior, Sorcerer, Paladin),
    18 -> (3*6) ->  Monster(Dragon, Exoskeleton, Spirit)
weapons.txt -> 120 weapons (2*60) -> 2/level:
armors.txt -> 80 shields (1*80) -> 1/level
potions.txt -> 66 elixirs (3*22) -> 3/level
spells.txt -> 30 spells (3*10) -> Ice, Fire, Light 1/level

## Πρέπει να προσθέσουμε
- Game
- Grid
- Move 
