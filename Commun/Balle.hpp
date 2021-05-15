#include "Objet.hpp"

class Balle:public Objet

{
private:


public:
    Balle(int x,int y):Objet(x,y){
        this->type=3;
        this->clip.x = 0;
        this->clip.y = 0;
	    this->clip.w = 16;
	    this->clip.h = 16;
    };
    //~Balle();
};