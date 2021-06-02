#include "Joueur.hpp"
#include "Garde.hpp"

//The tile
class Jeu
{
public:
    Jeu();
    ~Jeu();
    bool init();
    bool loadMedia(Tile *tiles[], SDL_Renderer *gRenderer, SDL_Rect *gTileClips);

    void close(Tile *tiles[], SDL_Renderer *gRenderer, SDL_Rect *gTileClips);

    bool setTiles(Tile *tiles[], SDL_Rect *gTileClips);

    void jeuUpdate(SDL_Rect *gTileClips, Joueur joueur,Garde garde, Garde garde2, Garde garde3);

    bool accueil();

    SDL_Window *gWindow;

    SDL_Renderer *gRenderer;

    LTexture gPersonnageTexture;
    //LTexture gPersonnage2Texture;
    LTexture gGardeTexture;
    LTexture gTileTexture;

    LTexture ArmeTexture;

    LTexture MoneyTexture;

    // LTexture BalleTexture;

    LTexture CleTexture;

    Tile *tileSet[TOTAL_TILES];

    SDL_Texture *img = NULL;

    bool acc = true;

private:
};
