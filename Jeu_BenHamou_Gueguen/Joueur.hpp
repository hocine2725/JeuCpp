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
	Joueur(std::string n, int i);

	//Destructeur
	// ~Joueur();

	//Prends les entrees calvier
	void evenement(SDL_Event &e);
	void evenement2(SDL_Event &e); // Methode a modifier pour l'IA

	//Deplace le joueur
	void deplacement(Tile *tiles[]);

	//Permet au joueur de ramasser l'objet
	bool ramasserObjet(Objet &o);

	void frameUpdate();

	//Pour corrompre et tuer le garde
	void corruption();
	bool tirer();
	
	//Pour l'IA
	void corruption2();
	bool tirer2();

	//Pour verifier les actions faites par le joueur
	int action(Garde garde);

	//Verifie si je joueur a terminé
	bool fin(Joueur j2);

	//Getters et setters

	bool getArmee() { return armee; }
	void setArme(bool armee) { this->armee = armee; }

	int getMoney() { return money; }
	std::string getNom() { return nom; }

	SDL_Rect clip[4][4];

protected:
	//Nom du joueur
	std::string nom;

	char key[512];

	bool armee;

	int money;

	bool cle;

	int id;

	bool tire;

	bool paye;
};

#endif