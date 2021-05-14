
#include"Dot.hpp"

Dot::Dot()
{
    //Initialize the collision box
    mBox.x = 10;
    mBox.y = 10;
    frame = 0;

    for (size_t i = 0; i < 4; i++){
        for (size_t j = 0; j < 4; j++){
            clip[i][j].x = 32*i;
            clip[i][j].y = 32*(j+3);
            clip[i][j].w = 32;
            clip[i][j].h = 32;
        }
    }



	mBox.w = 25;
	mBox.h = 25;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
}

void Dot::handleEvent( SDL_Event& e ,Tile *tiles[] )
{   
       
    //If a key was pressed
	if( e.type == SDL_KEYDOWN )
    {  // std::cout<<"push"<<std::endl;
        //Adjust the velocity
        frame+=4;
        switch( e.key.keysym.sym)
        {   
            //Haut
            case SDLK_UP:
                mBox.y-= DOT_VEL;
                curent_clip = 2;
                if((mBox.y < 0) || touchesWall( mBox, tiles ) ){
                    mBox.y += DOT_VEL;
                }
            break;
            //Bas
            case SDLK_DOWN:
                mBox.y  += DOT_VEL;  
                curent_clip = 0;
             if((mBox.y + DOT_HEIGHT > LEVEL_HEIGHT) || touchesWall( mBox, tiles ) ){
                 mBox.y -= DOT_VEL;
            }
            
            break;
            //Gauche
            case SDLK_LEFT:
                mBox.x  -= DOT_VEL;
                curent_clip = 3;
            if((mBox.x < 0) || touchesWall( mBox, tiles ) ){
                 mBox.x += DOT_VEL;
            }
            
            break;
            //Droite
            case SDLK_RIGHT: 
                mBox.x += DOT_VEL; 
                curent_clip = 1;
            if((mBox.x + DOT_WIDTH > LEVEL_WIDTH) || touchesWall( mBox, tiles ) ){
                 mBox.x -= DOT_VEL;
            }
        
            
            break;
        }
    }
   

  
}

void Dot::render( SDL_Renderer* gRenderer,LTexture gDotTexture)
{
    //Show the dot
  

	gDotTexture.render(gRenderer,mBox.x , mBox.y);
}

bool Dot::touchesWall( SDL_Rect box, Tile* tiles[] )
{
    //Go through the tiles
    for( int i = 0; i < TOTAL_TILES; ++i )
    {
        //If the tile is a wall type tile
        if( ( tiles[ i ]->getType() == T4))
        {
            //If the collision box touches the wall tile
            if( checkCollision( box, tiles[ i ]->getBox() ) )
            {	
                return true;
            }
        }
    }

    //If no wall tiles were touched
    return false;
}

// faire attention c peut etre pas la bonne 
// void Dot::move( Tile *tiles[] )
// {
//     //Move the dot left or right
//    // mBox.x += mVelX;
    
// 	//std::cout<<mBox.x<<std::endl;

//     //If the dot went too far to the left or right or touched a wall
//     if( ( mBox.x < 0 ) || ( mBox.x + DOT_WIDTH > LEVEL_WIDTH ) || touchesWall( mBox, tiles ) )
//     {
//         //move back
		
//         mBox.x -= mVelX;
//     }

//     //Move the dot up or down
//    // mBox.y += mVelY;

//     //If the dot went too far up or down or touched a wall
//     if( ( mBox.y < 0 ) || ( mBox.y + DOT_HEIGHT > LEVEL_HEIGHT ) || touchesWall( mBox, tiles ) )
//     {
//         //move back
//         mBox.y -= mVelY;
//     }
	
// }