//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe RxR - Tests unitaires des operateurs + et += 
//              (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "RxR.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.RxR", "3.0.0");

      Tests::Design("Controle des operateurs (Seconde partie)", 3);

         Tests::Case("Premiere forme de l'operateur +"); {
         RxR z1(1, 0), z2(3, 2), z3(-2.5, 0.5), z4(1.23, -7.56);
         RxR z5(0, 1);

            Tests::Unit("(4, 2)",         (z1+z2)->toString());
            Tests::Unit("(0.5, 2.5)",     (z2+z3)->toString());
            Tests::Unit("(-1.27, -7.06)", (z3+z4)->toString());
            Tests::Unit("(1.23, -6.56)",  (z4+z5)->toString());
         }

         Tests::Case("Seconde forme de l'operateur +"); {
         RxR z1(1, 0), z2(3, 2);

            Tests::Unit("(3, 0)", (z1+2.0)->toString());
            Tests::Unit("(6, 2)", (z2+3)->toString());
         }

         Tests::Case("Premiere forme de l'operateur +="); {
         RxR z1(1, 0), z2(3, 2), z3(-2.5, 0.5), z4(1.23, -7.56);
         RxR z5(0, 1);

            z1+=z2; Tests::Unit("(4, 2)",         z1.toString());
            z2+=z3; Tests::Unit("(0.5, 2.5)",     z2.toString());
            z3+=z4; Tests::Unit("(-1.27, -7.06)", z3.toString());
            z4+=z5; Tests::Unit("(1.23, -6.56)",  z4.toString());
         }

         Tests::Case("Seconde forme de l'operateur +="); {
         RxR z1(1, 0), z2(3, 2);

            z1+=2.0; Tests::Unit("(3, 0)", z1.toString());
            z2+=3;   Tests::Unit("(6, 2)", z2.toString());
         }

   Tests::End();
}
