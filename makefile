4gewinnt: field.o 4Gewinnt.o screens.o spiellogik.o level.o
	g++ -o 4gewinnt screens.o field.o 4Gewinnt.o spiellogik.o level.o

field.o: field.cpp field.hpp
	g++ -c field.cpp

4Gewinnt.o: 4Gewinnt.cpp	
	g++ -c 4Gewinnt.cpp

screens.o: screens.cpp screens.hpp level.hpp
	g++ -c screens.cpp

level.o: level.cpp level.hpp
	g++ -c level.cpp

spiellogik.o: spiellogik.cpp spiellogik.hpp CppRandom.hpp 
	g++ -c spiellogik.cpp

clean: 
	rm *.o 4gewinnt