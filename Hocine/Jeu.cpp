
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>



#include "Jeu.hpp"





bool Jeu::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}


bool Jeu::loadMedia( Tile* tiles[] ,SDL_Renderer* gRenderer,SDL_Rect* gTileClips )
{
	//Loading success flag
	bool success = true;

	//Load dot texture
	if( !gDotTexture.loadFromFile( "dot.bmp",gRenderer  ) )
	{
		printf( "Failed to load dot texture!\n" );
		success = false;
	}

	//Load tile texture
	if( !gTileTexture.loadFromFile("carte.png",gRenderer ) )
	{
		printf( "Failed to load tile set texture!\n" );
		success = false;
	}

	//Load tile map

	if( !setTiles( tiles , gTileClips ))
	{
		printf( "Failed to load tile set!\n" );
		success = false;
	}

	return success;
}



bool Jeu:: setTiles( Tile* tiles[],SDL_Rect* gTileClips )
{
	//Success flag
	bool tilesLoaded = true;

    //The tile offsets
    int x = 0, y = 0;

    //Open the map
    std::ifstream map( "lazy.map" );

    //If the map couldn't be loaded
    if( map.fail() )
    {
		printf( "Unable to load map file!\n" );
		tilesLoaded = false;
    }
	else
	{
		//Initialize the tiles
		for( int i = 0; i < TOTAL_TILES; ++i )
		{
			//Determines what kind of tile will be made
			int tileType = -1;

			//Read tile from map file
			map >> tileType;
			//std::cout<<"arret"<<std::endl;
			//std::cout<<tileType<<std::endl;
			//If the was a problem in reading the map
			if( map.fail() )
			{
				//Stop loading map
				printf( "Error loading map: Unexpected end of file!\n" );
				tilesLoaded = false;
				break;
			}

			//If the number is a valid tile number
			if( ( tileType >= 0 ) )
			{
				tiles[ i ] = new Tile( x, y, tileType );
				//std::cout<< tiles[i]->getType()<<std::endl;
			}
			//If we don't recognize the tile type
			else
			{
				//Stop loading map
				printf( "Error loading map: Invalid tile type at %d!\n", i );
				tilesLoaded = false;
				break;
			}

			//Move to next tile spot
			x += TILE_WIDTH;

			//If we've gone too far
			if( x >= LEVEL_WIDTH )
			{
				//Move back
				x = 0;

				//Move to the next row
				y += TILE_HEIGHT;
			}
		}
		
		//Clip the sprite sheet
		if( tilesLoaded )
		{
			gTileClips[ T1 ].x = 0;
			gTileClips[ T1 ].y = 0;
			gTileClips[ T1 ].w = TILE_WIDTH;
			gTileClips[ T1 ].h = TILE_HEIGHT;

			gTileClips[T2].x = 32;
			gTileClips[T2].y = 0;
			gTileClips[T2].w = TILE_WIDTH;
			gTileClips[T2].h = TILE_HEIGHT;

			gTileClips[T3].x = 32*2;
			gTileClips[T3].y = 0;
			gTileClips[T3].w = TILE_WIDTH;
			gTileClips[T3].h = TILE_HEIGHT;

			gTileClips[T4].x = 32*2;
			gTileClips[T4].y = 0;
			gTileClips[T4].w = TILE_WIDTH;
			gTileClips[T4].h = TILE_HEIGHT;

			gTileClips[T5].x = 32*4;
			gTileClips[T5].y = 0;
			gTileClips[T5].w = TILE_WIDTH;
			gTileClips[T5].h = TILE_HEIGHT;

			gTileClips[T6].x = 32*5;
			gTileClips[T6].y = 0;
			gTileClips[T6].w = TILE_WIDTH;
			gTileClips[T6].h = TILE_HEIGHT;


			gTileClips[T7].x = 32*6;
			gTileClips[T7].y = 0;
			gTileClips[T7].w = TILE_WIDTH;
			gTileClips[T7].h = TILE_HEIGHT;

			gTileClips[T8].x = 0;
			gTileClips[T8].y = 32;
			gTileClips[T8].w = TILE_WIDTH;
			gTileClips[T8].h = TILE_HEIGHT;


		}
	
		
			
	}

    //Close the file
    map.close();

    //If the map was loaded fine
    return tilesLoaded;
}











