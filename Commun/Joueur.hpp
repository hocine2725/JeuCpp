#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <list>

#include "Personnage.hpp"
#include "Garde.hpp"

#include <vector>
using std::vector;

class Joueur : public Personnage
{
public:
	//Constructeur

	bool tire;

	bool paye;
	Joueur(std::string n, int i);

	//Destructeur
	//~Joueur();

	//Prends les entrees calvier
	void evenement(SDL_Event &e);
	void evenement2(SDL_Event &e);

	void deplacement(Tile *tiles[]);

	bool ramasserObjet(Objet &o);

	bool getArmee() { return armee; }

	void frameUpdate();

	void corruption();
	int getMoney(){return money;}

	void tirer();

	int action(Garde garde);

	//SDL_Rect** getClip(){return clip;} //todo : mettre en protected
	SDL_Rect clip[4][4];

protected:
	//Nom du joueur
	std::string nom;
	char key[512];
	bool armee;

	int money;

	bool cle;

	int id;

	//SDL_Rect clip[4][4];

	int mVelX, mVelY;
};

#endif