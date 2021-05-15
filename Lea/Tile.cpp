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
void Tile::render(SDL_Rect* gTileClips, LTexture gTileTexture, SDL_Renderer* gRenderer)
{
        //Show the tile
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
	//gSpriteSheetTexture.free();
	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	//SDL_DestroyWindow( gWindow );
	
	//gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

bool Tile::setTiles(Tile* tiles[], SDL_Rect *gTileClips[])
{
	//Success flag
	bool tilesLoaded = true;

    //The tile offsets
    int x = 0, y = 0;

    //Open the map
    std::ifstream map( "lazy.map" );

    //If the map couldn't be loaded
    if( map.fail() )
    {
		printf( "Unable to load map file!\n" );
		tilesLoaded = false;
    }
	else
	{
		//Initialize the tiles
		for( int i = 0; i < TOTAL_TILES; ++i )
		{
			//Determines what kind of tile will be made
			int tileType = -1;

			//Read tile from map file
			map >> tileType;

			//std::cout<<tileType<<std::endl;
			//If the was a problem in reading the map
			if( map.fail() )
			{
				//Stop loading map
				printf( "Error loading map: Unexpected end of file!\n" );
				tilesLoaded = false;
				break;
			}

			//If the number is a valid tile number
			if( ( tileType >= 0 ) )
			{
				tiles[ i ] = new Tile( x, y, tileType );
			}
			//If we don't recognize the tile type
			else
			{
				//Stop loading map
				printf( "Error loading map: Invalid tile type at %d!\n", i );
				tilesLoaded = false;
				break;
			}

			//Move to next tile spot
			x += TILE_WIDTH;

			//If we've gone too far
			if( x >= LEVEL_WIDTH )
			{
				//Move back
				x = 0;

				//Move to the next row
				y += TILE_HEIGHT;
			}
		}
		
		//Clip the sprite sheet
		if( tilesLoaded )
		{
			gTileClips[ TILE_RED ]->x = 0;
			gTileClips[ TILE_RED ]->y = 0;
			gTileClips[ TILE_RED ]->w = TILE_WIDTH;
			gTileClips[ TILE_RED ]->h = TILE_HEIGHT;

			gTileClips[ TILE_GREEN ]->x = 0;
			gTileClips[ TILE_GREEN ]->y = 16;
			gTileClips[ TILE_GREEN ]->w = TILE_WIDTH;
			gTileClips[ TILE_GREEN ]->h = TILE_HEIGHT;
		}

			
	}

    //Close the file
    map.close();

    //If the map was loaded fine
    return tilesLoaded;
}
