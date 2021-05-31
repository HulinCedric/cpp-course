//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Polgygone - Tests unitaire des constructeurs
//
// Auteur : C.Fouco
//

#include "Polygone.h"
#include "T:\_Tests\Tests\Tests.h"

void main() {

	Tests::Begin("_Maths.Polygone", "1.0.0");

		Tests::Design("Controle des constructeurs", 3);

			Tests::Case("Constructeur par defaut"); {
				Polygone P;

				Tests::Unit("[(1, 1), (-1, 1), (-1, -1), (1, -1)]", P.toString());

			}

			Tests::Case("Constructeur avec trois points"); {
				Point A(0, 0), B(0, 1), C(1, 0);
				Polygone P(A, B, C);

				Tests::Unit("[(0, 0), (0, 1), (1, 0)]", P.toString());
			}

			Tests::Case("Constructeur avec un triangle"); {
				Point A(0, 0), B(0, 1), C(1, 0);
				Triangle T(A, B, C);
				Polygone P(T);

				Tests::Unit("[(0, 0), (0, 1), (1, 0)]", P.toString());
			}

			Tests::Case("Constructeur de copie"); {
				Point A(0, 0), B(0, 1), C(1, 0);
				Triangle T(A, B, C);
				Polygone P(T), P2(P);

				Tests::Unit("[(0, 0), (0, 1), (1, 0)]", P2.toString());
			}

	Tests::End();
}