//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe DemiDroite - Tests unitaires de la methode parallele
//                     (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "DemiDroite.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.DemiDroite", "2.0.0");

      Tests::Design("Controle des methodes (lot 3)", 3);

         Tests::Case("Methode parallele / Cas de deux demi droites"); {
         Point O(0,0),  A(3,0), B(0,2), C(3,2), D(-2,0), E(3,0);
         Point F(-2,0), G(0,2), H(1,1);
         Vecteur FG(F,G), OH(O,H), AB(A,B), OB(O,B), CE(C,E);

            DemiDroite d1(F,FG), d2(F,FG);
            Tests::Unit(true, d1.parallele(d2));

            DemiDroite d3(A,AB);
            Tests::Unit(false, d1.parallele(d3));

            DemiDroite d4(O,OB), d5(C,CE);
            Tests::Unit(true, d4.parallele(d5));

            DemiDroite d6(F,FG), d7(O,OH);
            Tests::Unit(true, d6.parallele(d7));
         }

         Tests::Case("Methode parallele / Cas d'une droite et d'une demi droite"); {
         Point O(0, 0), A(2, -2), B(2.5, -3.75);
         Vecteur v1(-1, -1), v2(0, 2);
         DemiDroite d1(O, v1), d2(O, v2), d3(B, v2);
         Droite D(1, -1, 0);

            Tests::Unit(true,  d1.parallele(D));
            Tests::Unit(false, d2.parallele(D));
            Tests::Unit(false, d3.parallele(D));
         }

   Tests::End();
}
