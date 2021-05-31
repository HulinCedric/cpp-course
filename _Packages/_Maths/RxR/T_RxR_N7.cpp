//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe RxR - Tests unitaires des operateurs / et /= 
//              (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "RxR.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.RxR", "2.0.0");

      Tests::Design("Controle des operateurs (Cinquieme partie)", 3);

         Tests::Case("Premiere forme de l'operateur /"); {
         RxR z1(1, 0), z2(3, 2);

            Tests::Unit("(4, 0)",     (z1/0.25)->toString());
            Tests::Unit("(-1.5, -1)", (z2/-2)->toString());
         }

         Tests::Case("Seconde forme de l'operateur /"); {
         RxR z1(1, 0), z2(-1, 1), z3(-1, -2), z4(-0.75, -1);
         RxR z0;

            Tests::Unit("(-0.5, -0.5)", (z1/z2)->toString());
            Tests::Unit("(-0.2, -0.6)", (z2/z3)->toString());
            Tests::Unit("(0, 0)",       (z0/z3)->toString());
            Tests::Unit("(1.76, 0.32)", (z3/z4)->toString());
         }

         Tests::Case("Premiere forme de l'operateur /="); {
         RxR z1(1, 0), z2(3, 2);

            z1/=0.25; Tests::Unit("(4, 0)",      z1.toString());
            z2/=-2;    Tests::Unit("(-1.5, -1)", z2.toString());
         }

         Tests::Case("Seconde forme de l'operateur /="); {
         RxR z1(1, 0), z2(-1, 1), z3(-1, -2), z4(-0.75, -1);
         RxR z0;

            z1/=z2; Tests::Unit("(-0.5, -0.5)", z1.toString());
            z2/=z3; Tests::Unit("(-0.2, -0.6)", z2.toString());
            z0/=z3; Tests::Unit("(0, 0)",       z0.toString());
            z3/=z4; Tests::Unit("(1.76, 0.32)", z3.toString());
         }

   Tests::End();
}
