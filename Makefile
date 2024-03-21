PROGRAMS_DIR = programs
INCLUDE_DIR = include
SOURCE = $(wildcard $(PROGRAMS_DIR)/*.cpp)
FLAGS = -g -I$(INCLUDE_DIR) -o

ITEM = game

run : compile
	./$(ITEM)

leaks: compile
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
