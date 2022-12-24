4gewinnt: field.o 4Gewinnt.o spiellogik.o
	g++ -o 4gewinnt field.o 4Gewinnt.o spiellogik.o

field.o: field.cpp field.hpp
	g++ -c field.cpp

4Gewinnt.o: 4Gewinnt.cpp	
	g++ -c 4Gewinnt.cpp

spiellogik.o: spiellogik.cpp spiellogik.hpp CppRandom.hpp
	g++ -c spiellogik.cpp

clean: 
	rm *.o 4gewinnt