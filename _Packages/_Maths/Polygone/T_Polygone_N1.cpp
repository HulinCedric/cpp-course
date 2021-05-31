//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Polgygone - Tests unitaire de l'operateur +=
//
// Auteur : C.Fouco
//


#include "Polygone.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {
	
	Tests::Begin("_Maths.Polygone", "1.0.0");
	
		Tests::Design("Controle de la surcharge de l'operateur +=", 3);
		
			Tests::Case("Surcharge de l'operateur +="); {
				Point A(2, 2), B(1, 2);
				Polygone P;

				Tests::Unit("[(1, 1), (-1, 1), (-1, -1), (1, -1)]", P.toString());

				P += A;
				Tests::Unit("[(1, 1), (-1, 1), (-1, -1), (1, -1), (2, 2)]", P.toString());

				P += B;
				Tests::Unit("[(1, 1), (-1, 1), (-1, -1), (1, -1), (2, 2), (1, 2)]", P.toString());
			}
	
	Tests::End();
}