#include "Tile.hpp"


//Screen dimension constants
const int SCREEN_WIDTH = 12*16;
const int SCREEN_HEIGHT = 12*16;

//The dimensions of the level
const int LEVEL_WIDTH = 12*16;
const int LEVEL_HEIGHT = 12*16;

class Jeu{
    public:
    SDL_Window* gWindow ;
    SDL_Renderer* gRenderer;
    Jeu(){
        gWindow=NULL;
        gRenderer=NULL;

    }
    bool init();


    //Box collision detector
    bool checkCollision( SDL_Rect a, SDL_Rect b );

    //Checks collision box against set of tiles
    bool touchesWall( SDL_Rect box, Tile* tiles[] );
    bool toucher(SDL_Rect box,SDL_Rect currentClip);

    //Sets tiles from tile map
    bool setTiles( Tile *tiles[] );


    protected:
    
};