#include "Objet.hpp"

class Argent:public Objet

{
private:


public:
    Argent(int x,int y):Objet(x,y){
        this->type=2;
        this->clip.x = 0;
        this->clip.y = 0;
	    this->clip.w = 32;
	    this->clip.h = 32;
    };
    //~Argent();
};