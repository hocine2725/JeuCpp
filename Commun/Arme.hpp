#include "Objet.hpp"

class Arme:public Objet

{
private:


public:
    Arme(int x,int y):Objet(x,y){
        this->type=1;
        this->clip.x = 0;
        this->clip.y = 0;
	    this->clip.w = 46;
	    this->clip.h = 19;

       
    };

    
    //~Arme();
};




