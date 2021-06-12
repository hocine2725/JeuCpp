#include "Jeu.hpp"

#include "Objet.hpp"

#include <SDL2/SDL_ttf.h>

#include <string>
#include <thread>
#include <chrono>

int main(int argc, char *args[])
{
	////////////////////////////////////////////////
	SDL_Rect gTileClips[TOTAL_TILE_SPRITES];
	///////////////////////////////////////////////

	Jeu jeu;

	int fin = 0;

	if (!jeu.init())
	{
		printf("Failed to initialize!\n");
	}

	else
	{

		//Load media
		if (!jeu.loadMedia(jeu.tileSet, jeu.gRenderer, gTileClips))
		{
			printf("Failed to load media!\n");
		}

		else
		{

			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//Les deux personnages
			Joueur joueur("lea", 1);
			Joueur joueur2("hocine", 0);

			Garde garde(100, 30, 30, true);
			Garde garde2(100, 50, 20, false);
			Garde garde3(100, 380, 300, true);

			int m = 0;
			int n = 0;

			//Les objets
			Objet arme(1, 200, 150);
			Objet money(2, 280, 200);
			Objet cle(3, 700, 200);

			//Le texte
			TTF_Init();
			TTF_Font *Sans = TTF_OpenFont("Images/Sans.ttf", 65);

			if (Sans == nullptr)
			{
				std::cout << "null" << std::endl;
			}

			SDL_Color Color = {0, 0, 0};

			SDL_Rect Message_rect;	  //create a rect
			Message_rect.x = 200;	  //controls the rect's x coordinate
			Message_rect.y = 450;	  // controls the rect's y coordinte
			Message_rect.w = 700; // controls the width of the rect
			Message_rect.h = 250 / 4; // controls the height of the rect

			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
					if (e.type == SDL_MOUSEMOTION)
					{
						n = e.motion.x;
						m = e.motion.y;
						// std::cout<<"x"<<n<<std::endl;
						// std::cout<<"y"<<m<<std::endl;
					}

					//Handle input for the joueur
					joueur.evenement(e);
					joueur2.evenement2(e);
				}

				SDL_SetRenderDrawColor(jeu.gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(jeu.gRenderer);

				std::string s = "Argent restant a " + joueur.getNom() + " : " + std::to_string(joueur.getMoney()) + "      Argent restant a " + joueur2.getNom() + " : " + std::to_string(joueur2.getMoney());

				int n = s.length();

				// declaring character array
				char char_array[n + 1];

				// copying the contents of the
				// string to char array
				strcpy(char_array, s.c_str());

				SDL_Surface *surfaceMessage = TTF_RenderText_Solid(Sans, char_array, Color);
				SDL_Texture *Message = SDL_CreateTextureFromSurface(jeu.gRenderer, surfaceMessage);

				joueur.frameUpdate();
				joueur2.frameUpdate();

				jeu.jeuUpdate(gTileClips, joueur, joueur2, garde, garde2, garde3);

				joueur.deplacement(jeu.tileSet);
				joueur2.deplacement(jeu.tileSet);
				garde.deplacement(jeu.tileSet);
				garde2.deplacement(jeu.tileSet);
				garde3.deplacement(jeu.tileSet);

				// Si on a perdu, le jeu se ferme
				if (joueur.action(garde) == 0 || joueur.action(garde2) == 0 || joueur.action(garde3) == 0 || joueur2.action(garde) == 0 || joueur2.action(garde2) == 0 || joueur2.action(garde3) == 0)
				{
					fin = 1;
					quit = true;
				}

				// Ne fonctionne pas dans la methode
				if (joueur.action(garde) == 1 || joueur2.action(garde) == 1)
				{
					garde.setMort(true);
				}
				if (joueur.action(garde2) == 1 || joueur2.action(garde2) == 1)
				{
					garde2.setMort(true);
				}
				if (joueur.action(garde3) == 1 || joueur2.action(garde3) == 1)
				{
					garde3.setMort(true);
				}

				//Si on a gagne, le jeu se ferme
				if (joueur.fin(joueur2))
				{
					fin = 2;
					std::cout << "Gagné !!" << std::endl;
					quit = true;
				}

				SDL_Rect armeBox = arme.getClip();
				SDL_Rect MoneyBox = money.getClip();
				SDL_Rect cleBox = cle.getClip();

				jeu.ArmeTexture.render(jeu.gRenderer, arme.getBox().x, arme.getBox().y, &armeBox);
				jeu.MoneyTexture.render(jeu.gRenderer, money.getBox().x, money.getBox().y, &MoneyBox);
				jeu.CleTexture.render(jeu.gRenderer, cle.getBox().x, cle.getBox().y, &cleBox);

				joueur.ramasserObjet(arme);
				joueur.ramasserObjet(money);
				joueur.ramasserObjet(cle);

				joueur2.ramasserObjet(arme);
				joueur2.ramasserObjet(money);
				joueur2.ramasserObjet(cle);

				SDL_RenderCopy(jeu.gRenderer, Message, NULL, &Message_rect);

				SDL_RenderPresent(jeu.gRenderer);
			}

			if (fin == 1)
			{
				if (!jeu.perdu())
				{
					printf("Failed to load media!\n");
				}
			}
			if (fin == 2)
			{
				if (!jeu.gagne())
				{
					printf("Failed to load media!\n");
				}
			}

			//gSpriteSheetTexture.free();
			//(*tileSet)->close( tileSet, jeu.gTileTexture, jeu.gRenderer);
		}
	}
	jeu.close(jeu.tileSet, jeu.gRenderer, gTileClips);
	return 0;
}
