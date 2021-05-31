//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe LigneBrisee - Tests unitaires des accesseurs 
//                      (Cas nominaux)
//
// Auteurs : C.Fouco
//

#include "LigneBrisee.h"
#include "T:\_Tests\Tests\Tests.h"

void main() {
	
	Tests::Begin("_Maths.LigneBrisee", "1.0.0");
	
		Tests::Design("Controle des accesseurs", 3);

			Tests::Case("Accesseur du cardinal"); {

				Point A(0, -6), B(-1.6, 3), C(4.3, -5), D(8.8, 6.3), E(-7, -5);
				Point T1[] = { A, B, C }, T2[] = { A, B, C, D, E };
				LigneBrisee L1(T1, 3), L2(T2, 5);

				Tests::Unit(3, L1.cardinal());

				Tests::Unit(5, L2.cardinal());
			}

			Tests::Case("Accesseur du premier sommet"); {

				Point A(0.5, 6), B(1, -3), C(4.2, 5), D(-8, 3);
				Point* pS;
				LigneBrisee L1(A, B), L2(C, D);

				pS = L1.premierSommet();
				Tests::Unit("(0.5, 6)", pS->toString());

				pS = L2.premierSommet();
				Tests::Unit("(4.2, 5)", pS->toString());
			}

			Tests::Case("Accesseur du dernier sommet"); {

				Point A(0, 6.7), B(-1, 3), C(-4, -5), D(8.9, 3);
				Point* pS;
				LigneBrisee L1(A, B), L2(C, D);

				pS = L1.dernierSommet();
				Tests::Unit("(-1, 3)", pS->toString());

				pS = L2.dernierSommet();
				Tests::Unit("(8.9, 3)", pS->toString());
			}

			Tests::Case("Accesseur du sommet precise en parametre par son indice"); {

				Point A(0, 5.6), B(1.1, 3), C(-4, 5), D(8, -3), E(7.5, 5);
				Point* pS, T[] = { A, B, C, D, E };
				LigneBrisee L(T, 5);

				pS = L[2];
				Tests::Unit("(1.1, 3)", pS->toString());

				pS = L[4];
				Tests::Unit("(8, -3)", pS->toString());
			}

			Tests::Case("Accesseur d'un interval");
			{
		
				Point A(0, 5.6), B(1.1, 3), C(-4, 5), D(8, -3), E(7.5, 5);
				Point T[] = { A, B, C, D, E };
				LigneBrisee L(T, 5), *L2;
		
				L2 = L(2, 4);
				Tests::Unit("[(1.1, 3), (-4, 5), (8, -3)]", L2->toString());
			}
	
	Tests::End();
}