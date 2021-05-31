//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Fraction - Tests unitaires de l'operateur -= (cas nominaux)
//
// Auteur : C.Fouco
//
#include "Fraction.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Fraction", "2.3.0");

   Tests::Design("Controle des operateurs (Dixieme partie)", 3);
	
      Tests::Case("Operateur -= : cas du produit des denominateurs"); {
      
      Fraction f1(2,3),  f2(5,4), f3(-2,-3), f4(-5,4);
      Fraction f5(2,-3), f6(5,4), f7(-2,-3), f8(5,-2);
      Fraction f9(-2,5), f10(-5,4);
      Fraction f(0);
     

         f=f1; f-=f2;  Tests::Unit("-7/12",  f.toString());
         f=f3; f-=f4;  Tests::Unit("23/12",  f.toString());
         f=f5; f-=f6;  Tests::Unit("-23/12", f.toString());
         f=f7; f-=f8;  Tests::Unit("19/6",   f.toString());
         f=f9; f-=f10; Tests::Unit("17/20", (f9-f10)->toString());
      }

      Tests::Case("Operateur -= : cas d'un PPCM different du produit"); {
      
      Fraction f1(1,10),  f2(1,20), f3(-2,5), f4(-2,15);
      Fraction f5(2,-3), f6(7,6), f7(7,-3), f8(1);
      Fraction f(0);

         f=f1; f-=f2; Tests::Unit("1/20",  f.toString());
         f=f3; f-=f4; Tests::Unit("-4/15", f.toString());
         f=f5; f-=f6; Tests::Unit("-11/6", f.toString());
         f=f7; f-=f8; Tests::Unit("-10/3", f.toString());
      }

      Tests::Case("Operateur -= : cas d'un resultat nul"); {
      
      Fraction f1(2,12),  f2(1,6), f3(2,3), f4(4,6);
      Fraction f5(12,4), f6(3), f7(-0,10), f8(0);
      Fraction f(0);

         f=f1; f-=f2; Tests::Unit("0", f.toString());
         f=f3; f-=f4; Tests::Unit("0", f.toString());
         f=f5; f-=f6; Tests::Unit("0", f.toString());
         f=f7; f-=f8; Tests::Unit("0", f.toString());
      }
	  
      Tests::Case("Operateur -= : cas d'un second operande entier"); {
      
      Fraction f1(-2,12),  f2(1,-5), f3(1,123), f4(4,-16);
      Fraction f(0);

         f=f1; f-=1;  Tests::Unit("-7/6",  f.toString());
         f=f2; f-=-2; Tests::Unit("9/5",   f.toString());
         f=f3; f-=0;  Tests::Unit("1/123", f.toString());
         f=f4; f-=10; Tests::Unit("-41/4", f.toString());
      }

   Tests::End();
}
