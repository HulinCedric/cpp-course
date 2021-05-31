//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe DemiDroite - Tests unitaires de la methode support
//                     (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "DemiDroite.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.DemiDroite", "2.0.0");

      Tests::Design("Controle des methodes (lot 1)", 3);

         Tests::Case("Methode support / Premiere forme"); {
         Point O(0, 0), A(2, -2), B(2.5, -3.75);
         Vecteur v1(-1, -1), v2(0, 2), v3(2, -0.5);
         DemiDroite d1(O, v1), d2(O, v2), d3(B, v2), d4(B, v3);
         Droite* pD;

            pD= d1.support();           
            Tests::Unit("[1, -1, 0]",        pD->toString());

            pD= d2.support();
            Tests::Unit("[0, 1, 0]",         pD->toString());

            pD= d3.support();
            Tests::Unit("[0, 1, -2.5]",      pD->toString());

            pD= d4.support();
            Tests::Unit("[1, 0.25, 3.125]",  pD->toString());
         }

         Tests::Case("Methode support / Seconde forme"); {
         Point O(0, 0), A(2, 0), B(4, 0), C(7, 0), D(0, 2);
         Segment OA(O, A), OD(O, D);
         Vecteur BC(B, C), CB(C, B);
         DemiDroite d1(C, CB), d2(B, BC);
           
            Tests::Unit(true,  d1.support(OA));
            Tests::Unit(false, d2.support(OA));
            Tests::Unit(false, d2.support(OD));
         }

   Tests::End();
}
