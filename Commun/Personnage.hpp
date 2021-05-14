#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP


#include "Tile.hpp"

#include "Objet.hpp"

class Personnage
{
    public:
		//Les dimensions des Personnage
		static const int PERSONNAGE_WIDTH = 20;
		static const int PERSONNAGE_HEIGHT = 30;
		static const int PERSONNAGE_VEL = 4;

		//Constructeur
        Personnage();

		//Destructeur
        //~Personnage();

		//Methode virtuelle pure
		virtual void deplacement(Tile *tiles[]) = 0;
        
		bool checkCollision(SDL_Rect a);

		bool touchesWall(Tile* tiles[]);

		bool ramasserObjet(Objet o);

		SDL_Rect getMBox(){return mBox;}
		
		int getCurrent_clip(){return current_clip;}

		int getFrame(){return frame;}

    	void setFrame(int f){frame = f;}


    protected:
		//Position et taille du personnage
        SDL_Rect mBox;

		//Vitesse du personnage
		int mVelX, mVelY;

		//Le personnage possede un objet
		bool objet;

   		int current_clip = 1;

        int frame;

};

#endif