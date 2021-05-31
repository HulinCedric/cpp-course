//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Polgygone - Tests unitaire de la méthode distance
//
// Auteur : C.Fouco
//

#include "Polygone.h"
#include "T:\_Tests\Tests\Tests.h"

void main() {
	
	Tests::Begin("_Maths.Polygone", "1.0.0");
	
		Tests::Design("Controle de la methode distance", 3);
		
			Tests::Case("Controle de la methode distance");{
				Polygone P;
				Point A(0, 0),B(0.5, 0.5), C(0.5, 2), D(0, 3), E(2, 2), F(3, 3), G(3,0), H(0,4);
				Polygone P2(A ,G , D);

				Tests::Unit(0.0, P.distance(A));
				Tests::Unit(0.0, P.distance(B));

				Tests::Unit(1.0, P.distance(C));
				Tests::Unit(2.0, P.distance(D));
				Tests::Unit(sqrt(2), P.distance(E));
				Tests::Unit(sqrt(8), P.distance(F));
				Tests::Unit(1.0, P2.distance(H));
			}
	
	Tests::End();
}