//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Point - Tests unitaires de la persistance
//              (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Point.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Point", "3.0.0");

      Tests::Design("Controle de la persistance", 3);
	
         Tests::Case("Persistance dans le repertoire courant"); {
         Point p1(-1,-0.5), p2(1, -2), p3(0.5, -0.75), p4(-0.125, -3);
         Point p5(1, 2), p6(-1, 2), p7(1, -2), p8(0.5, 1.75);
         Point p9(0.5, -1.75);
         Point resultat;

            _Archives::init();

            p1.enregistrer("p1.dat"); resultat.restaurer("p1.dat");
            Tests::Unit(p1.toString(), resultat.toString());

            p2.enregistrer("p2.dat"); resultat.restaurer("p2.dat");
            Tests::Unit(p2.toString(), resultat.toString());

            p3.enregistrer("p3.dat"); resultat.restaurer("p3.dat");
            Tests::Unit(p3.toString(), resultat.toString());

            p4.enregistrer("p4.dat"); resultat.restaurer("p4.dat");
            Tests::Unit(p4.toString(), resultat.toString());

            p5.enregistrer("p5.dat"); resultat.restaurer("p5.dat");
            Tests::Unit(p5.toString(), resultat.toString());

            p6.enregistrer("p6.dat"); resultat.restaurer("p6.dat");
            Tests::Unit(p6.toString(), resultat.toString());

            p7.enregistrer("p7.dat"); resultat.restaurer("p7.dat");
            Tests::Unit(p7.toString(), resultat.toString());

            p8.enregistrer("p8.dat"); resultat.restaurer("p8.dat");
            Tests::Unit(p8.toString(), resultat.toString());

            p9.enregistrer("p9.dat"); resultat.restaurer("p9.dat");
            Tests::Unit(p9.toString(), resultat.toString());
         }

   Tests::End();
}
