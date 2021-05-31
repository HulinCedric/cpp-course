//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Triangle - Tests unitaires du service distance
//                   (Cas nominaux)
//
// Auteur : C.Fouco
//
#include "Triangle.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Triangle", "2.1.0");

      Tests::Design("Controle du service distance", 3);
      Point A(0,0), B(2,0), C(0,2);
      Point P1(0, 1), P2(1, 0), P3(1, 1);
      Point E1(-0.5, -0.5), E2(3, 0), E3(0, 3), E4(-1, -1), E5(2, 2);
      Triangle ABC(A, B, C);

         Tests::Case("Controle de la methode distance"); {
         Point E5(2, 2);

            Tests::Unit(0.,  ABC.distance(A));
            Tests::Unit(0.,  ABC.distance(B));
            Tests::Unit(0.,  ABC.distance(C));

            Tests::Unit(0.,  ABC.distance(P1));
            Tests::Unit(0.,  ABC.distance(P2));
            Tests::Unit(0.,  ABC.distance(P3));

            Tests::Unit(0.707107, ABC.distance(E1), EPSILON);
            Tests::Unit(1.,       ABC.distance(E2));
            Tests::Unit(1.,       ABC.distance(E3));
            Tests::Unit(1.41421,  ABC.distance(E4), EPSILON);
            Tests::Unit(1.41421,  ABC.distance(E5), EPSILON);
         }
      
   Tests::End();
}
