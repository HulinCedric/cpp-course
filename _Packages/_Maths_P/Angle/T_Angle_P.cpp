//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Angle - Tests unitaires de la persistance
//              (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Angle.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Angle", "3.0.0");

      Tests::Design("Controle de la persistance", 3);
	
         Tests::Case("Persistance dans le repertoire courant"); {
         Angle a1(PI), a2(-PI/4), a3(0), a4(3*PI/4), a5(PI/3);
         Angle resultat;

            _Archives::init();

            a1.enregistrer("a1.dat"); resultat.restaurer("a1.dat");
            Tests::Unit(a1.toString(), resultat.toString());

            a2.enregistrer("a2.dat"); resultat.restaurer("a2.dat");
            Tests::Unit(a2.toString(), resultat.toString());

            a3.enregistrer("a3.dat"); resultat.restaurer("a3.dat");
            Tests::Unit(a3.toString(), resultat.toString());

            a4.enregistrer("a4.dat"); resultat.restaurer("a4.dat");
            Tests::Unit(a4.toString(), resultat.toString());

            a5.enregistrer("a5.dat"); resultat.restaurer("a5.dat");
            Tests::Unit(a5.toString(), resultat.toString());
         }

   Tests::End();
}
