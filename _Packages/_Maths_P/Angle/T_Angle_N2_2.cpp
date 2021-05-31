//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Angle - Tests unitaires des accesseurs 
//                (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Angle.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Angle", "3.0.0");

      Tests::Design("Controle des accesseurs", 3);
	
         Tests::Case("Methode sinus"); {
         Angle a1(PI), a2(-PI), a3(PI/2), a4(PI/4);

            Tests::Unit(0.,  a1.sinus());
            Tests::Unit(0.,  a2.sinus());
            Tests::Unit(1.,  a3.sinus());

            Tests::Unit(0.707107, a4.sinus(), EPSILON);
         }

         Tests::Case("Methode cosinus"); {
         Angle a1(PI), a2(-PI), a3(PI/2), a4(PI/4);

            Tests::Unit(-1.,  a1.cosinus());
            Tests::Unit(-1.,  a2.cosinus());
            Tests::Unit(0.,   a3.cosinus());

            Tests::Unit(0.707107,  a4.cosinus(), EPSILON);
         }

   Tests::End();
}
