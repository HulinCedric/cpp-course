//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe MatriceF - Tests unitaires de l'operateur +
//                   (cas d'anomalies)
//
// Auteur : A. Thuaire
//
#include "MatriceF.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.MatriceF", "2.1.0");

      Tests::Design("Controle d'anomalies pour l'operateur +", 2);
      MatriceF M1, M2(2);

         Tests::Case("Operandes d'ordres differents"); {

            try {(M1+M2).ordre();}
            catch(double e) {Tests::Unit(-3.0, e);}
         }

   Tests::End();
}

