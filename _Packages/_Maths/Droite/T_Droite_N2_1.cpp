//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Droite - Tests unitaires des predicats predefinis
//                 (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Droite.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths:Droite", "2.0.0");

      Tests::Design("Controle des predicats predefinis", 3);
      Droite Ox1, Ox2(1, 0, 0);

         Tests::Case("Predicat neutre"); {

            Tests::Unit(true,  Ox1.neutre());
            Tests::Unit(true,  Ox2.neutre());
         }

         Tests::Case("Predicat ok"); {
         Droite d1(1, -1, 4); 

            Tests::Unit(true,  Ox1.ok());
            Tests::Unit(true,  Ox2.ok());
            Tests::Unit(true,  d1.ok());
         }

   Tests::End();
}
