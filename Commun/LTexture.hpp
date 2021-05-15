#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>

//Screen dimension constants
const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 640;

//The dimensions of the level
const int LEVEL_WIDTH = 960;
const int LEVEL_HEIGHT = 640;

//Tile constants
const int TILE_WIDTH = 32;
const int TILE_HEIGHT = 32;
const int TOTAL_TILES = 30*20;
const int TOTAL_TILE_SPRITES = 8;

//The different tile sprites
const int T1 = 0;
const int T2 = 1;
const int T3 = 2;
const int T4 = 3;
const int T5 = 4;
const int T6 = 5;
const int T7 = 6;
const int T8 = 7;
//Texture wrapper class

class LTexture
{
	public:
		//Initializes variables
		LTexture();

		//Deallocates memory
		~LTexture();

		//Loads image at specified path
		bool loadFromFile(std::string path ,SDL_Renderer* gRenderer);

		//Deallocates texture
		void free();

		//Set color modulation
		void setColor(Uint8 red, Uint8 green, Uint8 blue);

		//Set blending
		void setBlendMode(SDL_BlendMode blending);

		//Set alpha modulation
		void setAlpha(Uint8 alpha);
		
		//Renders texture at given point
		void render(SDL_Renderer* gRenderer,int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

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