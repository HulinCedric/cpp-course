//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe DemiDroite - Tests unitaires des methodes support et appartient
//                     (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "DemiDroite.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.DemiDroite", "2.0.0");
   Point O(0, 0), A(2, -2);
   Vecteur v1(-1, -1), v2(0, 2);
   DemiDroite d1(O, v1), d2(A, v2);
   Point P1(2, 2), P2(-2, -2);

      Tests::Design("Controle des methodes (lot 2)", 3);

         Tests::Case("Methode appartient"); {
           
            Tests::Unit(true,   d1.appartient(O));
            Tests::Unit(false,  d1.appartient(P1));
            Tests::Unit(true,   d1.appartient(P2));

            Tests::Unit(true,   d2.appartient(A));
            Tests::Unit(true,   d2.appartient(P1));
            Tests::Unit(false,  d2.appartient(P2));
         }

   Tests::End();
}
