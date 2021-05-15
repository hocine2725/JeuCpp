#ifndef JOUEUR_HPP
#define JOUEUR_HPP


#include "Tile.hpp"

class Joueur : public Personnage
{
    public:
		//Constructeur
        Joueur();

        //Destructeur
        ~Joueur();
        
        //Prends les entrees calvier
		void handleEvent( SDL_Event& e );

		//Methode virtuelle pure
		void move( Tile *tiles[], SDL_Rect currentClip ) = 0;



    protected:
		//Nom du joueur
        std::string nom;

        int id;
};

#endif