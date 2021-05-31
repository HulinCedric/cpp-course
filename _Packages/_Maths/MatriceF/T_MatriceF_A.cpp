//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe MatriceF - Tests unitaires des constructeurs
//                   (cas d'anomalies)
//
// Auteur : A. Thuaire
//
#include "MatriceF.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {
   
   Tests::Begin("_Maths.MatriceF", "2.1.0");

      Tests::Design("Controle d'anomalies des constructeurs", 3);

         Tests::Case("Constructeur normal / Ordre < 1"); {
	  
            try {MatriceF M(-2);}
            catch (double e) {Tests::Unit(-2.1, e);}
         }

         Tests::Case("Constructeur normal / Ordre trop important"); {
	  
            try {MatriceF M(100000);}
            catch (double e) {Tests::Unit(-1.0, e);}
         }

   Tests::End();
}
