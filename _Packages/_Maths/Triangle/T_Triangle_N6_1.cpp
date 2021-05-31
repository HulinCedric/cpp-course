//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Triangle - Tests unitaires des services hauteur, mediane, mediatrice
//                   (Cas nominaux)
//
// Auteur : C.Fouco
//
#include "Triangle.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Maths.Triangle", "2.1.0");

      Tests::Design("Controle des services hauteur, mediane, mediatrice", 3);
      Point O(0.,0.), A(2.,0.), B(0., 2.);
	Triangle OAB(O, A, B);

		Tests::Case("Mediane");
		{
            Tests::Unit("[(0, 0), (1, 1)]",  OAB.mediane(1)->toString());
			Tests::Unit("[(2, 0), (0, 1)]",  OAB.mediane(2)->toString());
			Tests::Unit("[(0, 2), (1, 0)]",  OAB.mediane(3)->toString());

		}

		Tests::Case("Mediatrice");
		{         
			Tests::Unit("[(1, -1), (1, 1)]",  OAB.mediatrice(1)->toString());
			Tests::Unit("[(2, 2), (0, 0)]",  OAB.mediatrice(2)->toString());
			Tests::Unit("[(-1, 1), (1, 1)]",  OAB.mediatrice(3)->toString());
		}

		Tests::Case("Hauteur");
		{
			Tests::Unit("[(0, 0), (1, 1)]", OAB.hauteur(1)->toString());
		}
	

   Tests::End();
}
