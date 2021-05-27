#include "Objet.hpp"

Objet::Objet(int t, int x, int y)
{
    //Initialise l'emplacement et la boite pour la collision
    this->type = t;
    this->x = x;
    this->y = y;
    this->oBox.x = x;
    this->oBox.y = y;
    this->oBox.h = 32;
    this->oBox.w = 32;
    this->clip.x = 0;
    this->clip.y = 0;
    if (t == 1) //Arme
    {
        this->clip.w = 46;
        this->clip.h = 19;
    }
    if (t == 2) //Argent
    {
        this->clip.w = 32;
        this->clip.h = 32;
    }
    if (t == 3)
    {
        this->clip.w = 27;
        this->clip.h = 40;
    }

    ramassee = false;

    //Initialise le type d'objet
    //type = 0;
}
