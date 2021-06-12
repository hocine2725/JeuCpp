#include "catch.hpp"
//Ou si installé par la distribution : #include <catch2/catch.hpp>

#include "Objet.hpp"



TEST_CASE( "test objet", "[objet]" ) {

   Objet arme(1, 200, 150);

   REQUIRE(arme.getRamasse() == false);

    arme.setRamasse(true);

     REQUIRE(arme.getRamasse() == true);

    // on verifie que linitialisation fonctionne
    REQUIRE(arme.getClip().w==46);

    // ca se met a zéro
    arme.set();

    REQUIRE(arme.getClip().w==0);


}