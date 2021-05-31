//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe LigneBrisee - Tests unitaires de la surcharge de l'opérateur +=
//                      (Cas nominaux)
//
// Auteurs : C.Fouco
//

#include "LigneBrisee.h"
#include "T:\_Tests\Tests\Tests.h"

void main() {
	
	Tests::Begin("_Maths.LigneBrisee", "1.0.0");
	
		Tests::Design("Controle de la surcharge de l'operateur +=", 3);

			Tests::Case("Ajout des points d'une ligne brisee a une autre ligne brisee"); {

				Point A(0, 6), B(-1, -3), C(4, 5), D(6, -3), E(5, 0), F(-4, 10);
				LigneBrisee L1(A, B), L2(C, D), L3(E, F);

				L1 += L2;
				Tests::Unit("[(0, 6), (-1, -3), (4, 5), (6, -3)]", L1.toString());

				L1 += L3;
				Tests::Unit("[(0, 6), (-1, -3), (4, 5), (6, -3), (5, 0), (-4, 10)]", L1.toString());
			}

			Tests::Case("Ajout d'un point a une ligne brisee"); {

				Point A(-2, 4), B(0, -3), C(8, -6), D(4, 3), E(-9, 1), F(2, -5);
				LigneBrisee L(A, B);

				L += C;
				Tests::Unit("[(-2, 4), (0, -3), (8, -6)]", L.toString());

				L += D;
				Tests::Unit("[(-2, 4), (0, -3), (8, -6), (4, 3)]", L.toString());

				L += E;
				Tests::Unit("[(-2, 4), (0, -3), (8, -6), (4, 3), (-9, 1)]", L.toString());

				L += F;
				Tests::Unit("[(-2, 4), (0, -3), (8, -6), (4, 3), (-9, 1), (2, -5)]", L.toString());
			}
	
	Tests::End();
}