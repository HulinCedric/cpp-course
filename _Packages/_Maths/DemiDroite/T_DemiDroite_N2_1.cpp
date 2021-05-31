//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe DemiDroite - Tests unitaires des predicats predefinis
//                     (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "DemiDroite.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths:DemiDroite", "2.0.0");

      Tests::Design("Controle des predicats predefinis", 3);
      Point O(0,0), A(2, -3);
      Vecteur V1(1, 1), V2(2, -1);
      DemiDroite d1, d2(O, V1), d3(A, V2);

         Tests::Case("Predicat neutre"); {

            Tests::Unit(true,  d1.neutre());
            Tests::Unit(true,  d2.neutre());
         }

         Tests::Case("Predicat ok"); {

            Tests::Unit(true,  d1.ok());
            Tests::Unit(true,  d2.ok());
            Tests::Unit(true,  d3.ok());
         }

   Tests::End();
}
