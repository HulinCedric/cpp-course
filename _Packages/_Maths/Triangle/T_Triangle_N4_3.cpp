//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Triangle - Tests unitaires du service intersection
//                   (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Triangle.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Triangle", "2.1.0");

      Tests::Design("Controle de la methode intersection", 3);
      Point O(0,0), A(2,0), B(0,2);
      Triangle OAB(O, A, B);

         Tests::Case("L'origine de la demi droite est l'un des sommets"); {
         Point P(2, 2);
         Vecteur OP(O, P), AP(A, P);
         DemiDroite d1(O, OP), d2(A, AP);

            Tests::Unit("(0, 0)",  OAB.intersection(d1)->toString());
            Tests::Unit("(2, 0)",  OAB.intersection(d2)->toString());
         }

         Tests::Case("L'origine de la demi droite appartient au triangle"); {
         Point P(0.5, 0.5), Q(2, 2);
         Vecteur PO(P, O), PA(P, A), PB(P, B), PQ(P, Q);
         DemiDroite d1(P, PO), d2(P, PA), d3(P, PB), d4(P, PQ);

            Tests::Unit("(0, 0)",  OAB.intersection(d1)->toString());
            Tests::Unit("(2, 0)",  OAB.intersection(d2)->toString());
            Tests::Unit("(0, 2)",  OAB.intersection(d3)->toString());
            Tests::Unit("(1, 1)",  OAB.intersection(d4)->toString());
         }

         Tests::Case("L'origine de la demi droite est dans le prolongement d'une arete"); {
         Point P(4, 0), Q(-7, 0);
         Vecteur PA(P, A), QO(Q, O);
         DemiDroite d1(P, PA), d2(Q, QO);

            Tests::Unit("(2, 0)",  OAB.intersection(d1)->toString());
            Tests::Unit("(0, 0)",  OAB.intersection(d2)->toString());
         }

         Tests::Case("Cas general / Deux intersections"); {
         Point P(2, 2), Q(1, 2);
         Vecteur V1(-0.5, -0.5);
         DemiDroite d1(P, V1), d2(Q, V1);

            Tests::Unit("(1, 1)",     OAB.intersection(d1)->toString());
            Tests::Unit("(0.5, 1.5)", OAB.intersection(d2)->toString());
         }

         Tests::Case("Cas general / Intersection sur un sommet seulement"); {
         Point P(2, 2);
         Vecteur V1(0, -1), V2(-1, 0);
         DemiDroite d1(P, V1), d2(P, V2);

            Tests::Unit("(2, 0)", OAB.intersection(d1)->toString());
            Tests::Unit("(0, 2)", OAB.intersection(d2)->toString());
         }

		 Tests::Case("Cas general / Absence d'intersections"); {
         Point P(2, 2);
         Vecteur V1(0, 1), V2(1, 0);
         DemiDroite d1(P, V1), d2(P, V2);

            Tests::Unit(NULL, (int)OAB.intersection(d1));
            Tests::Unit(NULL, (int)OAB.intersection(d2));
         }

   Tests::End();
}
