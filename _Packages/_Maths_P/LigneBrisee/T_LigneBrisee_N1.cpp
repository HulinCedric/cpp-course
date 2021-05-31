//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe LigneBrisee - Tests unitaires des constructeurs
//                      (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "LigneBrisee.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.LigneBrisee", "3.0.0");

      Tests::Design("Controle des constructeurs", 3);

         Tests::Case("Cas du constructeur par defaut"); {
         LigneBrisee neutre;

            Tests::Unit("[]",  neutre.toString());
         }

         Tests::Case("Cas du constructeur de copie"); {
         LigneBrisee neutre;
         LigneBrisee copie(neutre);

            Tests::Unit("[]",  copie.toString());
         }

   Tests::End();
}
