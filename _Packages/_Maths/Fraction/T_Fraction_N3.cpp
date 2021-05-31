//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Fraction - Tests unitaires de l'operateur * (cas nominaux)
//
// Auteur : C.Fouco
//
#include "Fraction.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Fraction", "2.3.0");

   Tests::Design("Controle des operateurs (Troisieme partie)", 3);
	
      Tests::Case("Operateur * : cas de l'absence de reduction du resultat"); {
      
      Fraction f1(2,3),  f2(5,7), f3(-2,-3), f4(-5,9);
      Fraction f5(2,-3), f6(5,3), f7(-1,-3), f8(5,-2);
      Fraction f9(-1,5), f10(-7,4);

         Tests::Unit("10/21",  (f1*f2)->toString());
         Tests::Unit("-10/27", (f3*f4)->toString());
         Tests::Unit("-10/9",  (f5*f6)->toString());
         Tests::Unit("-5/6",   (f7*f8)->toString());
         Tests::Unit("7/20",   (f9*f10)->toString());
      }

      Tests::Case("Operateur * : cas d'une reduction apres multiplication"); {
      
      Fraction f1(7,10),  f2(1,7), f3(-3,5), f4(-2,15);
      Fraction f5(2,-3), f6(7,6), f7(7,-3), f8(1, 7);

         Tests::Unit("1/10", (f1*f2)->toString());
         Tests::Unit("2/25", (f3*f4)->toString());
         Tests::Unit("-7/9", (f5*f6)->toString());
         Tests::Unit("-1/3", (f7*f8)->toString());
      }

      Tests::Case("Operateur * : cas d'un resultat entier"); {
      
      Fraction f1(2,12),  f2(24), f3(2,3), f4(6,4);
      Fraction f5(9,4), f6(16, -3), f7(-0,10), f8(0);

         Tests::Unit("4",   (f1*f2)->toString());
         Tests::Unit("1",   (f3*f4)->toString());
         Tests::Unit("-12", (f5*f6)->toString());
         Tests::Unit("0",   (f7*f8)->toString());
      }
	  
      Tests::Case("Operateur * : cas d'un second operande entier"); {
      
      Fraction f1(-2,12),  f2(1,-5), f3(1,123), f4(1,-16);

         Tests::Unit("-1/6",  (f1*1)->toString());
         Tests::Unit("2/5",   (f2*(-2))->toString());
         Tests::Unit("0",     (f3*0)->toString());
         Tests::Unit("-5/16", (f4*5)->toString());
      }

   Tests::End();
}
