//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe RxR - Tests unitaires du calcul des racines
//              (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "RxR.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.RxR", "2.0.0");

      Tests::Design("Controle de la methode racines", 3);

         Tests::Case("Racines carrees d'un nombre reel positif"); {
         char attendu[20], obtenu[20];
         RxR z1(1, 0), z2(4, 0);
         RxR** pR;

            pR= z1.racines(2); 
            Tests::Unit("(1, 0)",  pR[0]->toString());
            Tests::Unit("(-1, 0)", pR[1]->toString());
         
            pR= z2.racines(2); 
            Tests::Unit("(2, 0)",  pR[0]->toString());
            Tests::Unit("(-2, 0)", pR[1]->toString());
         }

         Tests::Case("Racines carrees d'un nombre reel negatif"); {
         RxR z1(-1, 0), z2(-9, 0);
         RxR** pR;

            pR= z1.racines(2); 
            Tests::Unit("(0, 1)",  pR[0]->toString());
            Tests::Unit("(0, -1)", pR[1]->toString());
        
            pR= z2.racines(2); 
            Tests::Unit("(0, 3)",  pR[0]->toString());
            Tests::Unit("(0, -3)", pR[1]->toString());
         }

         Tests::Case("Racines carrees d'un nombre complexe quelconque"); {
         RxR z1(0, 1), z2(3, 4), z3(0, -1), z4(3, -4);
         RxR** pR;

            pR= z1.racines(2); 
            Tests::Unit("(0.707107, 0.707107)",   pR[0]->toString());
            Tests::Unit("(-0.707107, -0.707107)", pR[1]->toString());
         
            pR= z2.racines(2); 
            Tests::Unit("(2, 1)",   pR[0]->toString());
            Tests::Unit("(-2, -1)", pR[1]->toString());

            pR= z3.racines(2); 
            Tests::Unit("(0.707107, -0.707107)", pR[0]->toString());
            Tests::Unit("(-0.707107, 0.707107)", pR[1]->toString());
         
            pR= z4.racines(2); 
            Tests::Unit("(2, -1)",  pR[0]->toString());
            Tests::Unit("(-2, 1)",  pR[1]->toString());
         }

         Tests::Case("Racines cubiques d'un nombre reel positif"); {
         RxR z1(1, 0), z2(27, 0);
         RxR** pR;

            pR= z1.racines(3); 
            Tests::Unit("(1, 0)",            pR[0]->toString());
            Tests::Unit("(-0.5, 0.866025)",  pR[1]->toString());
            Tests::Unit("(-0.5, -0.866025)", pR[2]->toString());
         
            pR= z2.racines(3); 
            Tests::Unit("(3, 0)",            pR[0]->toString());
            Tests::Unit("(-1.5, 2.59808)",   pR[1]->toString());
            Tests::Unit("(-1.5, -2.59808)",  pR[2]->toString());
         }

         Tests::Case("Racines cubiques d'un nombre reel negatif"); {
         RxR z1(-1, 0), z2(-64, 0);
         RxR** pR;

            pR= z1.racines(3);
            Tests::Unit("(0.5, 0.866025)",  pR[0]->toString());
            Tests::Unit("(-1, 0)",          pR[1]->toString());
            Tests::Unit("(0.5, -0.866025)", pR[2]->toString());
         
            pR= z2.racines(3);
            Tests::Unit("(2, 3.4641)",      pR[0]->toString());
            Tests::Unit("(-4, 0)",          pR[1]->toString());
            Tests::Unit("(2, -3.4641)",     pR[2]->toString());
         }

         Tests::Case("Racines cubiques d'un nombre complexe quelconque"); {
         RxR z1(0, 1), z2(3, 4), z3(0, -1), z4(3, -4);
         RxR** pR;

            pR= z1.racines(3);
            Tests::Unit("(0.866025, 0.5)",  pR[0]->toString());
            Tests::Unit("(-0.866025, 0.5)", pR[1]->toString());
            Tests::Unit("(0, -1)",          pR[2]->toString());
         
            pR= z2.racines(3);		 
            Tests::Unit("(1.62894, 0.520175)",   pR[0]->toString());
            Tests::Unit("(-1.26495, 1.15061)",   pR[1]->toString());
            Tests::Unit("(-0.363984, -1.67079)", pR[2]->toString());        

            pR= z3.racines(3);
            Tests::Unit("(0.866025, -0.5)",      pR[0]->toString());
            Tests::Unit("(0, 1)",                pR[1]->toString());
            Tests::Unit("(-0.866025, -0.5)",     pR[2]->toString());
         
            pR= z4.racines(3);		 
            Tests::Unit("(1.62894, -0.520175)",  pR[0]->toString());
            Tests::Unit("(-0.363984, 1.67079)",  pR[1]->toString()); 
            Tests::Unit("(-1.26495, -1.15061)",  pR[2]->toString());
         }

   Tests::End();
}
