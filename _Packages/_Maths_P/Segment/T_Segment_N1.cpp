//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Segment - Tests unitaires des constructeurs
//                  (cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Segment.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Segment", "3.0.0");

      Tests::Design("Controle de la construction", 3);

         Tests::Case("Constructeur par defaut"); {
         Segment parDefaut;

            Tests::Unit("[(0, 0), (0, 1)]",  parDefaut.toString());
         }

         Tests::Case("Premier constructeur normal"); {
         Point A(1, 0), B(3, 2), C(-2.5, 0.5), D(1.23, -7.56);
         Segment AB(A, B), BC(B, C), CD(C, D), AC(A, C);

            Tests::Unit("[(1, 0), (3, 2)]",             AB.toString());
            Tests::Unit("[(3, 2), (-2.5, 0.5)]",        BC.toString());
            Tests::Unit("[(-2.5, 0.5), (1.23, -7.56)]", CD.toString());
            Tests::Unit("[(1, 0), (-2.5, 0.5)]",        AC.toString());
         }

         Tests::Case("Second constructeur normal"); {
         Point A(1, 0), B(3, 2), C(-2.5, 0.5), D(1.23, -7.56);
         Segment AB(A, B), BC(B, C), CD(C, D), AC(A, C);

            Tests::Unit("[(1, 0), (3, 2)]",             AB.toString());
            Tests::Unit("[(3, 2), (-2.5, 0.5)]",        BC.toString());
            Tests::Unit("[(-2.5, 0.5), (1.23, -7.56)]", CD.toString());
            Tests::Unit("[(1, 0), (-2.5, 0.5)]",        AC.toString());
         }
 
   Tests::End();
}
