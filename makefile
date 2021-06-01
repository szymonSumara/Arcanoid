make:
	g++ -c -Weffc++ main.cpp -I /usr/share/doc/libsfml-dev/include
	g++ -c -Weffc++ ./engines/gameEngine.cpp -I /usr/share/doc/libsfml-dev/include
	g++ -c -Weffc++ ./engines/collisionEngine.cpp -I /usr/share/doc/libsfml-dev/include
	g++ -c -Weffc++ ./engines/mapObjectGenerator.cpp -I /usr/share/doc/libsfml-dev/include
	g++ -c -Weffc++ ./engines/visualizationEngine.cpp -I /usr/share/doc/libsfml-dev/include
	g++ -c -Weffc++ ./components/playerBar.cpp -I /usr/share/doc/libsfml-dev/include
	g++ -c -Weffc++ ./components/brick.cpp -I /usr/share/doc/libsfml-dev/include
	g++ -c -Weffc++ ./components/ball.cpp -I /usr/share/doc/libsfml-dev/include
	g++ main.o gameEngine.o collisionEngine.o ball.o visualizationEngine.o brick.o mapObjectGenerator.o playerBar.o -o sfml-app -L /usr/share/doc/libsfml-dev/lib -lsfml-graphics -lsfml-window -lsfml-system

run:
	make
	./sfml-app
	
clear:
	rm -rf *.o

