#ifndef OBJET_HPP
#define OBJET_HPP

#include <SDL.h>

class Objet
{
public:
    //Constructeur
    Objet(int t, int x, int y);

    //Destructeur
    // ~Objet();

    //Pour faire disparaitre l'objet une fois ramasse
    void set() {clip.w = 0; clip.h = 0;}

	//Getters et setters
    
    SDL_Rect getBox() { return oBox; }
    SDL_Rect getClip() { return clip; }
    int getX() { return x; }
    int getY() { return y; }
    int getType() { return type; }

    bool getRamasse() { return ramassee; }

    void setRamasse(bool b) { ramassee = b; }


    // A mettre en protected mais ne fonctionne pas
    bool ramassee;

protected:
    //Type d'objet
    int type;
    int x;
    int y;
    SDL_Rect oBox; // pour la collision
    SDL_Rect clip; // cest pour delimiter la frame sur l'image
                   //Position et taille de l'objet
};

#endif