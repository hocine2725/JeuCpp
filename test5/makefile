main: main.o matrice.o vecteur.o
	g++ -o main matrice.o vecteur.o main.o

LTexture.o: LTexture.cpp LTexture.hpp
	g++ -g -c -I/usr/include/SDL2 LTexture.cpp -lSDL2_image -lSDL2_ttf -lSDL2

	
Jeu.o: Jeu.cpp Jeu.hpp Tile.hpp LTexture.hpp
	g++ -g -c -I/usr/include/SDL2 Jeu.cpp -lSDL2_image -lSDL2_ttf -lSDL2
	
Tile.o: Tile.cpp Tile.hpp
	g++ -g -c -I/usr/include/SDL2 Tile.cpp -lSDL2_image -lSDL2_ttf -lSDL2
 
main.o: main.cpp Jeu.hpp Tile.hpp LTexture.hpp
	g++ -g -c -I/usr/include/SDL2 main.cpp -lSDL2_image -lSDL2_ttf -lSDL2 


clean:
	rm -f *.o

	
