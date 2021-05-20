#include "Joueur.hpp"
#include "Garde.hpp"


//The tile
class Jeu
{
    public:
    Jeu();
    ~Jeu();
    bool init();
    bool loadMedia(Tile* tiles[],SDL_Renderer* gRenderer,SDL_Rect* gTileClips);

    bool setTiles(Tile* tiles[],SDL_Rect* gTileClips);
 
    void jeuUpdate(SDL_Rect* gTileClips,Joueur joueur,Garde garde,Garde garde2);
    SDL_Window* gWindow ;

    SDL_Renderer* gRenderer;
    LTexture gPersonnageTexture;
    //LTexture gPersonnage2Texture;
    LTexture gGardeTexture;
    LTexture gTileTexture;

    LTexture ArmeTexture;

     LTexture MoneyTexture;

       LTexture BalleTexture;

       Tile* tileSet[ TOTAL_TILES ];

    private:
   

};


