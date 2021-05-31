//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Angle - Tests unitaires des operateurs =, == et !=
//                (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Angle.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Angle", "2.1.0");

      Tests::Design("Controle des operateurs (1ere partie)", 3);

         Tests::Case("Operateur ="); {
         Angle a1(PI), a2(-PI/4);
         Angle A;
         
            A=a1; Tests::Unit(a1.toString(),  A.toString());
            A=a2; Tests::Unit(a2.toString(),  A.toString());
         }

         Tests::Case("Operateur == / Egalite absolue"); {
         Angle a1(PI), a2(-PI/2);
         Angle A;
         
            A=a1; Tests::Unit(true,  A==a1);
                  Tests::Unit(false, A==a2);
            A=a2; Tests::Unit(true,  A==a2);
                  Tests::Unit(false, a1==a2);
         }

         Tests::Case("Operateur == / Ecart inferieur a EPSILON"); {
         RxR z0(0, 0), z1(1, 1), z2(2, 2), z3(-3,-3);
         RxR z10(1, 0), z01(0, 1);
         Angle a1(z0, z1, z2), a2(z3, z1, z2), a3(z10, z0, z01);
         
            Tests::Unit(true,  a1==PI);
            Tests::Unit(true,  a2==PI);
            Tests::Unit(true,  a3==PI/2);
         }

         Tests::Case("Operateur !="); {
         Angle a1(PI), a2(-PI/2);
         Angle A;
         
            A=a1; Tests::Unit(false,  A!=a1);
                  Tests::Unit(true,   A!=a2);
            A=a2; Tests::Unit(false,  A!=a2);
                  Tests::Unit(true,   a1!=a2);
         }

   Tests::End();
}
