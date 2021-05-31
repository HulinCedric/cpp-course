//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe RxR - Tests unitaires des operateurs * et *= 
//              (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "RxR.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.RxR", "3.0.0");

      Tests::Design("Controle des operateurs (Quatrieme partie)", 3);

         Tests::Case("Premiere forme de l'operateur *"); {
         RxR z1(1, 0), z2(3, 2), z3(-2.5, 0.5), z4(-0.5, 3);
         RxR z0;

            Tests::Unit("(3, 2)",         (z1*z2)->toString());
            Tests::Unit("(-8.5, -3.5)",   (z2*z3)->toString());
            Tests::Unit("(0, 0)",         (z0*z3)->toString());
            Tests::Unit("(-0.25, -7.75)", (z3*z4)->toString());
         }

         Tests::Case("Seconde forme de l'operateur *"); {
         RxR z1(1, 0), z2(3, 2);

            Tests::Unit("(7.5, 0)", (z1*7.5)->toString());
            Tests::Unit("(-9, -6)", (z2*-3)->toString());
         }

         Tests::Case("Premiere forme de l'operateur *="); {
         RxR z1(1, 0), z2(3, 2), z3(-2.5, 0.5), z4(-0.5, 3);
         RxR z0;

            z1*=z2; Tests::Unit("(3, 2)",         z1.toString());
            z2*=z3; Tests::Unit("(-8.5, -3.5)",   z2.toString());
            z0*=z3; Tests::Unit("(0, 0)",         z0.toString());
            z3*=z4; Tests::Unit("(-0.25, -7.75)", z3.toString());
         }

         Tests::Case("Seconde forme de l'operateur *="); {
         RxR z1(1, 0), z2(3, 2);

            z1*=7.5; Tests::Unit("(7.5, 0)",   z1.toString());
            z2*=-3;   Tests::Unit("(-9, -6)",  z2.toString());
         }

   Tests::End();
}
