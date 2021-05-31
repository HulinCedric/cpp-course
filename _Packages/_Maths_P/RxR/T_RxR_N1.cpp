//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe RxR - Tests unitaires des accesseurs 
//              (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "RxR.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.RxR", "3.0.0");

   Tests::Design("Controle des constructeurs", 3);

      Tests::Case("Constructeur par defaut"); {
      RxR z0;
         
         Tests::Unit("(0, 0)", z0.toString());
      }

      Tests::Case("Premier constructeur normal"); {
      RxR z1(1, -2), z2(0.5, -0.75), z3(7, -0.125), z4(-1.1, 3);
         
         Tests::Unit("(1, -2)",      z1.toString());
         Tests::Unit("(0.5, -0.75)", z2.toString());
         Tests::Unit("(7, -0.125)",  z3.toString());
         Tests::Unit("(-1.1, 3)",    z4.toString());
      }

      Tests::Case("Second constructeur normal"); {
      RxR z1(-2), z2(0.5);
         
         Tests::Unit("(-2, 0)",   z1.toString());
         Tests::Unit("(0.5, 0)",  z2.toString());
      }

   Tests::End();
}
