#ifndef DOT_HPP
#define DOT_HPP

#include "Tile.hpp"
#include "Utile.hpp"



//Screen dimension constants




class Dot
{
    public:
		//The dimensions of the dot
		static const int DOT_WIDTH = 24;
		static const int DOT_HEIGHT = 32;

		int frame;

		SDL_Rect clip[4][4];

		int curent_clip = 1;

		int mVelX, mVelY;
        SDL_Rect mBox;
		//Maximum axis velocity of the dot
		static const int DOT_VEL = 7;

		//Initializes the variables
		Dot();
		//Takes key presses and adjusts the dot's velocity
		void handleEvent( SDL_Event& e ,Tile *tiles[] );

		//Moves the dot and check collision against tiles
		void move( Tile *tiles[]);

	

		//Shows the dot on the screen
		void render( SDL_Renderer* gRenderer,LTexture gDotTexture);
		bool touchesWall( SDL_Rect box, Tile* tiles[] );

    private:
		//Collision box of the dot
		

		//The velocity of the dot
	
};

#endif