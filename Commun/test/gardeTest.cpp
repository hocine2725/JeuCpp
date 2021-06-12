// Alex Coninx
// ISIR - Sorbonne Universite / CNRS
// 12/05/2020

#define CATCH_CONFIG_MAIN // Must only appear in ONE test file
#include "catch.hpp"
//Ou si installé par la distribution : #include <catch2/catch.hpp>

#include "Garde.hpp"

TEST_CASE("test du garde", "[Garde]")
{

    Garde garde(100, 30, 30, true);

    // methode get //le garde n'est pas mort donc false
    REQUIRE(garde.getMort() == false);

    // methode pour tuer
    garde.setMort(true);
    REQUIRE(garde.getMort() == true);

    // test vision
    // on cree un joueur qui est loin du garde
    SDL_Rect joueur;
    joueur.x = 150;
    joueur.y = 100;
    joueur.w = 32;
    joueur.h = 32;

    REQUIRE(garde.checkJoueur(joueur) == false);

    // le joueur se trouve a la meme position que le garde 35/30

    joueur.x = 35;
    joueur.y = 35;

    REQUIRE(garde.checkJoueur(joueur) == true);
}
