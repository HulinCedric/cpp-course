//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe LigneBrisee - Tests unitaires de la méthode longueur et de la méthode appartient
//                      (Cas nominaux)
//
// Auteurs : C.Fouco
//

#include "LigneBrisee.h"
#include "T:\_Tests\Tests\Tests.h"

void main() {
	
	Tests::Begin("_Maths.LigneBrisee", "1.0.0");
	
		Tests::Design("Controle de la methode longueur et de la methode appartient", 3);

			Tests::Case("Methode longueur"); {

				Point A(4, 5), B(7, 9), C(10, 6), D(9, 7);
				LigneBrisee L(A, B);

				Tests::Unit(A.distance(B), L.longueur());

				L += C;
				Tests::Unit(A.distance(B)+B.distance(C), L.longueur());

				L += D;
				Tests::Unit(A.distance(B)+B.distance(C)+C.distance(D), L.longueur());
			}

			Tests::Case("Methodes appartient"); {

				Point A(1, 1), B(3, 3), C(2,2), D(0,0);
				LigneBrisee L(A, B);

				Tests::Unit(true, L.appartient(B));
				Tests::Unit(true, L.appartient(C));
				Tests::Unit(false, L.appartient(D));
			}
	
	Tests::End();
}