//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Triangle - Tests unitaires des services equilateral, isocele et rectangle
//                   (Cas nominaux)
//
// Auteur : C.Fouco
//
#include "Triangle.h"
#include "../../_Tests/Tests/Tests.h"

int main () {

   Tests::Begin("_Maths.Triangle", "2.1.0");

      Tests::Design("Controle des services equilateral, isocele et rectangle", 3);
      Point O(0.,0.), A(2.,0.), B(1.,sqrt(3)), C(0.,2.), D(0.,3.);
	Triangle OAB(O, A, B), OAC(O, A, C), OAD(O, A, D);

		Tests::Case("Triangle equilateral");
		{
            Tests::Unit(true,  OAB.equilateral());
			Tests::Unit(false,  OAC.equilateral());
			Tests::Unit(false,  OAD.equilateral());
		}
	
		Tests::Case("Triangle isocele");
		{
			Tests::Unit(true,  OAB.isocele());
			Tests::Unit(true,  OAC.isocele());
			Tests::Unit(false,  OAD.isocele());
		}
	
		Tests::Case("Triangle rectangle");
		{
			Tests::Unit(false,  OAB.rectangle());
			Tests::Unit(true,  OAC.rectangle());
			Tests::Unit(true,  OAD.rectangle());
		}
	
	

          
   Tests::End();
}
