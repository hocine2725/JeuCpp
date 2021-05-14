#ifndef OBJET_HPP
#define OBJET_HPP

#include <SDL.h>

class Objet
{
    public:
		//Constructeur
        Objet(int x, int y){
    //Initialise l'emplacement et la boite pour la collision

            this->x=x;
            this->y=y;

            oBox.x = 0;
            oBox.y = 0;
	        oBox.w = 32;
	        oBox.h = 32;
    
    //Initialise le type d'objet
            type = 0;
            
}
        
        
        //Destructeur
       // ~Objet();

        SDL_Rect getBox(){return oBox;}

        int getX(){return x;}
        int getY(){return y;}

    protected:
        //Type d'objet
        int type;
        int x;
        int y;
        //Position et taille de l'objet
        SDL_Rect oBox;
};



#endif