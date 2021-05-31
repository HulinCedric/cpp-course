//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Angle - Tests unitaires des operateurs + et +=
//                (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Angle.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Angle", "2.1.0");

      Tests::Design("Controle des operateurs (2eme partie)", 3);

         Tests::Case("Operateur + / Sans cumul d'erreurs d'arrondis "); {
         Angle a1(PI/2), a2(PI/4), a3(PI/3), a4(-PI/2);
         
            Tests::Unit("{0.707107, -0.707107}",  (a1+a2)->toString());
            Tests::Unit("{-0.5, 0.866025}",       (a3+a4)->toString());
         }

         Tests::Case("Operateur + / Avec cumul d'erreurs d'arrondis "); {
         RxR O(0, 0), B(2, 0), A(0, 2), P(0.5, 0.5);
         Angle OPA(O, P, A), APB(A, P, B), BPO(B, P, O);
         
            Tests::Unit(true,  *(*(OPA+APB)+BPO)==-2*PI);

         }

         Tests::Case("Operateur +="); {
         Angle a1(PI/2), a2(PI/4), a3(PI/3), a4(-PI/2);
         
            a1+=a2; Tests::Unit("{0.707107, -0.707107}",  a1.toString());
            a3+=a4; Tests::Unit("{-0.5, 0.866025}",       a3.toString());
         }

   Tests::End();
}
