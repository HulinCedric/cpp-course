//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Fraction - Tests unitaires de l'operateur *= (cas nominaux)
//
// Auteur : C.Fouco
//
#include "Fraction.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Fraction", "2.3.0");

   Tests::Design("Controle des operateurs (Onzieme partie)", 3);
	
      Tests::Case("Operateur *= : cas de l'absence de reduction du resultat"); {
      
      Fraction f1(2,3),  f2(5,7), f3(-2,-3), f4(-5,9);
      Fraction f5(2,-3), f6(5,3), f7(-1,-3), f8(5,-2);
      Fraction f9(-1,5), f10(-7,4);
      Fraction f(0);

         f=f1; f*=f2;  Tests::Unit("10/21",  f.toString());
         f=f3; f*=f4;  Tests::Unit("-10/27", f.toString());
         f=f5; f*=f6;  Tests::Unit("-10/9",  f.toString());
         f=f7; f*=f8;  Tests::Unit("-5/6",   f.toString());
         f=f9; f*=f10; Tests::Unit("7/20",   f.toString());
      }

      Tests::Case("Operateur *= : cas d'une reduction apres multiplication"); {
      
      Fraction f1(7,10),  f2(1,7), f3(-3,5), f4(-2,15);
      Fraction f5(2,-3), f6(7,6), f7(7,-3), f8(1, 7);
      Fraction f(0);

         f=f1; f*=f2; Tests::Unit("1/10", f.toString());
         f=f3; f*=f4; Tests::Unit("2/25", f.toString());
         f=f5; f*=f6; Tests::Unit("-7/9", f.toString());
         f=f7; f*=f8; Tests::Unit("-1/3", f.toString());
      }

      Tests::Case("Operateur *= : cas d'un resultat entier"); {
      
      Fraction f1(2,12),  f2(24), f3(2,3), f4(6,4);
      Fraction f5(9,4), f6(16, -3), f7(-0,10), f8(0);
      Fraction f(0);

         f=f1; f*=f2; Tests::Unit("4",   f.toString());
         f=f3; f*=f4; Tests::Unit("1",   f.toString());
         f=f5; f*=f6; Tests::Unit("-12", f.toString());
         f=f7; f*=f8; Tests::Unit("0",   f.toString());
      }
	  
      Tests::Case("Operateur *= : cas d'un second operande entier"); {
      
      Fraction f1(-2,12),  f2(1,-5), f3(1,123), f4(1,-16);
      Fraction f(0);

         f=f1; f*=1;  Tests::Unit("-1/6",  f.toString());
         f=f2; f*=-2; Tests::Unit("2/5",   f.toString());
         f=f3; f*=0;  Tests::Unit("0",     f.toString());
         f=f4; f*=5;  Tests::Unit("-5/16", f.toString());
      }

   Tests::End();
}
