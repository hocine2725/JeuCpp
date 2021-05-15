#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP


#include "Tile.hpp"

class Personnage
{
    public:
		//Les dimensions des Personnage
		static const int PERSONNAGE_WIDTH = 20;
		static const int PERSONNAGE_HEIGHT = 20;
		static const int PERSONNAGE_VEL = 10;

		//Constructeur
        Personnage();

		//Destructeur
        ~Personnage();
        
		bool checkCollision( SDL_Rect a);

		bool touchesWall(Tile* tiles[] );

		//Methode virtuelle pure
		virtual void move( Tile *tiles[], SDL_Rect currentClip ) = 0;

		//Affiche le personnage sur l'ecran
		void render(SDL_Renderer* gRenderer,LTexture gPersonnageTexture);



    protected:
		//Position et taille du personnage
        SDL_Rect mBox;

		//Vitesse du personnage
		int vitesse;

		//Le personnage possede un objet
		bool objet;

};

#endif