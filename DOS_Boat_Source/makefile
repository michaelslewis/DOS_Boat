all: DOS_Boat

DOS_Boat: DOS_Boat_Main.o Babbage.o Ocean.o AwardSpace.o RecoverSpace.o EnemySpace.o RequireSpace.o AlienSpace.o EndSpace.o
	g++ -g DOS_Boat_Main.o Babbage.o Ocean.o AwardSpace.o RecoverSpace.o EnemySpace.o RequireSpace.o AlienSpace.o EndSpace.o -o DOS_Boat

DOS_Boat_Main.o: DOS_Boat_Main.cpp
	g++ -c DOS_Boat_Main.cpp

Babbage.o: Babbage.cpp Babbage.hpp
	g++ -c Babbage.cpp

Ocean.o: Ocean.cpp Ocean.hpp
	g++ -c Ocean.cpp

AwardSpace.o: AwardSpace.cpp AwardSpace.hpp
	g++ -c AwardSpace.cpp

RecoverSpace.o: RecoverSpace.cpp RecoverSpace.hpp
	g++ -c RecoverSpace.cpp

EnemySpace.o: EnemySpace.cpp EnemySpace.hpp
	g++ -c EnemySpace.cpp

RequireSpace.o: RequireSpace.cpp RequireSpace.hpp
	g++ -c RequireSpace.cpp

AlienSpace.o: AlienSpace.cpp AlienSpace.hpp
	g++ -c AlienSpace.cpp

EndSpace.o: EndSpace.cpp EndSpace.hpp
	g++ -c EndSpace.cpp

clean:
	rm -f DOS_Boat DOS_Boat_Main.o Babbage.o Ocean.o AwardSpace.o RecoverSpace.o EnemySpace.o RequireSpace.o AlienSpace.o EndSpace.o
