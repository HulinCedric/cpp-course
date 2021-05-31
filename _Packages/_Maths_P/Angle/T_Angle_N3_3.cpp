//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Angle - Tests unitaires des operateurs - et -=
//                (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Angle.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Angle", "3.0.0");

      Tests::Design("Controle des operateurs (3eme partie)", 3);

         Tests::Case("Operateur -"); {
         Angle a1(PI/2), a2(PI/4), a3(PI/3), a4(-PI/2);
         
            Tests::Unit("{0.707107, 0.707107}",  (a1-a2)->toString());
            Tests::Unit("{0.5, -0.866025}",      (a3-a4)->toString());
         }

         Tests::Case("Operateur -="); {
         Angle a1(PI/2), a2(PI/4), a3(PI/3), a4(-PI/2);
         
            a1-=a2; Tests::Unit("{0.707107, 0.707107}",  a1.toString());
            a3-=a4; Tests::Unit("{0.5, -0.866025}",      a3.toString());
         }

   Tests::End();
}
