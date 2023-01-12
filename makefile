4gewinnt:  4Gewinnt.o screens.o field.o gameLogic.o level.o startEnd.o
	g++ -o 4gewinnt 4Gewinnt.o screens.o field.o  gameLogic.o level.o startEnd.o

field.o: field.cpp field.hpp screens.hpp
	g++ -c field.cpp

4Gewinnt.o: 4Gewinnt.cpp	
	g++ -c 4Gewinnt.cpp

screens.o: screens.cpp screens.hpp level.hpp startEnd.hpp
	g++ -c screens.cpp

level.o: level.cpp level.hpp
	g++ -c level.cpp

gameLogic.o: gameLogic.cpp gameLogic.hpp CppRandom.hpp
	g++ -c gameLogic.cpp

startEnd.o: startEnd.cpp startEnd.hpp field.hpp gameLogic.hpp screens.hpp level.hpp
	g++ -c startEnd.cpp

clean: 
	rm *.o 4gewinnt