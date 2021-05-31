//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe Matrice - Tests unitaires des constructeurs
//                  (cas d'anomalies)
//
// Auteur : A. Thuaire
//
#include "Matrice.h"
#include "T:\_Tests\Tests.h"

void main () {
   
   Tests::Begin("_Maths.Matrice", "2.1.0");

      Tests::Design("Controle d'anomalies des constructeurs", 2);

         Tests::Case("Constructeur normal / Ordre < 1"); {
	  
            try {Matrice M(-2);}
            catch (double e) {Tests::Unit(-2.1, e);}
         }

         Tests::Case("Constructeur normal / Ordre trop important"); {
	  
            try {Matrice M(100000);}
            catch (double e) {Tests::Unit(-1.0, e);}
         }

   Tests::End();
}
