//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe vecteur - Tests unitaires de la persistance
//                  (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Vecteur.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Vecteur", "3.0.0");

      Tests::Design("Controle de la persistance", 3);
	
         Tests::Case("Persistance dans le repertoire courant"); {
         Vecteur v1(-1,-0.5), v2(1, -2), v3(0.5, -0.75), v4(-0.125, -3);
         Vecteur resultat;

            _Archives::init();

            v1.enregistrer("v1.dat"); resultat.restaurer("v1.dat");
            Tests::Unit(v1.toString(), resultat.toString());

            v2.enregistrer("v2.dat"); resultat.restaurer("v2.dat");
            Tests::Unit(v2.toString(), resultat.toString());

            v3.enregistrer("v3.dat"); resultat.restaurer("v3.dat");
            Tests::Unit(v3.toString(), resultat.toString());

            v4.enregistrer("v4.dat"); resultat.restaurer("v4.dat");
            Tests::Unit(v4.toString(), resultat.toString());
         }

   Tests::End();
}
