//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Triangle - Tests unitaires des services orhocentre, barycentre
//                   (Cas nominaux)
//
// Auteur : C.Fouco
//
#include "Triangle.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Maths.Triangle", "2.1.0");

      Tests::Design("Controle des services orhocentre et barycentre", 3);
		Point O(0.,0.), A(2.,0.), B(1.,sqrt(3)), C(0.,2.), D(0.,3.);
		Triangle OAB(O, A, B), OAC(O, A, C), OAD(O, A, D);

	Tests::Case("orthocentre");
	{

		Tests::Unit("(1, 0.57735)",	OAB.orthocentre()->toString());
		Tests::Unit("(0, 0)",		OAC.orthocentre()->toString());
		Tests::Unit("(0, 0)",		OAD.orthocentre()->toString());
	}
	
	Tests::Case("barycentre");
	{
		Tests::Unit("(1, 0.57735)",			OAB.barycentre()->toString());
		Tests::Unit("(0.666667, 0.666667)",	OAC.barycentre()->toString());
		Tests::Unit("(0.666667, 1)",		OAD.barycentre()->toString());
	}
		
   Tests::End();
}
