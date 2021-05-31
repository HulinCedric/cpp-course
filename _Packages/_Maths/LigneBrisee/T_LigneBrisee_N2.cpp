//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe LigneBrisee - Tests unitaires de la surcharge des operateurs =, == et !=
//                      (Cas nominaux)
//
//
// Auteurs : C.Fouco
//

#include "LigneBrisee.h"
#include "T:\_Tests\Tests\Tests.h"

void main() {

	Tests::Begin("_Maths.LigneBrisee", "1.0.0");

		Tests::Design("Controle de la surcharge des operateurs =, == et !=", 3);
		
			Tests::Case("Surcharge de l'operateur ="); {

				Point A(-1, 0), B(3, 2), C(-2.5, 0.5), D(1.23, -7.56);
				Point P1[] = { A, B, C, D }, P2[] = { A, B, C }, P3[] = { A, C };
				LigneBrisee L1(P1,4), L2(P2,3), L3(P3,2), LResultat;
				
				LResultat = L1;
				Tests::Unit(L1.toString(), LResultat.toString());

				LResultat = L2;
				Tests::Unit(L2.toString(), LResultat.toString());

				LResultat = L3;
				Tests::Unit(L3.toString(), LResultat.toString());
			}
			
			Tests::Case("Surcharge de l'operateur =="); {
				
				Point A(1.4, 10), B(5.3, -2), C(5, 5), D(3.3, -6);
				Point P1[] = { A, B, C, D }, P2[] = { A, B, C }, P3[] = { D, C, B, A };
				LigneBrisee L1(P1,4), L2(P1,4), L3(P2,3), L4(P3,4);
				
				Tests::Unit(true, L1 == L2);

				Tests::Unit(false, L1 == L3);

				Tests::Unit(false, L1 == L4);
			}
			
			Tests::Case("Surcharge de l'operateur !="); {
				
				Point A(8, -2), B(-3.4, 2), C(-4, 5.1), D(6.4, -8.6);
				Point P1[] = { A, B, C, D }, P2[] = { A, B, C }, P3[] = { D, C, B, A };
				LigneBrisee L1(P1,4), L2(P1,4), L3(P2,3), L4(P3,4);
				
				Tests::Unit(false, L1 != L2);

				Tests::Unit(true, L1 != L3);

				Tests::Unit(true, L1 != L4);
			}
			
	Tests::End();
}