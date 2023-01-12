4gewinnt:  4Gewinnt.o Screen.o Field.o GameLogic.o Level.o StartGame.o
	g++ -o 4gewinnt 4Gewinnt.o Screen.o Field.o  GameLogic.o Level.o StartGame.o

Field.o: Field.cpp Field.hpp Screen.hpp
	g++ -c Field.cpp

4Gewinnt.o: 4Gewinnt.cpp	
	g++ -c 4Gewinnt.cpp

Screen.o: Screen.cpp Screen.hpp Level.hpp StartGame.hpp
	g++ -c Screen.cpp

Level.o: Level.cpp Level.hpp
	g++ -c Level.cpp

GameLogic.o: GameLogic.cpp GameLogic.hpp CppRandom.hpp
	g++ -c GameLogic.cpp

StartGame.o: StartGame.cpp StartGame.hpp Field.hpp GameLogic.hpp Screen.hpp Level.hpp
	g++ -c StartGame.cpp

clean: 
	rm *.o 4gewinnt