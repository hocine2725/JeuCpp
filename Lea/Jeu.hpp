
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
    bool setTiles(Tile* tiles[], SDL_Rect* gTileClips);
    bool loadMedia(Tile* tiles[], SDL_Renderer* gRenderer, SDL_Rect* gTileClips);
    bool loadPlayer(SDL_Renderer* gRenderer, SDL_Rect* gTileClips);


  

    SDL_Window* gWindow ;

    SDL_Renderer* gRenderer;
    LTexture gDotTexture;
    LTexture gTileTexture;

    private:
   

};