4gewinnt:  4Gewinnt.o Screen.o Field.o GameLogic.o Level.o StartGame.o Random.o
	g++ -o 4gewinnt 4Gewinnt.o Screen.o Field.o  GameLogic.o Level.o StartGame.o Random.o

Field.o: Field.cpp Field.hpp Screen.hpp
	g++ -c Field.cpp

4Gewinnt.o: 4Gewinnt.cpp	
	g++ -c 4Gewinnt.cpp

Screen.o: Screen.cpp Screen.hpp Level.hpp StartGame.hpp
	g++ -c Screen.cpp

Level.o: Level.cpp Level.hpp Random.hpp
	g++ -c Level.cpp

GameLogic.o: GameLogic.cpp GameLogic.hpp Random.hpp
	g++ -c GameLogic.cpp

StartGame.o: StartGame.cpp StartGame.hpp Field.hpp GameLogic.hpp Screen.hpp Level.hpp
	g++ -c StartGame.cpp

Random.o: Random.cpp Random.hpp
	g++ -c Random.cpp

clean: 
	rm *.o 4gewinnt