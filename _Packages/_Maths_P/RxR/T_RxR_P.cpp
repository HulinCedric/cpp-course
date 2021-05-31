//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe RxR - Tests unitaires de la persistance
//              (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "RxR.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.RxR", "3.0.0");

      Tests::Design("Controle de la persistance", 3);
	
         Tests::Case("Persistance dans le repertoire courant"); {
         RxR z1(-1,-0.5), z2(1, -2), z3(0.5, -0.75), z4(-0.125, -3);
         RxR z5(1, 2), z6(-1, 2), z7(1, -2), z8(0.5, 1.75);
         RxR z9(0.5, -1.75);
         RxR resultat;

            _Archives::init();

            z1.enregistrer("z1.dat"); resultat.restaurer("z1.dat");
            Tests::Unit(z1.toString(), resultat.toString());

			resultat.enregistrer("test.txt");

            /*z2.enregistrer("z2.dat"); resultat.restaurer("z2.dat");
            Tests::Unit(z2.toString(), resultat.toString());

            z3.enregistrer("z3.dat"); resultat.restaurer("z3.dat");
            Tests::Unit(z3.toString(), resultat.toString());

            z4.enregistrer("z4.dat"); resultat.restaurer("z4.dat");
            Tests::Unit(z4.toString(), resultat.toString());

            z5.enregistrer("z5.dat"); resultat.restaurer("z5.dat");
            Tests::Unit(z5.toString(), resultat.toString());

            z6.enregistrer("z6.dat"); resultat.restaurer("z6.dat");
            Tests::Unit(z6.toString(), resultat.toString());

            z7.enregistrer("z7.dat"); resultat.restaurer("z7.dat");
            Tests::Unit(z7.toString(), resultat.toString());

            z8.enregistrer("z8.dat"); resultat.restaurer("z8.dat");
            Tests::Unit(z8.toString(), resultat.toString());

            z9.enregistrer("z9.dat"); resultat.restaurer("z9.dat");
            Tests::Unit(z9.toString(), resultat.toString());*/
         }

   Tests::End();
}
