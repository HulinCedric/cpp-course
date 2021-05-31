//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Fraction - Tests unitaires de l'operateur + (cas nominaux)
//
// Auteur : C.Fouco
//
#include "Fraction.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Fraction", "2.3.0");

   Tests::Design("Controle des operateurs (Premiere partie)", 3);
	
      Tests::Case("Operateur + : cas du produit des denominateurs"); {
      
      Fraction f1(2,3),  f2(5,4), f3(-2,-3), f4(-5,-4);
      Fraction f5(2,-3), f6(5,4), f7(-2,-3), f8(5,-4);
      Fraction f9(-2,3), f10(-5,4);

         Tests::Unit("23/12", (f1+f2)->toString());
         Tests::Unit("23/12", (f3+f4)->toString());
         Tests::Unit("7/12",  (f5+f6)->toString());
         Tests::Unit("-7/12", (f7+f8)->toString());
         Tests::Unit("-23/12", (f9+f10)->toString());
      }

      Tests::Case("Operateur + : cas d'un PPCM different du produit"); {
      
      Fraction f1(1,10),  f2(1,20), f3(-2,5), f4(-2,15);
      Fraction f5(2,-3), f6(3,4), f7(7,-3), f8(1);

         Tests::Unit("3/20",  (f1+f2)->toString());
         Tests::Unit("-8/15", (f3+f4)->toString());
         Tests::Unit("1/12",  (f5+f6)->toString());
         Tests::Unit("-4/3",  (f7+f8)->toString());
      }

      Tests::Case("Operateur + : cas d'un resultat nul"); {
      
      Fraction f1(2,12),  f2(1,-6), f3(-2,-3), f4(4,-6);
      Fraction f5(12,-4), f6(3), f7(-0,10), f8(0);

         Tests::Unit("0", (f1+f2)->toString());
         Tests::Unit("0", (f3+f4)->toString());
         Tests::Unit("0", (f5+f6)->toString());
         Tests::Unit("0", (f7+f8)->toString());
      }
	  
      Tests::Case("Operateur + : cas d'un second operande entier"); {
      
      Fraction f1(-2,12),  f2(1,-5), f3(1,123), f4(4,-16);

         Tests::Unit("-7/6",  (f1+(-1))->toString());
         Tests::Unit("4/5",   (f2+1)->toString());
         Tests::Unit("1/123", (f3+0)->toString());
         Tests::Unit("39/4",  (f4+10)->toString());
      }

   Tests::End();
}
