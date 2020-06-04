#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

TRGDIR=/tmp/robot_scena

__start__: ./robot_scena
	./robot_scena

./robot_scena: obj obj/main.o obj/ObiektGraficzny.o\
           obj/lacze_do_gnuplota.o obj/Robot.o obj/zbiorWierzcholkow.o obj/Sciezka.o obj/Scena.o obj/Przeszkoda.o
	g++ -Wall -pedantic -std=c++11 -o ./robot_scena obj/main.o\
                        obj/lacze_do_gnuplota.o obj/ObiektGraficzny.o obj/Robot.o obj/zbiorWierzcholkow.o obj/Sciezka.o obj/Scena.o obj/Przeszkoda.o


obj:
	mkdir -p obj

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	g++ -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/main.o: src/main.cpp inc/ObiektGraficzny.hh inc/Robot.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/ObiektGraficzny.o: src/ObiektGraficzny.cpp inc/ObiektGraficzny.hh\
                       inc/Wektor2D.hh  inc/SWektor.hh inc/Robot.hh  src/Robot.cpp inc/zbiorWierzcholkow.hh  src/zbiorWierzcholkow.cpp
	g++ -c ${CXXFLAGS} -o obj/ObiektGraficzny.o src/ObiektGraficzny.cpp

obj/Robot.o: src/Robot.cpp inc/Robot.hh
	g++ -c ${CXXFLAGS} -o obj/Robot.o src/Robot.cpp

obj/zbiorWierzcholkow.o: src/zbiorWierzcholkow.cpp inc/zbiorWierzcholkow.hh
	g++ -c ${CXXFLAGS} -o obj/zbiorWierzcholkow.o src/zbiorWierzcholkow.cpp

obj/Sciezka.o: src/Sciezka.cpp inc/Sciezka.hh
	g++ -c ${CXXFLAGS} -o obj/Sciezka.o src/Sciezka.cpp

obj/Scena.o: src/Scena.cpp inc/Scena.hh
	g++ -c ${CXXFLAGS} -o obj/Scena.o src/Scena.cpp

obj/Przeszkoda.o: src/Przeszkoda.cpp inc/Przeszkoda.hh
	g++ -c ${CXXFLAGS} -o obj/Przeszkoda.o src/Przeszkoda.cpp

clean:
	rm -f obj/*.o ./robot_scena
