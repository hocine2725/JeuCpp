#ifndef OBJET_HPP
#define OBJET_HPP

#include <SDL.h>

class Objet
{
public:
    bool ramassee;
    //Constructeur
    Objet(int t, int x, int y);

    //Destructeur
    // ~Objet();
    void set()
    {
        clip.w = 0;
        clip.h = 0;
    }

    // void set(int x, int y)
    // {
    //     oBox.x = x;
    //     oBox.y = y;
    // }
    SDL_Rect getBox() { return oBox; }
    SDL_Rect getClip() { return clip; }
    int getX() { return x; }
    int getY() { return y; }
    int getType() { return type; }

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