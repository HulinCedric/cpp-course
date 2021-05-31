//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Segment - Tests unitaires des accesseurs (1ere partie)
//                  (cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Segment.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Segment", "3.0.0");

      Tests::Design("Controle des accesseurs (1ere partie)", 3);

         Tests::Case("Methode extremites"); {
         Point A(1, 0), B(3, 2), C(-2.5, 0.5), D(1.23, -7.56);
         Segment AB(A, B), BC(B, C), CD(C, D);
         Point** pE;

            pE= AB.extremites();
            Tests::Unit(A.toString(), pE[0]->toString()); 
            Tests::Unit(B.toString(), pE[1]->toString()); 		 

            pE= BC.extremites();
            Tests::Unit(B.toString(), pE[0]->toString()); 
            Tests::Unit(C.toString(), pE[1]->toString()); 		 

            pE= CD.extremites();
            Tests::Unit(C.toString(), pE[0]->toString()); 
            Tests::Unit(D.toString(), pE[1]->toString()); 		 
         }

         Tests::Case("Methode extremite"); {
         Point A(1, 0), B(3, 2), C(-2.5, 0.5), D(1.23, -7.56);
         Segment AB(A, B), BC(B, C), CD(C, D);

            Tests::Unit(true,  AB.extremite(A));
            Tests::Unit(true,  AB.extremite(B)); 
            Tests::Unit(false, AB.extremite(C));
            Tests::Unit(false, CD.extremite(A));	 
         }

	Tests::Case("Methode horizontal"); {
         Point A(1, 0), B(3, 2), C(-2.5, 0.5), D(1.23, -7.56), E(-3, 0);
         Segment AB(A, B), BC(B, C), CD(C, D), AE(A, E);

            Tests::Unit(false, AB.horizontal());
            Tests::Unit(false, BC.horizontal()); 
            Tests::Unit(false, CD.horizontal());
            Tests::Unit(true,  AE.horizontal());	 
         }
 
   Tests::End();
}
