//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe DemiDroite - Tests unitaires des constructeurs et des accesseurs
//                     (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "DemiDroite.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.DemiDroite", "2.0.0");

      Tests::Design("Controle des constructeurs", 3);

         Tests::Case("Controle du constructeur par defaut"); {
         DemiDroite d;

            Tests::Unit("[(0, 0), (1, 1)[",  d.toString());
         }

         Tests::Case("Cas particulier d'une demidroite horizontale"); {
         Point O(0, 0), A(2, -2), B(2.5, -3.75);
         Vecteur v1(1, 0), v2(-1.5, 0);
         DemiDroite d1(O, v1), d2(A, v1), d3(B, v2);

            Tests::Unit("[(0, 0), (1, 0)[",           d1.toString());
            Tests::Unit("[(2, -2), (1, 0)[",          d2.toString());
            Tests::Unit("[(2.5, -3.75), (-1.5, 0)[",  d3.toString());
         }

         Tests::Case("Cas particulier d'une demidroite verticale"); {
         Point O(0, 0), A(2, -2), B(2.5, -3.75);
         Vecteur v1(0, -1), v2(0, 0.5);
         DemiDroite d1(O, v1), d2(A, v1), d3(B, v2);

            Tests::Unit("[(0, 0), (0, -1)[",         d1.toString());
            Tests::Unit("[(2, -2), (0, -1)[",        d2.toString());
            Tests::Unit("[(2.5, -3.75), (0, 0.5)[",  d3.toString());
         }

         Tests::Case("Cas d'une demidroite quelconque"); {
         Point O(0, 0), A(2, -2), B(2.5, -3.75);
         Vecteur v1(7, -1), v2(-4.2, 0.5);
         DemiDroite d1(O, v1), d2(A, v1), d3(B, v2);

            Tests::Unit("[(0, 0), (7, -1)[",            d1.toString());
            Tests::Unit("[(2, -2), (7, -1)[",           d2.toString());
            Tests::Unit("[(2.5, -3.75), (-4.2, 0.5)[",  d3.toString());
         }

   Tests::End();
}
