compile:
	g++ -c test.cpp && g++ test.o -o pacman -lsfml-graphics -lsfml-window -lsfml-system
run:
	./pacman
	
