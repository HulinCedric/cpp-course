//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Angle - Tests unitaires des constructeurs 
//                (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Angle.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Angle", "2.1.0");

      Tests::Design("Controle de la construction", 3);

         Tests::Case("Constructeur par defaut"); {
         Angle a1;

            Tests::Unit("{0, 1}",  a1.toString());
         }
	
         Tests::Case("Premier constructeur normal"); {
         Angle a1(PI), a2(-PI), a3(PI/2), a4(PI/4);

            Tests::Unit("{0, -1}",  a1.toString());
            Tests::Unit("{0, -1}",  a2.toString());
            Tests::Unit("{1, 0}",   a3.toString());
            Tests::Unit("{0.707107, 0.707107}",  a4.toString());
         }

         Tests::Case("Second constructeur normal"); {
         Angle a1(0, -1), a2(1, 0), a3(-1, 0), a4(0.707107, 0.707107);

            Tests::Unit("{0, -1}",              a1.toString());
            Tests::Unit("{1, 0}",               a2.toString());
            Tests::Unit("{-1, 0}",              a3.toString());
            Tests::Unit("{0.707107, 0.707107}", a4.toString());
         }

         Tests::Case("Troisieme constructeur normal"); {
         RxR z0(0, 0), z1(1, 0), z2(0, 1), z3(1, 1);
         Angle a0(z1, z0, z1), a1(z1, z0, z2), a2(z1, z0, z3);

            Tests::Unit("{0, 1}",               a0.toString());
            Tests::Unit("{1, 0}",               a1.toString());
            Tests::Unit("{0.707107, 0.707107}", a2.toString());
         }

   Tests::End();
}
