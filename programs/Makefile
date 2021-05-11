# INCLUDE = ../include
FLAGS = -g -o
SOURCE = living.cpp item_spell.cpp grid.cpp main.cpp game.cpp
ITEM = game

run : compile
	valgrind ./$(ITEM)

debug : $(ITEM)
	gdb $(ITEM)

compile : $(SOURCE)
	g++ $(FLAGS) $(ITEM) $(SOURCE)

clean :
	-rm $(ITEM)

compress: $(SOURCE)
	mkdir $(ITEM)_$(USER)
	cp $(SOURCE) $(ITEM)_$(USER)
	tar -cvzf $(ITEM)_$(USER).tar.gz $(ITEM)_$(USER)
	rm -r $(ITEM)_$(USER)
