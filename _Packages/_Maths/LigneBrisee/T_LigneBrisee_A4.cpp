//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe LigneBrisee - Tests unitaires de la surcharge de l'opérateur -=
//                      (Cas d'anomalies)
//
// Auteurs : N. Agostini,  C. Anfossi,    R. Brzokewicz,
//           R. Cochonot,  T. De Freyman, M. Ferrante,
//           O. Giammetta, J. Jot,        C. Loaec,
//           I. Mahjoub,   P. Saramito,   J. Scoffier.
//
#include "LigneBrisee.h"
#include "T:\_Tests\Tests\Tests.h"

void main() {
	
	Tests::Begin("_Maths.LigneBrisee", "1.0.0");
	
		Tests::Design("Controle de la surcharge de l'operateur -=", 3);

			Tests::Case("Retrait d'une ligne brisee a une autre ligne brisee"); {

				try {
				
					Point A(0, 6.6), B(4, 2);
					LigneBrisee L1(A, B), L2(B, A);

					L1 -= L2;
				}
				catch(double e) { Tests::Unit(-2.0, e); }

				try {
				
					Point A(3.4, 5), B(3, 8), C(3, -5), T[] = { A, B, C };
					LigneBrisee L1(T, 3), L2(B, C);

					L1 -= L2;
				}
				catch(double e) { Tests::Unit(-2.1, e); }
			}

			Tests::Case("Retrait d'un point a une ligne brisee"); {

				try {
				
					Point A(-1, -10.1), B(-4, -2);
					LigneBrisee L1(A, B);

					L1 -= B;
				}
				catch(double e) { Tests::Unit(-2.0, e); }
			}

	Tests::End();
}
