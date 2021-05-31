//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Segment - Tests unitaires des constructeurs
//                  (cas d'anomalies)
//
// Auteur : A. Thuaire
//
#include "Segment.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Segment", "3.0.0");
   int compteur= 0;

      Tests::Design("Controle de la construction", 3);
 
         Tests::Case("Constructeur normal"); {
         Point A(1, 0);

            try {Segment AA(A, A);}
            catch(double e) {Tests::Unit(-3.0, e); compteur++;}
         }

         Tests::Case("Controle de syntheses"); {

            Tests::Unit(1, compteur); 
         }

 
   Tests::End();
}
