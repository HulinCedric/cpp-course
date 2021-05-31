//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Segment - Tests unitaires des accesseurs (2eme partie)
//                  (cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Segment.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Segment", "2.0.0");

      Tests::Design("Controle des accesseurs (2eme partie)", 3);

	 Tests::Case("Methode vertical"); {
         Point A(1, 0), B(3, 2), C(-2.5, 0.5), D(1.23, -7.56), E(1, 7);
         Segment AB(A, B), BC(B, C), CD(C, D), AE(A, E);

            Tests::Unit(false, AB.vertical());
            Tests::Unit(false, BC.vertical()); 
            Tests::Unit(false, CD.vertical());
            Tests::Unit(true,  AE.vertical());	 
         }
 
         Tests::Case("Methode longueur"); {
         Point A(1, 0), B(3, 2), C(-1, 0);
         Segment AB(A, B), BC(B, C), AC(A, C);

         char attendu_1[10]; sprintf(attendu_1, "%lg", 2.828427);
         char obtenu_1 [10]; sprintf(obtenu_1,  "%lg", AB.longueur());

         char attendu_2[10]; sprintf(attendu_2, "%lg", 4.472136);
         char obtenu_2 [10]; sprintf(obtenu_2,  "%lg", BC.longueur());

            Tests::Unit(attendu_1, obtenu_1);
            Tests::Unit(attendu_2, obtenu_2);
            Tests::Unit(2, (int)AC.longueur());
         }

         Tests::Case("Methode milieu"); {
         Point A(1, 0), B(3, 2), C(-1, 0), D(0.5, -0.5);
         Segment AB(A, B), BC(B, C), AC(A, C), BD(B, D);
 
            Tests::Unit("(2, 1)",       AB.milieu()->toString());
            Tests::Unit("(1, 1)",       BC.milieu()->toString());
            Tests::Unit("(0, 0)",       AC.milieu()->toString());
            Tests::Unit("(1.75, 0.75)", BD.milieu()->toString());
         }
 
   Tests::End();
}
