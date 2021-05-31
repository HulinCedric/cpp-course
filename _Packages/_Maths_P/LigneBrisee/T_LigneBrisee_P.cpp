//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe LigneBrisee - Tests unitaires de la persistance
//                      (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "LigneBrisee.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.LigneBrisee", "3.0.0");

      Tests::Design("Controle de la persistance", 3);
      Point O(0, 0), A(1, 0), B(0, 1), C(-1, 0), D(0, -1);
	
         Tests::Case("Persistance dans le repertoire courant"); {
         LigneBrisee S, resultat;

            S += O;
            S += A;
            S += B;
            S += C;
            S += D;

            _Archives::init();

            S.enregistrer("s1.dat"); resultat.restaurer("s1.dat");
            Tests::Unit(S.longueur(), resultat.longueur());
         }

   Tests::End();
}
