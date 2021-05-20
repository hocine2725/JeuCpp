#include "Jeu.hpp"

#include "Arme.hpp"
#include "Objet.hpp"
#include "Argent.hpp"

#include <SDL2/SDL_ttf.h>

bool Collision( SDL_Rect a, SDL_Rect b )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}



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
		Tile* tileSet[ TOTAL_TILES ];


		//Load media
		if( !jeu.loadMedia( tileSet,jeu.gRenderer, gTileClips) )
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

		

			Garde garde(100, 30);
			Garde garde2(100, 380);

			int m=0;
			int n=0;

			SDL_Rect gSpriteClips[1];
			//LTexture gSpriteSheetTexture;
			//jeu.gTileTexture.loadFromFile("tiles.png",jeu.gRenderer );

			//gSpriteSheetTexture.loadFromFile( "hero1.png" ,jeu.gRenderer);
			gSpriteClips[ 0 ].x = 0;
			gSpriteClips[ 0 ].y = 32*4;
			gSpriteClips[ 0 ].w = 32;
			gSpriteClips[ 0 ].h = 32;

			//SDL_Rect* currentClip = &gSpriteClips[0];
			
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
		
				if( joueur.getFrame()/4 >=4 ){
					 //std::cout<<"zero"<<std::endl;
					joueur.setFrame(0);
				}	

				//gSpriteSheetTexture.render(jeu.gRenderer, ( SCREEN_WIDTH - currentClip->w ) / 2, ( SCREEN_HEIGHT - currentClip->h ) / 2 , currentClip );
				for( int i = 0; i < TOTAL_TILES; ++i )
				{	

					//tileSet[ i ]->render(gTileClips,jeu.gDotTexture,jeu.gRenderer);
					jeu.gTileTexture.render(jeu.gRenderer, tileSet[i]->getBox().x, tileSet[i]->getBox().y , &gTileClips[ tileSet[i]->getType()]);
				}
		
				joueur.deplacement(tileSet);
				garde.deplacement(tileSet);
				garde2.deplacement(tileSet);
				if(garde.checkJoueur(joueur.getMBox()) || garde2.checkJoueur(joueur.getMBox())){
					//std::cout<<"perdu, position garde : "<<garde.getMBox().y<<", position joueur :"<<joueur.getMBox().y<<std::endl;
					std::cout<<"perdu, delta position : "<<garde.getMBox().y - joueur.getMBox().y<<std::endl;
					//std::cout<<"perdu"<<std::endl;
					
				}


				//gSpriteSheetTexture.render(jeu.gRenderer,dot.getMBox().x,dot.getMBox().y,&gSpriteClips[0]);

				jeu.gPersonnageTexture.render(jeu.gRenderer,joueur.getMBox().x,joueur.getMBox().y,&joueur.clip[joueur.getFrame()/4][joueur.getCurrent_clip()]);

				
				
				jeu.gGardeTexture.render(jeu.gRenderer,garde.getMBox().x,garde.getMBox().y,&garde.clip[garde.getFrame()/4][garde.getCurrent_clip()]);
				jeu.gGardeTexture.render(jeu.gRenderer,garde2.getMBox().x,garde2.getMBox().y,&garde2.clip[garde2.getFrame()/4][garde2.getCurrent_clip()]);
				
				if(joueur.tire==true){
					if(Collision(garde.getMBox(),joueur.getMBox())){
						std::cout<<"poignardé"<<std::endl;
					}

				}

				

				/*SDL_Rect BalleBox;
				Balle b =joueur.my_list.at(0);

				BalleBox=b.getClip();

				std::cout<<"main!"<<b.getBox().y<<std::endl;
				jeu.BalleTexture.render(jeu.gRenderer,b.getBox().x,b.getBox().y,&BalleBox);*/
					
				

				
				//std::cout<<BalleBox.y<<std::endl;

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
			(*tileSet)->close( tileSet, jeu.gTileTexture, jeu.gRenderer);


		}

		
	}

	return 0;
}


