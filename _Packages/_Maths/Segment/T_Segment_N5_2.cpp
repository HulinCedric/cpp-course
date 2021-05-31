//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe Segment - Tests unitaires de la methode projection
//                  (cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Segment.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Segment", "2.0.0");

      Tests::Design("Controle de la methode projection", 3);

         Tests::Case("Cas ou le point P appartient au segment"); {
         Point A(0, 1), B(0, -1), C(0, -2);
         Point D(-2.5, 0), E(3.75, 0);
         Point P(0, 0);
         Segment AC(A, C);
	 
            Tests::Unit("(0, 0)",   AC.projection(P)->toString());
            Tests::Unit("(0, -1)",  AC.projection(B)->toString());
            Tests::Unit("(0, 1)",   AC.projection(A)->toString());
            Tests::Unit("(0, -2)",  AC.projection(C)->toString());
         }

         Tests::Case("Cas ou le point P est aligne"); {
         Point A(0, 1), B(0, -1), C(0, -2);
         Point D(-2.5, 0), E(3.75, 0);
         Point P(-3, 0);
         Segment AB(A, B), DE(D, E);
	 
            Tests::Unit((int)NULL,  (int)AB.projection(C));
            Tests::Unit((int)NULL,  (int)DE.projection(P));
         }

         Tests::Case("Cas ou la projection est hors du segment"); {
         Point O(0, 0), B(0, 2);
         Point P(-0.5, -0.5);
         Segment OB(O, B);
	 
            Tests::Unit((int)NULL,  (int)OB.projection(P));
         }

         Tests::Case("Cas d'un segment vertical"); {
         Point A(0, 1), B(0, -1), C(4, -1.5), D(4, 7.5);
         Point P(1, 1);
         Segment AB(A, B), CD(C, D);
	 
            Tests::Unit("(0, 1)", AB.projection(P)->toString());
            Tests::Unit("(4, 1)", CD.projection(P)->toString());
         }

         Tests::Case("Cas d'un segment horizontal"); {
         Point A(2, 0), B(-2, 0), C(-1.5, 3), D(7.5, 3);
         Point P(-1.25, 1);
         Segment AB(A, B), CD(C, D);
	 
            Tests::Unit("(-1.25, 0)", AB.projection(P)->toString());
            Tests::Unit("(-1.25, 3)", CD.projection(P)->toString());
         }

         Tests::Case("Cas d'un segment oblique quelconque"); {
         Point O(0, 0), A(1, 1), B(3, 2), C(3, 0), D(2, -1);
         Point E(1, 3), F(4, 0), G(-3, 7);
         Point P(2, 0);
         Segment AB(A, B), EF(E, F);
	 
            Tests::Unit("(1.4, 1.2)", AB.projection(P)->toString());
            Tests::Unit("(2.2, 1.6)", AB.projection(C)->toString());
            Tests::Unit("(1, 1)",     AB.projection(D)->toString());
            Tests::Unit("(2, 2)",     EF.projection(O)->toString());
            Tests::Unit("(3, 1)",     EF.projection(P)->toString());
         }

   Tests::End();
}
