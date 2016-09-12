simIceHockey: main.o Defensemen.o Forward.o Goalie.o Player.o simIce_Hockey.o
	g++ main.o Defensemen.o Forward.o Goalie.o Player.o simIce_Hockey.o -o simIceHockey
Defensemen.o: Defensemen.cpp Defensemen.h Player.h Rink.h Utilities.h
	g++ -Wall -pedantic-errors -ansi -c Defensemen.cpp
Forward.o: Forward.cpp Forward.h Player.h Rink.h Utilities.h
	g++ -Wall -pedantic-errors -ansi -c Forward.cpp
Goalie.o: Goalie.cpp Goalie.h Player.h Rink.h Utilities.h
	g++ -Wall -pedantic-errors -ansi -c Goalie.cpp
main.o: main.cpp simIce_Hockey.h Player.h Rink.h Utilities.h Tree.h \
 BstNode.h Goalie.h Defensemen.h Forward.h
	g++ -Wall -pedantic-errors -ansi -c main.cpp
Player.o: Player.cpp Player.h Rink.h Utilities.h
	g++ -Wall -pedantic-errors -ansi -c Player.cpp
simIce_Hockey.o: simIce_Hockey.cpp simIce_Hockey.h Player.h Rink.h \
 Utilities.h Tree.h BstNode.h Goalie.h Defensemen.h Forward.h
	g++ -Wall -pedantic-errors -ansi -c simIce_Hockey.cpp
