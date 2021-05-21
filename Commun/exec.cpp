#include "Jeu.hpp"

#include "Arme.hpp"
#include "Objet.hpp"
#include "Argent.hpp"

#include <SDL2/SDL_ttf.h>



int main( int argc, char* args[] )
{
    ////////////////////////////////////////////////
    SDL_Rect gTileClips[ TOTAL_TILE_SPRITES ];
    ///////////////////////////////////////////////

    Jeu jeu;
    if( !jeu.init() )
	{
		printf( "Failed to initialize!\n" );
	}

    else
	{
		//The level tiles
		/*int w, h;
		SDL_Texture *img = NULL;
		img = IMG_LoadTexture(jeu.gRenderer, "/hello_world.bmp");
		SDL_QueryTexture(img, NULL, NULL, &w, &h);*/


		//Load media
		if( !jeu.loadMedia( jeu.tileSet,jeu.gRenderer, gTileClips) )
		{
			printf( "Failed to load media!\n" );
		}
		

        else
		{
			


			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//The dot that will be moving around on the screen
			Joueur joueur("lea", 1);

		

			Garde garde(100, 30, 30, true);
			// Garde garde2(100, 380, 20, true);
			Garde garde2(100, 50, 20, false);

			int m=0;
			int n=0;

			
			Arme arme(200,150);

			Argent money(280,200);		

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					if(e.type==SDL_MOUSEMOTION){
							n=e.motion.x;
							m=e.motion.y;
							////std::cout<<"x"<<n<<std::endl;
							//std::cout<<"y"<<m<<std::endl;
					}

					//Handle input for the joueur
					joueur.evenement(e);
					
				}

				SDL_SetRenderDrawColor( jeu.gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( jeu.gRenderer );
		
				joueur.frameUpdate();

			
				jeu.jeuUpdate(gTileClips,joueur,garde,garde2);

				joueur.deplacement(jeu.tileSet);
				garde.deplacement(jeu.tileSet);
				garde2.deplacement(jeu.tileSet);


				if( ( (!garde.getMort()) && garde.checkJoueur(joueur.getMBox())) || ( (!garde2.getMort()) && garde2.checkJoueur(joueur.getMBox()) ) ){
					//std::cout<<"perdu, position garde : "<<garde.getMBox().y<<", position joueur :"<<joueur.getMBox().y<<std::endl;
					std::cout<<"perdu, delta position : "<<garde.getMBox().y - joueur.getMBox().y<<std::endl;
					//std::cout<<"perdu"<<std::endl;
					
				}


				
				if(joueur.tire==true && garde.checkCollision(joueur.getMBox())){
					std::cout<<"poignardé"<<std::endl;
					garde.setMort(true);
				}


				SDL_Rect armeBox=arme.getClip();
				SDL_Rect MoneyBox=money.getClip();
				
			
				jeu.ArmeTexture.render(jeu.gRenderer,arme.getX(),arme.getY(),&armeBox);
				jeu.MoneyTexture.render(jeu.gRenderer,money.getX(),money.getY(),&MoneyBox);
			
				
				bool rama=joueur.ramasserObjet(arme);
				if (rama){
					arme.set();
				}

				bool rama2=joueur.ramasserObjet(money);
				if (rama2){
					money.set();
				}
		


				SDL_RenderPresent( jeu.gRenderer );
				
			}

			//gSpriteSheetTexture.free();
			//(*tileSet)->close( tileSet, jeu.gTileTexture, jeu.gRenderer);


		}

		
	}

	return 0;
}


