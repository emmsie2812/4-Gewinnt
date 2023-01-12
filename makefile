4gewinnt:  4Gewinnt.o Screen.o field.o gameLogic.o level.o startEnd.o
	g++ -o 4gewinnt 4Gewinnt.o Screen.o field.o  gameLogic.o level.o startEnd.o

field.o: field.cpp field.hpp Screen.hpp
	g++ -c field.cpp

4Gewinnt.o: 4Gewinnt.cpp	
	g++ -c 4Gewinnt.cpp

Screen.o: Screen.cpp Screen.hpp level.hpp startEnd.hpp
	g++ -c Screen.cpp

level.o: level.cpp level.hpp
	g++ -c level.cpp

gameLogic.o: gameLogic.cpp gameLogic.hpp CppRandom.hpp
	g++ -c gameLogic.cpp

startEnd.o: startEnd.cpp startEnd.hpp field.hpp gameLogic.hpp Screen.hpp level.hpp
	g++ -c startEnd.cpp

clean: 
	rm *.o 4gewinnt