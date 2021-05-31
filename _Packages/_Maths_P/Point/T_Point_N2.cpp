//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Point - Tests unitaires des accesseurs 
//                (cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Point.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Point", "3.0.0");

      Tests::Design("Controle des accesseurs", 3);

         Tests::Case("Methode numero"); {
         Point p1(1, 4,0), p2(2, 11, 0);
         
            Tests::Unit(1, p1.numero());
            Tests::Unit(2, p2.numero());
         }

   Tests::End();
}
