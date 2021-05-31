//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Ensemble - Tests unitaires des accesseurs de consultation
//                   (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Ensemble.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Ensemble", "1.0.0");

      Tests::Design("Controle des accesseurs de consultation", 3);

         Tests::Case("Methode appartient"); {
         Ensemble vide;

            Tests::Unit(0, vide.appartient(NULL));
         }

   Tests::End();
}

