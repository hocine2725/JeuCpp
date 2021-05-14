#include "Personnage.hpp"

Personnage::Personnage()
{
    //Initialise la boite pour la collision
    mBox.x = 10;
    mBox.y = 10;
	mBox.w = PERSONNAGE_WIDTH;
	mBox.h = PERSONNAGE_HEIGHT;

    //Initialise la vitesse
    mVelX = PERSONNAGE_VEL;
    mVelY = PERSONNAGE_VEL;
    
    //Initialise la possession d'objet
    objet = false;
}


bool Personnage::checkCollision(SDL_Rect a)
{
    //The sides of the rectangles
    int leftA, left;
    int rightA, right;
    int topA, top;
    int bottomA, bottom;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect courant
    left = mBox.x;
    right = mBox.x + mBox.w;
    top = mBox.y;
    bottom = mBox.y + mBox.h;

    //If any of the sides from A are outside of B
    if( bottomA <= top )
    {
        return false;
    }

    if( topA >= bottom )
    {
        return false;
    }

    if( rightA <= left )
    {
        return false;
    }

    if( leftA >= right )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}

bool Personnage::touchesWall(Tile* tiles[])
{
    //Go through the tiles
    for( int i = 0; i < TOTAL_TILES; ++i )
    {
        //If the tile is a wall type tile
        if( ( tiles[i]->getType() == T4 ))
        {
            //If the collision box touches the wall tile
            if( this->checkCollision(tiles[i]->getBox() ) )
            {	
                return true;
            }
        }
    }

    //If no wall tiles were touched
    return false;
}

//Return true si l'objet est ramasse
bool Personnage::ramasserObjet(Objet o){
    if(this->checkCollision(o.getBox())){
        objet = true;
        return true;
    }
    else{
        return false;
    }
}