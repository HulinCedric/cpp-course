//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe RxR - Tests unitaires des operateurs =, == et !=
//              (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "RxR.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.RxR", "3.0.0");

      Tests::Design("Controle des operateurs (Premiere partie)", 3);

         Tests::Case("Premiere forme de l'operateur ="); {
         RxR z1(4,-7.1), z2(11, 9.81), z;
         
            z=z1; Tests::Unit(4.0,  z.abscisse());
                  Tests::Unit(-7.1, z.ordonnee());
            z=z2; Tests::Unit(11.0, z.abscisse());
                  Tests::Unit(9.81, z.ordonnee());
         }

         Tests::Case("Seconde forme de l'operateur ="); {
         RxR z;
         
            z=12.5; Tests::Unit(12.5, z.abscisse());
                    Tests::Unit(0.0,  z.ordonnee());
            z=-4.2; Tests::Unit(-4.2, z.abscisse());
                    Tests::Unit(0.0,  z.ordonnee());
         }


         Tests::Case("Premiere forme de l'operateur =="); {
         RxR z1(0,-11), z2(2.5, 0.5), z;
         
            z=z1; Tests::Unit(true,  z==z1);
                  Tests::Unit(false, z==z2);
            z=z2; Tests::Unit(true,  z==z2);
                  Tests::Unit(false, z1==z2);
         }
 
         Tests::Case("Seconde forme de l'operateur =="); {
         RxR z1(-11.5, 0), z2(2.5, 0), z;
         
            z=z1; Tests::Unit(true,  z==-11.5);
                  Tests::Unit(false, z==z2);
            z=z2; Tests::Unit(true,  z==2.5);
                  Tests::Unit(false, z1==z2);
         }

         Tests::Case("Premiere forme de l'operateur !="); {
         RxR z1(1,0), z2(-0.5, 4.125), z;
         
            z=z1; Tests::Unit(false, z!=z1);
                  Tests::Unit(true,  z!=z2);
            z=z2; Tests::Unit(false, z!=z2);
                  Tests::Unit(true,  z1!=z2);
         }

         Tests::Case("Seconde forme de l'operateur !="); {
         RxR z1(1,0), z2(-0.5, 0), z;
         
            z=z1; Tests::Unit(false, z!=1);
                  Tests::Unit(true,  z!=z2);
            z=z2; Tests::Unit(false, z!=-0.5);
                  Tests::Unit(true,  z1!=z2);
         }

   Tests::End();
}
