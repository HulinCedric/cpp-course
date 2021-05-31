//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Fraction - Tests unitaires des operateurs < et <= (cas nominaux)
//
// Auteur : C.Fouco
//
#include "Fraction.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Fraction", "2.3.0");

   Tests::Design("Controle des operateurs (Sixieme partie)", 3);
	
      Tests::Case("Operateur < : cas de deux fractions"); {
      
      Fraction f1(2,3),  f2(5,4), f3(-2,-3), f4(-5,4);
      Fraction f5(2,-3), f6(5,4), f7(-2,-3), f8(5,-2);
      Fraction f9(-2,5), f10(2, -5);

         Tests::Unit(1, f1<f2);
         Tests::Unit(0, f3<f4);
         Tests::Unit(1, f5<f6);
         Tests::Unit(0, f7<f8);
         Tests::Unit(0, f9<f10);
      }

      Tests::Case("Operateur < : comparaison avec un entier"); {
      
      Fraction f1(2,3),  f2(5,-4), f3(-2,-3), f4(-5,4);

         Tests::Unit(1, f1<1);
         Tests::Unit(1, f2<-1);
         Tests::Unit(0, f3<0);
         Tests::Unit(0, f4<-2);
      }

      Tests::Case("Operateur <= : cas de deux fractions"); {
      
      Fraction f1(2,3),  f2(-2,-3), f3(-2,-3), f4(-5,4);
      Fraction f5(2,-3), f6(5,4), f7(-2,-3), f8(5,-2);
      Fraction f9(-2,5), f10(2, -5);

         Tests::Unit(1, f1<=f2);
         Tests::Unit(0, f3<=f4);
         Tests::Unit(1, f5<=f6);
         Tests::Unit(0, f7<=f8);
         Tests::Unit(1, f9<=f10);
      }

      Tests::Case("Operateur <= : comparaison avec un entier"); {
      
      Fraction f1(2,3),  f2(5,-4), f3(0), f4(-5,4);

         Tests::Unit(1, f1<=1);
         Tests::Unit(1, f2<=-1);
         Tests::Unit(1, f3<=0);
         Tests::Unit(0, f4<=-2);
      }

   Tests::End();
}
