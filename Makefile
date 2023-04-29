all: bin/main_txt

sfml: bin/main_sfml

bin/main_sfml: obj/Main_sfml.o obj/sfmlJeu.o obj/Block.o obj/Cable.o obj/Entity.o obj/Level.o obj/Pickable.o obj/Platform.o obj/Player.o obj/Receptacle.o obj/Sensor.o obj/Trap.o obj/Vector2D.o obj/Gate.o obj/Door.o obj/playerSfml.o obj/sensorSfml.o obj/blockSfml.o obj/Menu.o obj/Button.o obj/Generator.o
	g++ -g -Wall -o bin/main_sfml obj/Main_sfml.o obj/sfmlJeu.o obj/Block.o obj/Cable.o obj/Entity.o obj/Level.o obj/Pickable.o obj/Platform.o obj/Player.o obj/Receptacle.o obj/Sensor.o obj/Trap.o obj/Vector2D.o obj/Gate.o obj/Door.o obj/playerSfml.o obj/sensorSfml.o obj/blockSfml.o obj/Menu.o obj/Button.o obj/Generator.o -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

bin/main_txt: obj/Main_txt.o obj/winTxt.o obj/txtJeu.o obj/Block.o obj/Cable.o obj/Entity.o obj/Level.o obj/Pickable.o obj/Platform.o obj/Player.o obj/Receptacle.o obj/Sensor.o obj/Trap.o obj/Vector2D.o obj/Gate.o obj/Door.o
	g++ -g -Wall -o bin/main_txt obj/Main_txt.o obj/winTxt.o obj/txtJeu.o obj/Block.o obj/Cable.o obj/Entity.o obj/Level.o obj/Pickable.o obj/Platform.o obj/Player.o obj/Receptacle.o obj/Sensor.o obj/Trap.o obj/Vector2D.o obj/Gate.o obj/Door.o

obj/Main_sfml.o: src/sfml/main_sfml.cpp src/sfml/sfmlJeu.h src/core/Level.h
	g++ -g -Wall -c src/sfml/main_sfml.cpp -o obj/Main_sfml.o

obj/Main_txt.o: src/txt/main_txt.cpp src/txt/winTxt.h src/txt/txtJeu.h src/core/Level.h
	g++ -g -Wall -c src/txt/main_txt.cpp -o obj/Main_txt.o

obj/sfmlJeu.o: src/sfml/sfmlJeu.cpp src/sfml/sfmlJeu.h src/core/Level.h src/sfml/playerSfml.h
	g++ -g -Wall -c src/sfml/sfmlJeu.cpp -o obj/sfmlJeu.o	

obj/blockSfml.o: src/sfml/blockSfml.cpp src/sfml/blockSfml.h src/core/Level.h
	g++ -g -Wall -c src/sfml/blockSfml.cpp -o obj/blockSfml.o	

obj/playerSfml.o: src/sfml/playerSfml.cpp src/sfml/playerSfml.h src/core/Player.h
	g++ -g -Wall -c src/sfml/playerSfml.cpp -o obj/playerSfml.o

obj/sensorSfml.o: src/sfml/sensorSfml.cpp src/sfml/sensorSfml.h src/core/Player.h src/core/Sensor.h
	g++ -g -Wall -c src/sfml/sensorSfml.cpp -o obj/sensorSfml.o	

obj/winTxt.o: src/txt/winTxt.cpp src/txt/winTxt.h
	g++ -g -Wall -c src/txt/winTxt.cpp -o obj/winTxt.o

obj/txtJeu.o: src/txt/txtJeu.cpp src/txt/txtJeu.h src/core/Level.h
	g++ -g -Wall -c src/txt/txtJeu.cpp -o obj/txtJeu.o	

obj/Generator.o: src/core/Generator.cpp src/core/Generator.h src/core/Enum.h src/core/Block.h src/core/Player.h
	g++ -g -Wall -c src/core/Generator.cpp -o obj/Generator.o

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

obj/Gate.o: src/core/Gate.cpp src/core/Gate.h src/core/Block.h src/core/Player.h src/core/Vector2D.h
	g++ -g -Wall -c src/core/Gate.cpp -o obj/Gate.o	

obj/Door.o: src/core/Door.cpp src/core/Door.h src/core/Block.h src/core/Player.h src/core/Enum.h
	g++ -g -Wall -c src/core/Door.cpp -o obj/Door.o	

obj/Trap.o: src/core/Trap.cpp src/core/Trap.h src/core/Block.h src/core/Player.h
	g++ -g -Wall -c src/core/Trap.cpp -o obj/Trap.o			

obj/Level.o: src/core/Level.cpp	src/core/Level.h src/core/Player.h src/core/Block.h src/core/Cable.h src/core/Entity.h src/core/Vector2D.h src/core/Gate.h
	g++ -g -Wall -c src/core/Level.cpp -o obj/Level.o

obj/Vector2D.o: src/core/Vector2D.cpp src/core/Vector2D.h
	g++ -g -Wall -c src/core/Vector2D.cpp -o obj/Vector2D.o	

obj/Button.o : src/sfml/menu/Button.cpp src/sfml/menu/Button.h
	g++ -g -Wall -c src/sfml/menu/Button.cpp -o obj/Button.o

obj/Menu.o : src/sfml/menu/Menu.cpp src/sfml/menu/Menu.h src/sfml/menu/Button.h 
	g++ -g -Wall -c src/sfml/menu/Menu.cpp -o obj/Menu.o
	
clean:
	rm -f obj/*
	rm -f bin/*