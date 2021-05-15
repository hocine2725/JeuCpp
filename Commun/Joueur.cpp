#include "Joueur.hpp"

Joueur::Joueur(std::string n, int i)
{
    //Initialise le nom du joueur
    nom = n;
    armee=false;
    money=0;
    //Initialise le numero du joueur
    id = i;

    //Initialise la position du joueur
    if(id == 0){
        mBox.x = 200;
        mBox.y = 150;
    }
    if(id == 1){
        mBox.x = 200;
        mBox.y = 250;
    }

    //Initialise la vitesse du joueur
    mVelX = 0;
    mVelY = 0;


    //Initialise chaque image
    for (size_t i = 0; i < 4; i++){
        for (size_t j = 0; j < 4; j++){
            clip[i][j].x = 32*i;
            clip[i][j].y = 32*(j+3);
            clip[i][j].w = 32;
            clip[i][j].h = 32;
        }
    }
}
/*
Joueur::~Joueur()
{
    for (size_t i = 0; i < 4; i++){
        free clip[i];
    }
    free clip;
}
*/


void Joueur::evenement(SDL_Event& e)
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {   //std::cout<<"push"<<std::endl;
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {   
            case SDLK_UP: mVelY -= PERSONNAGE_VEL;
                current_clip = 2;
            break;
            case SDLK_DOWN: mVelY += PERSONNAGE_VEL;
                current_clip = 0;
            break;
            case SDLK_LEFT: mVelX -= PERSONNAGE_VEL; 
                current_clip = 3;
            break;
            case SDLK_RIGHT: mVelX += PERSONNAGE_VEL; 
                current_clip = 1;
            break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY += PERSONNAGE_VEL; break;
            case SDLK_DOWN: mVelY -= PERSONNAGE_VEL; break;
            case SDLK_LEFT: mVelX += PERSONNAGE_VEL; break;
            case SDLK_RIGHT: mVelX -= PERSONNAGE_VEL; break;
        }
    }
}


void Joueur::deplacement(Tile *tiles[])
{
    if(mVelX != 0 || mVelY != 0){
        frame++;
        //frame = (frame+1)%16;
        //Move the dot left or right
        mBox.x += mVelX;
        
        //std::cout<<frame<<std::endl;

        //If the dot went too far to the left or right or touched a wall
        if( (mBox.x < 0) || (mBox.x + PERSONNAGE_WIDTH > LEVEL_WIDTH) || this->touchesWall(tiles))
        {
            //move back
            
            mBox.x -= mVelX;
        }

        //Move the dot up or down
        mBox.y += mVelY;

        //If the dot went too far up or down or touched a wall
        if( (mBox.y < 0) || (mBox.y + PERSONNAGE_HEIGHT > LEVEL_HEIGHT) || this->touchesWall(tiles))
        {
            //move back
            mBox.y -= mVelY;
        }
    }
}


//Return true si l'objet est ramasse
bool Joueur::ramasserObjet(Objet o){
    if(this->checkCollision(o.getBox())){
        if (o.getType()==1){
            //std::cout<<"arme"<<std::endl;
            o.ramassee = true;
            this->armee=true;
            return true;
        }
        else if( o.getType()==2){
            o.ramassee=true;
            this->money= 50;
            return true;
        }
        return true;
    }
    else{
        return false;
    }
}