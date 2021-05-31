//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Triangle - Tests unitaires des constructeurs
//                   (Cas nominaux)
//
// Auteur : C.Fouco
//
#include "Triangle.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Triangle", "2.1.0");

      Tests::Design("Controle de la construction", 3);

         Tests::Case("Premier constructeur normal"); {
         Triangle T;

         char attendu[]= "[(-1, 0), (1, 0), (0, 1)]";

            Tests::Unit(attendu, T.toString());
         }

         Tests::Case("Premier constructeur normal"); {
         Point A(2.36, 1), B(13.7, -7.5), C(-1.5, 2.256), D(1.5, -1.25);
         Triangle ABC(A, B, C), CDB(C, D, B);

         char attendu_1[]= "[(2.36, 1), (13.7, -7.5), (-1.5, 2.256)]";
         char attendu_2[]= "[(-1.5, 2.256), (1.5, -1.25), (13.7, -7.5)]";

            Tests::Unit(attendu_1, ABC.toString());
            Tests::Unit(attendu_2, CDB.toString());
         }

         Tests::Case("Second constructeur normal"); {
         Point A(2.36, 1), B(13.7, -7.5), C(-1.5, 2.256), D(1.5, -1.25);
         Vecteur AB(A, B), AC(A, C), CD(C, D), CB(C, B);
         Triangle ABC(A, AB, AC), CDB(C, CD, CB);

         char attendu_1[]= "[(2.36, 1), (13.7, -7.5), (-1.5, 2.256)]";
         char attendu_2[]= "[(-1.5, 2.256), (1.5, -1.25), (13.7, -7.5)]";

            Tests::Unit(attendu_1, ABC.toString());
            Tests::Unit(attendu_2, CDB.toString());
         }

   Tests::End();
}
