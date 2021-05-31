//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Triangle - Tests unitaires de l'homothétie
//                   (Cas nominaux)
//
// Auteur : C.Fouco
//
#include "Triangle.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Maths.Triangle", "2.1.0");

      Tests::Design("Controle des Transformations de plan", 3);
      Point O(0.,0.), A(2.,0.), B(0., 2.), C(2., 2.);
	  Triangle OAB(O, A, B), ABC(A, B, C);
	  Vecteur V1(O,C);

		Tests::Case("Homothetie");
		{
            Tests::Unit("[(0, 0), (4, 0), (0, 4)]",  OAB.homothetie(2)->toString());
			Tests::Unit("[(4, 0), (0, 4), (4, 4)]",  ABC.homothetie(2)->toString());
		}

		Tests::Case("Homothetie");
		{
            Tests::Unit("[(-2, -2), (2, -2), (-2, 2)]",  OAB.homothetie(C, 2)->toString());
			Tests::Unit("[(4, 0), (0, 4), (4, 4)]",  ABC.homothetie(O, 2)->toString());
		}

		


   Tests::End();
}
