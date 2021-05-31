//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Triangle - Tests unitaires du service appartient
//                   (Cas nominaux)
//
// Auteur : C.Fouco
//
#include "Triangle.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Triangle", "2.1.0");

      Tests::Design("Controle du service appartient", 3);
      Point A(0,0), B(2,0), C(0,2);
      Point P1(0, 1), P2(1, 0), P3(1, 1);
      Point E0(0.5, 0.5), E1(1, 0.5); 
      Point Ex1(-0.5, -0.5), Ex2(3, 0), Ex3(0, 3), Ex4(-1, -1), Ex5(2, 2);
      Triangle ABC(A, B, C);

         Tests::Case("Cas d'un sommet"); {

            Tests::Unit(true,  ABC.appartient(A));
            Tests::Unit(true,  ABC.appartient(B));
            Tests::Unit(true,  ABC.appartient(C));
         }

         Tests::Case("Cas d'une arete"); {

            Tests::Unit(true,  ABC.appartient(P1));
            Tests::Unit(true,  ABC.appartient(P2));
            Tests::Unit(true,  ABC.appartient(P3));
         }
            
         Tests::Case("Cas d'un point interieur"); {

            Tests::Unit(true, ABC.appartient(E0));
            Tests::Unit(true, ABC.appartient(E1));
         }

         Tests::Case("Cas d'un point exterieur"); {

            Tests::Unit(false, ABC.appartient(Ex1));
            Tests::Unit(false, ABC.appartient(Ex2));
            Tests::Unit(false, ABC.appartient(Ex3));
            Tests::Unit(false, ABC.appartient(Ex4));
            Tests::Unit(false, ABC.appartient(Ex5));
         }
		 
   Tests::End();
}
