//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Angle - Tests unitaires des predicats predefinis 
//                (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Angle.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Angle", "3.0.0");

      Tests::Design("Controle des predicats predefinis", 3);
	
         Tests::Case("Predicat neutre"); {
         Angle a0, a1(0), a2(2*PI), a3(PI), a4(-PI);

            Tests::Unit(true,  a0.neutre());
            Tests::Unit(true,  a1.neutre());
            Tests::Unit(true,  a2.neutre());

            Tests::Unit(false, a3.neutre());
            Tests::Unit(false, a4.neutre());
         }

         Tests::Case("Predicat ok"); {
         Angle a1(PI), a2(-PI/2), a3(PI/4);

            Tests::Unit(true,  a1.ok());
            Tests::Unit(true,  a2.ok());
            Tests::Unit(true,  a3.ok());
         }

   Tests::End();
}
