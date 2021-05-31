//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Segment - Tests unitaires des methodes projX, projY
//                  et translation (cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Segment.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Segment", "2.0.0");

      Tests::Design("Controle des methodes projX et projY", 3);

         Tests::Case("Methode projX"); {
         Point A(1, 0), B(3, 2), C(-2.5, 0.5), D(1.23, -7.56);
         Point A1(1, 0), B1(3, 0), C1(-2.5, 0), D1(1.23, 0);
         Segment AB(A, B), BC(B, C), CD(C, D);
         Segment A1B1(A1, B1), B1C1(B1, C1), C1D1(C1, D1);

            Tests::Unit(A1B1.toString(), AB.projX()->toString()); 
            Tests::Unit(B1C1.toString(), BC.projX()->toString());
            Tests::Unit(C1D1.toString(), CD.projX()->toString());             	 
         }

         Tests::Case("Methode projY"); {
         Point A(1, 0), B(3, 2), C(-2.5, 0.5), D(1.23, -7.56);
         Point A1(0, 0), B1(0, 2), C1(0, 0.5), D1(0, -7.56);
         Segment AB(A, B), BC(B, C), CD(C, D);
         Segment A1B1(A1, B1), B1C1(B1, C1), C1D1(C1, D1);

            Tests::Unit(A1B1.toString(), AB.projY()->toString()); 
            Tests::Unit(B1C1.toString(), BC.projY()->toString());
            Tests::Unit(C1D1.toString(), CD.projY()->toString());             	 
         }
 
   Tests::End();
}
