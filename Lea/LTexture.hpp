#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>

//Screen dimension constants
const int SCREEN_WIDTH = 12*16;
const int SCREEN_HEIGHT = 12*16;

//The dimensions of the level
const int LEVEL_WIDTH = 12*16;
const int LEVEL_HEIGHT = 12*16;

//Tile constants
const int TILE_WIDTH = 16;
const int TILE_HEIGHT = 16;
const int TOTAL_TILES = 12*12;
const int TOTAL_TILE_SPRITES = 2;

//The different tile sprites
const int TILE_RED = 0;
const int TILE_GREEN = 1;

//Texture wrapper class

class LTexture
{
	public:
		//Initializes variables
		LTexture();

		//Deallocates memory
		~LTexture();

		//Loads image at specified path
		bool loadFromFile( std::string path ,SDL_Renderer* gRenderer );

		//Deallocates texture
		void free();

		//Set color modulation
		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		//Set blending
		void setBlendMode( SDL_BlendMode blending );

		//Set alpha modulation
		void setAlpha( Uint8 alpha );
		
		//Renders texture at given point
		void render( SDL_Renderer* gRenderer,int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

		//Gets image dimensions
		int getWidth(){return mWidth;}
		int getHeight(){return mHeight;}


	private:
		//The actual hardware texture
		SDL_Texture* mTexture;

		//Image dimensions
		int mWidth;
		int mHeight;
};