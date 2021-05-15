#include "Garde.hpp"

Garde::Garde(int v, int posX)
{
    //Initialise le nom du joueur
    vision = v;
    //Position du garde
    mBox.x = posX;
    
    //Initialise la vitesse du joueur
    mVelY = 0;

    //Initialise chaque image
    for (size_t i = 0; i < 4; i++){
        for (size_t j = 0; j < 4; j++){
            clip[i][j].x = 22*i;
            clip[i][j].y = 32*j;
            clip[i][j].w = 22;
            clip[i][j].h = 32;
        }
    }
}
/*
Garde::~Garde()
{

}
*/


bool Garde::checkJoueur(SDL_Rect a){
    // if(checkCollision(a)){
    //     std::cout<<"perdu"<<a.y<<std::endl;
    // }

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
    left = mBox.x - 30;
    right = mBox.x + mBox.w + 30;
    if(current_clip == 0){ //Bas
        top = mBox.y;
        bottom = mBox.y + mBox.h + vision;
        //std::cout<<"Bas"<<bottom - mBox.y - mBox.h <<std::endl;
    }
    else if(current_clip == 3){ //Haut
        top = mBox.y - vision;
        bottom = mBox.y + mBox.h;
        //std::cout<<"Haut"<<top - mBox.y <<std::endl;
    }

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

void Garde::deplacement(Tile *tiles[])
{ //De haut en bas
    if(mBox.y < 20){ //Bas
        mVelY = 2;
        current_clip = 0;
    }
    if(mBox.y > 400){ //Haut
        mVelY = -2;
     	current_clip = 3;
    }

    frame = (frame+1)%16;
    // //Move the dot left or right
    // mBox.x += mVelX;
    
    // //std::cout<<frame<<std::endl;

    // //If the dot went too far to the left or right or touched a wall
    // if( (mBox.x < 0) || (mBox.x + PERSONNAGE_WIDTH > LEVEL_WIDTH) || this->touchesWall(tiles))
    // {
    //     //move back
        
    //     mBox.x -= mVelX;
    // }

    //Move the dot up or down
    mBox.y += mVelY;

    //If the dot went too far up or down or touched a wall
    if( (mBox.y < 0) || (mBox.y + PERSONNAGE_HEIGHT > LEVEL_HEIGHT) || this->touchesWall(tiles))
    {
        //move back
        mBox.y -= mVelY;
    }
}
