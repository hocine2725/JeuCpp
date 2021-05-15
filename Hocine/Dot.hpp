#ifndef DOT_HPP
#define DOT_HPP


#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>


#include "Tile.hpp"
#include"Utile.hpp"



//Screen dimension constants




class Dot
{
    public:
		//The dimensions of the dot
		static const int DOT_WIDTH = 20;
		static const int DOT_HEIGHT = 20;
		int mVelX, mVelY;
        SDL_Rect mBox;
		//Maximum axis velocity of the dot
		static const int DOT_VEL = 10;

		//Initializes the variables
		Dot();
		//Takes key presses and adjusts the dot's velocity
		void handleEvent( SDL_Event& e );

		//Moves the dot and check collision against tiles
		void move( Tile *tiles[], SDL_Rect currentClip );

	

		//Shows the dot on the screen
		void render( SDL_Renderer* gRenderer,LTexture gDotTexture);
		bool touchesWall( SDL_Rect box, Tile* tiles[] );

    private:
		//Collision box of the dot
		

		//The velocity of the dot
	
};

#endif