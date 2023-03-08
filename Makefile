all: bin/main

bin/main: obj/Main.o obj/Block.o obj/Cable.o obj/Entity.o obj/Level.o obj/Pickable.o obj/Platform.o obj/Player.o obj/Receptacle.o obj/Sensor.o obj/Trap.o
	g++ -g -Wall -o bin/main obj/Main.o obj/Block.o obj/Cable.o obj/Entity.o obj/Level.o obj/Pickable.o obj/Platform.o obj/Player.o obj/Receptacle.o obj/Sensor.o obj/Trap.o

obj/Main.o: src/main.cpp src/core/Block.h src/core/Cable.h src/core/Entity.h src/core/Level.h src/core/Pickable.h src/core/Platform.h src/core/Player.h src/core/Receptacle.h src/core/Sensor.h src/core/Trap.h
	g++ -g -Wall -c src/main.cpp -o obj/Main.o

obj/Block.o: src/core/Block.cpp	src/core/Block.h src/core/Player.h src/core/Enum.h
	g++ -g -Wall -c src/core/Block.cpp -o obj/Block.o

obj/Cable.o: src/core/Cable.cpp src/core/Cable.h src/core/Enum.h src/core/Level.h
	g++ -g -Wall -c src/core/Cable.cpp -o obj/Cable.o

obj/Entity.o: src/core/Entity.cpp src/core/Entity.h src/core/Level.h
	g++ -g -Wall -c src/core/Entity.cpp -o obj/Entity.o

obj/Pickable.o: src/core/Pickable.cpp src/core/Pickable.h src/core/Entity.h src/core/Level.h
	g++ -g -Wall -c src/core/Pickable.cpp -o obj/Pickable.o

obj/Platform.o: src/core/Platform.cpp src/core/Platform.h src/core/Block.h
	g++ -g -Wall -c src/core/Platform.cpp -o obj/Platform.o		

obj/Player.o: src/core/Player.cpp src/core/Player.h src/core/Entity.h src/core/Level.h
	g++ -g -Wall -c src/core/Player.cpp -o obj/Player.o

obj/Receptacle.o: src/core/Receptacle.cpp src/core/Receptacle.h src/core/Enum.h src/core/Block.h src/core/Player.h src/core/Pickable.h
	g++ -g -Wall -c src/core/Receptacle.cpp -o obj/Receptacle.o

obj/Sensor.o: src/core/Sensor.cpp src/core/Sensor.h src/core/Block.h src/core/Player.h
	g++ -g -Wall -c src/core/Sensor.cpp -o obj/Sensor.o

obj/Trap.o: src/core/Trap.cpp src/core/Trap.h src/core/Block.h src/core/Player.h
	g++ -g -Wall -c src/core/Trap.cpp -o obj/Trap.o			

obj/Level.o: src/core/Level.cpp	src/core/Level.h src/core/Player.h src/core/Block.h src/core/Cable.h src/core/Entity.h
	g++ -g -Wall -c src/core/Level.cpp -o obj/Level.o
	
clean:
	rm -f obj/*
	rm -f bin/*