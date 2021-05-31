//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Triangle - Tests unitaires de la translation
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
	  Triangle OAB(O, A, B);
	  Vecteur V1(O,C);

		Tests::Case("Translation");
		{
            Tests::Unit("[(2, 2), (4, 2), (2, 4)]",  OAB.translation(V1)->toString());

		}

   Tests::End();
}
