#include "Tile.hpp"




Tile::Tile( int x, int y, int tileType )
{
    //Get the offsets
    mBox.x = x;
    mBox.y = y;

    //Set the collision box
    mBox.w = TILE_WIDTH;
    mBox.h = TILE_HEIGHT;

    //Get the tile type
    mType = tileType;
}

////// args 
void Tile::render(SDL_Rect* gTileClips,LTexture gTileTexture,SDL_Renderer* gRenderer)
{
    
        //Show the tile
      //  std::cout<<"x :"<<mBox.x<<"y :"<< mBox.y<<std::endl;
        gTileTexture.render(gRenderer, mBox.x , mBox.y , &gTileClips[ mType ] );
    
}

void Tile::close(Tile* tiles[], LTexture gTileTexture, SDL_Renderer* gRenderer)
{
	//Deallocate tiles
	for( int i = 0; i < TOTAL_TILES; ++i )
	{
		 if( tiles[ i ] != NULL )
		 {
			delete tiles[ i ];
			tiles[ i ] = NULL;
		 }
	}

//todo dans le main maybe ?????
	//Free loaded images
	//gDotTexture.free();
	gTileTexture.free();
	//gSpriteSheetTexture.free(); //fait dans le main
	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	//SDL_DestroyWindow( gWindow );
	
	//gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}