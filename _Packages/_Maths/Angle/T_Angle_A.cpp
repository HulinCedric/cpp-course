//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Angle - Tests unitaires des cas d'anomalies 
//                (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Angle.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Angle", "2.1.0");

      Tests::Design("Controle des anomalies", 3);
	
         Tests::Case("Constructeurs"); { 

			try {Angle a(0.1, 0.1);}
            catch (double e) {           
               Tests::Unit(-3.0, e);
            }

            try {Angle a(1, 1);}
            catch (double e) {           
               Tests::Unit(-3.1, e);
            }
         }

   Tests::End();
}
