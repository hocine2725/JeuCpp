#include "Joueur.hpp"
#include "Garde.hpp"

//The tile
class Jeu
{
public:
    //Constructeur
    Jeu();

    //Destructeur
    ~Jeu();
    bool init();
    bool loadMedia(Tile *tiles[], SDL_Renderer *gRenderer, SDL_Rect *gTileClips);

    void close(Tile *tiles[], SDL_Renderer *gRenderer, SDL_Rect *gTileClips);

    bool setTiles(Tile *tiles[], SDL_Rect *gTileClips);

    void jeuUpdate(SDL_Rect *gTileClips, Joueur joueur, Joueur joueur2, Garde garde, Garde garde2, Garde garde3);

    //Affiche l'accueil
    bool accueil();

    //Affiche gagne ou perdu a la fin du jeu
    bool perdu();
    bool gagne();

    SDL_Window *gWindow;

    SDL_Renderer *gRenderer;

    LTexture gPersonnageTexture;
    LTexture gGardeTexture;
    LTexture gTileTexture;

    LTexture ArmeTexture;

    LTexture MoneyTexture;

    LTexture CleTexture;

    Tile *tileSet[TOTAL_TILES];

    SDL_Texture *img = NULL;

    bool acc = true;

private:
};
