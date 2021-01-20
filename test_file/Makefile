FLAGS = -Wall -g -o
SOURCE = main.cpp point.cpp int.cpp double.cpp
ITEM = main

run : compile
	./$(ITEM)

debug : $(ITEM)
	gdb $(ITEM)

compile : $(SOURCE)
	#gcc $(FLAGS) $(ITEM) $(SOURCE)
	g++ $(FLAGS) $(ITEM) $(SOURCE)

clean :
	-rm $(ITEM)

compress: $(SOURCE)
	mkdir $(ITEM)_$(USER)
	cp $(SOURCE) $(ITEM)_$(USER)
	tar -cvzf $(ITEM)_$(USER).tar.gz $(ITEM)_$(USER)
	rm -r $(ITEM)_$(USER)
