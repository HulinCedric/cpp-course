//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe LigneBrisee - Tests unitaires de la méthode inclus
//                      (Cas nominaux)
//
// Auteurs : C.Fouco
//

#include "LigneBrisee.h"
#include "T:\_Tests\Tests\Tests.h"

void main() {
	
	Tests::Begin("_Maths.LigneBrisee", "1.0.0");
	
		Tests::Design("Controle de la methode inclus", 3);

			Tests::Case("Methode inclus"); {

				Point A(-1, 0), B(3, 2), C(-2.5, 0.5), D(1.23, -7.56);
				Point P1[] = { A, B, C, D }, P2[] = { A, B, C }, P3[] = { C, B, A }, P4[] = { A, C, D}, P5[] = { C, A };
				LigneBrisee L1(P1,4), L2(P2,3), L3(P3,3), L4(P4,3), L5(P5,2);

				Tests::Unit(1,L1.inclus(L2));
				Tests::Unit(1,L1.inclus(L3));
				Tests::Unit(0,L1.inclus(L4));
				Tests::Unit(0,L1.inclus(L5));
				Tests::Unit(1,L4.inclus(L5));
			}


	Tests::End();
}