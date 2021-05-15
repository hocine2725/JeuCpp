#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>

#include "Dot.hpp"


//The tile
class Jeu
{
    public:
    Jeu(){
        SDL_Window* gWindow = NULL;
        SDL_Renderer* gRenderer = NULL;
    }
    bool init();
     bool loadMedia( Tile* tiles[],SDL_Renderer* gRenderer,SDL_Rect* gTileClips);

    bool setTiles( Tile* tiles[],SDL_Rect* gTileClips );
   
  

    SDL_Window* gWindow ;

    SDL_Renderer* gRenderer;
    LTexture gDotTexture;
    LTexture gTileTexture;

    private:
   

};