//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe RxR - Tests unitaires des operateurs - et -= 
//              (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "RxR.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.RxR", "2.0.0");

      Tests::Design("Controle des operateurs (Troisieme partie)", 3);

         Tests::Case("Premiere forme de l'operateur -"); {
         RxR z1(1, 0), z2(3, 2), z3(-2.5, 0.5), z4(1.23, -7.56);
         RxR z0(0,0);

            Tests::Unit("(-2, -2)",      (z1-z2)->toString());
            Tests::Unit("(5.5, 1.5)",    (z2-z3)->toString());
            Tests::Unit("(-3.73, 8.06)", (z3-z4)->toString());
            Tests::Unit("(-1.23, 7.56)", (z0-z4)->toString());
         }
 
         Tests::Case("Seconde forme de l'operateur -"); {
         RxR z1(1, 0), z2(3, 2);

            Tests::Unit("(-1, 0)", (z1-2)->toString());
            Tests::Unit("(0, 2)",  (z2-3.0f)->toString());
         }

         Tests::Case("Operateur de changement de signe"); {
         RxR z1(1, 0), z2(3, 2);

            Tests::Unit("(-1, 0)",  (-z1)->toString());
            Tests::Unit("(-3, -2)", (-z2)->toString());
         }

         Tests::Case("Premiere forme de l'operateur -="); {
         RxR z1(1, 0), z2(3, 2), z3(-2.5, 0.5), z4(1.23, -7.56);
         RxR z0;

            z1-=z2; Tests::Unit("(-2, -2)",      z1.toString());
            z2-=z3; Tests::Unit("(5.5, 1.5)",    z2.toString());
            z3-=z4; Tests::Unit("(-3.73, 8.06)", z3.toString());
            z0-=z4; Tests::Unit("(-1.23, 7.56)", z0.toString());
         }
 
         Tests::Case("Seconde forme de l'operateur -="); {
         RxR z1(1, 0), z2(3, 2);

            z1-=2;    Tests::Unit("(-1, 0)", z1.toString());
            z2-=3.0; Tests::Unit("(0, 2)",   z2.toString());
         }

   Tests::End();
}
