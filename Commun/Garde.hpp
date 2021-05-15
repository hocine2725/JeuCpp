#ifndef GARDE_HPP
#define GARDE_HPP


#include "Personnage.hpp"

class Garde : public Personnage
{
    public:
		//Constructeur
    Garde(int v, int posX);

    //Destructeur
    //~Garde();
        
		bool checkJoueur(SDL_Rect a);


		void deplacement(Tile *tiles[]);



    SDL_Rect clip[4][4];


    protected:
        //Distance jusqu'à laquelle peut voir le garde
        int vision;



        int mVelY;

};

#endif