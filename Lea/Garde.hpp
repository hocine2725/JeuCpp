#ifndef GARDE_HPP
#define GARDE_HPP


#include "Tile.hpp"

class Garde : public Personnage
{
    public:
		//Constructeur
        Garde();

        //Destructeur
        ~Garde();
        
		bool checkJoueur( SDL_Rect a);


		//Methode virtuelle pure
		void move( Tile *tiles[], SDL_Rect currentClip ) = 0;


    protected:
        //Distance jusqu'à laquelle peut voir le garde
        int vision;
};

#endif