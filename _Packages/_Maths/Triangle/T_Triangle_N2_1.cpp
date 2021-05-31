//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Triangle - Tests unitaires des accesseurs (1ere partie)
//                   (Cas nominaux)
//
// Auteur : C.Fouco
//
#include "Triangle.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Triangle", "2.1.0");

      Tests::Design("Controle des accesseurs (1ere partie)", 3);

         Tests::Case("Controle de la presence d'un sommet"); {
         Point O(0, 0), A(0, 2), B(-2, 0), C(-1.5, 2.2), D(1.5, -1.25);
         Triangle ABC(A, B, C), CDB(C, D, B);
         Triangle T;

            Tests::Unit(true,  ABC.sommet(B));
            Tests::Unit(false, ABC.sommet(O));
            Tests::Unit(true,  ABC.sommet(C));
            Tests::Unit(true,  ABC.sommet(A));
 
            Tests::Unit(true,  CDB.sommet(B));
            Tests::Unit(false, CDB.sommet(A));
            Tests::Unit(true,  CDB.sommet(D));
            Tests::Unit(true,  CDB.sommet(C));

            Tests::Unit(false, T.sommet(A));
         }

         Tests::Case("Controle de la restitution d'un sommet"); {
         Point O(0, 0), A(0, 2), B(-2, 0), C(-1.5, 2.2), D(1.5, -1.25);
         Triangle ABC(A, B, C), CDB(C, D, B);
         Triangle T;

            Tests::Unit("(0, 2)",       ABC.sommet(1)->toString());
            Tests::Unit("(-2, 0)",      ABC.sommet(2)->toString());
            Tests::Unit("(-1.5, 2.2)",  ABC.sommet(3)->toString());

            Tests::Unit("(1.5, -1.25)", CDB.sommet(2)->toString());
         }

         Tests::Case("Controle de la methode perimetre"); {
         Point O(0,0), A(0, 1), B(-1, 0), C(1, 0);
         Triangle ABC(A,B,C), AOB(A, O, B), T;
         char obtenu[10];
		 
            sprintf(obtenu, "%lg", ABC.perimetre()); 
            Tests::Unit("4.82843", obtenu);

            sprintf(obtenu, "%lg", AOB.perimetre());
            Tests::Unit("3.41421", obtenu);

            sprintf(obtenu, "%lg", T.perimetre());
            Tests::Unit("4.82843", obtenu);
         }

         Tests::Case("Controle de la methode surface"); {
         Point O(0,0), A(0, 1), B(-1, 0), C(1, 0);
         Triangle ABC(A,B,C), AOB(A, O, B), T;
         char obtenu[10];
		 
            sprintf(obtenu, "%lg", ABC.surface()); 
            Tests::Unit("1", obtenu);

            sprintf(obtenu, "%lg", AOB.surface());
            Tests::Unit("0.5", obtenu);

            sprintf(obtenu, "%lg", T.surface());
            Tests::Unit("1", obtenu);
         }

   Tests::End();
}
