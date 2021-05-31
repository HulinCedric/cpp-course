//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe DemiDroite - Tests unitaires des accesseurs de consultation
//                     (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "DemiDroite.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths:DemiDroite", "2.0.0");

      Tests::Design("Controle des accesseurs de consultation", 3);
      Point O(0,0), A(2, -3);
      Vecteur V1(1, 1), V2(2, -1);
      DemiDroite d1(O, V1), d2(A, V2);

         Tests::Case("Methode origine"); {

            Tests::Unit(O.toString(),  d1.origine()->toString());
            Tests::Unit(A.toString(),  d2.origine()->toString());
         }

         Tests::Case("Methode directeur"); {

            Tests::Unit(V1.toString(),  d1.directeur()->toString());
            Tests::Unit(V2.toString(),  d2.directeur()->toString());
         }

   Tests::End();
}
