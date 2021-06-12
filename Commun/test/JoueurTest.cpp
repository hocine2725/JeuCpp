#include "catch.hpp"
//Ou si installé par la distribution : #include <catch2/catch.hpp>

#include "Joueur.hpp"



TEST_CASE( "test Joueur", "[Joueur]" ) {

  Joueur j1("lea", 1);
  REQUIRE(j1.getArmee() == false);


    Objet arme(1, 200, 250);
    // le joueur est l'objet se trouve a la meme position , le joueur ramasse l'objet
    j1.ramasserObjet(arme);

    REQUIRE(j1.getArmee() == true);

    // on désarme le joueur 
    j1.setArme(false);
    REQUIRE(j1.getArmee() == false);



    // on ne peut pas tirer 
     REQUIRE(j1.tirer() == false);


    // on arme le joueur de nouveau 
    j1.setArme(true);
    REQUIRE(j1.getArmee() == true);

    // vu quil est armée il peut tirer 
    REQUIRE(j1.tirer() == true);

}