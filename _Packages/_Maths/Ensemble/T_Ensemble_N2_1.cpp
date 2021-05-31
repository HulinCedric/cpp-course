
//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Ensemble - Tests unitaires des predicats predefinis
//                   (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Ensemble.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Ensemble", "1.0.0");

      Tests::Design("Controle des predicats predefinis", 3);
      Ensemble vide;

         Tests::Case("Predicat neutre"); {

            Tests::Unit(true,  vide.neutre());
         }

         Tests::Case("Predicat ok"); {

            Tests::Unit(true,  vide.ok());
         }

   Tests::End();
}
