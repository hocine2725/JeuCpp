all: Personnage.o Objet.o Joueur.o Garde.o Objet.o exec




	
Personnage.o: Personnage.cpp Personnage.hpp
	g++ -g -c -I/usr/include/SDL2 Personnage.cpp -lSDL2_image -lSDL2_ttf -lSDL2

Garde.o: Garde.cpp Garde.hpp
	g++ -g -c -I/usr/include/SDL2 Garde.cpp -lSDL2_image -lSDL2_ttf -lSDL2

Objet.o: Objet.cpp Objet.hpp
	g++ -g -c -I/usr/include/SDL2 Objet.cpp -lSDL2_image -lSDL2_ttf -lSDL2

Joueur.o: Joueur.cpp Joueur.hpp
	g++ -g -c -I/usr/include/SDL2 Joueur.cpp -lSDL2_image -lSDL2_ttf -lSDL2
	
LTexture.o: LTexture.cpp LTexture.hpp
	g++ -g -c -I/usr/include/SDL2 LTexture.cpp -lSDL2_image -lSDL2_ttf -lSDL2

Tile.o: Tile.cpp Tile.hpp
	g++ -g -c -I/usr/include/SDL2 Tile.cpp -lSDL2_image -lSDL2_ttf -lSDL2

Jeu.o: Jeu.cpp Jeu.hpp
	g++ -g -c -I/usr/include/SDL2 Jeu.cpp -lSDL2_image -lSDL2_ttf -lSDL2

Dot.o: Dot.cpp Dot.hpp
	g++ -g -c -I/usr/include/SDL2 Dot.cpp -lSDL2_image -lSDL2_ttf -lSDL2

exec.o: exec.cpp Jeu.hpp
	g++ -g -c -I/usr/include/SDL2 exec.cpp -lSDL2_image -lSDL2_ttf -lSDL2
	
exec: LTexture.o Tile.o Jeu.o Joueur.o Personnage.o Garde.o exec.o Objet.o
	g++ -o exec LTexture.o Tile.o Jeu.o Joueur.o Personnage.o Garde.o Objet.o exec.o  -lSDL2_image -lSDL2_ttf -lSDL2


clean:
	rm -f *.o

	
