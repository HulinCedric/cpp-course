//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Triangle - Tests unitaires des accesseurs (2eme partie)
//
// Auteur : C.Fouco
//
#include "Triangle.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Triangle", "2.1.0");

      Tests::Design("Controle des accesseurs (2eme partie)", 3);

         Tests::Case("Controle de la methode angle"); {
         Point O(0,0), A(0, 1), B(-1, 0), C(1, 0);
         Triangle ABC(A,B,C), AOB(A, O, B), T;
		 
            Tests::Unit("{0.707107, 0.707107}",  ABC.angle(C)->toString());
            Tests::Unit("{1, 0}",                ABC.angle(A)->toString());
            Tests::Unit("{-0.707107, 0.707107}", ABC.angle(B)->toString());
         }

         Tests::Case("Controle de la methode oppose"); {
         Point O(0,0), A(0, 1), B(-1, 0), C(1, 0);
         Triangle ABC(A,B,C), AOB(A, O, B), T;
		 
            Tests::Unit("(-1, -1)", ABC.oppose(C)->toString());
            Tests::Unit("(2, 0)",   ABC.oppose(A)->toString());
            Tests::Unit("(1, -1)",  ABC.oppose(B)->toString());
         }

         Tests::Case("Controle de la methode plusProcheSommet"); {
         Point O(0,0), A(0, 1), B(-1, 0), C(1, 0);
         Triangle ABC(A,B,C), AOB(A, O, B), T;
		 
            Tests::Unit("(0, 1)",  ABC.plusProcheSommet(C)->toString());
            Tests::Unit("(1, 0)",  ABC.plusProcheSommet(A)->toString());
            Tests::Unit("(0, 1)",  ABC.plusProcheSommet(B)->toString());
         }

   Tests::End();
}
