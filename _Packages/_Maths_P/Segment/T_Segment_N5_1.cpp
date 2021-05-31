//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Segment - Tests unitaires des methodes aligne et appartient
//                  (cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Segment.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Segment", "3.0.0");

      Tests::Design("Controle de la methode aligne", 3);

         Tests::Case("Cas particulier d'un segment vertical"); {
         Point O(0, 0), A(0, 1), B(0, 2), C(0, -5), D(0, 1.25);
         Point E(-1, 2);
         Segment AB(A, B);
	 
            Tests::Unit(true,  AB.aligne(O));
            Tests::Unit(true,  AB.aligne(C));
            Tests::Unit(true,  AB.aligne(A));
            Tests::Unit(true,  AB.aligne(B));
            Tests::Unit(true,  AB.aligne(D));
            Tests::Unit(false, AB.aligne(E));
         }

         Tests::Case("Cas particulier d'un segment horizontal"); {
         Point O(0, 0), A(1, 0), B(2, 0), C(-5, 0), D(1.25, 0);
         Point E(-1, 2);
         Segment AB(A, B), CD(C, D);
	 
            Tests::Unit(true,  AB.aligne(O));
            Tests::Unit(true,  AB.aligne(C));
            Tests::Unit(true,  AB.aligne(A));
            Tests::Unit(true,  CD.aligne(B));
            Tests::Unit(true,  CD.aligne(D));
            Tests::Unit(false, CD.aligne(E));
         }

         Tests::Case("Cas general d'un segment oblique"); {
         Point O(0, 0), A(0.5, 0.5), B(1, 1), C(-4.5, -4.5);
         Point E(-1, 2);
         Segment AB(A, B), BC(B, C);
	 
            Tests::Unit(true,  AB.aligne(O));
            Tests::Unit(true,  AB.aligne(C));
            Tests::Unit(true,  BC.aligne(A));
            Tests::Unit(true,  BC.aligne(B));
            Tests::Unit(false, BC.aligne(E));
         }

      Tests::Design("Controle de la methode appartient", 3);

         Tests::Case("Cas particulier des deux extremites"); {
         Point O(0, 0), A(0, 1), B(0, -5);
         Segment AB(A, B);
	 
            Tests::Unit(true,  AB.appartient(O));
            Tests::Unit(true,  AB.appartient(A));
            Tests::Unit(true,  AB.appartient(B));
         }

         Tests::Case("Cas general d'un segment oblique"); {
         Point O(0, 0), A(0.5, 0.5), B(1, 1), C(-4.5, -4.5);
         Point E(-1, 2);
         Segment AB(A, B), BC(B, C), OC(O, C);
	 
            Tests::Unit(false,  AB.appartient(O));
            Tests::Unit(true,   BC.appartient(O));
            Tests::Unit(false,  OC.appartient(A));
            Tests::Unit(true,   BC.appartient(A));
            Tests::Unit(false,  AB.appartient(C));
            Tests::Unit(false,  BC.appartient(E));
         }

         Tests::Case("Controles complementaires"); {
         Point O(0, 0), A(2, 0), B(0, 2);
         Point P1(3, 0), P2(-0.5, 0), P3(-0.5, -0.5), P4(0, -0.5);
         Segment OA(O, A), OB(O, B);

            Tests::Unit(false,  OA.appartient(P1));
            Tests::Unit(false,  OA.appartient(P2));
            Tests::Unit(false,  OB.appartient(P3));
            Tests::Unit(false,  OB.appartient(P4));
         }

   Tests::End();
}
