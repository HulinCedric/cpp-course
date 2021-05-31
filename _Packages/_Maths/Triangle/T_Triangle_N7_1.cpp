//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Triangle - Tests unitaires de la rotation
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

		Tests::Case("Rotation(double)");
		{
            Tests::Unit("[(0, 0), (-2, 0), (0, -2)]",  OAB.rotation(PI)->toString());
			Tests::Unit("[(0, 0), (2, 0), (0, 2)]",  OAB.rotation(2*PI)->toString());
			Tests::Unit("[(0, 0), (0, 2), (-2, 0)]",  OAB.rotation(PI/2)->toString());
			Tests::Unit("[(0, 0), (1, 1.73205), (-1.73205, 1)]",  OAB.rotation(PI/3)->toString());
			

		}

		Tests::Case("Rotation(const Point&, double");
		{
            Tests::Unit("[(4, 0), (4, 2), (2, 0)]",  OAB.rotation(C,PI/2)->toString());
			Tests::Unit("[(0, 0), (2, 0), (0, 2)]",  OAB.rotation(C,2*PI)->toString());
			Tests::Unit("[(4, 4), (2, 4), (4, 2)]",  OAB.rotation(C,PI)->toString());

		}

	
	

   Tests::End();
}
