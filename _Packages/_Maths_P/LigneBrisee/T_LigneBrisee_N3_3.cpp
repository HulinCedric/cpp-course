//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe LigneBrisee - Tests unitaires de la surcharge de l'operateur ==
//                      (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "LigneBrisee.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.LigneBrisee", "3.0.0");

      Tests::Design("Controle de l'operateur ==", 3);
      Point O(0, 0), A(1, 0), B(0, 1), C(-1, 0), D(0, -1);

         Tests::Case("Cas de deux operandes vides"); {
         LigneBrisee S, L;

            Tests::Unit(true, L==S);
         }

         Tests::Case("Cas d'un premier operande vide et l'autre pas"); {
         LigneBrisee S, L;

             S += O; Tests::Unit(false, L==S);
         }

         Tests::Case("Cas d'un second operande vide et l'autre pas"); {
         LigneBrisee S, L;

             L += O; Tests::Unit(false, L==S);
         }

         Tests::Case("Cas avec un seul sommet"); {
         LigneBrisee L, S;

            S += O; Tests::Unit(false, L==S);
            L += O; Tests::Unit(true,  L==S);

         }

         Tests::Case("Cas avec deux sommets"); { 
         LigneBrisee L, S;

            S += O; S += A;
            Tests::Unit(false, L==S);

            L += O; Tests::Unit(false, L==S);
            L += A; Tests::Unit(true,  L==S);
         }

         Tests::Case("Cas d'une construction progressive"); {
         LigneBrisee L, S;

            S += O;
            S += A;
            S += B;
            S += C;
            S += D;

            L += O; Tests::Unit(false, L==S);
                    Tests::Unit(false, S==L);
            L += A; Tests::Unit(false, L==S);
            L += B; Tests::Unit(false, L==S);
            L += C; Tests::Unit(false, L==S);
            L += D; Tests::Unit(true,  L==S);
            
         }

         Tests::Case("Cas d'un ordre different"); {
         LigneBrisee L, S;

            L += O; S += A;
            L += A; S += O;

            Tests::Unit(false, S==L);
         }
       
   Tests::End();
}
