//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe LigneBrisee - Tests unitaires de la surcharge de l'operateur =
//                      (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "LigneBrisee.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.LigneBrisee", "3.0.0");

      Tests::Design("Controle de l'operateur =", 3);
      Point O(0, 0), A(1, 0), B(0, 1), C(-1, 0), D(0, -1);

         Tests::Case("Cas de deux operandes vides"); {
         LigneBrisee S, L;

            L= S;

            Tests::Unit(0,  L.cardinal());
            Tests::Unit(0., L.longueur());

         }

         Tests::Case("Cas d'un premier operande vide et l'autre pas"); {
         LigneBrisee L, S;

            S += O;

            L= S;

            Tests::Unit(1,  L.cardinal());
            Tests::Unit(0., L.longueur());

         }

         Tests::Case("Cas d'un second operande vide et l'autre pas"); {
         LigneBrisee L, S;

            L += O;

            L= S;

            Tests::Unit(0,  L.cardinal());
            Tests::Unit(0., L.longueur());

         }

         Tests::Case("Cas avec deux sommets"); {
         LigneBrisee L, S;

            S += O; S += A;

            L= S;

            Tests::Unit(2,   L.cardinal());
            Tests::Unit(1.,  L.longueur());
         }

         Tests::Case("Cas de l'affectation a une ligne brisee vide"); {
         LigneBrisee L, S;

            S += O; S += A; S += B; S += C; S += D;

            L= S;

            Tests::Unit(5,         L.cardinal());
            Tests::Unit(5.242641,  L.longueur(), EPSILON);
         }

         Tests::Case("Cas de l'affectation d'une ligne brisee vide"); {
         LigneBrisee L, S;

            L += O; L += A; L += B; L += C; L += D;

            L= S;

            Tests::Unit(0,  L.cardinal());
            Tests::Unit(0., L.longueur(), EPSILON);
         }

         Tests::Case("Cas general"); {
         LigneBrisee L, S;

            L += O; L += A; L += B;
            S += C; S += D;

            L= S;

            Tests::Unit(2,       L.cardinal());
            Tests::Unit(1.41421, L.longueur(), EPSILON);
         }
        
   Tests::End();
}
