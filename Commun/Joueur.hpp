#ifndef JOUEUR_HPP
#define JOUEUR_HPP


#include "Personnage.hpp"

class Joueur : public Personnage
{
    public:
		//Constructeur
    Joueur(std::string n, int i);

    //Destructeur
    //~Joueur();
        
    //Prends les entrees calvier
		void evenement(SDL_Event& e);

		void deplacement(Tile *tiles[]);

    bool ramasserObjet(Objet o);

    bool getArmee(){return armee;}

    //SDL_Rect** getClip(){return clip;} //todo : mettre en protected
    SDL_Rect clip[4][4];


    protected:
		//Nom du joueur
        std::string nom;

        bool armee;

        int money;

        int id;
        
        //SDL_Rect clip[4][4];


        int mVelX, mVelY;
};

#endif