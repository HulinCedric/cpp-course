//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Segment - Tests unitaires de la persistance
//                  (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Segment.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Segment", "3.0.0");

      Tests::Design("Controle de la persistance", 3);
	
         Tests::Case("Persistance dans le repertoire courant"); {
         Point O(0, 0), A(0.5, 0.5), B(1, 1), C(-4.5, -4.5);
         Segment s1(A, B), s2(B, C), s3(O, C);
         Segment resultat;

            _Archives::init();

            s1.enregistrer("s1.dat"); resultat.restaurer("s1.dat");
            Tests::Unit(s1.toString(), resultat.toString());

            s2.enregistrer("s2.dat"); resultat.restaurer("s2.dat");
            Tests::Unit(s2.toString(), resultat.toString());

            s3.enregistrer("s3.dat"); resultat.restaurer("s3.dat");
            Tests::Unit(s3.toString(), resultat.toString());
         }

   Tests::End();
}
