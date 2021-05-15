#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>

#include "LTexture.hpp"



//Tile constants
const int TILE_WIDTH = 16;
const int TILE_HEIGHT = 16;
const int TOTAL_TILES = 12*12;
const int TOTAL_TILE_SPRITES = 2;

//The different tile sprites
const int TILE_RED = 5;
const int TILE_GREEN = 1;

SDL_Rect gTileClips[ TOTAL_TILE_SPRITES ];

//The tile
class Tile
{
    public:
		//Initializes position and type
		Tile( int x, int y, int tileType );

		//Shows the tile
		void render( SDL_Rect& camera, LTexture gTileTexture );

		//Get the tile type
		int getType();

		//Get the collision box
		SDL_Rect getBox();

		//Loads media
		bool loadMedia( Tile* tiles[],LTexture gDotTexture,LTexture gTileTexture);

		//Frees media and shuts down SDL
		void close( Tile* tiles[],LTexture gDotTexture,LTexture gTileTexture, SDL_Renderer* gRenderer, SDL_Window* gWindow);

    protected:
		//The attributes of the tile
		SDL_Rect mBox;

		//The tile type
		int mType;
};