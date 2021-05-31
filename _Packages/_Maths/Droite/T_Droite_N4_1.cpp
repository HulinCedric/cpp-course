//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Droite - Tests unitaires des methodes parallele et orthogonale
//                 (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Droite.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Droite", "2.0.0");

      Tests::Design("Controle des methodes parallele et orthogonale", 3);

         Tests::Case("Controle de la methode parallele"); {
         Point A(3, 0), B(0, 2), C(3, 2), E(3,0);
         Point O(0, 0), F(-2,0), G(0,2), H(1,1);
		 
         Droite FG(F, G), OH(O, H), AB(A, B);
         Droite OB(O, B), CE(C, E);
		 
         Droite d1(1, 0, -10), d2(0, 1,  -5);

            Tests::Unit(true,  FG.parallele(OH));
            Tests::Unit(false, FG.parallele(AB));
            Tests::Unit(true,  OB.parallele(CE));
            Tests::Unit(false, d1.parallele(d2));
         }

         Tests::Case("Controle de la methode orthogonale"); {
         Point O(0, 0), A(1, 1), B(-1, 1);
         Droite d1(1, 0, -10), d2(0, 1,  -5);		 
         Droite OA(O, A), OB(O, B);

            Tests::Unit(true,  d1.orthogonale(d2));
            Tests::Unit(true,  OA.orthogonale(OB));
            Tests::Unit(false, d1.orthogonale(OB));
         }

   Tests::End();
}
