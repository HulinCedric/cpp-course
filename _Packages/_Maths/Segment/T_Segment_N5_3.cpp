//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Segment - Tests unitaires de la methode distance
//                  (cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Segment.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Segment", "2.0.0");

      Tests::Design("Controle de la methode distance", 3);

         Tests::Case("Cas ou le point P appartient au segment"); {
         Point A(0, 1), B(0, -1), C(0, -2);
         Point D(-2.5, 0), E(3.75, 0);
         Point P(0, 0);
         Segment AC(A, C);
	 
            Tests::Unit(0.,  AC.distance(P));
            Tests::Unit(0.,  AC.distance(B));
            Tests::Unit(0.,  AC.distance(A));
         }

         Tests::Case("Cas d'un segment vertical"); {
         Point A(0, 1), B(0, -1), C(4, -1.5), D(4, 7.5);
         Point P(1, 1);
         Segment AB(A, B), CD(C, D);
	 
            Tests::Unit(1., AB.distance(P));
            Tests::Unit(3., CD.distance(P));
         }

         Tests::Case("Cas d'un segment horizontal"); {
         Point A(2, 0), B(-2, 0), C(-1.5, 3), D(7.5, 3);
         Point P(-1.25, 1);
         Segment AB(A, B), CD(C, D);
	 
            Tests::Unit(1., AB.distance(P));
            Tests::Unit(2., CD.distance(P));
         }

         Tests::Case("Cas d'un segment oblique quelconque"); {
         Point O(0, 0), A(1, 1), B(3, 2), C(3, 0), D(2, -1);
         Point E(1, 3), F(4, 0), G(-3, 7);
         Point P(2, 0);
         Segment AB(A, B), EF(E, F);
         char attendu[15], obtenu[15];
	 
            sprintf(attendu, "%lg", 1.341641);
            sprintf(obtenu,  "%lg", AB.distance(P));
            Tests::Unit(attendu, obtenu);

            sprintf(attendu, "%lg", 1.788854);
            sprintf(obtenu,  "%lg", AB.distance(C));
            Tests::Unit(attendu, obtenu);

            sprintf(attendu, "%lg", 2.236068);
            sprintf(obtenu,  "%lg", AB.distance(D));
            Tests::Unit(attendu, obtenu);

            sprintf(attendu, "%lg", 2.828427);
            sprintf(obtenu,  "%lg", EF.distance(O));
            Tests::Unit(attendu, obtenu);

            sprintf(attendu, "%lg", 1.414214);
            sprintf(obtenu,  "%lg", EF.distance(P));
            Tests::Unit(attendu, obtenu);
         }

   Tests::End();
}
