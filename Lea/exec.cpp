#include "Jeu.hpp"

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
			int c=2;
			SDL_Rect petit;
			petit.x = 0;
			petit.y = 0;
			petit.w = 25;
			petit.h = 25;



			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//The dot that will be moving around on the screen
			Dot dot;

			int m=0;
			int n=0;

			SDL_Rect gSpriteClips[1];
			LTexture gSpriteSheetTexture;
//jeu.gTileTexture.loadFromFile("tiles.png",jeu.gRenderer );

			gSpriteSheetTexture.loadFromFile( "hero1.png" ,jeu.gRenderer);
			gSpriteClips[ 0 ].x =   0;
			gSpriteClips[ 0 ].y =   32*4;
			gSpriteClips[ 0 ].w =  32;
			gSpriteClips[ 0 ].h = 32;

			SDL_Rect* currentClip = &gSpriteClips[0];
			


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
							std::cout<<"x"<<n<<std::endl;
							std::cout<<"y"<<m<<std::endl;
					}

					//Handle input for the dot
					dot.handleEvent( e );
					
				}

				SDL_SetRenderDrawColor( jeu.gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( jeu.gRenderer );
				//std::cout<< gTileClips[ TILE_GREEN ].y<<std::endl;
				
				//gSpriteSheetTexture.render(jeu.gRenderer, ( SCREEN_WIDTH - currentClip->w ) / 2, ( SCREEN_HEIGHT - currentClip->h ) / 2 , currentClip );
				for( int i = 0; i < TOTAL_TILES; ++i )
				{	

					//tileSet[ i ]->render(gTileClips,jeu.gDotTexture,jeu.gRenderer);
					jeu.gTileTexture.render(jeu.gRenderer, tileSet[i]->getBox().x, tileSet[i]->getBox().y , &gTileClips[ tileSet[i]->getType()]);
				}
		
				dot.move( tileSet,petit);
				//std::cout<<dot.mBox.x<<std::endl;
				gSpriteSheetTexture.render(jeu.gRenderer,dot.mBox.x,dot.mBox.y,&gSpriteClips[0]);

				// work //jeu.gDotTexture.render(jeu.gRenderer,dot.mBox.x,dot.mBox.y,&gSpriteClips[0]);
				//dot.render( jeu.gRenderer,jeu.gDotTexture);

				SDL_RenderPresent( jeu.gRenderer );
				
			}

			gSpriteSheetTexture.free();
			(*tileSet)->close( tileSet, jeu.gTileTexture, jeu.gRenderer);


		}


		

	}

	return 0;
}