
#include "LTexture.hpp"


//The tile
class Tile
{
    public:
		//Initializes position and type
		Tile( int x, int y, int tileType );

		//Shows the tile
		void render( SDL_Rect* gTileClips, LTexture gTileTexture, SDL_Renderer* gRenderer);

		void close(Tile* tiles[], LTexture gTileTexture, SDL_Renderer* gRenderer);

		bool setTiles(Tile* tiles[], SDL_Rect *gTileClips[]);

		//Get the tile type
		int getType(){return mType;};

		//Get the collision box
		SDL_Rect getBox(){return mBox;};

    private:
		//The attributes of the tile
		SDL_Rect mBox;
	
		//The tile type
		int mType;
};