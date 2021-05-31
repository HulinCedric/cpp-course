//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe LigneBrisee - Tests unitaires des accesseurs
//                      (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "LigneBrisee.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.LigneBrisee", "3.0.0");

      Tests::Design("Controle des accesseurs", 3);

         Tests::Case("Methode cardinal"); {
         LigneBrisee neutre;

            Tests::Unit(0,  neutre.cardinal());
         }

         Tests::Case("Methode premierSommet"); {
         LigneBrisee neutre;

            Tests::Unit(NULL,  (int)neutre.premierSommet());
         }

         Tests::Case("Methode dernierSommet"); {
         LigneBrisee neutre;

            Tests::Unit(NULL,  (int)neutre.dernierSommet());
         }

         Tests::Case("Methode longueur"); {
         LigneBrisee neutre;

            Tests::Unit(0.,  neutre.longueur());
         }
         
   Tests::End();
}
