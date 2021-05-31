//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Fraction - Tests unitaires de l'operateur = (cas nominaux)
//
// Auteur : C.Fouco
//
#include "Fraction.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Fraction", "2.3.0");

   Tests::Design("Controle des operateurs (Huitieme partie)", 3);
	
      Tests::Case("Operateur = : cas de deux fractions"); {
      
      Fraction f1(2,3),  f2(5,4);
      Fraction f(0);

         f=f1;  Tests::Unit(1, f==f1);
                Tests::Unit(0, f==f2);
         f1=f2; Tests::Unit(0, f1==f);
                Tests::Unit(1, f1==f2);
      }

      Tests::Case("Operateur = : cas d'un entier"); {
      
      Fraction f(-1);

         f=0; Tests::Unit(0, f==1);
              Tests::Unit(1, f==0);
              Tests::Unit(1, f==-0);
         f=7; Tests::Unit(0, f==0);
              Tests::Unit(1, f==7);
      }

   Tests::End();
}
