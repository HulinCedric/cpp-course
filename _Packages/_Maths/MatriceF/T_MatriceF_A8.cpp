//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe MatriceF - Tests unitaires des operateurs () et []
//                   (cas d'anomalies)
//
// Auteur : A. Thuaire
//
#include "MatriceF.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.MatriceF", "2.1.0");

      Tests::Design("Controle d'anomalies des operateurs () et []", 2);
      MatriceF M2(2), M3(3);

         Tests::Case("Premier parametre invalide"); {
         Fraction* pR;

           try {M2(-1, 1)= -3;}
            catch(double e) {Tests::Unit(-2.1, e);}

            try {pR= M2(0);}
            catch(double e) {Tests::Unit(-2.1, e);}

            try {pR= M3[5];}
            catch(double e) {Tests::Unit(-2.1, e);}
         }

		 Tests::Case("Second parametre invalide"); {

            try {M3(1, 0)= -3;}
            catch(double e) {Tests::Unit(-2.2, e);}
         }

   Tests::End();
}

