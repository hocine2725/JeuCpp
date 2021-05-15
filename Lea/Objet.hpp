#ifndef OBJET_HPP
#define OBJET_HPP


#include "Tile.hpp"

class Objet
{
    public:
		//Constructeur
        Objet();
        
        //Destructeur
        ~Objet();


    protected:
        //Type d'objet
        int type;

        //Position de l'objet
        int posX;
        int posY;
};

#endif