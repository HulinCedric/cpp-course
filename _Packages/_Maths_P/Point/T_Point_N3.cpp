//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Point - Tests unitaires des methodes projX, projY et distance 
//                (cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Point.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Point", "3.0.0");

      Tests::Design("Controle des services (1ere partie)", 3);

         Tests::Case("Methode projX"); {
         
         Point p1(4,-7.1), p2(11, 9.81), p3(-1.34, 2.55), p4(-77.12, -22.13);
         Point r1(4,0), r2(11, 0), r3(-1.34, 0), r4(-77.12, 0);
         
            Tests::Unit(r1.toString(), p1.projX()->toString());
            Tests::Unit(r2.toString(), p2.projX()->toString());
            Tests::Unit(r3.toString(), p3.projX()->toString());
            Tests::Unit(r4.toString(), p4.projX()->toString());
         }

         Tests::Case("Methode projY"); {  
         Point p1(4,-7.1), p2(11, 9.81), p3(-1.34, 2.55), p4(-77.12, -22.13);
         Point r1(0,-7.1), r2(0, 9.81), r3(0, 2.55), r4(0, -22.13); 
	  
            Tests::Unit(r1.toString(), p1.projY()->toString());
            Tests::Unit(r2.toString(), p2.projY()->toString());
            Tests::Unit(r3.toString(), p3.projY()->toString());
            Tests::Unit(r4.toString(), p4.projY()->toString());
         }

         Tests::Case("Methode distance"); { 
         Point p0(0,0), p1(1, 0), p2(0, 1), p3(0, -1), p4(1, 1);
         
            Tests::Unit(1.0, p0.distance(p1));
            Tests::Unit(1.0, p0.distance(p2));
            Tests::Unit(sqrt(2), p1.distance(p2));
            Tests::Unit(sqrt(5), p3.distance(p4));
         }

   Tests::End();
}
