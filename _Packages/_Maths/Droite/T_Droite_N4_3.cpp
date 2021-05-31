//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Droite - Tests unitaires des methodes projection et distance
//                 (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Droite.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Droite", "2.0.0");

      Tests::Design("Controle des methodes projection et distance", 3);

         Tests::Case("Controle de la methode projection"); {
         Point O(0,0), A(3,0), B(0,2), C(3,2);
         Point p1(0, 2), p2(-2, 0), p3(2, 0);
         Droite AB(A, B), AC(A, C), BC(B, C), d1(p1, p2);

            Tests::Unit("(0.923077, 1.38462)", AB.projection(O)->toString());

            Tests::Unit(A.toString(),     AC.projection(A)->toString());
            Tests::Unit(C.toString(),     AC.projection(B)->toString());
            Tests::Unit(B.toString(),     BC.projection(O)->toString());
            Tests::Unit("(0, 2)",         d1.projection(p3)->toString());
         }

         Tests::Case("Controle de la methode distance"); {
         Point  O(0,0), A(3,0), B(0,2), C(3,2);
         Droite AB(A, B), AC(A, C), BC(B, C);

            Tests::Unit(1.6641,  AB.distance(O), EPSILON);
            Tests::Unit(0,       AC.distance(C), EPSILON);               
         }

   Tests::End();
}
