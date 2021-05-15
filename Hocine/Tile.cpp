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

int Tile::getType()
{
    return mType;
}

SDL_Rect Tile::getBox()
{
    return mBox;
}