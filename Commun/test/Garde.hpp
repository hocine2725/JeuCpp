#ifndef GARDE_HPP
#define GARDE_HPP

#include "Personnage.hpp"

class Garde : public Personnage
{
public:
  //Constructeur
  Garde(int v, int posX, int posY, bool dir);

  //Destructeur
  //~Garde();

  bool checkJoueur(SDL_Rect a);

  void deplacement(Tile *tiles[]);

  //Getters et setters

  bool getMort() { return mort; }
  void setMort(bool m) { mort = m; }

  SDL_Rect clip[4][4];

protected:
  //Distance jusqu'à laquelle peut voir le garde
  int vision;

  bool mort = false;

  bool direction;

  int mVelY;
};

#endif