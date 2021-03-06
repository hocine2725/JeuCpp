#include "Joueur.hpp"

Joueur::Joueur(std::string n, int i)
{
    //Initialise le nom du joueur
    nom = n;
    armee = false;
    money = 0;
    paye = false;

    tire = false;
    //Initialise le numero du joueur
    id = i;

    //Initialise la position du joueur
    if (id == 0)
    {
        mBox.x = 200;
        mBox.y = 200;
    }
    if (id == 1)
    {
        mBox.x = 200;
        mBox.y = 250;
    }

    //Initialise la vitesse du joueur
    mVelX = 0;
    mVelY = 0;

    //Initialise chaque image
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            clip[i][j].x = 32 * i;
            clip[i][j].y = 32 * (j + 3);
            clip[i][j].w = 32;
            clip[i][j].h = 32;
        }
    }
}

// Joueur::~Joueur()
// {
//     for (size_t i = 0; i < 4; i++){
//         delete[] clip[i];
//     }
//     delete[] clip;
// }

bool Joueur::tirer()
{
    //std::list<Balle> my_list = { Balle(23,23) };
    if (this->armee == true)
    {
        std::cout << "tirer" << std::endl;
        tire = true;
        // on eleve l'arme
        return true;
        // std::cout<<"after: "<<b.getBox().y<<std::endl;
    }
    return false;
}

//Remplace tirer, pour l'IA
bool Joueur::tirer2()
{
}

void Joueur::corruption()
{

    if (this->money >= 20)
    {
        std::cout << "money before: " << money << std::endl;
        std::cout << "corruption" << std::endl;
        money = money - 20;
        std::cout << "money after: " << money << std::endl;
        paye = true;
    }

    else
    {
        std::cout << "pas assez d'argent " << std::endl;
    }
}


//Remplace corruption, pour l'IA
void Joueur::corruption2()
{
}

void Joueur::evenement(SDL_Event &e)
{
    //If a key was pressed
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
    { //std::cout<<"push"<<std::endl;
        //Adjust the velocity
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
            mVelY -= PERSONNAGE_VEL;
            current_clip = 2;
            tire = false;

            break;
        case SDLK_DOWN:
            mVelY += PERSONNAGE_VEL;
            current_clip = 0;
            tire = false;

            break;
        case SDLK_LEFT:
            mVelX -= PERSONNAGE_VEL;
            current_clip = 3;
            tire = false;

            break;
        case SDLK_RIGHT:
            mVelX += PERSONNAGE_VEL;
            current_clip = 1;
            tire = false;

            break;
        case SDLK_t:

            tirer();
            break;

        case SDLK_c:
            corruption();
            break;
        }
    }
    //If a key was released
    else if (e.type == SDL_KEYUP && e.key.repeat == 0)
    {
        //Adjust the velocity
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
            mVelY += PERSONNAGE_VEL;
            break;
        case SDLK_DOWN:
            mVelY -= PERSONNAGE_VEL;
            break;
        case SDLK_LEFT:
            mVelX += PERSONNAGE_VEL;
            break;
        case SDLK_RIGHT:
            mVelX -= PERSONNAGE_VEL;
            break;
        }
    }
}

//Pour faire une IA, modifier le code suivant permettant de r??gler la vitesse en X et en Y
void Joueur::evenement2(SDL_Event &e)
{

    //std::cout<<"j2 :"<<mVelY<<std::endl;

    switch (e.type)
    {

    case SDL_KEYDOWN:
        key[SDL_GetScancodeFromKey(e.key.keysym.sym)] = 1;
        //std::cout<<"here"<<std::endl;

        break;
    case SDL_KEYUP:
        key[SDL_GetScancodeFromKey(e.key.keysym.sym)] = 0;
        break;
    }

    if (key[SDL_SCANCODE_W])
    {
        // std::cout<<"Z"<<std::endl;

        mVelY = -PERSONNAGE_VEL;
        current_clip = 2;
        tire = false;
    }

    else if (key[SDL_SCANCODE_S])
    {
        // std::cout<<"S"<<std::endl;
        mVelY = PERSONNAGE_VEL;
        current_clip = 0;
        tire = false;
    }
    else if (key[SDL_SCANCODE_D])
    {
        // std::cout<<"D"<<std::endl;
        mVelX = PERSONNAGE_VEL;
        current_clip = 1;
        tire = false;
    }

    else if (key[SDL_SCANCODE_A])
    {
        //std::cout<<"Q"<<std::endl;
        mVelX = -PERSONNAGE_VEL;
        current_clip = 3;
        tire = false;
    }
    else if (key[SDL_SCANCODE_T])
    {
        tirer();
    }
    else if (key[SDL_SCANCODE_C])
    {
        corruption();
    }
    else
    {
        mVelX = 0;
        mVelY = 0;
    }
}

void Joueur::deplacement(Tile *tiles[])
{
    if (mVelX != 0 || mVelY != 0)
    {
        frame++;
        //frame = (frame+1)%16;
        //Move the dot left or right
        mBox.x += mVelX;

        //std::cout<<frame<<std::endl;

        //If the dot went too far to the left or right or touched a wall
        if ((mBox.x < 0) || (mBox.x + PERSONNAGE_WIDTH > LEVEL_WIDTH) || this->touchesWall(tiles))
        {
            //move back

            mBox.x -= mVelX;
        }

        //Move the dot up or down
        mBox.y += mVelY;

        //If the dot went too far up or down or touched a wall
        if ((mBox.y < 0) || (mBox.y + PERSONNAGE_HEIGHT > LEVEL_HEIGHT) || this->touchesWall(tiles))
        {
            //move back
            mBox.y -= mVelY;
        }
    }
}

//Return true si l'objet est ramasse
bool Joueur::ramasserObjet(Objet &o)
{
    if (this->checkCollision(o.getBox()))
    {
        if (o.getType() == 1)
        {
            //std::cout<<"arme"<<std::endl;
            o.setRamasse(true);
            this->armee = true;
            o.set();
        }
        else if (o.getType() == 2)
        {
            o.setRamasse(true);
            this->money = 50;
            o.set();
        }
        else if (o.getType() == 3)
        {
            o.setRamasse(true);
            this->cle = true;
            o.set();
        }
        return true;
    }
    return false;
}

void Joueur::frameUpdate()
{

    if (this->getFrame() / 4 >= 4)
    {
        //std::cout<<"zero"<<std::endl;
        this->setFrame(0);
    }
}

int Joueur::action(Garde garde)
{
    if (((!garde.getMort()) && garde.checkJoueur(this->getMBox())))
    {
        //std::cout<<"perdu, position garde : "<<garde.getMBox().y<<", position joueur :"<<joueur.getMBox().y<<std::endl;
        std::cout << "perdu, delta position : " << garde.getMBox().y - this->getMBox().y << std::endl;
        //std::cout<<"perdu"<<std::endl;
        return 0;
    }

    if (this->tire == true && garde.checkCollision(this->getMBox()))
    {
        garde.setMort(true); // Ne fonctionne pas, on le fait donc dans exec.cpp
        std::cout << "poignard??" << std::endl;
        return 1;
    }

    if (this->paye == true && garde.checkCollision(this->getMBox()))
    {
        std::cout << "corrompu" << std::endl;
        garde.setMort(true); // Ne fonctionne pas, on le fait donc dans exec.cpp
        return 1;
    }

    return 2;
}

bool Joueur::fin(Joueur j2)
{
    if ((mBox.x + mBox.w >= SCREEN_WIDTH - mBox.w) && (j2.getMBox().x + j2.getMBox().w >= SCREEN_WIDTH - j2.getMBox().w))
    {
        if (this->cle == true || j2.cle == true)
        {
            return true;
        }
    }
    return false;
}