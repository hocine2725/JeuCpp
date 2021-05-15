#include "exec.hpp"



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
			/*
			int c=2;
			SDL_Rect petit;
			petit.x = 0;
			petit.y = 0;
			petit.w = 25;
			petit.h = 25;
*/


			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//The dot that will be moving around on the screen
			Dot dot;

		int m=0;
		int n=0;
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

				for( int i = 0; i < TOTAL_TILES; ++i )
				{	

					tileSet[ i ]->render(gTileClips, jeu.gTileTexture, jeu.gRenderer);
				}
			


				SDL_RenderPresent( jeu.gRenderer );
				
			}
		}

		
	}

	return 0;
}