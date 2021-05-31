//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Droite - Tests unitaires des accesseurs
//                 (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Droite.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths:Droite", "2.0.0");

      Tests::Design("Controle des accesseurs", 3);

         Tests::Case("Controle de la methode directeur"); {
         Point A(3, 0), B(0, 2), C(3, 2);
         Droite AB(A, B), AC(A, C), BC(B, C);

            Tests::Unit("(1, -0.666667)",  AB.directeur()->toString());
            Tests::Unit("(0, -1)",         AC.directeur()->toString());
            Tests::Unit("(1, 0)",          BC.directeur()->toString());
         }

   Tests::End();
}
