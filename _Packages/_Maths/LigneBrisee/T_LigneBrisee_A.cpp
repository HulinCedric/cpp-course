//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe LigneBrisee - Tests unitaires des constructeurs 
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
	
		Tests::Design("Controle d'anomalies des constructeurs", 3);

			Tests::Case("Constructeur normal avec deux pointeurs de point"); {

				try {

					Point* A = NULL;
					Point* B = new Point(3.5, 2);

					LigneBrisee L(A, B);
				}
				catch(double e) { Tests::Unit(-2.1, e); }

				try {

					Point* A = new Point(-8, -6);
					Point* B = NULL;

					LigneBrisee L(A, B);
				}
				catch(double e) { Tests::Unit(-2.2, e); }
			}

			Tests::Case("Constructeur normal avec un tableau de points"); {

				try {

					Point *pT = NULL;

					LigneBrisee L(pT, 2);
				}
				catch(double e) { Tests::Unit(-2.1, e); }

				try {

					Point A(0, 6.6), T[] = { A };

					LigneBrisee L(T, 1);
				}
				catch(double e) { Tests::Unit(-2.2, e); }
			}

			Tests::Case("Constructeur normal avec un tableau de pointeurs de point"); {

				try {

					Point** pT = NULL;

					LigneBrisee L(pT);
				}
				catch(double e) { Tests::Unit(-2.1, e); }

				try {

					Point** pT = new Point*[2];
					pT[0] = new Point(4.3, -6);
					pT[1] = NULL;

					LigneBrisee L(pT);
				}
				catch(double e) { Tests::Unit(-2.2, e); }
			}

	Tests::End();
}
