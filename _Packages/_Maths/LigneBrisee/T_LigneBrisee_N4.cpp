//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe LigneBrisee - Tests unitaires de la surcharge de l'opérateur -=
//                      (Cas nominaux)
//
// Auteurs : C.Fouco
//

#include "LigneBrisee.h"
#include "T:\_Tests\Tests\Tests.h"

void main() {
	
	Tests::Begin("_Maths.LigneBrisee", "1.0.0");
	
		Tests::Design("Controle de la surcharge de l'operateur -=", 3);

			Tests::Case("Retrait des points d'une ligne brisee a une autre ligne brisee"); {
			
				Point A(0, -6), B(1, -3), C(-5, 5), D(-8, -3), E(5, 3), F(-4, 5);
				Point T[] = { A, B, C, D, E, F };
				LigneBrisee L1(T, 6), L2(B, E), L3(F, A);
				
				L1 -= L2;
				Tests::Unit("[(0, -6), (-5, 5), (-8, -3), (-4, 5)]", L1.toString());

				L1 -= L3;
				Tests::Unit("[(-5, 5), (-8, -3)]", L1.toString());
			}
		
			Tests::Case("Retrait d'un point a une ligne brisee"); {
				
				Point A(-4, 3), B(-6, -8), C(2, 5), D(-7, 1), E(0, 0), F(-1, -6);
				Point T[] = { A, B, C, D, E, F };
				LigneBrisee L(T, 6);
				
				L -= B;
				Tests::Unit("[(-4, 3), (2, 5), (-7, 1), (0, 0), (-1, -6)]", L.toString());

				L -= D;
				Tests::Unit("[(-4, 3), (2, 5), (0, 0), (-1, -6)]", L.toString());

				L -= E;
				Tests::Unit("[(-4, 3), (2, 5), (-1, -6)]", L.toString());

				L -= C;
				Tests::Unit("[(-4, 3), (-1, -6)]", L.toString());
			}
			
	Tests::End();
}