/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, strings, and file streams
#include "Dot.hpp"


//Starts up SDL and creates window


//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Scene textures
LTexture gDotTexture;
LTexture gTileTexture;
SDL_Rect gTileClips[ TOTAL_TILE_SPRITES ];











SDL_Rect gSpriteClips[1];
LTexture gSpriteSheetTexture;





int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//The level tiles
		Tile* tileSet[ TOTAL_TILES ];

		//Load media
		if( !loadMedia( tileSet ) )
		{
			printf( "Failed to load media!\n" );
		}

		if( !loadMedia2( ) )
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

			//Level camera
			SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

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

					//Handle input for the dot
					dot.handleEvent( e );
				}

				//Move the dot
				dot.move( tileSet );
				dot.setCamera( camera );

				//Clear screen
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

				//Render level
				for( int i = 0; i < TOTAL_TILES; ++i )
				{
					tileSet[ i ]->render( camera );
				}
				SDL_Rect* currentClip = &gSpriteClips[0];
				
				gSpriteSheetTexture.render( ( SCREEN_WIDTH - currentClip->w ) / 2, ( SCREEN_HEIGHT - currentClip->h ) / 2, currentClip );
	
				//Render dot
				dot.render( camera );
				
				if(c!=1){
				petit.x = ( SCREEN_WIDTH - currentClip->w ) / 2;
				petit.y = ( SCREEN_HEIGHT - currentClip->h ) / 2;
				}
				bool a =toucher(dot.mBox,petit);
				//std::cout<<currentClip->x<<std::endl;
				//std::cout<<currentClip->y<<std::endl;


				//std::cout<<dot.mBox.x<<std::endl;


				if(a==true){
					currentClip->x=2000;
	
					currentClip->y=2000;

					petit.x = 2000;
					petit.y=2000;
					int c=1;
					std::cout<<"touche"<<std::endl;
				}

				//Update screen
				SDL_RenderPresent( gRenderer );
			}
		}
		
		//Free resources and close SDL
		close( tileSet );
	}

	return 0;
}