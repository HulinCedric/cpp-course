//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Droite - Controle de la surcharge des operateurs = et ==
//                 (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Droite.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Droite", "2.0.0");

      Tests::Design("Controle de la surcharge des operateurs", 3);

         Tests::Case("Surcharge de l'operateur ="); {
         Droite d1(2, 1, -2.5), d2(-3, -2, 1), d3(1.5, 1.25, 0);
         Droite d;

            d=d1; Tests::Unit("[2, 1, -2.5]",   d.toString());
            d=d2; Tests::Unit("[-3, -2, 1]",    d.toString());
            d=d3; Tests::Unit("[1.5, 1.25, 0]", d.toString()); 
         }

         Tests::Case("Surcharge de l'operateur =="); {
         Droite d1(2, 1, -2.5), d2(-3, -2, 1), d3(1.5, 1.25, 0);
         Droite d;

            d=d1; Tests::Unit(true,  (d==d1));
                  Tests::Unit(false, (d==d2));
                  Tests::Unit(false, (d1==d2));
         }

         Tests::Case("Surcharge de l'operateur !="); {
         Droite d1(2, 1, -2.5), d2(-3, -2, 1), d3(1.5, 1.25, 0);
         Droite d;

            d=d1; Tests::Unit(false, (d!=d1));
                  Tests::Unit(true,  (d!=d2));
                  Tests::Unit(true,  (d1!=d2));
         }

   Tests::End();
}
