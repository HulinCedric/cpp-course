//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe DemiDroite - Tests unitaires de la surcharge des operateurs
//                     (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "DemiDroite.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.DemiDroite", "2.0.0");

      Tests::Design("Controle des operateurs", 3);

         Tests::Case("Controle de l'operateur ="); {
         Point O(0, 0), A(2, -2), B(2.5, -3.75);
         Vecteur v1(7, -1), v2(-4.2, 0.5);
         DemiDroite d1(O, v1), d2(A, v1), d3(B, v2);
         DemiDroite d;
                        
            d= d1; Tests::Unit("[(0, 0), (7, -1)[",           d.toString());
            d= d2; Tests::Unit("[(2, -2), (7, -1)[",          d.toString());
            d= d3; Tests::Unit("[(2.5, -3.75), (-4.2, 0.5)[", d.toString());
         }

         Tests::Case("Controle de l'operateur =="); {
         Point O(0, 0), A(2, -2);
         Vecteur v1(1, 1), v2(2, 2), v3(3, -3);
         DemiDroite d1(O, v1), d2(O, v2), d3(A, v2), d4(A, v3);
         DemiDroite d(d1);

            Tests::Unit(true,  d==d1);
            Tests::Unit(true,  d==d2);
            Tests::Unit(false, d==d3);
            Tests::Unit(false, d2==d4);
            Tests::Unit(false, d3==d4);
         } 

         Tests::Case("Controle de l'operateur !="); {
         Point O(0, 0), A(2, -2);
         Vecteur v1(1, -1), v2(2, 2);
         DemiDroite d1(O, v1), d2(O, v2), d3(A, v2);
         DemiDroite d;

            Tests::Unit(true,  d!=d1);
            Tests::Unit(false, d!=d2);
            Tests::Unit(true,  d!=d3);
         } 

   Tests::End();
}
