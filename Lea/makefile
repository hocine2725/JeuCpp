all:LTexture.o Tile.o Jeu.o Dot.o exec.o Utile.o exec




Utile.o: Utile.cpp Utile.hpp
	g++ -g -c -I/usr/include/SDL2 Utile.cpp -lSDL2_image -lSDL2_ttf -lSDL2
	
LTexture.o: LTexture.cpp LTexture.hpp
	g++ -g -c -I/usr/include/SDL2 LTexture.cpp -lSDL2_image -lSDL2_ttf -lSDL2
Tile.o: Tile.cpp Tile.hpp LTexture.hpp
	g++ -g -c -I/usr/include/SDL2 Tile.cpp -lSDL2_image -lSDL2_ttf -lSDL2
Jeu.o: Jeu.cpp Jeu.hpp LTexture.hpp Tile.hpp
	g++ -g -c -I/usr/include/SDL2 Jeu.cpp -lSDL2_image -lSDL2_ttf -lSDL2

Dot.o: Dot.cpp Dot.hpp Jeu.hpp Utile.hpp
	g++ -g -c -I/usr/include/SDL2 Dot.cpp -lSDL2_image -lSDL2_ttf -lSDL2

exec.o: exec.cpp Jeu.hpp
	g++ -g -c -I/usr/include/SDL2 exec.cpp -lSDL2_image -lSDL2_ttf -lSDL2
	
exec:LTexture.o Tile.o Jeu.o Dot.o exec.o
	g++ -o exec LTexture.o Tile.o Jeu.o Dot.o Utile.o exec.o -lSDL2_image -lSDL2_ttf -lSDL2


clean:
	rm -f *.o

	
