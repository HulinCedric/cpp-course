//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe LigneBrisee - Tests unitaires des constructeurs 
//                      (Cas nominaux)
//
// Auteurs : C.Fouco 
//           
//
#include "LigneBrisee.h"
#include "T:\_Tests\Tests\Tests.h"

void main() {
	
	Tests::Begin("_Maths.LigneBrisee", "1.0.0");
	
		Tests::Design("Controle de la construction", 3);
		
			Tests::Case("Constructeur par defaut"); {

				LigneBrisee L;
				Tests::Unit("[(0, 0), (0, 1)]", L.toString());
			}

			Tests::Case("Constructeur normal avec deux points"); {

				Point A(-4, 1), B(2.8, 5);

				LigneBrisee L(A, B);
				Tests::Unit("[(-4, 1), (2.8, 5)]", L.toString());
			}

			Tests::Case("Constructeur normal avec deux pointeurs de point"); {

				Point* A = new Point(-7.8, 6);
				Point* B = new Point(-3, 9.2);

				LigneBrisee L(A, B);
				Tests::Unit("[(-7.8, 6), (-3, 9.2)]", L.toString());

				delete A; delete B;
			}

			Tests::Case("Constructeur normal avec un tableau de points"); {

				Point A(3, 6), B(-1, -3), C(4.4, 5), T[] = { A, B, C };

				LigneBrisee L(T, 3);
				Tests::Unit("[(3, 6), (-1, -3), (4.4, 5)]", L.toString());
			}

			Tests::Case("Constructeur normal avec un tableau de pointeurs de point"); {

				Point** pT = new Point*[5];
				pT[0] = new Point(3.4, 3.6); pT[1] = new Point(-8, 4);
				pT[2] = new Point(1, 7); pT[3] = new Point(6.5, -5);
				pT[4] = NULL;

				LigneBrisee L(pT);
				Tests::Unit("[(3.4, 3.6), (-8, 4), (1, 7), (6.5, -5)]", L.toString());

				delete pT[0]; delete pT[1]; delete pT[2]; delete pT[3]; delete[] pT;
			}

			Tests::Case("Constructeur normal avec un segment"); {

				Point A(4.3, 4.9), B(-2, 0);
				Segment AB(A, B);

				LigneBrisee L(AB);
				Tests::Unit("[(4.3, 4.9), (-2, 0)]", L.toString());
			}

			Tests::Case("Constructeur de copie"); {

				Point A(2.4, 8.2), B(-3.3, 0);

				LigneBrisee L1(A, B), L2(L1);
				Tests::Unit("[(2.4, 8.2), (-3.3, 0)]", L2.toString());
			}
	
	Tests::End();
}